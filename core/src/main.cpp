//
// main.cpp for  in /home/otoshigami/rendu/cpp_nibbler/core
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:09:53 2014
// Last update Tue Mar 25 19:13:48 2014 
//

#include <iostream>
#include <cstdlib>
#include <dlfcn.h>
#include "RenderAPI.hpp"

typedef   IRenderer*	(*renderFactory)() ;

int	main(int argc, char** argv)
{
  renderFactory	factory;
  void*		handle;

  // open .so
  handle = dlopen("../sfml/bin/sfml-renderer.so", RTLD_LAZY);
  if (handle == NULL)
    {
      std::cerr << dlerror() << std::endl;
      return (-1);
    }

  // load library
  factory = (renderFactory)dlsym(handle, "createRenderer");
  if (factory == NULL)
    {
      std::cerr << dlerror() << std::endl;
      return (-1);
    }

  IRenderer* renderer = factory();
  while (renderer->isOpen())
    {
      if (renderer->getEvent() == CLOSE)
	{
	  renderer->close();
	}
      renderer->clear();
    }
  dlclose(handle);
  delete renderer;
  return (0);
}
