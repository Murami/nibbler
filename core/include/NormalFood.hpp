//
// NormalFood.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Fri Mar 28 14:06:52 2014 guerot_a
// Last update Fri Mar 28 19:17:29 2014 guerot_a
//

#ifndef NORMAL_FOOD_HPP
#define NORMAL_FOOD_HPP

#include "IObject.hpp"

class NormalFood : public IObject
{
public:
  NormalFood();
  ~NormalFood();

  void	use(const Snake& snake);
  bool	obosolete() const;

private:
  bool	m_used;
};

#endif /* NORMAL_FOOD_HPP */
