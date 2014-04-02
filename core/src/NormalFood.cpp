//
// NormalFood.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Fri Mar 28 14:17:02 2014 guerot_a
// Last update Wed Apr  2 09:09:58 2014 guerot_a
//

#include <iostream>
#include "NormalFood.hpp"
#include "Snake.hpp"

NormalFood::NormalFood()
{
}

NormalFood::NormalFood(int x, int y)
  : m_used(false),
    m_x(x),
    m_y(y)
{
}

NormalFood::~NormalFood()
{
}

const std::string&	getType() const
{
  return ("NormalFood");
}

void	NormalFood::use(const Snake& snake) const
{
  // snake.addElm();
  m_used = true;
}

bool	NormalFood::obsolete() const
{
  return (m_used);
}

void	NormalFood::draw(const Renderer& renderer) const
{
  renderer->drawWall(m_x, m_y);
}

bool	NormalFood::collide(int x, int y) const
{
  return (m_x == x && m_y == y);
}

IObject*	NormalFood::clone(int x, int y) const
{
  return (new NormalFood(x, y));
}
