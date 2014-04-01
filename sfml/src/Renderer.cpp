//
// Renderer.cpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:22:12 2014
// Last update Tue Apr  1 19:10:40 2014 guerot_a
//

#include <exception>
#include <stdexcept>
#include <iostream>
#include "Renderer.hpp"

namespace API
{

  Renderer::Renderer(int width, int height) :
    m_window(sf::VideoMode(width * TILESIZE, height * TILESIZE), "Test")
  {
    if (width > 200 || height > 200)
      throw std::runtime_error("cannot create a windows with a size higher than 200x200");
    m_tiles["head"].LoadFromFile("./sfml/assets/sprites/head.png");
    m_tiles["core"].LoadFromFile("./sfml/assets/sprites/core.png");
    m_tiles["corner"].LoadFromFile("./sfml/assets/sprites/corner.png");
    m_tiles["tail"].LoadFromFile("./sfml/assets/sprites/tail.png");

    m_window.SetFramerateLimit(0);
    m_window.EnableKeyRepeat(false);
    m_tiles["wall"].Create(TILESIZE, TILESIZE, sf::Color(255, 0, 0));
    m_tiles["ground"].Create(TILESIZE, TILESIZE, sf::Color(200, 200, 200));
    m_tiles["snake"].Create(TILESIZE-2, TILESIZE-2, sf::Color(0, 255, 255));
    m_tiles["food"].Create(TILESIZE, TILESIZE, sf::Color(0, 0, 255));
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
    m_window.Clear(sf::Color(255, 255, 255));
  }

  void	Renderer::update() const
  {
    m_window.Display();
  }

  /*
  ** Game draws
  */

  void	Renderer::drawSnake(int x, int y) const
  {
    this->draw("snake", x, y);
  }

  void	Renderer::drawFood(int x, int y) const
  {
    this->draw("food", x, y);
  }

  void	Renderer::drawWall(int x, int y) const
  {
    this->draw("wall", x, y);
  }

  void	Renderer::drawGround(int x, int y) const
  {
    this->draw("ground", x, y);
  }

  void	Renderer::draw(const std::string& ressource, int x, int y) const
  {
    sf::Sprite	sprite(m_tiles.at(ressource));

    sprite.SetPosition(x * TILESIZE , m_window.GetHeight() - (y + 1) * TILESIZE);
    m_window.Draw(sprite);
  }
};

API::IRenderer*	createRenderer(int width, int height)
{
  return (new API::Renderer(width, height));
}
