#include "Player.h"

Player::Player(ge::GameContext& gameContext) : 
	m_gameContext(gameContext)
{

}

Player::~Player()
{
}

void Player::Initialise()
{
	// Initialise our sprite
	m_sprite.Load("Textures/player.png", 
		m_gameContext, 
		glm::vec4(770.0f, 280.0f, 50.0f, 32.0f), 
		glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
		ge::Rendering::ColourRGBA8(255, 255, 255, 255), 
		false);
}

void Player::ProcessInput(const std::vector<SDL_Event>& events)
{
	// Add all the events to the event manager
	auto& inputManager = m_gameContext.GetInputManager();

	inputManager.Update(events);

	// change the sprite direction depending on what key is pressed
	m_spriteDir = glm::vec2(0.0f);
	
	
	if (inputManager.IsKeyPressed(SDLK_w) )
	{
		m_spriteDir.y = -1.0f;
	}
	else if (inputManager.IsKeyPressed(SDLK_s))
	{
		m_spriteDir.y = 1.0f;
	}

	if (inputManager.IsKeyPressed(SDLK_a))
	{
		m_spriteDir.x = -1.0f;
	}
	else if (inputManager.IsKeyPressed(SDLK_d))
	{
		m_spriteDir.x = 1.0f;
	}
	

}

glm::vec2 Player::getPosition() {
	return m_sprite.GetPosition();
}

float Player::getPositionX() {
	return m_sprite.GetPositionX();
}

float Player::getPositionY() {
	return m_sprite.GetPositionY();
}

glm::vec2 Player::getSize() {
	return m_sprite.GetSize();
}

float Player::getSizeZ() {
	return m_sprite.GetSizeZ();
}

float Player::getSizeW() {
	return m_sprite.GetSizeW();
}



void Player::Update(float elapsedTime)
{
	// update the player position
	m_sprite.PlayerBoundries(m_spriteDir * 200.0f * elapsedTime);
	//m_spriteBullet.BulletBoundries(m_spriteBulletDir * 200.0f * elapsedTime);
}

void Player::Draw(ge::Rendering::SpriteBatch& spriteBatch, ge::Rendering::Camera& camera)
{
	// Only render if we can be seen
	if (camera.IsBoxInView(m_sprite.GetPosition(), m_sprite.GetSize()))
	{
		spriteBatch.Draw(m_sprite);
	}
}
