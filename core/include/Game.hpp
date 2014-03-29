//
// Game.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Fri Mar 28 19:14:00 2014 guerot_a
// Last update Sat Mar 29 17:54:50 2014 guerot_a
//

#ifndef GAME_HPP
#define GAME_HPP

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
  Game(IRenderer* renderer);
  ~Game();

  void	run();
  void	release();

private:
  Renderer	m_renderer;
  IManager*	m_manager;
  bool		m_alive;
};

#endif /* GAME_HPP */
