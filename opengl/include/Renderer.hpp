
//
// Renderer.hpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:19:32 2014
// Last update Sun Apr  6 04:04:51 2014 
//

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "IRenderer.hpp"

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

    void	draw(const std::string& ressource, int x, int y, int rotation) const;
    void	drawBackground(int width, int height) const;
    void	drawBoost(int boost, int boostmax) const;
    void	drawScore(int score) const;

  private:
    void	initBinds();
    void	initRessources();
    void	initGL();
    void	initWindow(int x, int y);

    void	drawGround() const;

    void	drawSkybox() const;
    void	drawSkyboxNorth() const;
    void	drawSkyboxSouth() const;
    void	drawSkyboxEst() const;
    void	drawSkyboxWest() const;

    void	drawLimit() const;
    void	drawLimitNorthInside() const;
    void	drawLimitNorthTop() const;
    void	drawLimitNorthOutside() const;
    void	drawLimitSouthInside() const;
    void	drawLimitSouthTop() const;
    void	drawLimitSouthOutside() const;
    void	drawLimitEstInside() const;
    void	drawLimitEstTop() const;
    void	drawLimitEstOutside() const;
    void	drawLimitWestInside() const;
    void	drawLimitWestTop() const;
    void	drawLimitWestOutside() const;

    void	drawTop(int x, int y) const;
    void	drawBottom(int x, int y) const;
    void	drawLeft(int x, int y) const;
    void	drawRight(int x, int y) const;
    void	drawBack(int x, int y) const;
    void	drawFront(int x, int y) const;

    void	loadTexture(const std::string& name, const std::string& filepath);
    void	enableTexture(const std::string& name) const;
    void	disableTexture() const;

    std::string	toString(int) const;

  private:
    mutable sf::RenderWindow		m_window;
    std::map<std::string, GLuint>	m_textures;
    int					m_height;
    int					m_width;
    std::map<sf::Key::Code, Key::Code>				eventKeyBinds;
    std::map<sf::Event::EventType, Event::EventType>		eventBinds;
    std::map<std::string, void (Renderer::*)(int, int, int)>	m_drawMethods;
  };
};

extern "C"  API::IRenderer* createRenderer(int, int);

#endif /* RENDERER_HPP */
