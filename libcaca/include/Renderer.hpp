//
// Renderer.hpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:19:32 2014
// Last update Sun Apr  6 01:58:18 2014 
//

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <map>
#include <caca.h>
#include "IRenderer.hpp"

typedef enum caca_key caca_key;

namespace API
{
  class Renderer : public IRenderer
  {
  public:
    Renderer(int x, int y);
    ~Renderer();

    bool	getEvent(Event& event) const;
    void	close();
    bool	isOpen() const;
    void	clear() const;
    void	update() const;
    void	updateCam(int x, int y, int xdir, int ydir);

    //init

    void	initWindow(int, int);
    void	initBinds();
    void	initRessource();

    //game draws

    void	draw(const std::string& ressource, int x, int y,
		     int rotation) const;
    void	drawBackground(int width, int height) const;
    void	drawScore(int score) const;
    void	drawBoost(int boost, int boostmax) const;

    //misc

    std::string	toString(int i) const;
  private:
    caca_canvas_t*	m_canvas;
    caca_display_t*	m_display;
    bool		m_open;
    std::map<caca_key, Key::Code>		eventKeyBinds;
    std::map<caca_event_type, Event::EventType>	eventBinds;
    std::map<std::string, int>			m_ressources;
  };
};

extern "C"  API::IRenderer* createRenderer(int, int);

#endif /* RENDERER_HPP */
