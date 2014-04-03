//
// Renderer.cpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:22:12 2014
// Last update Thu Apr  3 15:58:54 2014 guerot_a
//

#include <exception>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include "Renderer.hpp"

namespace API
{
  Renderer::Renderer(int width, int height) :
    m_window()
  {
    sf::WindowSettings	settings;

    if (width > 200 || height > 200)
      throw std::runtime_error("cannot create a windows with a size higher than 200x200");

    settings.DepthBits = 24;
    settings.StencilBits = 8;
    settings.AntialiasingLevel = 16;
    m_window.Create(sf::VideoMode(800, 600, 32), "SFML OpenGL", sf::Style::Close, settings);
    m_window.SetFramerateLimit(0);
    m_window.EnableKeyRepeat(false);

    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f, 1.f, 1.f, 500.f);

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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(10, 0, 20, 10, 10, 0, 0, 0, 1);
    glColor3d(255, 0, 0);

    glBegin(GL_QUADS);

    glVertex3f(x,	y,	0);
    glVertex3f(x + 1,	y,	0);
    glVertex3f(x + 1,	y,	1);
    glVertex3f(x,	y,	1);

    glVertex3f(x,	y,	0);
    glVertex3f(x,	y,	1);
    glVertex3f(x,	y + 1,	1);
    glVertex3f(x,	y + 1,	0);

    glVertex3f(x,	y + 1,	0);
    glVertex3f(x,	y + 1,	1);
    glVertex3f(x + 1,	y + 1,	1);
    glVertex3f(x + 1,	y + 1,	0);

    glVertex3f(x + 1,	y + 1,	0);
    glVertex3f(x + 1,	y + 1,	1);
    glVertex3f(x + 1,	y,	1);
    glVertex3f(x + 1,	y,	0);

    glVertex3f(x + 1,	y,	1);
    glVertex3f(x + 1,	y + 1,	1);
    glVertex3f(x,	y + 1,	1);
    glVertex3f(x,	y,	1);

    glVertex3f(x + 1,	y,	0);
    glVertex3f(x + 1,	y + 1,	0);
    glVertex3f(x,	y + 1,	0);
    glVertex3f(x,	y,	0);

    glEnd();
  }

  void	Renderer::drawBackground(int width, int height) const
  {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(10, 0, 20, 10, 10, 0, 0, 0, 1);
    glColor3d(0, 255, 0);

    glBegin(GL_QUADS);

    glVertex3f(0,	0,	0);
    glVertex3f(0,	height,	0);
    glVertex3f(width,	height,	0);
    glVertex3f(width,	0,	0);

    glEnd();
  }
};

API::IRenderer*	createRenderer(int width, int height)
{
  return (new API::Renderer(width, height));
}
