#pragma once
#include <GameEngine\GameEngine.hpp>
class Enemies
{
public:
	Enemies(ge::GameContext& gameContext);
	~Enemies();

	void Initialise();
	void Update(float elapsedTime);
	void Restrictions();
	void Draw(ge::Rendering::SpriteBatch& spriteBatch, ge::Rendering::Camera& camera);

private:
	ge::GameContext& m_gameContext;

	// A sprite
	ge::Rendering::Sprite m_sprite;
	glm::vec2 m_spriteDir;
};

