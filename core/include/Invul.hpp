//
// Invul.hpp for Invul in /home/desabr_q/rendu/cpp_nibbler/core/include
//
// Made by quentin desabre
// Login   <desabr_q@epitech.net>
//
// Started on  Sun Apr  6 02:10:15 2014 quentin desabre
// Last update Sun Apr  6 05:24:44 2014 
//

#ifndef INVUL_HPP
#define INVUL_HPP

#include "IObject.hpp"

class Invul : public IObject
{
public:
  Invul();
  Invul(int x, int y);
  ~Invul();


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
