//
// ManagerGame.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 17:25:21 2014 guerot_a
// Last update Tue Apr  1 21:18:44 2014 guerot_a
//

#include "NormalFood.hpp"
#include "ManagerGame.hpp"
#include "ManagerGamePauseOverlay.hpp"

Game::ManagerGame::ManagerGame(Game& game) :
  m_game(game),
  m_snake(game.m_width, game.m_height, m_objectList)
{
  m_objectList.push_back(new NormalFood(10, 10));
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
	  // m_game.m_manager = new ManagerGamePauseOverlay(m_game, this);
	  m_game.m_alive = false;
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
  std::vector<IObject*>::iterator	it;

  m_snake.update();
  //erase obsolete objects
  for (it = m_objectList.begin(); it < m_objectList.end(); it++)
    {
      if((*it)->obsolete())
	{
	  delete (*it);
	  it = m_objectList.erase(it);
	  it--;
	}
    }
}

void	Game::ManagerGame::draw() const
{
  Renderer&	renderer = m_game.m_renderer;
  std::vector<IObject*>::const_iterator	it;

  renderer->clear();
  m_snake.draw(renderer);
  for (it = m_objectList.begin(); it < m_objectList.end(); it++)
    (*it)->draw(renderer);
  renderer->update();
}
