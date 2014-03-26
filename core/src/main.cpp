//
// main.cpp for  in /home/otoshigami/rendu/cpp_nibbler/core
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:09:53 2014
// Last update Wed Mar 26 17:51:01 2014 guerot_a
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

  if (argc != 2)
    return (0);

  // open .so
  handle = dlopen(argv[1], RTLD_LAZY);
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
