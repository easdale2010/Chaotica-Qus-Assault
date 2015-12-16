#pragma once
#include <GameEngine\GameEngine.hpp>
#include < time.h>

class Player
{
public:
	Player(ge::GameContext& gameContext);
	~Player();
	void Initialise();
	void ProcessInput(const std::vector<SDL_Event>& events);
	void Update(float elapsedTime);
	void Restrictions();
	void Draw(ge::Rendering::SpriteBatch& spriteBatch, ge::Rendering::Camera& camera);
	glm::vec2 getPosition();
	float getPositionX();
	float getPositionY();
	glm::vec2 getSize();
	float getSizeZ();
	float getSizeW();
	bool invincible = false;
	float invCooldown = 2.5;
	int score = 0;
	int lives = 10;


	bool collision = false;

private:
	ge::GameContext& m_gameContext;

	// A sprite
	ge::Rendering::Sprite m_sprite;
	glm::vec2 m_spriteDir;
};

