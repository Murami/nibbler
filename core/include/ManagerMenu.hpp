//
// ManagerMenu.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 16:08:22 2014 guerot_a
// Last update Sat Mar 29 20:18:04 2014 guerot_a
//

#ifndef MANAGER_MENU_HPP
#define MANAGER_MENU_HPP

#include "Game.hpp"
#include "IManager.hpp"

class Game::ManagerMenu : public Game::IManager
{
public:
  ManagerMenu(Game& game);
  ~ManagerMenu();

  void	run();

private:
  Game&	m_game;
};

#endif /* MANAGER_MENU_HPP */
