//
// Timer.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Tue Apr  1 15:37:49 2014 guerot_a
// Last update Sat Apr  5 18:20:41 2014 
//

#include <iostream>
#include <sys/time.h>
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
  struct timeval	time;

  gettimeofday(&time, NULL);
  std::cout << "sec : " <<
    (time.tv_sec * 1000 + time.tv_usec / 1000) / 1000
	    << std::endl;
  return ((time.tv_sec * 1000 + time.tv_usec / 1000) - _time);
}

void	Timer::reset()
{
  struct timeval	time;

  gettimeofday(&time, NULL);
  _time = (time.tv_sec * 1000 + time.tv_usec / 1000);
}
