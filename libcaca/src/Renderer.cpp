//
// Renderer.cpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:22:12 2014
// Last update Sat Apr  5 23:51:14 2014 
//

#include <iostream>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include "Renderer.hpp"

namespace API
{
  Renderer::Renderer(int width, int height)
  {
    m_open = true;
    initWindow(width, height);
    initBinds();
  }

  Renderer::~Renderer()
  {
    caca_free_display(m_display);
    cucul_free_canvas(m_canvas);
  }


  void	Renderer::initWindow(int width, int height)
  {
    m_canvas = cucul_create_canvas(width, height);
    m_display = caca_create_display(m_canvas);
    if (!m_display)
      throw (std::runtime_error("failed to init display"));
    caca_set_display_title(m_display, "Nibbler");
  }

  void	Renderer::initBinds()
  {
    eventBinds[CACA_EVENT_KEY_PRESS] = Event::KeyPressed;
    eventBinds[CACA_EVENT_KEY_RELEASE] = Event::KeyReleased;
    eventBinds[CACA_EVENT_QUIT] = Event::Closed;
    eventKeyBinds[CACA_KEY_LEFT] = Key::Left;
    eventKeyBinds[CACA_KEY_RIGHT] = Key::Right;
    eventKeyBinds[static_cast<caca_key>(' ')] = Key::Space;
    eventKeyBinds[CACA_KEY_ESCAPE] = Key::Escape;
    eventKeyBinds[CACA_KEY_RETURN] = Key::Return;
  }

  void	Renderer::close()
  {
    m_open = false;
  }

  bool	Renderer::isOpen() const
  {
    return (m_open);
  }

  bool	Renderer::getEvent(Event& eventRcv) const
  {
    std::map<caca_event_type, Event::EventType>::const_iterator	itType;
    std::map<caca_key, Key::Code>::const_iterator		itKey;
    caca_event_t	event;

    if (!caca_get_event(m_display, CACA_EVENT_KEY_PRESS | CACA_EVENT_KEY_RELEASE | CACA_EVENT_QUIT, &event, 0))
      return (false);

    eventRcv.type = Event::None;
    eventRcv.key = Key::None;
    for (itType = eventBinds.begin(); itType != eventBinds.end(); itType++)
      {
	if ((*itType).first == event.type)
	  eventRcv.type = (*itType).second;
      }

    if (event.type == CACA_EVENT_KEY_RELEASE ||
	event.type == CACA_EVENT_KEY_PRESS)
      {
	for (itKey = eventKeyBinds.begin(); itKey != eventKeyBinds.end(); itKey++)
	  {
	    if ((*itKey).first == event.data.key.ch)
	      eventRcv.key = (*itKey).second;
	  }
      }
    return (true);
  }

  void	Renderer::clear() const
  {
    caca_set_color_ansi(m_canvas, CACA_BLACK, CACA_WHITE);
    cucul_clear_canvas(m_canvas);
  }

  void	Renderer::update() const
  {
    caca_refresh_display(m_display);
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
  }

  void	Renderer::drawBackground(int x, int y) const
  {
  }

  void	Renderer::drawScore(int score) const
  {
  }

  void	Renderer::drawBoost(int boost, int boostmax) const
  {
  }
};

API::IRenderer*	createRenderer(int width, int height)
{
  return (new API::Renderer(width, height));
}
