
//
// Renderer.hpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:19:32 2014
// Last update Sat Mar 29 21:54:51 2014 guerot_a
//

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include "IRenderer.hpp"

#define TILESIZE	32
#define NB_TILEY	10
#define NB_TILEX	10

class Renderer : public IRenderer
{
public:
  Renderer();
  ~Renderer();

  Event	getEvent() const;
  void	close();
  bool	isOpen() const;
  void	clear() const;
  void	update() const;
  void	drawGround(int x, int y) const;
  void	drawSnake(int x, int y) const;
  void	drawFood(int x, int y) const;
  void	drawWall(int x, int y) const;

  void	draw(const std::string& ressource, int x, int y) const;

private:
  sf::RenderWindow*			m_window;
  std::map<std::string, sf::Image>	m_tiles;
};

extern "C"  IRenderer* createRenderer();

#endif /* RENDERER_HPP */
