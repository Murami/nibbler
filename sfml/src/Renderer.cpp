//
// Renderer.cpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:22:12 2014
// Last update Tue Mar 25 17:00:29 2014 
//

#include <iostream>
#include "Renderer.hpp"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void	Renderer::init()
{
  m_window = new sf::RenderWindow(sf::VideoMode(64 * 20, 64 * 10), "Test");
  if (m_window == NULL)
    {
      std::cout << "Window create failed" << std::endl;
    }
  m_image.create(64, 64, sf::Color(0, 0, 0));
  m_texture.loadFromImage(m_image);
  m_sprite.setTexture(m_texture);
}

void	Renderer::renderBlank() const
{
  sf::Event event;

  m_window->clear(sf::Color(255, 0, 255));
  m_window->display();
  while (m_window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	m_window->close();
    }
}

bool	Renderer::isOpen() const
{
  return (m_window->isOpen());
}

IRenderer*	createRenderer()
{
  return (new Renderer);
}
