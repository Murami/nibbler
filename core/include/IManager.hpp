//
// IManager.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 15:42:52 2014 guerot_a
// Last update Sun Mar 30 20:25:08 2014 guerot_a
//

#ifndef IMANAGER_HPP
#define IMANAGER_HPP

#include "Game.hpp"

class Game::IManager
{
public:
  virtual ~IManager() {}

  virtual void	handleEvent(const API::Event& event) = 0;
  virtual void	update() = 0;
  virtual void	draw() const = 0;
};

#endif /* IMANAGER_HPP */
