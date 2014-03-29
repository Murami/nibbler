//
// main.cpp for  in /home/otoshigami/rendu/cpp_nibbler/core
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:09:53 2014
// Last update Sat Mar 29 17:58:51 2014 guerot_a
//

#include <iostream>
#include <cstdlib>
#include <dlfcn.h>
#include "RenderAPI.hpp"

#include "Vector2.hpp"

void	nibbler(const std::string& libpath)
{
  Game		game(Renderer(libpath));

  game.run();
}

int	main(int argc, char** argv)
{
  try
    {
      if (argc != 2)
	std::cout << "Usage: ./nibbler renderer-lib.so" << std::endl;
      else
	nibbler(argv[2]);
    }
  catch (const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
