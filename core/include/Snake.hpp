//
// Snake.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 14:43:54 2014 guerot_a
// Last update Wed Apr  2 02:54:11 2014 pinon
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

#define SNAKE_UPDATE_PERIOD	(10.f)

class Snake
{
public:
  Snake();
  ~Snake();

  void	enableBoost();
  void	disableBoost();

  void	turnRight();
  void	turnLeft();

  void	addElem();
  void	addSkin();
  bool	collideMap(int width, int height) const;
  bool	collideSnake(int x, int y) const;

  void	update(int width, int height, const MapObject& mapObject);
  void	draw(const Renderer& renderer) const;

private:
  void	moveSnake(int width, int height, const MapObject& mapObject);

private:
  std::list<Vector2i>		m_snakeLimbs;
  std::vector<std::string>	m_skinLimbs;
  Vector2i			m_direction;
  Vector2i			m_size;
  int				m_boostDuration;
  bool				m_boost;
  bool				m_alive;
  bool				m_isFed;
  Timer				m_timer;
};

#endif /* SNAKE_HPP */
