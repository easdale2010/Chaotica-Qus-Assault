#pragma once

#include "Player.h"
#include "Enemies.h"
#include "Item.h"
#include "Background.h"
#include "Bullet.h"
#include <vector>


class World
{
public:
	World(ge::GameContext& gameContext);
	~World();

	void Initialise();
	void ProcessInput(std::vector<SDL_Event> events);
	void Update(float elapsedTime);
	void Draw(ge::Rendering::SpriteBatch& spriteBatch, ge::Rendering::Camera& camera);
private:
	void CheckCollisions();
	void CheckCollisions2();

	ge::GameContext& m_gameContext;

	Player m_player;
	Bullet m_playerBullet;
	Enemies m_enemies;

	std::vector<Item> m_items;
	Background m_Background;

	ge::Rendering::Sprite m_sprite[2];
	ge::Rendering::Sprite m_sprite1;
	ge::Rendering::Sprite m_sprite2;
	ge::Rendering::Sprite m_sprite3;
	ge::Rendering::Sprite m_sprite4;
	ge::Rendering::Sprite m_sprite5;
	ge::Rendering::Sprite m_sprite6;
	ge::Rendering::Sprite m_sprite7;
	ge::Rendering::Sprite m_sprite8;
	ge::Rendering::Sprite m_sprite9;
	ge::Rendering::Sprite m_sprite10;

	ge::Rendering::Sprite m_Enemies[100];
	ge::Rendering::Sprite m_Enemies2[100];
	

};

