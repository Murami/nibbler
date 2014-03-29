//
// SnakeElm.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 17:24:44 2014 guerot_a
// Last update Fri Mar 28 13:41:55 2014 guerot_a
//

#include <cstdlib>
#include "SnakeElm.hpp"

namespace Game
{
  SnakeElm::SnakeElm(const Vector2i& pos, bool isHead) :
    m_position(pos),
    m_elements(NULL),
    m_isHead(isHead)
  {
  }

  SnakeElm::SnakeElm(const SnakeElm& snakeElm)
  {
    *this = snakeElm;
  }

  SnakeElm::~SnakeElm()
  {
    if (m_elements)
      delete m_elements;
  }

  SnakeElm&	SnakeElm::operator=(const SnakeElm& snakeElm)
  {
    m_position = snakeElm.m_position;
    m_elements = snakeElm.m_elements;
    m_isHead = snakeElm.m_isHead;

    return (*this);
  }

  void	SnakeElm::move(const Vector2i& movement)
  {
    if (m_elements)
      m_elements->moveTo(m_position);
    m_position += movement;
  }

  void	SnakeElm::moveTo(const Vector2i& position)
  {
    if (m_elements)
      m_elements->moveTo(m_position);
    m_position = position;
  }

  bool	SnakeElm::isTail()
  {
    return (m_elements == NULL);
  }

  bool	SnakeElm::isHead()
  {
    return (m_isHead);
  }

  void	SnakeElm::addElm(const Vector2i& parentPos)
  {
    if (!m_elements)
      {
	if (!m_isHead)
	  m_elements = new SnakeElm((m_position * 2) - parentPos, false);
	else
	  m_elements = new SnakeElm(parentPos, false);
      }
    else
      m_elements->addElm(m_position);
  }

  void	SnakeElm::delElm()
  {
    if (m_elements->isTail())
      delete m_elements;
    else
      m_elements->delElm();
  }

  void	SnakeElm::draw(IRenderer* renderer) const
  {
    if (m_elements)
      m_elements->draw(renderer);
    renderer->drawSnakeBody(m_position.x, m_position.y);
  }

  int	SnakeElm::size() const
  {
    if (!m_elements)
      return (1);
    return (m_elements->size() + 1);
  }
}
