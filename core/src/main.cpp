//
// main.cpp for  in /home/otoshigami/rendu/cpp_nibbler/core
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:09:53 2014
// Last update Tue Mar 25 17:02:02 2014 
//

#include <iostream>
#include <cstdlib>
#include <dlfcn.h>
#include "RenderAPI.hpp"

typedef   IRenderer*	(*renderFactory)() ;

int	main()
{
  renderFactory	factory;
  void*		handle;

  // open .so
  handle = dlopen("../sfml/bin/sfml-renderer.so", RTLD_NOW);
  if (handle == NULL)
    {
      std::cerr << "dlopen failed !" << std::endl;
      return (-1);
    }

  // load library
  factory = (renderFactory)dlsym(handle, "createRenderer");
  if (factory == NULL)
    {
      std::cerr << "dlsym failed !" << std::endl;
      return (-1);
    }

  IRenderer* renderer = factory();
  renderer->init();
  while (renderer->isOpen())
    {
      renderer->renderBlank();
    }
  delete renderer;
  return (0);
}
