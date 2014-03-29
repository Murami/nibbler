//
// Game.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Fri Mar 28 19:15:55 2014 guerot_a
// Last update Sat Mar 29 17:58:56 2014 guerot_a
//

#include "Game.hpp"
#include "MenuManager.hpp"

Game::Game(IRenderer* renderer)
{
  m_manager = new ManagerMenu(*this);
  m_renderer = renderer;
  m_alive = true;
}

Game::~Game()
{
  delete m_manager;
}

void	Game::run(const std::string& libpath)
{
  while (m_alive)
    {
      if (!m_manager)
	throw std::runtime_error("game manager is not setted");
      m_manager->run();
    }
}
