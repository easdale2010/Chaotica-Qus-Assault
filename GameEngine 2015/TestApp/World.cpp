 #include "World.h"
#include <time.h>
#include <iostream>

using namespace std;

World::World(ge::GameContext& gameContext) :
m_gameContext(gameContext),
m_player(gameContext),
m_playerBullet(gameContext),
m_Background(gameContext),
m_enemies(gameContext)
{
}

World::~World()
{
}

void World::Initialise()
{
	for (int i = 0; i < 2; i++)
	{
		m_sprite[i].Load("Textures/stars.png",
			m_gameContext,
			glm::vec4(-1280.0f * i, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);
	}
	
	int size = -1280.0f;
		// Initialise our sprite
		m_sprite1.Load("Textures/Background1.png",
			m_gameContext,
			glm::vec4(size * 10, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);

		/*m_sprite2.Load("Textures/Background1flare.png",
			m_gameContext,
			glm::vec4(size * 6, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);


		m_sprite3.Load("Textures/Clouds.png",
			m_gameContext,
			glm::vec4(size * 10, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);	

		m_sprite4.Load("Textures/Gasblue.png",
			m_gameContext,
			glm::vec4(size * 15, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);

		m_sprite5.Load("textures/GasOrange.png",
			m_gameContext,
			glm::vec4(size * 16, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);

		m_sprite6.Load("Textures/GasPurple.png",
			m_gameContext,
			glm::vec4(size * 17, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);

		m_sprite7.Load("Textures/MettalicWithflare.png",
			m_gameContext,
			glm::vec4(size * 18, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);

		m_sprite8.Load("Textures/MettalicWithflare2.png",
			m_gameContext,
			glm::vec4(size * 19, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);

		m_sprite9.Load("Textures/MettalicWithflare21.png",
			m_gameContext,
			glm::vec4(size * 20, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);	

		m_sprite10.Load("Textures/MettalicWithoutflare.png",
			m_gameContext,
			glm::vec4(size * 24, 0.0f, 1280.0f, 720.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);*/
	

	// Add some more items to our item list here
	for (int i = 0; i < 8; i++)
	{
		Item& key = Item(m_gameContext, "Key", glm::vec2(i * 150, i * 75));
		key.Initialise();
		m_items.push_back(key);
	}

	/* initialize random seed: */
	srand(time(NULL));
	/* generate secret number between 1 and 10: */

	for (int i = 0; i < 100; i++)
	{
		//int eXPosition = rand() % 12800;
		int eXPosition = rand() % -size * 10;

		int eYPosition = rand() % 710;
		m_Enemies[i].Load("Textures/enemy.png",
			m_gameContext,
			glm::vec4(-eXPosition, eYPosition, 60.0f, 30.0f),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
			ge::Rendering::ColourRGBA8(255, 255, 255, 255),
			true);
	}
	//for (int i = 0; i < 100; i++)
	//{
	//	int eXPosition = rand() % 12800;
	//	int eYPosition = rand() % 710;
	//	m_Enemies2[i].Load("Textures/test.png",
	//		m_gameContext,
	//		glm::vec4(-eXPosition, eYPosition, 32.0f, 32.0f),
	//		glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.0f, 0.0f,
	//		ge::Rendering::ColourRGBA8(255, 255, 255, 255),
	//		true);
	//}

	m_player.Initialise();
	m_playerBullet.Initialise();
}

void World::ProcessInput(std::vector<SDL_Event> events)
{
	m_player.ProcessInput(events);
	m_playerBullet.ProcessInput(events, m_player.getPosition());

}

void World::Update(float elapsedTime)
{
	// Update the player here
	m_player.Update(elapsedTime);
	m_playerBullet.Update(elapsedTime);
	glm::vec2 coOfEnemies(10.0f, 0);
	glm::vec2 coOfEnemies2(10.0f, 0);
	glm::vec2 coOfBackgrounds(8.0f,0);
	m_sprite1.Move(coOfBackgrounds);
	m_sprite2.Move(coOfBackgrounds);
	m_sprite3.Move(coOfBackgrounds);
	m_sprite4.Move(coOfBackgrounds);
	m_sprite5.Move(coOfBackgrounds);
	m_sprite6.Move(coOfBackgrounds);
	m_sprite7.Move(coOfBackgrounds);
	m_sprite8.Move(coOfBackgrounds);
	m_sprite9.Move(coOfBackgrounds);
	m_sprite10.Move(coOfBackgrounds);

	//m_sprite2.Move(coOfBackgrounds);
	for (int i = 0; i < 2; i++)
	{
		m_sprite[i].Move(coOfBackgrounds);

	}

	for (int i = 0; i < 100; i++)
	{
		m_Enemies[i].Move(coOfEnemies);
		m_Enemies2[i].Move(coOfEnemies2);

	}
	if (m_player.invincible && m_player.invCooldown > 0)
	{
		m_player.invCooldown -= elapsedTime;

		if (m_player.invCooldown <= 0) {
			m_player.invincible = false;
			m_player.invCooldown = 0;
			m_player.collision = false;
		}
	}
	
	CheckCollisions();
	CheckCollisions2();
}

void World::CheckCollisions()
{
	glm::vec2 bgPos(-1280, 0);
	for (int i = 0; i < 100; i++)
		glm::vec2 bgPose(m_Enemies[i].GetSize());
	glm::vec4 bgPos2(120, 120, 120, 120);

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (!m_Enemies[i].collision && !m_player.collision && !m_player.invincible) {
				if (m_Enemies[i].GetPositionX() < m_player.getPositionX() + m_player.getSizeW()
					&& m_Enemies[i].GetPositionX() + m_Enemies[i].GetSizeW() > m_player.getPositionX()
					&& m_Enemies[i].GetPositionY() < m_player.getPositionY() + m_player.getSizeZ()
					&& m_Enemies[i].GetSizeW() + m_Enemies[i].GetPositionY() > m_player.getPositionY())
				{
					m_Enemies[i].collision = true;
					//m_player.collision = true;
					m_player.lives --;
					m_player.invincible = true;
					m_player.invCooldown = 2.5;
				}
			}
		}//for loop end (j)
	}//for loop end (i)
}


