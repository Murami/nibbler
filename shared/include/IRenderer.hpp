//
// IRenderer.hpp for IRenderer in /home/guerot_a/rendu/cpp_nibbler/shared/include
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 21:51:22 2014 guerot_a
// Last update Fri Apr  4 16:19:47 2014 
//

#ifndef IRENDERER_HPP
#define IRENDERER_HPP

#include <string>

/*
** Event API
*/

namespace API
{
  namespace Key
  {
    enum	Code
      {
	None,
	Left,
	Right,
	Up,
	Down,
	Space,
	Escape,
	Return
      };
  };

  class Event
  {
  public:

    enum	EventType
      {
	None,
	KeyPressed,
	KeyReleased,
	Closed
      };

    EventType	type;
    Key::Code	key;
  };

  /*
  ** IRenderer
  */

  class	IRenderer
  {
  public:
    virtual ~IRenderer() {};

    virtual bool	getEvent(Event& event) const = 0;
    virtual void	close() = 0;
    virtual bool	isOpen() const = 0;
    virtual void	clear() const = 0;
    virtual void	update() const = 0;
    virtual void	updateCam(int x, int y, int xdir, int ydir) = 0;

    virtual void	drawScore(int score) const = 0;
    virtual void	drawBoost(int boost, int boostmax) const = 0;
    virtual void        draw(const std::string& ressource, int x, int y,
			     int rotation) const = 0;
    virtual void	drawBackground(int width, int height) const = 0;
  };
};

#endif /* IRENDERER_HPP */
