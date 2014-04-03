//
// Renderer.cpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:22:12 2014
// Last update Thu Apr  3 14:08:23 2014 guerot_a
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
    std::string		str;

    if (width > 200 || height > 200)
      throw std::runtime_error("cannot create a windows with a size higher than 200x200");
    m_window.SetFramerateLimit(0);
    m_window.EnableKeyRepeat(false);
    i = 1;
    while (i <= 48)
      {
	std::stringstream   ss;
	ss << i;
	str = ss.str();
	m_tiles[str].LoadFromFile("./sfml/assets/sprites/ghost_" + str + ".bmp");
	m_tiles[str].SetSmooth(true);
	i++;
      }
    m_tiles["head"].LoadFromFile("./sfml/assets/sprites/head_1.bmp");
    m_tiles["apple"].LoadFromFile("./sfml/assets/sprites/apple.png");

    eventBinds[sf::Event::Closed] = Event::Closed;
    eventBinds[sf::Event::KeyPressed] = Event::KeyPressed;
    eventBinds[sf::Event::KeyReleased] = Event::KeyReleased;

    eventKeyBinds[sf::Key::Left] = Key::Left;
    eventKeyBinds[sf::Key::Right] = Key::Right;
    eventKeyBinds[sf::Key::Space] = Key::Space;
    eventKeyBinds[sf::Key::Escape] = Key::Escape;
    eventKeyBinds[sf::Key::Return] = Key::Return;
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
    std::map<sf::Event::EventType, Event::EventType>::const_iterator	itType;
    std::map<sf::Key::Code, Key::Code>::const_iterator			itKey;
    sf::Event	event;

    if (!m_window.GetEvent(event))
      return (false);
    eventRcv.type = Event::None;
    eventRcv.key = Key::None;
    for (itType = eventBinds.begin(); itType != eventBinds.end(); itType++)
      {
	if ((*itType).first == event.Type)
	  eventRcv.type = (*itType).second;
      }

    if (event.Type == sf::Event::KeyPressed ||
	event.Type == sf::Event::KeyReleased)
      {
	for (itKey = eventKeyBinds.begin(); itKey != eventKeyBinds.end(); itKey++)
	  {
	    if ((*itKey).first == event.Key.Code)
	      eventRcv.key = (*itKey).second;
	  }
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
		       int rotation) const
  {
    sf::Sprite	sprite(m_tiles.at(ressource));

    sprite.SetSubRect(sf::Rect<int>(1, 1, TILESIZE, TILESIZE));
    sprite.SetCenter(TILESIZE / 2, TILESIZE / 2);
    sprite.SetRotation(rotation);
    sprite.SetPosition(x * TILESIZE + TILESIZE / 2,
		       m_window.GetHeight() - (y + 1) * TILESIZE + TILESIZE / 2);
    m_window.Draw(sprite);
  }
};

API::IRenderer*	createRenderer(int width, int height)
{
  return (new API::Renderer(width, height));
}
