#pragma once
#include <GameEngine\GameEngine.hpp>
class Bullet
{
public:
	Bullet(ge::GameContext& gameContext);
	~Bullet();
	void Initialise();
	void ProcessInput(const std::vector<SDL_Event>& events, glm::vec2 getPosition);
	void Update(float elapsedTime);
	void Restrictions();
	void Draw(ge::Rendering::SpriteBatch& spriteBatch, ge::Rendering::Camera& camera);
	glm::vec2 getPosition();
	float getPositionX();
	float getPositionY();
	glm::vec2 getSize();
	float getSizeZ();
	float getSizeW();

	bool pressed = false;
	bool collision = false;
	bool visible = false;

private:
	ge::GameContext& m_gameContext;

	// A sprite
	ge::Rendering::Sprite m_sprite;
	glm::vec2 m_spriteDir;


};

