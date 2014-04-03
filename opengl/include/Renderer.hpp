
//
// Renderer.hpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:19:32 2014
// Last update Thu Apr  3 17:04:36 2014 guerot_a
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

    bool	getEvent(Event& event) const;
    void	close();
    bool	isOpen() const;
    void	clear() const;
    void	update() const;

    //game draws

    void	draw(const std::string& ressource, int x, int y,
		     int rotation) const;
    void	drawBackground(int width, int height) const;

  private:
    void	loadTexture(const std::string& name, const std::string& filepath);
    void	enableTexture(const std::string& name);
    void	disableTexture();

  private:
    mutable sf::RenderWindow		m_window;
    std::map<std::string, GLuint>	m_textures;

  public:
    std::map<sf::Key::Code, Key::Code>			eventKeyBinds;
    std::map<sf::Event::EventType, Event::EventType>	eventBinds;
  };
};

extern "C"  API::IRenderer* createRenderer(int, int);

#endif /* RENDERER_HPP */
