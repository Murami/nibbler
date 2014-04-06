//
// MulScore.hpp for MulScore in /home/desabr_q/rendu/cpp_nibbler/core/include
//
// Made by quentin desabre
// Login   <desabr_q@epitech.net>
//
// Started on  Sun Apr  6 02:10:15 2014 quentin desabre
// Last update Sun Apr  6 05:02:53 2014 Desabre Quentin
//

#ifndef MULLIMB_HPP
#define MULLIMB_HPP

#include "IObject.hpp"

class MulLimb : public IObject
{
public:
  MulLimb();
  MulLimb(int x, int y);
  ~MulLimb();


  const std::string&	getType() const;

  void	use(Snake& snake) const;
  bool	obsolete() const;

  void	draw(const Renderer& renderer) const;
  bool	collide(int x, int y) const;

  IObject*	clone(int x, int y) const;

private:
  mutable bool	m_used;
  std::string	m_type;
  int		m_x;
  int		m_y;
};

#endif /* NORMAL_FOOD_HPP */
