//
// Game.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Fri Mar 28 19:15:55 2014 guerot_a
// Last update Sun Apr  6 00:03:39 2014 
//

#include <unistd.h>
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
  Timer		gametimer;

  while (m_alive)
    {
      while (m_renderer->getEvent(event))
      	{
      	  if (!m_manager)
      	    throw std::runtime_error("game manager is not setted");
      	  m_manager->handleEvent(event);
      	}
      if (gametimer.getElapsedTime() < GAME_FRAME_PERIOD)
	{
	  usleep((GAME_FRAME_PERIOD - gametimer.getElapsedTime()) * 1000);
	  gametimer.reset();
	}
      m_manager->update();
      m_manager->draw();
    }
}

void	Game::close()
{
  m_alive = false;
}
