//
// Snake.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 14:43:21 2014 guerot_a
// Last update Tue Apr  1 16:47:42 2014 guerot_a
//

#include <iostream>
#include "Snake.hpp"

Snake::Snake(int width, int height) :
  m_direction(1, 0),
  m_alive(true),
  m_haveTurned(false)
{
  m_size(width, height);
  m_snakeLimbs.push_back(Vector2i(0, 0));
  m_snakeLimbs.push_back(Vector2i(1, 0));
  m_snakeLimbs.push_back(Vector2i(2, 0));
  m_snakeLimbs.push_back(Vector2i(3, 0));
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
  if (!m_alive || m_haveTurned)
    return;
  m_direction(m_direction.y, -m_direction.x);
  m_haveTurned = true;
  moveSnake();
}

void	Snake::turnLeft()
{
  if (!m_alive)
    return;
  if (m_haveTurned)
    return;
  m_direction(-m_direction.y, m_direction.x);
  m_haveTurned = true;
  moveSnake();
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
      m_haveTurned = false;
    }
  while (nbMove)
    {
      moveSnake();
      nbMove--;
    }
}

void	Snake::moveSnake()
{
  if (m_snakeLimbs.front().x + m_direction.x < 0 ||
      m_snakeLimbs.front().x + m_direction.x >= m_size.x ||
      m_snakeLimbs.front().y + m_direction.y < 0 ||
      m_snakeLimbs.front().y + m_direction.x >= m_size.y - 1)
    {
      m_alive = false;
      std::cout << "die" << std::endl;
    }
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
