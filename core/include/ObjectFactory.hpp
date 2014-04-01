//
// ObjectFactory.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Tue Apr  1 21:22:04 2014 guerot_a
// Last update Tue Apr  1 22:48:13 2014 guerot_a
//

#ifndef OBJECT_FACTORY_HPP
#define OBJECT_FACTORY_HPP

#include <string>
#include <vector>
#include <map>

class IObject;

class ObjectFactory
{
public:
  ObjectFactory();
  ~ObjectFactory();

  void	learn(const std::string& name, IObject* object);

  IObject*	create(const std::string& name, int x, int y) const;
  IObject*	randomCreate(int x, int y) const;

private:
  std::map<std::string, IObject*>		m_recipes;
  std::vector<std::string>			m_objectNames;
};

#endif /* OBJECT_FACTORY_HPP */
