//
// Invul.cpp for Invul in /home/desabr_q/rendu/cpp_nibbler/core/src
//
// Made by quentin desabre
// Login   <desabr_q@epitech.net>
//
// Started on  Sun Apr  6 02:07:57 2014 quentin desabre
// Last update Sun Apr  6 02:52:30 2014 Desabre Quentin
//

#include <iostream>
#include "Invul.hpp"
#include "Snake.hpp"

Invul::Invul()
{
  m_type = "Invul";
}

Invul::Invul(int x, int y)
  : m_used(false),
    m_x(x),
    m_y(y)
{
  m_type = "Invul";
}

Invul::~Invul()
{
}

const std::string&	Invul::getType() const
{
  return (m_type);
}

void	Invul::use(Snake& snake) const
{
  snake.addScore(25);
  snake.addElem();
  snake.setInvul(true);
  m_used = true;
}

bool	Invul::obsolete() const
{
  return (m_used);
}

void	Invul::draw(const Renderer& renderer) const
{
  renderer->draw("head", m_x, m_y, 0);
}

bool	Invul::collide(int x, int y) const
{
  return (m_x == x && m_y == y);
}

IObject*	Invul::clone(int x, int y) const
{
  return (new Invul(x, y));
}
