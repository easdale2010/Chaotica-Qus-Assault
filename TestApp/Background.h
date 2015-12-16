#pragma once
#include <GameEngine\GameEngine.hpp>
class Background
{
public:
	Background(ge::GameContext& gameContext);
	~Background();

	void Initialise();
	void Update(float elapsedTime);
	void Draw(ge::Rendering::SpriteBatch& spriteBatch, ge::Rendering::Camera& camera);

private:
	ge::GameContext& m_gameContext;

	// A sprite
	ge::Rendering::Sprite m_sprite;
	glm::vec2 m_spriteDir;
};

