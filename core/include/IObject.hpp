//
// IObject.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Fri Mar 28 14:02:54 2014 guerot_a
// Last update Tue Apr  1 15:03:34 2014 guerot_a
//

#ifndef IOBJECT_HPP
#define IOBJECT_HPP

#include "Snake.hpp"
#include "Renderer.hpp"

class IObject
{
public:
  virtual void use(const Snake& snake) = 0;
  virtual bool obosolete() const = 0;

  virtual IObject*	clone() const;

  virtual void		draw(const Renderer& renderer) const;
};

#endif /* IOBJECT_HPP */
