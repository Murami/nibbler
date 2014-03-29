//
// Renderer.cpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:22:12 2014
// Last update Sat Mar 29 22:32:15 2014 guerot_a
//

#include <iostream>
#include "Renderer.hpp"

Renderer::Renderer()
{
  sf::Image	tile;

  m_window = new sf::RenderWindow(sf::VideoMode(NB_TILEX * TILESIZE, NB_TILEY * TILESIZE), "Test");

  m_tiles["wall"].Create(TILESIZE, TILESIZE, sf::Color(255, 0, 0));
  m_tiles["ground"].Create(TILESIZE, TILESIZE, sf::Color(200, 200, 200));
  m_tiles["snake"].Create(TILESIZE, TILESIZE, sf::Color(0, 255, 255));
  m_tiles["food"].Create(TILESIZE, TILESIZE, sf::Color(0, 0, 255));
}

Renderer::~Renderer()
{
  delete m_window;
}

void	Renderer::close()
{
  m_window->Close();
}

bool	Renderer::isOpen() const
{
  return (m_window->IsOpened());
}

Event	Renderer::getEvent() const
{
  sf::Event	event;

  m_window->GetEvent(event);
  if (event.Type == sf::Event::Closed)
    return (CLOSE);
  if (event.Type == sf::Event::KeyPressed)
    {
      switch (event.Key.Code)
	{
	case sf::Key::Left:
	  return (LEFT);

	case sf::Key::Right:
	  return (RIGHT);

	case sf::Key::Up:
	  return (UP);

	case sf::Key::Down:
	  return (DOWN);

	default:
	  return (NONE);
	}
    }
  return (NONE);
}

void	Renderer::clear() const
{
  m_window->Clear(sf::Color(255, 255, 255));
}

void	Renderer::update() const
{
  m_window->Display();
}

void	Renderer::drawSnake(int x, int y) const
{
  this->draw("snake", x, y);
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
  sf::Sprite	sprite(m_tiles.at(ressource));

  sprite.SetPosition(x * TILESIZE, m_window->GetHeight() - y * TILESIZE);
  m_window->Draw(sprite);
}

/*
** Render Factory
*/

IRenderer*	createRenderer()
{
  return (new Renderer);
}
