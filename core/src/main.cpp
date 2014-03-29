//
// main.cpp for  in /home/otoshigami/rendu/cpp_nibbler/core
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:09:53 2014
// Last update Sat Mar 29 22:48:04 2014 guerot_a
//

#include <iostream>
#include <cstdlib>
#include "Game.hpp"

void	nibbler(const std::string& libpath, int width, int height)
{
  Renderer	renderer(libpath);
  Game		game(renderer, width, height);

  game.run();
}

int	main(int argc, char** argv)
{
  try
    {
      if (argc != 4)
	std::cout << "usage: ./nibbler width height renderer-lib.so" << std::endl;
      else
	nibbler(argv[4], atoi(argv[2]), atoi(argv[3]));
    }
  catch (const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
