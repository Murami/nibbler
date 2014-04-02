//
// Game.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Fri Mar 28 19:14:00 2014 guerot_a
// Last update Wed Apr  2 11:16:08 2014 guerot_a
//

#ifndef GAME_HPP
#define GAME_HPP

#include "Renderer.hpp"

class IManager;

class Game
{
  /*
  ** Managers for the game
  ** (theses are differents states of the game)
  */

  class IManager;
  class ManagerMenu;
  class ManagerGame;
  class ManagerGamePauseOverlay;

public:
  Game(Renderer& renderer, int width, int height);
  ~Game();

  void	run();

  void	close();

private:
  Renderer&	m_renderer;
  IManager*	m_manager;
  bool		m_alive;
  int		m_width;
  int		m_height;
};

#endif /* GAME_HPP */
