//
// Renderer.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 18:05:23 2014 guerot_a
// Last update Sat Mar 29 18:22:21 2014 guerot_a
//

#include "Renderer.hpp"

Renderer::Renderer(const std::string& libpath)
{
  void*	(*factory)();

  m_libhandle = dlopen(libpath.c_str(), RTLD_LAZY);
  if (!m_libhandle)
    throw std::runtime_error(dlerror());
  factory = dlsym("rendererCreate");
  if (!factory)
    throw std::runtime_error(dlerror());
  m_renderer = factory();
  if (!m_renderer)
    throw std::runtime_error("creation of the renderer failed");
}

Renderer::Renderer(const Renderer& renderer)
{
  *this = renderer;
}

Renderer::~Renderer()
{
  delete m_renderer;
  if (dlclose(libhandle) != 0)
    throw std::runtime_error("dlclose failed");
}

Renderer&	Renderer::operator=(const Renderer& renderer)
{
  m_renderer = renderer.m_renderer;
  m_libhandle = renderer.m_libhandle;

  return (*this);
}

IRenderer*	Renderer::operator->()
{
  return (m_renderer);
}
