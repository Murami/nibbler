//
// ManagerGame.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 17:25:21 2014 guerot_a
// Last update Sat Apr  5 20:10:53 2014 
//

#include <iostream>
#include <cstdlib>
#include "NormalFood.hpp"
#include "ManagerGame.hpp"
#include "ManagerGamePauseOverlay.hpp"

#include "Command.hpp"

Game::ManagerGame::ManagerGame(Game& game) :
  m_game(game)
{
  m_commands.push_back(new Game_Left_Pressed(m_snake));
  m_commands.push_back(new Game_Right_Pressed(m_snake));
  m_commands.push_back(new Game_Space_Pressed(m_snake));
  m_commands.push_back(new Game_Space_Released(m_snake));
  m_commands.push_back(new Game_Escape_Pressed(m_game));
  m_commands.push_back(new App_Quit(m_game));

}

Game::ManagerGame::~ManagerGame()
{
  std::vector<ICommand*>::iterator	it;

  it = m_commands.begin();
  while (it != m_commands.end())
    it = m_commands.erase(it);
}

void	Game::ManagerGame::handleEvent(const API::Event& event)
{
  std::vector<ICommand*>::iterator	it;

  for (it = m_commands.begin(); it < m_commands.end(); it++)
    {
      if ((*it)->isActive(event))
	{
	  (*it)->run();
	  return;
	}
    }
}

void	Game::ManagerGame::update()
{
  m_snake.update(m_game.m_width, m_game.m_height, m_mapObject);
  m_mapObject.update(m_game.m_width, m_game.m_height, m_snake);
}

void	Game::ManagerGame::draw() const
{
  Renderer&	renderer = m_game.m_renderer;

  renderer->clear();
  m_snake.updateCam(renderer);
  renderer->drawBackground(m_game.m_width, m_game.m_height);
  renderer->drawBoost(m_snake.getBoost(), SNAKE_BOOST_MAX);
  renderer->drawScore(m_snake.getScore());
  m_snake.draw(renderer);
  m_mapObject.draw(renderer);
  renderer->update();
}
