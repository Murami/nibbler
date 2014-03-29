//
// NormalFood.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Fri Mar 28 14:17:02 2014 guerot_a
// Last update Fri Mar 28 14:27:44 2014 guerot_a
//

#include "NormalFood.hpp"
#include "Snake.hpp"

namespace Game
{
  NormalFood::NormalFood()
    : m_used(true);
  {
  }

  NormalFood::~NormalFood()
  {
  }

  void	NormalFood::use(const Snake& snake)
  {
    snake.addElm();
    m_used = true;
  }

  bool	NormalFood::obosolete() const
  {
    return (!m_used);
  }
};
