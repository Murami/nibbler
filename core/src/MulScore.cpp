//
// MulScore.cpp for doublescore in /home/desabr_q/rendu/cpp_nibbler
//
// Made by quentin desabre
// Login   <desabr_q@epitech.net>
//
// Started on  Sun Apr  6 02:50:49 2014 quentin desabre
// Last update Sun Apr  6 05:08:30 2014 Desabre Quentin
//

#include <iostream>
#include "MulScore.hpp"
#include "Snake.hpp"

MulScore::MulScore()
{
  m_type = "MulScore";
}

MulScore::MulScore(int x, int y)
  : m_used(false),
    m_x(x),
    m_y(y)
{
  m_type = "MulScore";
}

MulScore::~MulScore()
{
}

const std::string&	MulScore::getType() const
{
  return (m_type);
}

void	MulScore::use(Snake& snake) const
{
  snake.addScore(25);
  snake.addElem();
  snake.setMulScore();
  m_used = true;
}

bool	MulScore::obsolete() const
{
  return (m_used);
}

void	MulScore::draw(const Renderer& renderer) const
{
  renderer->draw("mulScore", m_x, m_y, 0);
}

bool	MulScore::collide(int x, int y) const
{
  return (m_x == x && m_y == y);
}

IObject*	MulScore::clone(int x, int y) const
{
  return (new MulScore(x, y));
}
