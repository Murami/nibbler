//
// Snake.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 14:43:21 2014 guerot_a
// Last update Sun Mar 30 22:57:08 2014 guerot_a
//

#include "Snake.hpp"

Snake::Snake() :
  m_direction(1, 0)
{
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
  m_direction(m_direction.y, -m_direction.x);
}

void	Snake::turnLeft()
{
  m_direction(-m_direction.y, m_direction.x);
}

void	Snake::update()
{
}

void	Snake::draw(const Renderer& renderer) const
{
  (void) renderer;
}
