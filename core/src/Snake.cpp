//
// Snake.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 14:43:21 2014 guerot_a
// Last update Fri Apr  4 13:25:24 2014 
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
  m_alive(true),
  m_isFed(false),
  m_movePeriod(SNAKE_MOVE_NORMAL_PERIOD),
  m_boost(SNAKE_BOOST_MAX),
  m_score(0)
{
  m_snakeLimbs.push_back(Vector2i(4, 0));
  m_snakeLimbs.push_back(Vector2i(3, 0));
  m_snakeLimbs.push_back(Vector2i(2, 0));
  m_snakeLimbs.push_back(Vector2i(1, 0));
  m_snakeLimbs.push_back(Vector2i(0, 0));
  addSkin();
  addSkin();
  addSkin();
  addSkin();
  addSkin();
}

Snake::~Snake()
{
}

void	Snake::enableBoost()
{
  m_movePeriod = SNAKE_MOVE_BOOST_PERIOD;
}

void	Snake::disableBoost()
{
  m_movePeriod = SNAKE_MOVE_NORMAL_PERIOD;
}

bool	Snake::boostEnabled()
{
  return (m_movePeriod == SNAKE_MOVE_BOOST_PERIOD);
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
  m_isFed = true;
  addSkin();
}

void	Snake::addSkin()
{
  std::stringstream ss;

  ss << rand() % 48 + 1;
  m_skinLimbs.push_back(ss.str());
}

void	Snake::update(int width, int height, const MapObject& mapObject)
{
  int	nbMove;
  int	boostDelta;

  if (!m_alive)
    return;

  if (m_boost == 0)
    disableBoost();

  if (boostEnabled())
    {
      boostDelta = m_boostTimer.getElapsedTime() / SNAKE_BOOST_DEGEN_PERIOD;
      m_boost -= boostDelta;
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

bool	Snake::collideMap(int x, int y) const
{
  if (m_snakeLimbs.front().x + m_direction.x < 0 ||
      m_snakeLimbs.front().x + m_direction.x >= x ||
      m_snakeLimbs.front().y + m_direction.y < 0 ||
      m_snakeLimbs.front().y + m_direction.y >= y)
    return true;
  return false;
}

bool	Snake::collideSnake(int x, int y) const
{
  std::list<Vector2i>::const_iterator it;

  it = m_snakeLimbs.begin();
  it++;
  while (it != m_snakeLimbs.end())
    {
      if ((*it).x == x && (*it).y == y)
	return true;
      it++;
    }
  return false;

}

void	Snake::moveSnake(int width, int height, const MapObject& mapObject)
{
  if (collideMap(width, height) ||
      collideSnake((m_snakeLimbs.front().x + m_direction.x),
		   (m_snakeLimbs.front().y + m_direction.y)))
    m_alive = false;
  else
    {
      if (!m_isFed)
	m_snakeLimbs.pop_back();
      else
	m_isFed = false;
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
  m_score += score;
}

int	Snake::getScore() const
{
  return (m_score);
}
