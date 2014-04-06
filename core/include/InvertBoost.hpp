//
// InvertBoost.hpp for  in /home/otoshigami/rendu/cpp_nibbler
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Sun Apr  6 04:38:55 2014
// Last update Sun Apr  6 04:51:04 2014 
//

#ifndef INVERT_BOOST_HPP
#define INVERT_BOOST_HPP

#include "IObject.hpp"

class InvertBoost : public IObject
{
public:
  InvertBoost();
  InvertBoost(int, int);
  ~InvertBoost();

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

#endif /* INVERT_BOOST_HPP */
