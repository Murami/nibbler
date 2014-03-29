//
// ManagerMenu.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 17:22:42 2014 guerot_a
// Last update Sat Mar 29 20:33:24 2014 guerot_a
//

#include "ManagerMenu.hpp"

Game::ManagerMenu::ManagerMenu(Game& game) :
  m_game(game)
{
}

Game::ManagerMenu::~ManagerMenu()
{
}

void	Game::ManagerMenu::run()
{
  (void) m_game;
}
