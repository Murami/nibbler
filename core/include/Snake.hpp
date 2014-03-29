//
// Snake.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 14:43:54 2014 guerot_a
// Last update Fri Mar 28 19:18:31 2014 guerot_a
//

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "SnakeElm.hpp"
#include "Vector2.hpp"

class Snake
{
public:
  Snake(const Vector2i& position, Direction direction);
  ~Snake();

  void	move(const Vector2i& movement);
  void	moveTo(const Vector2i& move);
  void	setDirection(Direction direction);
  void	delElm();
  void	addElm();
  void	draw(IRenderer* renderer) const;
  void	boost(bool state);
  bool	boost() const;

  void	die();
  bool	isAlive() const;

private:
  SnakeElm	m_elements;
  Direction	m_direction;
  bool	m_boost;
  bool	m_alive;
};

#endif /* SNAKE_HPP */
