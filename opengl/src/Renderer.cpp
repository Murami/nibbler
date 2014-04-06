//
// Renderer.cpp for  in /home/otoshigami/rendu/cpp_nibbler/sfml
//
// Made by
// Login   <otoshigami@epitech.net>
//
// Started on  Tue Mar 25 15:22:12 2014
// Last update Sun Apr  6 10:27:03 2014 
//

#include <exception>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include "Renderer.hpp"

namespace API
{
  Renderer::Renderer(int width, int height) :
    m_window(),
    m_height(height),
    m_width(width)
  {
    initWindow(width, height);
    initGL();
    initRessources();
    initBinds();
  }


  Renderer::~Renderer()
  {
  }

  void	Renderer::close()
  {
    m_window.Close();
  }

  bool	Renderer::isOpen() const
  {
    return (m_window.IsOpened());
  }

  bool	Renderer::getEvent(Event& eventRcv) const
  {
    std::map<sf::Event::EventType, Event::EventType>::const_iterator	itType;
    std::map<sf::Key::Code, Key::Code>::const_iterator			itKey;
    sf::Event	event;

    if (!m_window.GetEvent(event))
      return (false);
    eventRcv.type = Event::None;
    eventRcv.key = Key::None;
    for (itType = eventBinds.begin(); itType != eventBinds.end(); itType++)
      {
	if ((*itType).first == event.Type)
	  eventRcv.type = (*itType).second;
      }

    if (event.Type == sf::Event::KeyPressed ||
	event.Type == sf::Event::KeyReleased)
      {
	for (itKey = eventKeyBinds.begin(); itKey != eventKeyBinds.end(); itKey++)
	  {
	    if ((*itKey).first == event.Key.Code)
	      eventRcv.key = (*itKey).second;
	  }
      }
    return (true);
  }

  void	Renderer::updateCam(int x, int y, int xdir, int ydir)
  {
    glPushMatrix();
    gluLookAt(x - xdir * 10 + abs(ydir) * 0.5,
	      y - ydir * 10 + abs(xdir) * 0.5,
	      6,
    	      x + xdir * 5,
	      y + ydir * 5,
	      0,
    	      0, 0, 1);
    glPushMatrix();
  }

