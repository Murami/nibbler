//
// Snake.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 14:43:21 2014 guerot_a
// Last update Fri Mar 28 14:35:45 2014 guerot_a
//

#include "Snake.hpp"

namespace Game
{
  Snake::Snake(const Vector2i& position, Direction direction)
    : m_elements(position, true),
      m_direction(direction)
  {
    for (int i = 0; i < 3; i++)
      this->addElm();
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
    Vector2i	vectorDir;

    switch (m_direction)
      {
      case LEFT:
	vectorDir(1, 0);
	break;
      case RIGHT:
	vectorDir(1, 0);
	break;
      case DOWN:
	vectorDir(0, -1);
	break;
      case UP:
	vectorDir(0, 1);
	break;
      }
    m_elements.addElm(vectorDir);
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

  void	Snake::die()
  {
    m_alive = false;
  }

  bool	Snake::isAlive()
  {
    return (m_alive);
  }
};
