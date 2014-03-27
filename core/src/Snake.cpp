//
// Snake.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 14:43:21 2014 guerot_a
// Last update Thu Mar 27 19:31:57 2014 guerot_a
//

#include "Snake.hpp"

Snake::Snake()
{
}

Snake::~Snake()
{
}

void	Snake::move(const Vector2i& movement)
{
  m_elements.move(movement);
}

void	Snake::delElm()
{
  if (m_elements.size() > 4)
    m_elements.delElm();
}

void	Snake::addElm()
{
  m_elements.addElm();
}

void	Snake::draw(IRenderer* renderer) const
{
  m_elements.draw(renderer);
}

void	Snake::boost(bool state)
{
  m_boost = state;
}

bool	Snake::boost() const
{
  return (m_boost);
}
