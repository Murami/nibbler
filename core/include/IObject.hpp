//
// IObject.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Fri Mar 28 14:02:54 2014 guerot_a
// Last update Tue Apr  1 22:42:24 2014 guerot_a
//

#ifndef IOBJECT_HPP
#define IOBJECT_HPP

#include "Snake.hpp"
#include "Renderer.hpp"

class IObject
{
public:
  virtual ~IObject() {}

  virtual void use(const Snake& snake) const = 0;
  virtual bool obsolete() const = 0;

  virtual IObject*	clone(int x, int y) const = 0;

  virtual void		draw(const Renderer& renderer) const = 0;
  virtual bool		collide(int x, int y) const = 0;
};

#endif /* IOBJECT_HPP */
