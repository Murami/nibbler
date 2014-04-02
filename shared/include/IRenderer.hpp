//
// IRenderer.hpp for IRenderer in /home/guerot_a/rendu/cpp_nibbler/shared/include
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 21:51:22 2014 guerot_a
// Last update Wed Apr  2 02:01:14 2014 pinon
//

#ifndef IRENDERER_HPP
#define IRENDERER_HPP

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

    //game draws

    virtual void        draw(const std::string& ressource, int x, int y,
			     int rotation) const = 0;
  };
};

#endif /* IRENDERER_HPP */
