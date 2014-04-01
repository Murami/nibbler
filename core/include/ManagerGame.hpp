//
// ManagerGame.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 16:11:26 2014 guerot_a
// Last update Tue Apr  1 22:47:37 2014 guerot_a
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

class Game::ManagerGame : public Game::IManager
{
public:
  ManagerGame(Game& game);
  ~ManagerGame();

  void	handleEvent(const API::Event& event);
  void	update();
  void	draw() const;

private:
  Game&			m_game;
  Snake			m_snake;
  MapObject		m_mapObject;
};

#endif /* MANAGER_GAME_HPP */
