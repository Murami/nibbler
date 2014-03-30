//
// ManagerGamePauseOverlay.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 17:32:53 2014 guerot_a
// Last update Sun Mar 30 22:40:50 2014 guerot_a
//

#include "ManagerGamePauseOverlay.hpp"
#include "ManagerGame.hpp"

Game::ManagerGamePauseOverlay::ManagerGamePauseOverlay(Game& game, IManager* managerGame) :
  m_game(game),
  m_managerGame(managerGame)
{
}

Game::ManagerGamePauseOverlay::~ManagerGamePauseOverlay()
{
}

void	Game::ManagerGamePauseOverlay::handleEvent(const API::Event& event)
{
  (void) m_managerGame;
  (void) event;
  (void) m_game;
}

void	Game::ManagerGamePauseOverlay::update()
{
}

void	Game::ManagerGamePauseOverlay::draw() const
{
}
