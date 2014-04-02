//
// Game.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Fri Mar 28 19:15:55 2014 guerot_a
// Last update Wed Apr  2 11:16:46 2014 guerot_a
//

#include <exception>
#include <stdexcept>
#include <iostream>
#include "Game.hpp"
#include "ManagerGame.hpp"

Game::Game(Renderer& renderer, int width, int height) :
  m_renderer(renderer),
  m_width(width),
  m_height(height)
{
  m_manager = new ManagerGame(*this);
  m_alive = true;
}

Game::~Game()
{
  delete m_manager;
}

void	Game::run()
{
  API::Event	event;

  while (m_alive)
    {
      while (m_renderer->getEvent(event))
      	{
      	  if (!m_manager)
      	    throw std::runtime_error("game manager is not setted");
      	  m_manager->handleEvent(event);
      	}
      m_manager->update();
      m_manager->draw();
    }
}

void	Game::close()
{
  m_alive = false;
}
