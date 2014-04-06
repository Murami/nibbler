
//
// Renderer.hpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:19:32 2014
// Last update Sun Apr  6 00:12:57 2014 
//

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Window.hpp>
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

    void	initBinds();

    bool	getEvent(Event& event) const;
    void	close();
    bool	isOpen() const;
    void	clear() const;
    void	update() const;
    void	updateCam(int x, int y, int xdir, int ydir);

    //game draws

    void	draw(const std::string& ressource, int x, int y,
		     int rotation) const;
    void	drawBackground(int width, int height) const;
    void	drawBoost(int boost, int boostmax) const;
    void	drawScore(int score) const;

  private:
    void	loadTexture(const std::string& name, const std::string& filepath);
    void	enableTexture(const std::string& name) const;
    void	disableTexture() const;

  private:
    mutable sf::RenderWindow		m_window;
    std::map<std::string, GLuint>	m_textures;
    int					m_height;
    int					m_width;

  public:
    std::map<sf::Key::Code, Key::Code>			eventKeyBinds;
    std::map<sf::Event::EventType, Event::EventType>	eventBinds;
  };
};

extern "C"  API::IRenderer* createRenderer(int, int);

#endif /* RENDERER_HPP */
