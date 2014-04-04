//
// NormalFood.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Fri Mar 28 14:17:02 2014 guerot_a
// Last update Fri Apr  4 13:24:20 2014 
//

#include <iostream>
#include "NormalFood.hpp"
#include "Snake.hpp"

NormalFood::NormalFood()
{
  m_type = "NormalFood";
}

NormalFood::NormalFood(int x, int y)
  : m_used(false),
    m_x(x),
    m_y(y)
{
  m_type = "NormalFood";
}

NormalFood::~NormalFood()
{
}

const std::string&	NormalFood::getType() const
{
  return (m_type);
}

void	NormalFood::use(Snake& snake) const
{
  snake.addScore(10);
  snake.addElem();
  m_used = true;
}

bool	NormalFood::obsolete() const
{
  return (m_used);
}

void	NormalFood::draw(const Renderer& renderer) const
{
  renderer->draw("apple", m_x, m_y, 0);
}

bool	NormalFood::collide(int x, int y) const
{
  return (m_x == x && m_y == y);
}

IObject*	NormalFood::clone(int x, int y) const
{
  return (new NormalFood(x, y));
}
