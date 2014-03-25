
//
// Renderer.hpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:19:32 2014
// Last update Tue Mar 25 19:12:35 2014 
//

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include "RenderAPI.hpp"

class Renderer : public IRenderer
{
public:
  Renderer();
  ~Renderer();

  Event	getEvent() const;
  void	close();
  bool	isOpen() const;
  void	clear() const;
  void	drawGround(int x, int y) const;
  void	drawSnakeHead(int x, int y) const;
  void	drawSnakeBody(int x, int y) const;
  void	drawFood(int x, int y) const;
  void	drawWall(int x, int y) const;

  void	addTexture(const std::string& name, const std::string& file);

private:
  sf::RenderWindow*			m_window;
  std::map<std::string, sf::Texture>	m_textures;
};

extern "C"  IRenderer* createRenderer();

#endif /* RENDERER_HPP */
