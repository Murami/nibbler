//
// SoundEngine.hpp for  in /home/otoshigami/rendu/cpp_nibbler
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Wed Mar 19 17:12:33 2014
// Last update Wed Mar 19 17:14:09 2014 
//

#ifndef SOUND_ENGINE_HPP
#define SOUND_ENGINE_HPP

class SoundEngine
{
  SoundEngine();
  ~SoundEngine();

private:
  ISoundRenderer*	m_soundRenderer;
};

#endif /* SOUND_ENGINE_HPP */
