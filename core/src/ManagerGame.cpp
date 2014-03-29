//
// ManagerGame.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 17:25:21 2014 guerot_a
// Last update Sat Mar 29 20:31:09 2014 guerot_a
//

#include "ManagerGame.hpp"

Game::ManagerGame::ManagerGame(Game& game) :
  m_game(game)
{
}

Game::ManagerGame::~ManagerGame()
{
}

void	Game::ManagerGame::run()
{
  (void) m_game;
}
