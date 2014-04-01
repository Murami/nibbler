//
// ObjectFactory.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Tue Apr  1 21:33:04 2014 guerot_a
// Last update Tue Apr  1 22:55:10 2014 guerot_a
//

#include <cstdlib>
#include "ObjectFactory.hpp"
#include "IObject.hpp"

ObjectFactory::ObjectFactory()
{
}

ObjectFactory::~ObjectFactory()
{
}

void	ObjectFactory::learn(const std::string& name, IObject* object)
{
  m_recipes[name] = object;
  m_objectNames.push_back(name);
}

IObject*	ObjectFactory::create(const std::string& name, int x, int y) const
{
  return (m_recipes.at(name)->clone(x, y));
}

IObject*	ObjectFactory::randomCreate(int x, int y) const
{
  return (m_recipes.at(m_objectNames.at(rand() % m_objectNames.size()))->clone(x, y));
}
