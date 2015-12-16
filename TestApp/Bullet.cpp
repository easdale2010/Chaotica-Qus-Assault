#include "Bullet.h"

Bullet::Bullet(ge::GameContext& gameContext) :
	m_gameContext(gameContext)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialise()
{
	// Initialise our sprite
	m_sprite.Load("Textures/Rbullet.png",
		m_gameContext,
		glm::vec4(300,220, 24.16f, 6.4f),
		glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
		ge::Rendering::ColourRGBA8(255, 255, 255, 255),
		true);
}

void Bullet::ProcessInput(const std::vector<SDL_Event>& events, glm:: vec2 getPosition)
{
	// Add all the events to the event manager
	auto& inputManager = m_gameContext.GetInputManager();

	inputManager.Update(events);

	if (inputManager.IsKeyPressed(SDLK_SPACE) &! visible)
	{
		m_sprite.pressed = true;
		visible = true;
		m_sprite.SetPosition(getPosition);
	}

	if (visible)
	{
		if (m_sprite.GetPositionX() <= -50) 
		{
			m_sprite.SetPosition(getPosition);
			m_sprite.pressed = false;
			visible = false;
		}
	}
}

glm::vec2 Bullet::getPosition(){ return m_sprite.GetPosition(); }

float Bullet::getPositionX(){ return m_sprite.GetPositionX(); }

float Bullet::getPositionY(){ return m_sprite.GetPositionY(); }

glm::vec2 Bullet::getSize(){ return m_sprite.GetSize(); }

float Bullet::getSizeZ(){ return m_sprite.GetSizeZ(); }

float Bullet::getSizeW(){ return m_sprite.GetSizeW(); }

void Bullet::Update(float elapsedTime)
{
	// update the player position
	m_sprite.BulletBoundries(m_spriteDir * 200.0f * elapsedTime);
	if(m_sprite.pressed && visible)
		m_sprite.Move2();
//	m_sprite.pressed = false;

}

void Bullet::Draw(ge::Rendering::SpriteBatch& spriteBatch, ge::Rendering::Camera& camera)
{
	// Only render if we can be seen
	if (camera.IsBoxInView(m_sprite.GetPosition(), m_sprite.GetSize()))
	{
		if (visible)
			spriteBatch.Draw(m_sprite);
	}
}
