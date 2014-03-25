//
// Renderer.cpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:22:12 2014
// Last update Tue Mar 25 19:14:29 2014 
//

#include <iostream>
#include "Renderer.hpp"

Renderer::Renderer()
{
  m_window = new sf::RenderWindow(sf::VideoMode(64 * 20, 64 * 10), "Test");
  // addTexture("SnakeHead", "Sprites/snake_head.bmp");
  // addTexture("SnakeBody", "Sprites/snake_body.bmp");
  // addTexture("Wall", "Sprites/wall.bmp");
  // addTexture("Ground", "Sprites/ground.bmp");
}

Renderer::~Renderer()
{
  delete m_window;
}

void	Renderer::close()
{
  m_window->close();
}

bool	Renderer::isOpen() const
{
  return (m_window->isOpen());
}

Event	Renderer::getEvent() const
{
  sf::Event	event;

  m_window->pollEvent(event);
  if (event.type == sf::Event::Closed)
    return (CLOSE);
  return (NONE);
}

void	Renderer::clear() const
{
  m_window->clear(sf::Color(255, 255, 255));
  m_window->display();
}

void	Renderer::drawSnakeHead(int x, int y) const
{
  (void) x;
  (void) y;
}

void	Renderer::drawSnakeBody(int x, int y) const
{
  (void) x;
  (void) y;
}

void	Renderer::drawFood(int x, int y) const
{
  (void) x;
  (void) y;
}

void	Renderer::drawWall(int x, int y) const
{
  (void) x;
  (void) y;
}

void	Renderer::drawGround(int x, int y) const
{
  (void) x;
  (void) y;
}

void		Renderer::addTexture(const std::string& name, const std::string& file)
{
  //Il faut faire des vrais execptions !
  if (m_textures.find(name) == m_textures.end())
    throw std::string("texture name already used");
  if (!m_textures[name].loadFromFile(file))
    {
      m_textures.erase(m_textures.find(name));
      throw std::string("file not found");
    }
}

/*
** Render Factory
*/

IRenderer*	createRenderer()
{
  return (new Renderer);
}