// TODO delte this method and and its Header file instanciation and replace with smart Collion
void World::CheckCollisions2()
{
	glm::vec2 bgPos(-1280, 0);
	for (int i = 0; i < 100; i++)
		glm::vec2 bgPose(m_Enemies[i].GetSize());
	glm::vec4 bgPos2(120, 120, 120, 120);

	for (int i = 0; i < 100; i++)
	{

			if (!m_Enemies[i].collision && !m_playerBullet.collision && m_playerBullet.visible) {
				if (m_Enemies[i].GetPositionX() < m_playerBullet.getPositionX() + m_playerBullet.getSizeW()
					&& m_Enemies[i].GetPositionX() + m_Enemies[i].GetSizeW() > m_playerBullet.getPositionX()
					&& m_Enemies[i].GetPositionY() < m_playerBullet.getPositionY() + m_playerBullet.getSizeZ()
					&& m_Enemies[i].GetSizeW() + m_Enemies[i].GetPositionY() > m_playerBullet.getPositionY())
				{
					m_Enemies[i].collision = true;
					m_playerBullet.visible = false;
					m_player.score += 100;
				}
			}
		
	}//for loop end (i)
}
void World::Draw(ge::Rendering::SpriteBatch& spriteBatch, ge::Rendering::Camera& camera)
{
	// Render the background here
	int count = 0;

	for (int i = 0; i < 2; i++)
	{
		glm::vec2 bgPos(-1280, 0);
		spriteBatch.Draw(m_sprite[i]);
		if (m_sprite[i].GetPositionX() >= 1280)
			m_sprite[i].SetPosition(bgPos);
	}

	for (int i = 0; i < 100; i++)
		if(!m_Enemies[i].collision)
			spriteBatch.Draw(m_Enemies[i]);
	//for (int i = 0; i < 100; i++)
	//	if (!m_Enemies2[i].collision)
	//		spriteBatch.Draw(m_Enemies2[i]);

	spriteBatch.Draw(m_sprite1);
	spriteBatch.Draw(m_sprite2);
	spriteBatch.Draw(m_sprite3);
	spriteBatch.Draw(m_sprite4);
	spriteBatch.Draw(m_sprite5);
	spriteBatch.Draw(m_sprite6);
	spriteBatch.Draw(m_sprite7);
	spriteBatch.Draw(m_sprite8);
	spriteBatch.Draw(m_sprite9);
	spriteBatch.Draw(m_sprite10);

	// Render the player here
	if (!m_player.collision && m_player.lives > 0)
		m_player.Draw(spriteBatch, camera);
	if (m_playerBullet.visible)
		m_playerBullet.Draw(spriteBatch, camera);

	cout << "Score: " << m_player.score << endl << " Lives:  " << m_player.lives << endl;
}