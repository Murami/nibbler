//
// Snake.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 14:43:54 2014 guerot_a
// Last update Tue Apr  1 16:36:40 2014 guerot_a
//

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <list>
#include "Renderer.hpp"
#include "Vector2.hpp"
#include "Timer.hpp"

#define SNAKE_UPDATE_PERIOD	(100.f)

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
  void	moveSnake();

private:
  std::list<Vector2i>		m_snakeLimbs;
  Vector2i			m_direction;
  Vector2i			m_size;
  int				m_boostDuration;
  bool				m_boost;
  bool				m_alive;
  Timer				m_timer;
  bool				m_haveTurned;
};

#endif /* SNAKE_HPP */
