//
// Nibbler.hpp for  in /home/otoshigami/rendu/cpp_nibbler
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Wed Mar 19 16:59:59 2014
// Last update Wed Mar 19 17:18:21 2014 
//

#ifndef NIBBLER_HPP
#define NIBBLER_HPP

class Nibbler
{
public:
  Nibbler();
  ~Nibbler();

  void	init();
  void	run();
  void	quit();

  /*
  ** Nibbler modules
  */
private:
  GraphicEngine		m_graphicEngine;
  SoundEngine		m_soundEngine;
  GameEngine		m_gameEngine;
};

#endif /* NIBBLER_HPP */