  void	Renderer::clear() const
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glColor3d(255, 255, 255);
  }

  void	Renderer::update() const
  {
    drawLimit();
    glPopMatrix();
    glPopMatrix();
    m_window.Display();
  }

  ///////////
  // DRAWS //
  ///////////

  void	Renderer::draw(const std::string& ressource, int x, int y,
		       int rotation) const
  {
    (void) rotation;

    glDisable(GL_BLEND);
    enableTexture(ressource);

    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    // glRotatef(180, 0, 0, 1);
    glScalef(1, -1, 0);
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_QUADS);
    drawTop(x, y);
    drawBottom(x, y);
    drawLeft(x, y);
    drawRight(x, y);
    drawBack(x, y);
    drawFront(x, y);
    glEnd();

    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    disableTexture();
    glEnable(GL_BLEND);
  }

  void	Renderer::drawBackground(int width, int height) const
  {
    (void) width;
    (void) height;
    drawGround();
    drawSkybox();
  }

  void	Renderer::drawBoost(int boost, int boostmax) const
  {
    (void) boost;
    (void) boostmax;
  }

  void	Renderer::drawScore(int score) const
  {
    (void) score;
  }

  ///////////
  // INITS //
  ///////////

  void	Renderer::initWindow(int width, int height)
  {
    sf::WindowSettings	settings;

    if (width > 200 || height > 200)
      throw std::runtime_error("cannot create a windows with a size higher than 200x200");

    settings.DepthBits = 24;
    settings.StencilBits = 8;
    settings.AntialiasingLevel = 16;
    m_window.Create(sf::VideoMode(1400, 1000, 32), "Nibbler", sf::Style::Close, settings);
    m_window.SetFramerateLimit(0);
    m_window.EnableKeyRepeat(false);
  }

  void	Renderer::initGL()
  {
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthMask(GL_TRUE);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f, 1.f, 0.1f, 2000.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
  }

  void	Renderer::initRessources()
  {
    std::string		str;

    loadTexture("head", "opengl/assets/sprites/snake.jpg");
    loadTexture("apple", "opengl/assets/sprites/apple.png");
    loadTexture("invul", "opengl/assets/sprites/invul.png");
    loadTexture("mulScore", "opengl/assets/sprites/mul.png");
    loadTexture("mul", "opengl/assets/sprites/mul.png");
    loadTexture("mulLimb", "opengl/assets/sprites/mulLimb.png");
    loadTexture("wall", "opengl/assets/sprites/wall.png");
    loadTexture("invertBoost", "opengl/assets/sprites/boost.png");
    loadTexture("ground", "opengl/assets/sprites/ground.bmp");
    loadTexture("skybox", "opengl/assets/sprites/skybox2.png");
    loadTexture("limit", "opengl/assets/sprites/limit.png");
    for (int i = 0; i <= 48; i++)
      {
	str = toString(i);
	m_textures[str] = m_textures["head"];
      }
   }

  void	Renderer::initBinds()
  {
    eventBinds[sf::Event::Closed] = Event::Closed;
    eventBinds[sf::Event::KeyPressed] = Event::KeyPressed;
    eventBinds[sf::Event::KeyReleased] = Event::KeyReleased;
    eventKeyBinds[sf::Key::Left] = Key::Left;
    eventKeyBinds[sf::Key::Right] = Key::Right;
    eventKeyBinds[sf::Key::Space] = Key::Space;
    eventKeyBinds[sf::Key::Escape] = Key::Escape;
    eventKeyBinds[sf::Key::Return] = Key::Return;
  }

  void	Renderer::drawGround() const
  {
    enableTexture("ground");

    glBegin(GL_QUADS);
    glTexCoord2d(8000, 0);
    glVertex3d(4000, -4000, 0);
    glTexCoord2d(8000, 8000);
    glVertex3d(4000, 4000, 0);
    glTexCoord2d(0, 8000);
    glVertex3d(-4000, 4000, 0);
    glTexCoord2d(0, 0);
    glVertex3d(-4000, -4000, 0);
    glEnd();

    disableTexture();
  }

  /////////////////
  // DRAW LIMITS //
  /////////////////

  void	Renderer::drawLimit() const
  {
    enableTexture("limit");

    glBegin(GL_QUADS);
    drawLimitNorthInside();
    drawLimitNorthTop();
    drawLimitNorthOutside();
    drawLimitSouthInside();
    drawLimitSouthTop();
    drawLimitSouthOutside();
    drawLimitEstInside();
    drawLimitEstTop();
    drawLimitEstOutside();
    drawLimitWestInside();
    drawLimitWestTop();
    drawLimitWestOutside();
    glEnd();

    disableTexture();
  }

  void	Renderer::drawLimitNorthInside() const
  {
    glTexCoord2d(m_width, 0);
    glVertex3d(m_width, m_height, 0);
    glTexCoord2d(m_width, 1);
    glVertex3d(m_width, m_height, 4);
    glTexCoord2d(0, 1);
    glVertex3d(0, m_height, 4);
    glTexCoord2d(0, 0);
    glVertex3d(0, m_height, 0);
  }

  void	Renderer::drawLimitNorthTop() const
  {
    glTexCoord2d(-1, 0);
    glVertex3d(-1, m_height + 1, 4);
    glTexCoord2d(-1, 1);
    glVertex3d(-1, m_height, 4);
    glTexCoord2d(m_width + 1, 1);
    glVertex3d(m_width + 1, m_height, 4);
    glTexCoord2d(m_width + 1, 0);
    glVertex3d(m_width + 1, m_height + 1, 4);
  }

  void	Renderer::drawLimitNorthOutside() const
  {
    glTexCoord2d(-1, 0);
    glVertex3d(-1, m_height + 1, 0);
    glTexCoord2d(-1, 1);
    glVertex3d(-1, m_height + 1, 4);
    glTexCoord2d(m_width + 1, 1);
    glVertex3d(m_width + 1, m_height + 1, 4);
    glTexCoord2d(m_width + 1, 0);
    glVertex3d(m_width + 1, m_height + 1, 0);
  }

  void	Renderer::drawLimitSouthInside() const
  {
    glTexCoord2d(0, 1);
    glVertex3d(0, 0, 4);
    glTexCoord2d(m_width, 1);
    glVertex3d(m_width, 0, 4);
    glTexCoord2d(m_width, 0);
    glVertex3d(m_width, 0, 0);
    glTexCoord2d(0, 0);
    glVertex3d(0, 0, 0);
  }

  void	Renderer::drawLimitSouthTop() const
  {
    glTexCoord2d(-1, 0);
    glVertex3d(-1, 0, 4);
    glTexCoord2d(-1, 1);
    glVertex3d(-1, -1, 4);
    glTexCoord2d(m_width + 1, 1);
    glVertex3d(m_width + 1, -1, 4);
    glTexCoord2d(m_width + 1, 0);
    glVertex3d(m_width + 1, 0, 4);
  }

  void	Renderer::drawLimitSouthOutside() const
  {
    glTexCoord2d(m_width + 1, 0);
    glVertex3d(m_width + 1, -1, 0);
    glTexCoord2d(m_width + 1, 1);
    glVertex3d(m_width + 1, -1, 4);
    glTexCoord2d(-1, 1);
    glVertex3d(-1, -1, 4);
    glTexCoord2d(-1, 0);
    glVertex3d(-1, -1, 0);
  }

  void	Renderer::drawLimitEstInside() const
  {
    glTexCoord2d(0, 0);
    glVertex3d(m_width, 0, 0);
    glTexCoord2d(0, 1);
    glVertex3d(m_width , 0, 4);
    glTexCoord2d(m_height, 1);
    glVertex3d(m_width , m_height, 4);
    glTexCoord2d(m_height, 0);
    glVertex3d(m_width, m_height, 0);
  }

  void	Renderer::drawLimitEstTop() const
  {
    glTexCoord2d(0, 0);
    glVertex3d(m_width , 0, 4);
    glTexCoord2d(0, 1);
    glVertex3d(m_width + 1 , 0, 4);
    glTexCoord2d(m_height, 1);
    glVertex3d(m_width + 1, m_height, 4);
    glTexCoord2d(m_height, 0);
    glVertex3d(m_width, m_height, 4);
  }

  void	Renderer::drawLimitEstOutside() const
  {
    glTexCoord2d(m_height + 1, 0);
    glVertex3d(m_width + 1, m_height + 1, 0);
    glTexCoord2d(m_height + 1, 1);
    glVertex3d(m_width + 1, m_height + 1, 4);
    glTexCoord2d(-1, 1);
    glVertex3d(m_width + 1, -1, 4);
    glTexCoord2d(-1, 0);
    glVertex3d(m_width + 1, -1, 0);
  }

  void	Renderer::drawLimitWestInside() const
  {
    glTexCoord2d(m_width, 0);
    glVertex3d(0, m_height, 0);
    glTexCoord2d(m_width, 1);
    glVertex3d(0, m_height, 4);
    glTexCoord2d(0, 1);
    glVertex3d(0, 0, 4);
    glTexCoord2d(0, 0);
    glVertex3d(0, 0, 0);
  }

  void	Renderer::drawLimitWestTop() const
  {
    glTexCoord2d(0, 0);
    glVertex3d(-1, 0, 4);
    glTexCoord2d(0, 1);
    glVertex3d(0 , 0, 4);
    glTexCoord2d(m_height, 1);
    glVertex3d(0, m_height, 4);
    glTexCoord2d(m_height, 0);
    glVertex3d(-1, m_height, 4);
  }

  void	Renderer::drawLimitWestOutside() const
  {
    glTexCoord2d(-1, 0);
    glVertex3d(-1, -1, 0);
    glTexCoord2d(-1, 1);
    glVertex3d(-1 , -1, 4);
    glTexCoord2d(m_height + 1, 1);
    glVertex3d(-1, m_height + 1, 4);
    glTexCoord2d(m_height + 1, 0);
    glVertex3d(-1, m_height + 1, 0);
  }

  /////////////////
  // DRAW SKYBOX //
  /////////////////

  void	Renderer::drawSkybox() const
  {
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glRotatef(180, 0, 0, 1);
    glTranslatef(0.5, 0, 0);
    glScalef(2, 1, 0);
    glMatrixMode(GL_MODELVIEW);
    enableTexture("skybox");

    glBegin(GL_QUADS);
    drawSkyboxNorth();
    drawSkyboxSouth();
    drawSkyboxWest();
    drawSkyboxEst();
    glEnd();

    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
  }

  void	Renderer::drawSkyboxNorth() const
  {
    glTexCoord2d(1, 0);
    glVertex3f(1000, 1000, 0);
    glTexCoord2d(1, 1);
    glVertex3f(1000, 1000, 1038);
    glTexCoord2d(0, 1);
    glVertex3f(-1000, 1000, 1038);
    glTexCoord2d(0, 0);
    glVertex3f(-1000, 1000, 0);

  }

  void	Renderer::drawSkyboxSouth() const
  {
    glTexCoord2d(1, 1);
    glVertex3f( 1000, -1000, 1038);
    glTexCoord2d(1, 0);
    glVertex3f( 1000, -1000, 0);
    glTexCoord2d(0, 0);
    glVertex3f(-1000, -1000, 0);
    glTexCoord2d(0, 1);
    glVertex3f(-1000, -1000, 1038);
  }

  void	Renderer::drawSkyboxEst() const
  {
    glTexCoord2d(1, 0);
    glVertex3f(1000, -1000, 0);
    glTexCoord2d(1, 1);
    glVertex3f(1000, -1000, 1038);
    glTexCoord2d(0, 1);
    glVertex3f(1000, 1000, 1038);
    glTexCoord2d(0, 0);
    glVertex3f(1000, 1000, 0);
  }

  void	Renderer::drawSkyboxWest() const
  {
    glTexCoord2d(0, 0);
    glVertex3f(-1000, 1000, 0);
    glTexCoord2d(0, 1);
    glVertex3f(-1000, 1000, 1038);
    glTexCoord2d(1, 1);
    glVertex3f(-1000, -1000, 1038);
    glTexCoord2d(1, 0);
    glVertex3f(-1000, -1000, 0);
  }

  ////////////////////////////////////////////
  // DRAWS FOR GENERIC DRAW BY RESSOURCE ID //
  ////////////////////////////////////////////
  void	Renderer::drawTop(int x, int y) const
  {
    glTexCoord2d(1, 0);
    glVertex3f(x + 0.8,	y, 1.3);
    glTexCoord2d(1, 1);
    glVertex3f(x + 0.8,	y + 0.8, 1.3);
    glTexCoord2d(0, 1);
    glVertex3f(x, y + 0.8, 1.3);
    glTexCoord2d(0, 0);
    glVertex3f(x, y, 1.3);
  }

  void	Renderer::drawBottom(int x, int y) const
  {
    glTexCoord2d(1, 0);
    glVertex3f(x + 0.8,	y, 0.3);
    glTexCoord2d(1, 1);
    glVertex3f(x + 0.8,	y + 0.8, 0.3);
    glTexCoord2d(0, 1);
    glVertex3f(x, y + 0.8, 0.3);
    glTexCoord2d(0, 0);
    glVertex3f(x, y, 0.3);
  }

  void	Renderer::drawLeft(int x, int y) const
  {
    glTexCoord2d(0, 0);
    glVertex3f(x, y, 0.3);
    glTexCoord2d(1, 0);
    glVertex3f(x + 0.8,	y, 0.3);
    glTexCoord2d(1, 1);
    glVertex3f(x + 0.8,	y, 1.3);
    glTexCoord2d(0, 1);
    glVertex3f(x, y, 1.3);
  }

  void	Renderer::drawRight(int x, int y) const
  {
    glTexCoord2d(0, 0);
    glVertex3f(x,	y + 0.8,0.3);
    glTexCoord2d(0, 1);
    glVertex3f(x,	y + 0.8,1.3);
    glTexCoord2d(1, 1);
    glVertex3f(x + 0.8,	y + 0.8,1.3);
    glTexCoord2d(1, 0);
    glVertex3f(x + 0.8,	y + 0.8,0.3);
  }

  void	Renderer::drawBack(int x, int y) const
  {
    glTexCoord2d(0, 0);
    glVertex3f(x,	y,	0.3);
    glTexCoord2d(0, 1);
    glVertex3f(x,	y,	1.3);
    glTexCoord2d(1, 1);
    glVertex3f(x,	y + 0.8,1.3);
    glTexCoord2d(1, 0);
    glVertex3f(x,	y + 0.8,0.3);
  }

  void	Renderer::drawFront(int x, int y) const
  {
    glTexCoord2d(1, 0);
    glVertex3f(x + 0.8,	y + 0.8,0.3);
    glTexCoord2d(1, 1);
    glVertex3f(x + 0.8,	y + 0.8,1.3);
    glTexCoord2d(0, 1);
    glVertex3f(x + 0.8,	y,	1.3);
    glTexCoord2d(0, 0);
    glVertex3f(x + 0.8,	y,	0.3);
  }

  //////////////////////
  // TEXTURE HANDLERS //
  //////////////////////

  void	Renderer::loadTexture(const std::string& name, const std::string& filepath)
  {
    GLuint	glid;
    sf::Image	image;

    image.LoadFromFile(filepath);
    glGenTextures(1, &glid);
    glBindTexture(GL_TEXTURE_2D, glid);
    glTexParameteri(GL_TEXTURE_2D,
		    GL_TEXTURE_MAG_FILTER,
		    GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,
		    GL_TEXTURE_MIN_FILTER,
		    GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    gluBuild2DMipmaps(GL_TEXTURE_2D,
		      GL_RGBA,
		      image.GetWidth(),
		      image.GetHeight(),
		      GL_RGBA,
		      GL_UNSIGNED_BYTE,
		      image.GetPixelsPtr());
    m_textures[name] = glid;
  }

  void	Renderer::enableTexture(const std::string& name) const
  {
    glBindTexture(GL_TEXTURE_2D, m_textures.at(name));
  }

  void	Renderer::disableTexture() const
  {
    glBindTexture(GL_TEXTURE_2D, 0);
  }

  ///////////
  // UTILS //
  ///////////

  std::string	Renderer::toString(int i) const
  {
    std::stringstream   ss;

    ss << i;
    return (ss.str());
  }
};

///////////////
// C FACTORY //
///////////////

API::IRenderer*	createRenderer(int width, int height)
{
  return (new API::Renderer(width, height));
}
