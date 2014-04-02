//
// NormalFood.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Fri Mar 28 14:06:52 2014 guerot_a
// Last update Wed Apr  2 00:19:59 2014 pinon
//

#ifndef NORMAL_FOOD_HPP
#define NORMAL_FOOD_HPP

#include "IObject.hpp"

class NormalFood : public IObject
{
public:
  NormalFood();
  NormalFood(int x, int y);
  ~NormalFood();

  void	use(Snake& snake) const;
  bool	obsolete() const;

  void	draw(const Renderer& renderer) const;
  bool	collide(int x, int y) const;

  IObject*	clone(int x, int y) const;

private:
  mutable bool	m_used;
  int		m_x;
  int		m_y;
};

#endif /* NORMAL_FOOD_HPP */
