//
// Snake.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 14:43:54 2014 guerot_a
// Last update Sat Apr  5 16:36:09 2014 Desabre Quentin
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

#define SNAKE_MOVE_NORMAL_PERIOD	(60.f)
#define SNAKE_MOVE_BOOST_PERIOD		(20.f)
#define SNAKE_BOOST_DEGEN_PERIOD	(10.f)
#define SNAKE_BOOST_REGEN_PERIOD	(30.f)
#define	SNAKE_BOOST_MAX			(200.f)

class Snake
{
public:
  Snake();
  ~Snake();

  void	enableBoost();
  void	disableBoost();
  bool	boostEnabled();

  void	turnRight();
  void	turnLeft();

  void	addElem();
  void	addSkin();
  bool	collideMap(int width, int height) const;
  bool	collideSnake(int x, int y, int flag) const;

  void	update(int width, int height, const MapObject& mapObject);
  void	updateCam(Renderer& renderer) const;
  void	draw(const Renderer& renderer) const;

  void	addScore(int score);
  int	getScore() const;
  int	getBoost() const;

private:
  void	moveSnake(int width, int height, const MapObject& mapObject);

private:
  std::list<Vector2i>		m_snakeLimbs;
  std::vector<std::string>	m_skinLimbs;
  Vector2i			m_direction;
  Vector2i			m_size;
  bool				m_alive;
  bool				m_isFed;
  int				m_firstRun;
  Timer				m_moveTimer;
  int				m_movePeriod;
  Timer				m_boostTimer;
  int				m_boost;
  int				m_score;
};

#endif /* SNAKE_HPP */
