//
// SnakeElm.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 17:07:42 2014 guerot_a
// Last update Fri Mar 28 13:27:51 2014 guerot_a
//

#ifndef SNAKE_ELM_HPP
#define SNAKE_ELM_HPP

#include <map>
#include "RenderAPI.hpp"
#include "Vector2.hpp"

namespace Game
{

  typedef enum	Direction
    {
      DOWN,
      LEFT,
      UP,
      RIGHT
    }		Direction;

  class SnakeElm
  {
  public:
    SnakeElm(const Vector2i& pos, bool isHead = true);
    SnakeElm(const SnakeElm& snakeElm);
    ~SnakeElm();

    SnakeElm&	operator=(const SnakeElm& snakeElm);

    void	move(const Vector2i& movement);
    void	moveTo(const Vector2i& movement);
    bool	isTail();
    bool	isHead();
    void	addElm(const Vector2i& parentPos);
    void	addElm(Direction direction);
    void	delElm();
    void	draw(IRenderer* renderer) const;
    int	size() const;

  private:
    Vector2i	m_position;
    SnakeElm*	m_elements;
    bool	m_isHead;
  };
};
#endif /* SNAKE_ELM_HPP */
