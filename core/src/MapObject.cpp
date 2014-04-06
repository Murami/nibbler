//
// MapObject.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Tue Apr  1 22:05:46 2014 guerot_a
// Last update Sun Apr  6 05:30:01 2014 
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "NormalFood.hpp"
#include "Invul.hpp"
#include "MulScore.hpp"
#include "MulLimb.hpp"
#include "InvertBoost.hpp"
#include "Wall.hpp"
#include "IObject.hpp"
#include "Renderer.hpp"
#include "MapObject.hpp"
#include "Snake.hpp"

MapObject::MapObject()
{
  srand(time(NULL));

  m_objectFactory.learn("NormalFood", new NormalFood);
  m_objectFactory.learn("Invul", new Invul);
  m_objectFactory.learn("MulScore", new MulScore);
  m_objectFactory.learn("MulLimb", new MulLimb);
  m_objectFactory.learn("InvertBoost", new InvertBoost);
  m_objectFactory.learn("Wall", new Wall);
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
      this->addObjectRandom(width, height, snake);
      m_objectCreationTimer.reset();
    }

  bool	haveFood = false;
  for (it = m_objectList.begin(); it < m_objectList.end(); it++)
    {
      if ((*it)->getType() == "NormalFood")
	{
	  haveFood = true;
	}
    }
  if (!haveFood)
    this->addObjectRandom("NormalFood", width, height, snake);
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

void	MapObject::useObject(int x, int y, Snake& snake) const
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

void	MapObject::addObjectRandom(const std::string& objectType, int width, int height, const Snake& snake)
{
  Vector2i	vect;

  vect(rand() % width, rand() % height);
  while (snake.collideSnake(vect.x, vect.y, 1) || collideObject(vect.x, vect.y))
    vect(rand() % width, rand() % height);
  addObject(m_objectFactory.create(objectType, vect.x, vect.y));
}

void	MapObject::addObjectRandom(int width, int height, const Snake& snake)
{
  Vector2i	vect;

  vect(rand() % width, rand() % height);
  while (snake.collideSnake(vect.x, vect.y, 1) || collideObject(vect.x, vect.y))
    vect(rand() % width, rand() % height);
  addObject(m_objectFactory.randomCreate(vect.x, vect.y));
}
