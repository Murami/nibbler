
//
// Renderer.hpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:19:32 2014
// Last update Tue Mar 25 16:46:07 2014 
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

  void	init();
  void	renderBlank() const;
  bool	isOpen() const;

private:
  sf::RenderWindow*	m_window;
  sf::Image		m_image;
  sf::Texture		m_texture;
  sf::Sprite		m_sprite;
};

extern "C"  IRenderer* createRenderer();

#endif /* RENDERER_HPP */
