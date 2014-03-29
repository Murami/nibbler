//
// Renderer.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 18:05:23 2014 guerot_a
// Last update Sat Mar 29 20:37:54 2014 guerot_a
//

#include <exception>
#include <stdexcept>
#include <dlfcn.h>
#include "Renderer.hpp"

int	Renderer::m_nbInstance = 0;

Renderer::Renderer(const std::string& libpath)
{
  IRenderer*	(*factory)();

  m_libhandle = dlopen(libpath.c_str(), RTLD_LAZY);
  if (!m_libhandle)
    throw std::runtime_error(dlerror());
  factory = (IRenderer* (*)())(dlsym(m_libhandle, "rendererCreate"));
  if (!factory)
    throw std::runtime_error(dlerror());
  m_renderer = factory();
  if (!m_renderer)
    throw std::runtime_error("creation of the renderer failed");
  m_nbInstance++;
}

Renderer::Renderer(const Renderer& renderer)
{
  *this = renderer;
  m_nbInstance++;
}

Renderer::~Renderer()
{
  m_nbInstance--;
  if (m_nbInstance != 0)
    return;
  delete m_renderer;
  if (dlclose(m_libhandle) != 0)
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
