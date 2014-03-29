//
// ObjectFactory.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Fri Mar 28 14:37:21 2014 guerot_a
// Last update Fri Mar 28 19:17:48 2014 guerot_a
//

#ifndef OBJECT_FACTORY_HPP
#define OBJECT_FACTORY_HPP


class ObjectFactory
{
public:
  ObjectFactory();
  ~ObjectFactory();

  static void	learn();
  IObject	create();

private:
  static std::map<std::string, IObject*>	m_recipes;
};


#endif /* OBJECT_FACTORY_HPP */
