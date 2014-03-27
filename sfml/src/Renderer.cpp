//
// Renderer.cpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:22:12 2014
// Last update Thu Mar 27 13:42:23 2014 guerot_a
//

#include <iostream>
#include "Renderer.hpp"

Renderer::Renderer()
{
  sf::Image	tile;

  m_window = new sf::RenderWindow(sf::VideoMode(NB_TILEX * TILESIZE, NB_TILEY * TILESIZE), "Test");

  tile.create(TILESIZE, TILESIZE, sf::Color(255, 0, 0));
  m_textures["wall"].loadFromImage(tile);

  tile.create(TILESIZE, TILESIZE, sf::Color(200, 200, 200));
  m_textures["ground"].loadFromImage(tile);

  tile.create(TILESIZE, TILESIZE, sf::Color(0, 255, 255));
  m_textures["snakeHead"].loadFromImage(tile);

  tile.create(TILESIZE, TILESIZE, sf::Color(0, 255, 0));
  m_textures["snakeBody"].loadFromImage(tile);

  tile.create(TILESIZE, TILESIZE, sf::Color(0, 0, 255));
  m_textures["food"].loadFromImage(tile);

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
  if (event.type == sf::Event::KeyPressed)
    {
      switch (event.key.code)
	{
	case sf::Keyboard::Left:
	  return (LEFT);

	case sf::Keyboard::Right:
	  return (RIGHT);

	default:
	  return (NONE);
	}
    }
  return (NONE);
}

void	Renderer::clear() const
{
  m_window->clear(sf::Color(255, 255, 255));
}

void	Renderer::update() const
{
  m_window->display();
}

void	Renderer::drawSnakeHead(int x, int y) const
{
  this->draw("snakeHead", x, y);
}

void	Renderer::drawSnakeBody(int x, int y) const
{
  this->draw("snakeBody", x, y);
}

void	Renderer::drawFood(int x, int y) const
{
  this->draw("food", x, y);
}

void	Renderer::drawWall(int x, int y) const
{
  this->draw("wall", x, y);
}

void	Renderer::drawGround(int x, int y) const
{
  this->draw("ground", x, y);
}

void	Renderer::draw(const std::string& ressource, int x, int y) const
{
  sf::Sprite	sprite;

  sprite.setTexture(m_textures.at(ressource));
  sprite.setPosition(x * TILESIZE, m_window->getSize().y - y * TILESIZE);
  m_window->draw(sprite);
}

/*
** Render Factory
*/

IRenderer*	createRenderer()
{
  return (new Renderer);
}
