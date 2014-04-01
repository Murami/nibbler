//
// Snake.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 14:43:21 2014 guerot_a
// Last update Tue Apr  1 23:12:05 2014 guerot_a
//

#include <iostream>
#include "IObject.hpp"
#include "Snake.hpp"
#include "MapObject.hpp"

Snake::Snake() :
  m_direction(1, 0),
  m_alive(true)
{
  // m_snakeLimbs.push_back(Vector2i(6, 0));
  // m_snakeLimbs.push_back(Vector2i(5, 0));
  // m_snakeLimbs.push_back(Vector2i(4, 0));
  // m_snakeLimbs.push_back(Vector2i(3, 0));
  m_snakeLimbs.push_back(Vector2i(2, 0));
  m_snakeLimbs.push_back(Vector2i(1, 0));
  m_snakeLimbs.push_back(Vector2i(0, 0));
}

Snake::~Snake()
{
}

void	Snake::enableBoost()
{
  m_boost = true;
}

void	Snake::disableBoost()
{
  m_boost = false;
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

void	Snake::update(int width, int height, const MapObject& mapObject)
{
  int	nbMove;

  if (!m_alive)
    return;
  nbMove = m_timer.getElapsedTime() / SNAKE_UPDATE_PERIOD;
  if (nbMove)
    {
      m_timer.reset();
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
      m_snakeLimbs.pop_back();
      m_snakeLimbs.push_front(Vector2i(m_snakeLimbs.front().x + m_direction.x,
				       m_snakeLimbs.front().y + m_direction.y));
      mapObject.useObject((m_snakeLimbs.front().x + m_direction.x),
			  (m_snakeLimbs.front().y + m_direction.y),
			  *this);
    }

}

void	Snake::draw(const Renderer& renderer) const
{
  std::list<Vector2i>::const_iterator it;

  for (it = m_snakeLimbs.begin(); it != m_snakeLimbs.end(); it++)
    {
      renderer->drawSnake((*it).x, (*it).y);
    }
}
