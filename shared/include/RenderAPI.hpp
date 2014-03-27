//
// RenderAPI.hpp for  in /home/otoshigami/rendu/cpp_nibbler/shared/include
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:15:40 2014
// Last update Thu Mar 27 13:38:55 2014 guerot_a
//

#ifndef RENDERAPI_HPP
#define RENDERAPI_HPP

typedef enum Event
  {
    NONE,
    LEFT,
    RIGHT,
    SPACE,
    CLOSE
  } Event;

class	IRenderer
{
public:
  virtual ~IRenderer() {};

  virtual Event	getEvent() const = 0;
  virtual void	close() = 0;
  virtual bool	isOpen() const = 0;
  virtual void	clear() const = 0;
  virtual void	update() const = 0;
  virtual void	drawGround(int x, int y) const = 0;
  virtual void	drawSnakeHead(int x, int y) const = 0;
  virtual void	drawSnakeBody(int x, int y) const = 0;
  virtual void	drawFood(int x, int y) const = 0;
  virtual void	drawWall(int x, int y) const = 0;
};

#endif /* RENDERAPI_HPP */
