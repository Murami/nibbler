//
// Snake.cpp for snake in /home/desabr_q/rendu/cpp_nibbler
//
// Made by quentin desabre
// Login   <desabr_q@epitech.net>
//
// Started on  Sun Apr  6 05:11:34 2014 quentin desabre
// Last update Sun Apr  6 11:40:42 2014 
//

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cmath>
#include "IObject.hpp"
#include "Snake.hpp"
#include "MapObject.hpp"

Snake::Snake() :
  m_direction(1, 0),
  m_firstRun(0),
  m_movePeriod(SNAKE_MOVE_NORMAL_PERIOD),
  m_boost(SNAKE_BOOST_MAX),
  m_score(0),
  m_nbLimb(1),
  m_mulScore(1),
  m_alive(true),
  m_isFed(0),
  m_isInvul(false),
  m_boostPeriod(SNAKE_MOVE_BOOST_PERIOD)
{
  m_snakeLimbs.push_back(Vector2i(3, 9));
  m_snakeLimbs.push_back(Vector2i(2, 9));
  m_snakeLimbs.push_back(Vector2i(1, 9));
  m_snakeLimbs.push_back(Vector2i(0, 9));
  addSkin();
  addSkin();
  addSkin();
  addSkin();
  addSkin();
}

Snake::~Snake()
{
  std::cout << "Your score is : " << m_score << std::endl;
}

void	Snake::enableBoost()
{
  m_movePeriod = m_boostPeriod;
}

void	Snake::disableBoost()
{
  m_movePeriod = SNAKE_MOVE_NORMAL_PERIOD;
}

bool	Snake::boostEnabled()
{
  return (m_movePeriod == SNAKE_MOVE_BOOST_PERIOD ||
	  m_movePeriod == SNAKE_MOVE_BOOST_INV_PERIOD);
}

void	Snake::turnRight()
{
  if (!m_alive)
    return;
  m_direction(m_direction.y, -m_direction.x);
}

void	Snake::turnLeft()
{
  if (!m_alive)
    return;
  m_direction(-m_direction.y, m_direction.x);
}

void	Snake::addElem()
{
  int	i;

  i = 0;
  m_isFed = m_nbLimb;
  while (i != m_nbLimb)
    {
      addSkin();
      i++;
    }
}

void	Snake::addSkin()
{
  std::stringstream ss;

  ss << rand() % 48 + 1;
  m_skinLimbs.push_back(ss.str());
}

void	Snake::checkBoost()
{
  int	boostDelta;

  if (m_boost <= 0)
    disableBoost();
  if (boostEnabled())
    {
      boostDelta = m_boostTimer.getElapsedTime() / SNAKE_BOOST_DEGEN_PERIOD;
      m_boost -= boostDelta;
      if (m_boost <= 0)
	m_boost = 0;
    }
  else
    {
      boostDelta = m_boostTimer.getElapsedTime() / SNAKE_BOOST_REGEN_PERIOD;
      m_boost += boostDelta;
      if (m_boost > SNAKE_BOOST_MAX)
	m_boost = SNAKE_BOOST_MAX;
    }
  if (boostDelta)
    m_boostTimer.reset();
}

void	Snake::checkMove(int width, int height, const MapObject& mapObject)
{
  int	nbMove;

  nbMove = m_moveTimer.getElapsedTime() / m_movePeriod;
  if (nbMove)
    {
      m_moveTimer.reset();
    }
  while (nbMove)
    {
      moveSnake(width, height, mapObject);
      nbMove--;
    }
}

void	Snake::update(int width, int height, const MapObject& mapObject)
{
  if (!m_alive)
    return;
  if (m_firstRun <= 10)
    {
      m_firstRun++;
      m_moveTimer.reset();
    }
  checkBoost();
  checkMove(width, height, mapObject);
}

bool	Snake::collideMap(int x, int y) const
{
  if (m_snakeLimbs.front().x + m_direction.x < 0 ||
      m_snakeLimbs.front().x + m_direction.x >= x ||
      m_snakeLimbs.front().y + m_direction.y < 0 ||
      m_snakeLimbs.front().y + m_direction.y >= y)
    return true;
  return false;
}

bool	Snake::collideSnake(int x, int y, int flag) const
{
  std::list<Vector2i>::const_iterator it;

  it = m_snakeLimbs.begin();
  if (!flag)
    it++;
  while (it != m_snakeLimbs.end())
    {
      if ((*it).x == x && (*it).y == y)
	{
	  if (m_isInvul)
	    {
	      m_isInvul = false;
	      return false;
	    }
	  return true;
	}
      it++;
    }
  return false;

}

void	Snake::moveSnake(int width, int height, const MapObject& mapObject)
{
  if (collideMap(width, height) ||
      collideSnake((m_snakeLimbs.front().x + m_direction.x),
		   (m_snakeLimbs.front().y + m_direction.y), 0))
    m_alive = false;
  else
    {
      if (!m_isFed)
	m_snakeLimbs.pop_back();
      else
	m_isFed--;
      m_snakeLimbs.push_front(Vector2i(m_snakeLimbs.front().x + m_direction.x,
				       m_snakeLimbs.front().y + m_direction.y));
      mapObject.useObject((m_snakeLimbs.front().x),
			  (m_snakeLimbs.front().y),
			  *this);
    }

}

void	Snake::updateCam(Renderer& renderer) const
{
  renderer->updateCam(m_snakeLimbs.front().x, m_snakeLimbs.front().y,
		      m_direction.x, m_direction.y);
}

void	Snake::draw(const Renderer& renderer) const
{
  std::list<Vector2i>::const_iterator	it;
  int					i;

  i = 0;
  for (it = m_snakeLimbs.begin(); it != m_snakeLimbs.end(); it++)
    {
      if (it == m_snakeLimbs.begin())
	{
	  renderer->draw("head", (*it).x, (*it).y,
			 atan2(-m_direction.x, m_direction.y) * 180 / M_PI);
	}
      else
	renderer->draw(m_skinLimbs[i], (*it).x, (*it).y, 0);
      i++;
    }
}

void	Snake::addScore(int score)
{
  m_score += (score * m_mulScore);
}

int	Snake::getScore() const
{
  return (m_score);
}

int	Snake::getBoost() const
{
  return (m_boost);
}

void	Snake::setInvul(bool b)
{
  m_isInvul = b;
}

void	Snake::setMulScore()
{
  if (m_mulScore != 32)
    m_mulScore *= 2;
}

void	Snake::setInvertBoost()
{
  if (m_boostPeriod == SNAKE_MOVE_BOOST_PERIOD)
    m_boostPeriod = SNAKE_MOVE_BOOST_INV_PERIOD;
  else
    m_boostPeriod = SNAKE_MOVE_BOOST_PERIOD;
}

void	Snake::setNbLimb()
{
  if (m_nbLimb != 8)
    m_nbLimb *= 2;
}

void	Snake::die()
{
  m_alive = false;
}

bool	Snake::alive() const
{
  return (m_alive);
}
