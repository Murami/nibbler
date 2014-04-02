//
// ICommand.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Wed Apr  2 09:42:25 2014 guerot_a
// Last update Wed Apr  2 10:36:08 2014 guerot_a
//

#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP

#include "IRenderer.hpp"

class ICommand
{
public:
  ~ICommand() {};

  virtual void	run() const = 0;
  virtual bool	isActive(const API::Event& event) const = 0;
};

#endif /* ICOMMAND_HPP */
