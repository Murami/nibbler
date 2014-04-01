//
// Snake.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 14:43:54 2014 guerot_a
// Last update Tue Apr  1 23:08:48 2014 guerot_a
//

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <list>
#include <vector>
#include "Renderer.hpp"
#include "Vector2.hpp"
#include "Timer.hpp"

class MapObject;
class IObject;

#define SNAKE_UPDATE_PERIOD	(16.f)

class Snake
{
public:
  Snake();
  ~Snake();

  void	enableBoost();
  void	disableBoost();

  void	turnRight();
  void	turnLeft();

  bool	collideMap(int width, int height) const;
  bool	collideSnake(int x, int y) const;

  void	update(int width, int height, const MapObject& mapObject);
  void	draw(const Renderer& renderer) const;

private:
  void	moveSnake(int width, int height, const MapObject& mapObject);

private:
  std::list<Vector2i>		m_snakeLimbs;
  Vector2i			m_direction;
  Vector2i			m_size;
  int				m_boostDuration;
  bool				m_boost;
  bool				m_alive;
  Timer				m_timer;
};

#endif /* SNAKE_HPP */
