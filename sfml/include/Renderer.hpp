//
// Renderer.hpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:19:32 2014
// Last update Fri Apr  4 21:09:16 2014 Desabre Quentin
//

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include "IRenderer.hpp"

#define TILESIZE	50
#define NB_TILEY	10
#define NB_TILEX	10

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
    void	initSprite();
    void	initRessource();
    void	initBinds();

    //game draws

    void	draw(const std::string& ressource, int x, int y,
		     int rotation) const;
    void	drawBackground(int width, int height) const;
    void	drawScore(int score) const;
    void	drawBoost(int boost, int boostmax) const;

    // misc

    std::string	toString(int) const;

  private:
    mutable sf::RenderWindow		m_window;
    std::map<std::string, sf::Image>	m_tiles;
    sf::Shape				m_hud;
    sf::Shape				m_boost;
    sf::Font				m_font;

  public:
    std::map<sf::Key::Code, Key::Code>			eventKeyBinds;
    std::map<sf::Event::EventType, Event::EventType>	eventBinds;
  };
};

extern "C"  API::IRenderer* createRenderer(int, int);

#endif /* RENDERER_HPP */
