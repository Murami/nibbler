//
// MapObject.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Tue Apr  1 22:05:46 2014 guerot_a
// Last update Tue Apr  1 23:25:35 2014 guerot_a
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "NormalFood.hpp"
#include "IObject.hpp"
#include "Renderer.hpp"
#include "MapObject.hpp"
#include "Snake.hpp"

MapObject::MapObject()
{
  srand(time(NULL));

  m_objectFactory.learn("NormalFood", new NormalFood);
  m_objectList.push_back(new NormalFood(10, 10));
}

MapObject::~MapObject()
{
  std::vector<IObject*>::iterator	it;

  for (it = m_objectList.begin(); it < m_objectList.end(); it++)
    delete (*it);
}

void	MapObject::update(int width, int height, const Snake& snake)
{
  std::vector<IObject*>::iterator	it;
  Vector2i				vect;

  for (it = m_objectList.begin(); it < m_objectList.end(); it++)
    {
      if((*it)->obsolete())
	{
	  delete (*it);
	  it = m_objectList.erase(it);
	  it--;
	}
    }

  if (m_objectCreationTimer.getElapsedTime() > OBJECT_CREATION_PERIOD)
    {
      vect(rand() % width, rand() % height);
      while (snake.collideSnake(vect.x, vect.y) &&
	     collideObject(vect.x, vect.y))
	vect(rand() % width, rand() % height);

      addObject(m_objectFactory.randomCreate(vect.x, vect.y));
      m_objectCreationTimer.reset();
    }
}

void	MapObject::draw(const Renderer& renderer) const
{
  std::vector<IObject*>::const_iterator	it;

  for (it = m_objectList.begin(); it < m_objectList.end(); it++)
    (*it)->draw(renderer);
}

bool	MapObject::collideObject(int x, int y)
{
  std::vector<IObject*>::iterator	it;

  for (it = m_objectList.begin(); it < m_objectList.end(); it++)
    if((*it)->collide(x, y))
      return (true);
  return (false);
}

void	MapObject::useObject(int x, int y, const Snake& snake) const
{
 std::vector<IObject*>::const_iterator	it;

  for (it = m_objectList.begin(); it < m_objectList.end(); it++)
    if((*it)->collide(x, y))
      (*it)->use(snake);
}

void	MapObject::addObject(IObject* object)
{
  m_objectList.push_back(object);
}
