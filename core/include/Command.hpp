//
// Command.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Wed Apr  2 10:01:41 2014 guerot_a
// Last update Wed Apr  2 10:41:54 2014 guerot_a
//

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "ICommand.hpp"

class Game_Left_Pressed : public ICommand
{
public:
  Game_Left_Pressed(Snake& snake);
  ~Game_Left_Pressed() {};

  void	run() const;
  bool	isActive(const API::Event& event) const;

private:
  Snake&	m_snake;
};

class Game_Right_Pressed : public ICommand
{
public:
  Game_Right_Pressed(Snake& snake);
  ~Game_Right_Pressed() {};

  void	run() const;
  bool	isActive(const API::Event& event) const;

private:
  Snake&	m_snake;
};

class Game_Space_Pressed : public ICommand
{
public:
  Game_Space_Pressed(Snake& snake);
  ~Game_Space_Pressed() {};

  void	run() const;
  bool	isActive(const API::Event& event) const;

private:
  Snake&	m_snake;
};

class Game_Space_Released : public ICommand
{
public:
  Game_Space_Released(Game& game);
  ~Game_Space_Released() {};

  void	run() const;
  bool	isActive(const API::Event& event) const;

private:
  Game&		m_game;
};

class Game_Escape_Pressed : public ICommand
{
public:
  Game_Escape_Pressed(Game& game);
  ~Game_Escape_Pressed() {};

  void	run() const;
  bool	isActive(const API::Event& event) const;

private:
  Game&		m_game;
};

class App_Quit : public ICommand
{
public:
  App_Quit(Game& game);
  ~App_Quit() {};

  void	run() const;
  bool	isActive(const API::Event& event) const;

private:
  Game&		m_game;
};

#endif /* COMMAND_HPP */
