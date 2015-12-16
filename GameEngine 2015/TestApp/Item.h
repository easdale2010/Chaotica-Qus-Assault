#pragma

#include <GameEngine\GameEngine.hpp>
#include "Player.h"

class Item
{
public:
	Item(ge::GameContext& gameContext, const std::string& name, const glm::vec2& pos);
	~Item();

	void Initialise();
	void Draw(ge::Rendering::SpriteBatch& spriteBatch, ge::Rendering::Camera& camera);
	std::string Item::ToString() const;
private:
	ge::GameContext& m_gameContext;

	std::string m_name;
	glm::vec2 m_pos;
	ge::Rendering::Sprite m_sprite;
};

