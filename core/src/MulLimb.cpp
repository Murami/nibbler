//
// MulLimb.cpp for doublescore in /home/desabr_q/rendu/cpp_nibbler
//
// Made by quentin desabre
// Login   <desabr_q@epitech.net>
//
// Started on  Sun Apr  6 02:50:49 2014 quentin desabre
// Last update Sun Apr  6 05:23:50 2014 Desabre Quentin
//

#include <iostream>
#include "MulLimb.hpp"
#include "Snake.hpp"

MulLimb::MulLimb()
{
  m_type = "MulLimb";
}

MulLimb::MulLimb(int x, int y)
  : m_used(false),
    m_x(x),
    m_y(y)
{
  m_type = "MulLimb";
}

MulLimb::~MulLimb()
{
}

const std::string&	MulLimb::getType() const
{
  return (m_type);
}

void	MulLimb::use(Snake& snake) const
{
  snake.addScore(250);
  snake.setNbLimb();
  m_used = true;
}

bool	MulLimb::obsolete() const
{
  return (m_used);
}

void	MulLimb::draw(const Renderer& renderer) const
{
  renderer->draw("mulLimb", m_x, m_y, 0);
}

bool	MulLimb::collide(int x, int y) const
{
  return (m_x == x && m_y == y);
}

IObject*	MulLimb::clone(int x, int y) const
{
  return (new MulLimb(x, y));
}
