//
// Manager.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Fri Mar 28 19:47:23 2014 guerot_a
// Last update Fri Mar 28 19:53:16 2014 guerot_a
//

#ifndef MANAGER_HPP
#define MANAGER_HPP

class IManager
{
public:
  virtual ~Manager() {}

  virtual void	handleEvent(const Game& game, const Event& event) = 0;
  virtual void	update(const Game& game) = 0;
  virtual void	draw(const Game& game) = 0;
};

#endif /* MANAGER_HPP */
