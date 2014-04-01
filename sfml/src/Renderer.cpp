//
// Renderer.cpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:22:12 2014
// Last update Tue Apr  1 22:11:30 2014 pinon
//

#include <exception>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include "Renderer.hpp"

namespace API
{

  Renderer::Renderer(int width, int height) :
    m_window(sf::VideoMode(width * TILESIZE, height * TILESIZE), "Test")
  {
    int			i;
    std::stringstream	ss;
    std::string		str;

    if (width > 200 || height > 200)
      throw std::runtime_error("cannot create a windows with a size higher than 200x200");
    m_window.SetFramerateLimit(0);
    m_window.EnableKeyRepeat(false);
    i = 1;
    while (i <= 48)
      {
	ss << i;
	str = ss.str();
	m_tiles["body"].LoadFromFile("./sfml/assets/sprites/ghost_" + str + ".bmp");
	i++;
      }
    m_tiles["head"].LoadFromFile("./sfml/assets/sprites/head_1.bmp");
    m_tiles["apple"].LoadFromFile("./sfml/assets/sprites/apple.png");
  }

  Renderer::~Renderer()
  {
  }

  void	Renderer::close()
  {
    m_window.Close();
  }

  bool	Renderer::isOpen() const
  {
    return (m_window.IsOpened());
  }

  bool	Renderer::getEvent(Event& eventRcv) const
  {
    sf::Event	event;

    if (!m_window.GetEvent(event))
      {
	eventRcv.type = Event::None;
	eventRcv.key = Key::None;
	return (false);
      }
    switch (event.Type)
      {
      case sf::Event::Closed:
	eventRcv.type = Event::Closed;
	break;

      case sf::Event::KeyPressed:
      case sf::Event::KeyReleased:
	{
	  if (event.Type == sf::Event::KeyPressed)
	    eventRcv.type = Event::KeyPressed;
	  else
	    eventRcv.type = Event::KeyReleased;

	  switch (event.Key.Code)
	    {
	    case sf::Key::Left:
	      eventRcv.key = Key::Left;
	      break;

	    case sf::Key::Right:
	      eventRcv.key = Key::Right;
	      break;

	    case sf::Key::Up:
	      eventRcv.key = Key::Up;
	      break;

	    case sf::Key::Down:
	      eventRcv.key = Key::Down;
	      break;

	    case sf::Key::Space:
	      eventRcv.key = Key::Space;
	      break;

	    case sf::Key::Escape:
	      eventRcv.key = Key::Escape;
	      break;

	    case sf::Key::Return:
	      eventRcv.key = Key::Return;
	      break;

	    default:
	      break;
	    }

	default:
	  break;
	}
	break;
      }
    return (true);
  }

  void	Renderer::clear() const
  {
    m_window.Clear(sf::Color(254, 239, 220));
  }

  void	Renderer::update() const
  {
    m_window.Display();
  }

  /*
  ** Game draws
  */

  void	Renderer::draw(const std::string& ressource, int x, int y,
		       Orientation ori) const
  {
    sf::Sprite	sprite(m_tiles.at(ressource));

    sprite.SetPosition(x * TILESIZE , m_window.GetHeight() - (y + 1) * TILESIZE);
    if (ori)
      sprite.SetRotation(ori * 90);
    m_window.Draw(sprite);
  }
};

API::IRenderer*	createRenderer(int width, int height)
{
  return (new API::Renderer(width, height));
}
