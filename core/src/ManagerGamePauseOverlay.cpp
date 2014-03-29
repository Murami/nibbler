//
// ManagerGamePauseOverlay.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 17:32:53 2014 guerot_a
// Last update Sat Mar 29 20:31:38 2014 guerot_a
//

#include "ManagerGamePauseOverlay.hpp"

Game::ManagerGamePauseOverlay::ManagerGamePauseOverlay(Game& game) :
  m_game(game)
{
}

Game::ManagerGamePauseOverlay::~ManagerGamePauseOverlay()
{
}

void	Game::ManagerGamePauseOverlay::run()
{
  (void) m_game;
}
