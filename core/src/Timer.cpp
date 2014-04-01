//
// Timer.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Tue Apr  1 15:37:49 2014 guerot_a
// Last update Tue Apr  1 18:48:12 2014 guerot_a
//

#include <iostream>
#include "Timer.hpp"

Timer::Timer()
{
  this->reset();
}

Timer::~Timer()
{
}

int	Timer::getElapsedTime()
{
  return ((10000 * ((float)clock() - m_ticks)) / CLOCKS_PER_SEC);
}

void	Timer::reset()
{
  m_ticks = clock();
}
