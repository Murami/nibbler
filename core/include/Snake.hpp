//
// Snake.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 14:43:54 2014 guerot_a
// Last update Thu Mar 27 19:31:12 2014 guerot_a
//

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "SnakeElm.hpp"
#include "Vector2.hpp"

class Snake
{
public:
  Snake();
  ~Snake();

  void	move(const Vector2i& movement);
  void	delElm();
  void	addElm();
  void	draw(IRenderer* renderer) const;
  void	boost(bool state);
  bool	boost() const;

private:
  SnakeElm	m_elements;
  bool		m_boost;
};

#endif /* SNAKE_HPP */
