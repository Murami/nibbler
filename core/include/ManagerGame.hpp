//
// ManagerGame.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 16:11:26 2014 guerot_a
// Last update Sat Mar 29 17:06:22 2014 guerot_a
//

#ifndef MANAGER_GAME_HPP
#define MANAGER_GAME_HPP

#include "Game.hpp"

class Game::ManagerGame : public Game::IManager
{
public:
  ManagerGame(Game& game);
  ~ManagerGame();

  void	run();

private:
  Game&	m_game;
};

#endif /* MANAGER_GAME_HPP */
