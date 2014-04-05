//
// Timer.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Tue Apr  1 15:34:01 2014 guerot_a
// Last update Sat Apr  5 17:44:56 2014 
//

#ifndef TIMER_HPP
#define TIMER_HPP

class Timer
{
public:
  Timer();
  ~Timer();

  int	getElapsedTime();
  void	reset();

private:
  unsigned int	_time;
};

#endif /* TIMER_HPP */
