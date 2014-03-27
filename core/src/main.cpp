//
// main.cpp for  in /home/otoshigami/rendu/cpp_nibbler/core
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:09:53 2014
// Last update Thu Mar 27 13:40:43 2014 guerot_a
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
    {
      std::cerr << "missing argument" << std::endl;
      return (-1);
    }

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

  //////////////////////

  int	x = 0;
  int	y = 3;

  IRenderer* renderer = factory();
  while (renderer->isOpen())
    {
      switch(renderer->getEvent())
	{
	case CLOSE:
	  renderer->close();
	  break;

	case RIGHT:
	  x++;
	  break;

	case LEFT:
	  x--;
	  break;
	}
      if (renderer->getEvent() == CLOSE)
  	{
  	  renderer->close();
  	}
      renderer->clear();
      renderer->drawSnakeHead(x, y);
      renderer->update();
    }
  dlclose(handle);
  delete renderer;
  return (0);
}
