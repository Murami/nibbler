//
// GameEngine.hpp for  in /home/otoshigami/rendu/cpp_nibbler
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Wed Mar 19 17:20:58 2014
// Last update Wed Mar 19 18:48:46 2014 
//

#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

typedef std::array<std::array<T> > std::array2<T>

class GameEngine
{
public:
  GameEngine();
  ~GameEngine();

private:
  Player				m_player;
  std::vector<Bot>			m_botArray;
  std::vector<Item>			m_itemArray;
  std::array2<int>			m_TileMap;
};

#endif /* GAME_ENGINE_HPP */
