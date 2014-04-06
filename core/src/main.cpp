//
// main.cpp for  in /home/otoshigami/rendu/cpp_nibbler/core
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:09:53 2014
// Last update Sun Apr  6 12:47:50 2014 
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"

void	nibbler(const std::string& libpath, int width, int height)
{
  Renderer	renderer(libpath, width, height);
  Game		game(renderer, width, height);

  game.run();
}

int	main(int argc, char** argv)
{
  srand(time(NULL));
  try
    {
      if (argc != 4)
	std::cout << "usage: ./nibbler width height renderer-lib.so" << std::endl;
      else
	nibbler(argv[3], atoi(argv[1]), atoi(argv[2]));
    }
  catch (const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
