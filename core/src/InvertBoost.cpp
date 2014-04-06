//
// InvertBoost.cpp for  in /home/otoshigami/rendu/cpp_nibbler
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Sun Apr  6 04:43:02 2014
// Last update Sun Apr  6 05:01:31 2014 
//

#include <iostream>
#include "InvertBoost.hpp"
#include "Snake.hpp"

InvertBoost::InvertBoost()
{
  m_type = "InvertBoost";
}

InvertBoost::InvertBoost(int x, int y)
  : m_used(false),
    m_x(x),
    m_y(y)
{
  m_type = "InvertBoost";
}

InvertBoost::~InvertBoost()
{
}

const std::string&	InvertBoost::getType() const
{
  return (m_type);
}

void	InvertBoost::use(Snake& snake) const
{
  snake.addScore(25);
  snake.setInvertBoost();
  m_used = true;
}

bool	InvertBoost::obsolete() const
{
  return (m_used);
}

void	InvertBoost::draw(const Renderer& renderer) const
{
  renderer->draw("head", m_x, m_y, 0);
}

bool	InvertBoost::collide(int x, int y) const
{
  return (m_x == x && m_y == y);
}

IObject*	InvertBoost::clone(int x, int y) const
{
  return (new InvertBoost(x, y));
}
