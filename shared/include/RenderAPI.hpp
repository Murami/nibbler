//
// RenderAPI.hpp for  in /home/otoshigami/rendu/cpp_nibbler/shared/include
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:15:40 2014
// Last update Tue Mar 25 16:55:07 2014 
//

#ifndef RENDERAPI_HPP
#define RENDERAPI_HPP

class	IRenderer
{
public:
  virtual ~IRenderer() {};
  virtual void	init() = 0;
  virtual void	renderBlank() const = 0;
  virtual bool	isOpen() const = 0;
};

#endif /* RENDERAPI_HPP */
