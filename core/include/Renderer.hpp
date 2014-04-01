//
// Renderer.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 17:59:15 2014 guerot_a
// Last update Tue Apr  1 15:09:16 2014 guerot_a
//

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <string>
#include "IRenderer.hpp"

class Renderer
{
public:
  Renderer(const std::string& libpath, int width, int height);
  Renderer(const Renderer& renderer);
  ~Renderer();

  Renderer&		operator=(const Renderer& renderer);

  API::IRenderer*	operator->();

private:
  void*			m_libhandle;
  API::IRenderer*	m_renderer;
  static int		m_nbInstance;
};

#endif /* RENDERER_HPP */
