//
// ManageGamePauseOverlay.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 17:08:01 2014 guerot_a
// Last update Sun Mar 30 22:33:55 2014 guerot_a
//

#ifndef MANAGER_GAME_PAUSE_OVERLAY_HPP
#define MANAGER_GAME_PAUSE_OVERLAY_HPP

#include "Game.hpp"
#include "IManager.hpp"

class Game::ManagerGamePauseOverlay : public Game::IManager
{
public:
  ManagerGamePauseOverlay(Game& game, IManager* managerGame);
  ~ManagerGamePauseOverlay();

  void	handleEvent(const API::Event& event);
  void	update();
  void	draw() const;

private:
  Game&		m_game;
  IManager*	m_managerGame;
};

#endif /* MANAGER_GAME_PAUSE_OVERLAY_HPP */
