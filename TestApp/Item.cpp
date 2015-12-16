#include "Item.h"
#include "Player.h"

Item::Item(ge::GameContext& gameContext, const std::string& name, const glm::vec2& pos) :
	m_name(name),
	m_gameContext(gameContext),
	m_pos(pos)
{
}


Item::~Item()
{
}

void Item::Initialise()
{
	// Initialise our sprite
	const std::string& texture = "Textures/" + m_name + ".png";

	m_sprite.Load(texture,
		m_gameContext,
		glm::vec4(m_pos.x, m_pos.y, 32.0f, 32.0f),
		glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
		ge::Rendering::ColourRGBA8(255, 255, 255, 255),
		true);
}

void Item::Draw(ge::Rendering::SpriteBatch& spriteBatch, ge::Rendering::Camera& camera)
{
	// Only render if we can be seen
	if (camera.IsBoxInView(m_sprite.GetPosition(), m_sprite.GetSize()))
	{
		spriteBatch.Draw(m_sprite);
	}
}

std::string Item::ToString() const
{
	return m_name;
}