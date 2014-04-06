//
// Renderer.cpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Sat Mar 29 18:05:23 2014 guerot_a
// Last update Sun Apr  6 22:53:11 2014 
//

#include <exception>
#include <stdexcept>
#include <dlfcn.h>
#include "Renderer.hpp"

int	Renderer::m_nbInstance = 0;

Renderer::Renderer(const std::string& libpath, int width, int height)
{
  API::IRenderer*	(*factory)(int, int);
  std::string		path;

  path = libpath;
  if (path.compare(0, 2, "./") != 0 && path.compare(0, 1, "/") != 0)
    path = "./" + path;
  m_libhandle = dlopen(path.c_str(), RTLD_LAZY);
  if (!m_libhandle)
    throw std::runtime_error(dlerror());
  factory = (API::IRenderer* (*)(int, int))(dlsym(m_libhandle, "createRenderer"));
  if (!factory)
    throw std::runtime_error(dlerror());
  m_renderer = factory(width, height);
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

API::IRenderer*	Renderer::operator->()
{
  return (m_renderer);
}

API::IRenderer*	Renderer::operator->() const
{
  return (m_renderer);
}
