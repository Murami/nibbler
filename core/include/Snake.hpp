//
// Snake.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 14:43:54 2014 guerot_a
// Last update Tue Apr  1 15:06:36 2014 Desabre Quentin
//

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <list>
#include "Renderer.hpp"
#include "Vector2.hpp"

class Snake
{
public:
  Snake(int, int);
  ~Snake();

  void	enableBoost();
  void	disableBoost();

  void	turnRight();
  void	turnLeft();

  void	update();
  void	draw(const Renderer& renderer) const;

private:
  std::list<Vector2i>		m_snakeLimbs;
  Vector2i			m_direction;
  Vector2i			m_size;
  int				m_boostDuration;
  bool				m_boost;
  bool				m_alive;
};

#endif /* SNAKE_HPP */
