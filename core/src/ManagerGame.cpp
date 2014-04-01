//
// ManagerGame.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 17:25:21 2014 guerot_a
// Last update Tue Apr  1 14:53:21 2014 Desabre Quentin
//

#include "ManagerGame.hpp"
#include "ManagerGamePauseOverlay.hpp"

Game::ManagerGame::ManagerGame(Game& game) :
  m_game(game),
  m_snake(game.m_width, game.m_height)
{
}

Game::ManagerGame::~ManagerGame()
{
}

void	Game::ManagerGame::handleEvent(const API::Event& event)
{
  if (event.type == API::Event::Closed)
    {
      m_game.m_alive = false;
    }
  else if (event.type == API::Event::KeyPressed)
    {
      switch (event.key)
	{
	case API::Key::Left:
	  m_snake.turnLeft();
	  break;

	case API::Key::Right:
	  m_snake.turnRight();
	  break;

	case API::Key::Space:
	  m_snake.enableBoost();
	  break;

	case API::Key::Escape:
	  m_game.m_manager = new ManagerGamePauseOverlay(m_game, this);
	  break;

	default:
	  break;
	}
    }
  else if (event.type == API::Event::KeyReleased)
    {
      switch (event.key)
	{
	case API::Key::Space:
	  m_snake.disableBoost();
	  break;

	default:
	  break;
	}
    }
}

void	Game::ManagerGame::update()
{
  m_snake.update();
}

void	Game::ManagerGame::draw() const
{
  Renderer&	renderer = m_game.m_renderer;

  renderer->clear();
  m_snake.draw(renderer);
  renderer->update();
}
