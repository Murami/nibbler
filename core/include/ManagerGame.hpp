//
// ManagerGame.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 16:11:26 2014 guerot_a
// Last update Tue Apr  1 21:15:45 2014 guerot_a
//

#ifndef MANAGER_GAME_HPP
#define MANAGER_GAME_HPP

#include <vector>
#include "IObject.hpp"
#include "Game.hpp"
#include "IManager.hpp"
#include "Snake.hpp"

class Game::ManagerGame : public Game::IManager
{
public:
  ManagerGame(Game& game);
  ~ManagerGame();

  void	handleEvent(const API::Event& event);
  void	update();
  void	draw() const;

private:
  std::vector<IObject*>	m_objectList;
  Game&			m_game;
  Snake			m_snake;
  int			m_mapWidth;
  int			m_mapHeight;
};

#endif /* MANAGER_GAME_HPP */
