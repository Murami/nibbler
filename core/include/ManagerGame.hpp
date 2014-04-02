//
// ManagerGame.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 16:11:26 2014 guerot_a
// Last update Wed Apr  2 10:52:49 2014 guerot_a
//

#ifndef MANAGER_GAME_HPP
#define MANAGER_GAME_HPP

#include <vector>
#include "IObject.hpp"
#include "Game.hpp"
#include "IManager.hpp"
#include "Snake.hpp"
#include "ObjectFactory.hpp"
#include "MapObject.hpp"
#include "ICommand.hpp"

class Game::ManagerGame : public Game::IManager
{
public:
  ManagerGame(Game& game);
  ~ManagerGame();

  void	handleEvent(const API::Event& event);
  void	update();
  void	draw() const;

private:
  Game&				m_game;
  Snake				m_snake;
  MapObject			m_mapObject;
  std::vector<ICommand*>	m_commands;
};

#endif /* MANAGER_GAME_HPP */
