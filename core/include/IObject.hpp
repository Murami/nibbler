//
// IObject.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Fri Mar 28 14:02:54 2014 guerot_a
// Last update Fri Mar 28 19:17:10 2014 guerot_a
//

#ifndef IOBJECT_HPP
#define IOBJECT_HPP

class Snake;

class IObject
{
public:
  virtual void use(const Snake& snake) = 0;
  virtual bool obosolete() const = 0;

  virtual IObject*	clone() const;
};

#endif /* IOBJECT_HPP */
