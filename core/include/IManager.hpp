//
// IManager.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 15:42:52 2014 guerot_a
// Last update Sat Mar 29 17:06:31 2014 guerot_a
//

#ifndef IMANAGER_HPP
#define IMANAGER_HPP

#include "Game.hpp"

class Game::IManager
{
public:
  ~IManager() {}

  virtual void	run() = 0;
};

#endif /* IMANAGER_HPP */
