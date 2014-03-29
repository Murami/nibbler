//
// IRenderer.hpp for IRenderer in /home/guerot_a/rendu/cpp_nibbler/shared/include
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 21:51:22 2014 guerot_a
// Last update Sat Mar 29 21:53:20 2014 guerot_a
//

#ifndef IRENDERER_HPP
#define IRENDERER_HPP

typedef enum Event
  {
    NONE,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    SPACE,
    RETURN,
    ESCAPE,
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
  virtual void	drawSnake(int x, int y) const = 0;
  virtual void	drawFood(int x, int y) const = 0;
  virtual void	drawWall(int x, int y) const = 0;
};

#endif /* IRENDERER_HPP */
