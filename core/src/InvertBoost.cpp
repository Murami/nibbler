//
// InvertBoost.cpp for invertBoost in /home/desabr_q/rendu/cpp_nibbler
//
// Made by quentin desabre
// Login   <desabr_q@epitech.net>
//
// Started on  Sun Apr  6 05:11:13 2014 quentin desabre
// Last update Sun Apr  6 05:11:13 2014 Desabre Quentin
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
  renderer->draw("invertBoost", m_x, m_y, 0);
}

bool	InvertBoost::collide(int x, int y) const
{
  return (m_x == x && m_y == y);
}

IObject*	InvertBoost::clone(int x, int y) const
{
  return (new InvertBoost(x, y));
}
