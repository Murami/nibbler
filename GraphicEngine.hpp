//
// GraphicEngine.hpp for  in /home/otoshigami/rendu/cpp_nibbler
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Wed Mar 19 17:08:02 2014
// Last update Wed Mar 19 17:11:27 2014 
//

#ifndef GRAPHIC_ENGINE_HPP
#define GRAPHIC_ENGINE_HPP

class GraphicEngine
{
public:
  GraphicEngine();
  ~GraphicEngine();

  /*
  ** Graphic engine modules
  */
private:
  IEventHandler*	m_eventHandler;
  IScene*		m_scene;
  IGUI*			m_GUI;
};

#endif /* GRAPHIC_ENGINE_HPP */
