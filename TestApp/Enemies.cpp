#include "Enemies.h"

Enemies::Enemies(ge::GameContext& gameContext) :
	m_gameContext(gameContext)
{

}

Enemies::~Enemies()
{
}

void Enemies::Initialise()
{
	// Initialise our sprite
	m_sprite.Load("Textures/enemy.png",
		m_gameContext,
		glm::vec4(770.0f, 280.0f, 32.0f, 32.0f),
		glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
		ge::Rendering::ColourRGBA8(255, 255, 255, 255),
		true);
}

void Enemies::Update(float elapsedTime)
{
	// update the player position
	m_sprite.PlayerBoundries(m_spriteDir * 200.0f * elapsedTime);
}

void Enemies::Draw(ge::Rendering::SpriteBatch& spriteBatch, ge::Rendering::Camera& camera)
{
	// Only render if we can be seen
	if (camera.IsBoxInView(m_sprite.GetPosition(), m_sprite.GetSize()))
	{
		spriteBatch.Draw(m_sprite);
	}
}
