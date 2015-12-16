#include "Background.h"

Background::Background(ge::GameContext& gameContext) :
	m_gameContext(gameContext)
{

}

Background::~Background()
{
}

void Background::Initialise()
{
	// Initialise our sprite
	m_sprite.Load("Textures/Space1.1.png",
		m_gameContext,
		glm::vec4(0.0f, 0.0f, 800.0f, 600.0f),
		glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
		ge::Rendering::ColourRGBA8(255, 255, 255, 255),
		true);
}


void Background::Update(float elapsedTime)
{
	// update the player position
	glm::vec2 moveBackground(0.5f, 0);
	m_sprite.Move(moveBackground);
}

void Background::Draw(ge::Rendering::SpriteBatch& spriteBatch, ge::Rendering::Camera& camera)
{
	// Only render if we can be seen
	if (camera.IsBoxInView(m_sprite.GetPosition(), m_sprite.GetSize()))
	{
		spriteBatch.Draw(m_sprite);
	}
}
