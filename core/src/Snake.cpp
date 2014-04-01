//
// Snake.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 14:43:21 2014 guerot_a
// Last update Tue Apr  1 20:10:15 2014 Desabre Quentin
//

#include <iostream>
#include "Snake.hpp"

Snake::Snake(int width, int height) :
  m_direction(1, 0),
  m_alive(true),
  m_haveTurned(false)
{
  m_size(width, height);
  m_snakeLimbs.push_back(Vector2i(6, 0));
  m_snakeLimbs.push_back(Vector2i(5, 0));
  m_snakeLimbs.push_back(Vector2i(4, 0));
  m_snakeLimbs.push_back(Vector2i(3, 0));
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

void	Snake::update()
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
      moveSnake();
      nbMove--;
    }
}

bool	Snake::collideMap()
{
  if (m_snakeLimbs.front().x + m_direction.x < 0 ||
      m_snakeLimbs.front().x + m_direction.x >= m_size.x ||
      m_snakeLimbs.front().y + m_direction.y < 0 ||
      m_snakeLimbs.front().y + m_direction.y >= m_size.y)
    return true;
  return false;
}

bool	Snake::collideSnake()
{
  std::list<Vector2i>::const_iterator it;

  it = m_snakeLimbs.begin();
  it++;
  while (it != m_snakeLimbs.end())
    {
      if (((*it).x == (m_snakeLimbs.front().x + m_direction.x)) &&
	  ((*it).y == (m_snakeLimbs.front().y + m_direction.y)))
	return true;
      it++;
    }
  return false;

}

bool	Snake::collideObject()
{

}

void	Snake::moveSnake()
{
  if (collideMap() || collideSnake())
    m_alive = false;
  else
    {
      m_snakeLimbs.pop_back();
      m_snakeLimbs.push_front(Vector2i(m_snakeLimbs.front().x + m_direction.x,
				       m_snakeLimbs.front().y + m_direction.y));
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
