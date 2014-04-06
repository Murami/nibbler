//
// Wall.cpp for  in /home/otoshigami/rendu/cpp_nibbler
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Sun Apr  6 05:14:47 2014
// Last update Sun Apr  6 05:35:10 2014 
//

#include <iostream>
#include "Wall.hpp"
#include "Snake.hpp"

Wall::Wall()
{
  m_type = "Wall";
}

Wall::Wall(int x, int y)
  : m_used(false),
    m_x(x),
    m_y(y)
{
  m_type = "Wall";
}

Wall::~Wall()
{
}

const std::string&	Wall::getType() const
{
  return (m_type);
}

void	Wall::use(Snake& snake) const
{
  snake.die();
}

bool	Wall::obsolete() const
{
  return (m_used);
}

void	Wall::draw(const Renderer& renderer) const
{
  renderer->draw("wall", m_x, m_y, 0);
}

bool	Wall::collide(int x, int y) const
{
  return (m_x == x && m_y == y);
}

IObject*	Wall::clone(int x, int y) const
{
  return (new Wall(x, y));
}
