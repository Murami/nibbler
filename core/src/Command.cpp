//
// Command.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Wed Apr  2 10:39:54 2014 guerot_a
// Last update Wed Apr  2 11:17:08 2014 guerot_a
//

#include "Command.hpp"
#include "Game.hpp"
#include "Snake.hpp"


/*
** Commands constructions
*/

Game_Left_Pressed::Game_Left_Pressed(Snake& snake) :
  m_snake(snake) {}

Game_Right_Pressed::Game_Right_Pressed(Snake& snake) :
  m_snake(snake) {}

Game_Space_Pressed::Game_Space_Pressed(Snake& snake) :
  m_snake(snake) {}

Game_Space_Released::Game_Space_Released(Snake& snake) :
  m_snake(snake) {}

Game_Escape_Pressed::Game_Escape_Pressed(Game& game) :
  m_game(game) {}

App_Quit::App_Quit(Game& game) :
  m_game(game) {}

/*
** Commands tests
*/

bool	Game_Left_Pressed::isActive(const API::Event& event) const
{
  return (event.type == API::Event::KeyPressed &&
	  event.key == API::Key::Left);
}

bool	Game_Right_Pressed::isActive(const API::Event& event) const
{
  return (event.type == API::Event::KeyPressed &&
	  event.key == API::Key::Right);
}

bool	Game_Space_Pressed::isActive(const API::Event& event) const
{
  return (event.type == API::Event::KeyPressed &&
	  event.key == API::Key::Space);
}

bool	Game_Space_Released::isActive(const API::Event& event) const
{
  return (event.type == API::Event::KeyReleased &&
	  event.key == API::Key::Space);
}

bool	Game_Escape_Pressed::isActive(const API::Event& event) const
{
  return (event.type == API::Event::KeyPressed &&
	  event.key == API::Key::Escape);
}

bool	App_Quit::isActive(const API::Event& event) const
{
  return (event.type == API::Event::Closed);
}

/*
** Commands runs
*/

void	Game_Left_Pressed::run() const
{
  m_snake.turnLeft();
}

void	Game_Right_Pressed::run() const
{
  m_snake.turnRight();
}

void	Game_Space_Pressed::run() const
{
  m_snake.enableBoost();
}

void	Game_Space_Released::run() const
{
  m_snake.disableBoost();
}

void	Game_Escape_Pressed::run() const
{
  m_game.close();
}

void	App_Quit::run() const
{
  m_game.close();
}
