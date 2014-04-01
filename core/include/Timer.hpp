//
// Timer.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Tue Apr  1 15:34:01 2014 guerot_a
// Last update Tue Apr  1 15:37:09 2014 guerot_a
//

#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>

class Timer
{
public:
  Timer();
  ~Timer();

  int	getElapsedTime();
  void	reset();

private:
  clock_t	m_ticks;
};

#endif /* TIMER_HPP */
