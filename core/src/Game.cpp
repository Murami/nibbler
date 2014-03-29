//
// Game.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Fri Mar 28 19:15:55 2014 guerot_a
// Last update Sat Mar 29 22:51:32 2014 guerot_a
//

#include <exception>
#include <stdexcept>
#include "Game.hpp"
#include "ManagerMenu.hpp"

Game::Game(Renderer& renderer, int width, int height) :
  m_renderer(renderer),
  m_width(width),
  m_height(height)
{
  m_manager = new ManagerMenu(*this);
  m_alive = true;
}

Game::~Game()
{
  delete m_manager;
}

void	Game::run()
{
  while (m_alive)
    {
      if (!m_manager)
	throw std::runtime_error("game manager is not setted");
      m_manager->run();
    }
}
