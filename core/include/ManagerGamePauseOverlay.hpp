//
// ManageGamePauseOverlay.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 17:08:01 2014 guerot_a
// Last update Sat Mar 29 20:18:21 2014 guerot_a
//

#ifndef MANAGER_GAME_HPP
#define MANAGER_GAME_HPP

#include "Game.hpp"
#include "IManager.hpp"

class Game::ManagerGamePauseOverlay : public Game::IManager
{
public:
  ManagerGamePauseOverlay(Game& game);
  ~ManagerGamePauseOverlay();

  void	run();

private:
  Game&	m_game;
};

#endif /* MANAGER_GAME_HPP */
