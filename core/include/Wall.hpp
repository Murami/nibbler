//
// Wall.hpp for  in /home/otoshigami/rendu/cpp_nibbler
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Sun Apr  6 05:13:39 2014
// Last update Sun Apr  6 05:14:44 2014 
//

#ifndef WALL_HPP
#define WALL_HPP

#include "IObject.hpp"

class Wall : public IObject
{
public:
  Wall();
  Wall(int x, int y);
  ~Wall();


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


#endif /* WALL_HPP */
