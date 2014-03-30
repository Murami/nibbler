//
// Snake.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 14:43:54 2014 guerot_a
// Last update Sun Mar 30 22:43:16 2014 guerot_a
//

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include "Renderer.hpp"
#include "Vector2.hpp"

class Snake
{
public:
  Snake();
  ~Snake();

  void	enableBoost();
  void	disableBoost();

  void	turnRight();
  void	turnLeft();

  void	update();
  void	draw(const Renderer& renderer) const;

private:
  std::vector<Vector2i>		m_snakeLimbs;
  Vector2i			m_direction;
  int				m_boostDuration;
  bool				m_boost;
  bool				m_alive;
};

#endif /* SNAKE_HPP */
