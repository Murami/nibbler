
//
// Renderer.hpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:19:32 2014
// Last update Sun Mar 30 01:53:30 2014 guerot_a
//

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include "IRenderer.hpp"

#define TILESIZE	32
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

    //menu draws
    void	drawMenuPlay(bool selected) const;
    void	drawMenuQuit(bool selected) const;

    //game draws
    void	drawGround(int x, int y) const;
    void	drawSnake(int x, int y) const;
    void	drawFood(int x, int y) const;
    void	drawWall(int x, int y) const;

    void	draw(const std::string& ressource, int x, int y) const;

  private:
    mutable sf::RenderWindow		m_window;
    std::map<std::string, sf::Image>	m_tiles;
  };
};

extern "C"  API::IRenderer* createRenderer(int, int);

#endif /* RENDERER_HPP */
