//
// MapObject.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Tue Apr  1 22:02:07 2014 guerot_a
// Last update Tue Apr  1 23:23:50 2014 guerot_a
//

#ifndef MAP_OBJECT_HPP
#define MAP_OBJECT_HPP

#include "Timer.hpp"
#include "ObjectFactory.hpp"

#define OBJECT_CREATION_PERIOD	(1000.f)

class Renderer;
class Snake;

class MapObject
{
public:
  MapObject();
  ~MapObject();

  void	update(int width, int height, const Snake& snake);
  void	draw(const Renderer& renderer) const;

  bool	collideObject(int x, int y);
  void	useObject(int x, int y, const Snake& snake) const;

  void	addObject(IObject* object);

private:
  std::vector<IObject*>	m_objectList;
  ObjectFactory		m_objectFactory;
  Timer			m_objectCreationTimer;
};

#endif /* MAP_OBJECT_HPP */
