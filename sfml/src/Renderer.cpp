//
// Renderer.cpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:22:12 2014
// Last update Sat Apr  5 22:55:15 2014 
//

#include <exception>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include "Renderer.hpp"

namespace API
{
  Renderer::Renderer(int width, int height) :
    m_window(sf::VideoMode(width * TILESIZE, (height + 1) * TILESIZE), "Nibbler", sf::Style::Close)
  {
    initWindow(width, height);
    initRessource();
    initSprite();
    initBinds();
  }

  Renderer::~Renderer()
  {
  }


  void	Renderer::initRessource()
  {
    sf::Color		white(255, 255, 255);
    sf::Color		black(0, 0, 0);
    sf::Color		grey(85, 85, 85);
    sf::Vector2f	p3(m_window.GetWidth() / 2, m_window.GetHeight() - TILESIZE);
    sf::Vector2f	p4(m_window.GetWidth(), m_window.GetHeight());
    sf::Vector2f	p1(0, m_window.GetHeight() - TILESIZE);
    sf::Vector2f	p2(m_window.GetWidth(), m_window.GetHeight());

    if (!m_font.LoadFromFile("./sfml/assets/TechnoHideo.ttf"))
      throw std::runtime_error("Couldn't load .ttf");
    m_hud = sf::Shape::Rectangle(p1, p2, white, 0, black);
    m_boost = sf::Shape::Rectangle(p3, p4, grey, 0, black);

  }

  void	Renderer::initWindow(int width, int height)
  {
    if (width > 200 || height > 200)
      throw std::runtime_error("Map must be inferior than 200x200");
    m_window.SetFramerateLimit(0);
    m_window.EnableKeyRepeat(false);
  }

  std::string	Renderer::toString(int i) const
  {
    std::stringstream   ss;

    ss << i;
    return (ss.str());
  }

  void	Renderer::initSprite()
  {
    int			i;
    std::string		str;

    i = 1;
    while (i <= 48)
      {
	str = toString(i);
	m_tiles[str].LoadFromFile("./sfml/assets/sprites/ghost_" + str + ".png");
	m_tiles[str].SetSmooth(true);
	i++;
      }
    m_tiles["head"].LoadFromFile("./sfml/assets/sprites/head_1.png");
    m_tiles["apple"].LoadFromFile("./sfml/assets/sprites/apple.png");
  }

  void	Renderer::initBinds()
  {
    eventBinds[sf::Event::Closed] = Event::Closed;
    eventBinds[sf::Event::KeyPressed] = Event::KeyPressed;
    eventBinds[sf::Event::KeyReleased] = Event::KeyReleased;
    eventKeyBinds[sf::Key::Left] = Key::Left;
    eventKeyBinds[sf::Key::Right] = Key::Right;
    eventKeyBinds[sf::Key::Space] = Key::Space;
    eventKeyBinds[sf::Key::Escape] = Key::Escape;
    eventKeyBinds[sf::Key::Return] = Key::Return;
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
    m_window.Clear(sf::Color(0, 0, 0));
  }

  void	Renderer::update() const
  {
    m_window.Display();
  }

  void	Renderer::updateCam(int x, int y, int xdir, int ydir)
  {
    (void) x;
    (void) y;
    (void) xdir;
    (void) ydir;
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
		       m_window.GetHeight() - (y + 2) * TILESIZE + TILESIZE / 2);
    m_window.Draw(sprite);
  }

  void	Renderer::drawBackground(int x, int y) const
  {
    m_window.Draw(m_hud);
  }

  void	Renderer::drawScore(int score) const
  {
    sf::String	str;

    str.SetFont(m_font);
    str.SetSize(50);
    str.SetColor(sf::Color(0, 0, 0));
    str.Move(10, m_window.GetHeight() - TILESIZE - 20);
    str.SetText(std::string("Score : " + toString(score)));
    m_window.Draw(str);
  }

  void	Renderer::drawBoost(int boost, int boostmax) const
  {
    float		pos;
    sf::Shape		curr_boost;
    sf::Vector2f	p1(m_window.GetWidth() / 2, m_window.GetHeight() - TILESIZE);
    sf::Vector2f	p2;


    pos = (float)boost / (float)boostmax;
    pos *=  m_window.GetWidth() / 2;
    p2 = sf::Vector2f(m_window.GetWidth() / 2 + pos, m_window.GetHeight());
    curr_boost = sf::Shape::Rectangle(p1, p2, sf::Color(120,120,255),0.f, sf::Color(0,0,0));
    m_window.Draw(m_boost);
    m_window.Draw(curr_boost);
  }
};

API::IRenderer*	createRenderer(int width, int height)
{
  return (new API::Renderer(width, height));
}
