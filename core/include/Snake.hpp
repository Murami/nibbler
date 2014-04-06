//
// Snake.hpp for snake in /home/desabr_q/rendu/cpp_nibbler
//
// Made by quentin desabre
// Login   <desabr_q@epitech.net>
//
// Started on  Sun Apr  6 05:10:19 2014 quentin desabre
// Last update Sun Apr  6 05:29:14 2014 
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

#define SNAKE_MOVE_NORMAL_PERIOD	(100.f)
#define SNAKE_MOVE_BOOST_PERIOD		(40.f)
#define SNAKE_BOOST_DEGEN_PERIOD	(10.f)
#define SNAKE_BOOST_REGEN_PERIOD	(30.f)
#define	SNAKE_BOOST_MAX			(200.f)
#define SNAKE_MOVE_BOOST_INV_PERIOD	(180.f)

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

  void	checkBoost();
  void	checkMove(int width, int height, const MapObject& mapObject);

  void	update(int width, int height, const MapObject& mapObject);
  void	updateCam(Renderer& renderer) const;
  void	draw(const Renderer& renderer) const;

  void	addScore(int score);
  int	getScore() const;
  int	getBoost() const;

  void	setInvul(bool);
  void	setMulScore();
  void	setNbLimb();
  void	setInvertBoost();
  void	die();

private:
  void	moveSnake(int width, int height, const MapObject& mapObject);

private:
  std::list<Vector2i>		m_snakeLimbs;
  std::vector<std::string>	m_skinLimbs;
  Vector2i			m_direction;
  Timer				m_boostTimer;
  Timer				m_moveTimer;
  int				m_firstRun;
  int				m_movePeriod;
  int				m_boost;
  int				m_score;
  int				m_nbLimb;
  int				m_mulScore;
  bool				m_alive;
  int				m_isFed;
  mutable bool		       	m_isInvul;
  int				m_boostPeriod;
};

#endif /* SNAKE_HPP */
