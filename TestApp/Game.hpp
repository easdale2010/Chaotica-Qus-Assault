#ifndef GAME_HPP
#define GAME_HPP

#include <GameEngine/GameEngine.hpp>

#include "World.h"

class Game
{
public:
	Game();

	int Run();
private:
	void LoadShaders();

	void ProcessInput();
	void Update(float elapsedTime);
	void Render();

	bool m_running = true;

	int m_screenWidth = 1280;
	int m_screenHeight = 720;

	// The context for our game, similiar to XNA ContentManager
	ge::GameContext m_gameContext;

	// Our games window
	ge::Rendering::Window m_window;

	// The texture program we use for shaders and rendering
	ge::Rendering::GLSLProgram m_textureProgram;

	// The camera for our game
	ge::Rendering::Camera m_camera;

	// The spritebatch for our game
	ge::Rendering::SpriteBatch m_spriteBatch;

	World m_world;

	// to keep our game loop in time
	static const ge::Timing::Time TimePerFrame;
};

#endif