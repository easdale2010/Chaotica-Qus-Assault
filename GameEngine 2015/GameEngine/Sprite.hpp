#ifndef GAME_ENGINE_SPRITE_HPP
#define GAME_ENGINE_SPRITE_HPP

#include <GL\glew.h>
#include <glm\glm.hpp>

#include "GameContext.hpp"
#include "GLTexture.hpp"
#include "Vertex.hpp"

#include <string>


namespace GameEngine
{

	namespace Rendering
	{
		class Sprite
		{
		public:
			Sprite() = default;
			bool pressed;
			bool collision = false;
			Sprite(const std::string& filename, GameEngine::GameContext& context, const glm::vec4& destRect, const glm::vec4& uvRect, float depth, float angle, const GameEngine::Rendering::ColourRGBA8& colour, bool flip = true);
			void Load(const std::string& filename, GameEngine::GameContext& context, const glm::vec4& destRect, const glm::vec4& uvRect, float depth, float angle, const GameEngine::Rendering::ColourRGBA8& colour, bool flip = true);
			//glm::vec2 playerPosition;
			void Move(const glm::vec2& pos)
			{
				m_destRect.x += pos.x;
				m_destRect.y += pos.y;
			}
			void Move2()
			{	
				m_destRect.x -= 4;
			//	m_destRect.y += pos.y;
     		}

			void PlayerBoundries(const glm::vec2& pos)
			{
				m_destRect.x += pos.x;
				m_destRect.y += pos.y;
				if (m_destRect.y <= 0)
					m_destRect.y = 0;

				if (m_destRect.y >= 690)
					m_destRect.y = 690;

				if (m_destRect.x <= 300)
					m_destRect.x = 300;

				if (m_destRect.x >= 1250)
					m_destRect.x = 1250;
			}
			void BulletBoundries(const glm::vec2& pos)
			{
				m_destRect.x += pos.x;
				m_destRect.y += pos.y;
				if (m_destRect.y <= 0)
					m_destRect.y = 0;

				if (m_destRect.y >= 690)
					m_destRect.y = 690;

				if (m_destRect.x <= -50)
				{
					m_destRect.x = -50;
					pressed = false;
				}


				if (m_destRect.x >= 1250)
					m_destRect.x = 1250;
			}

			void SetPosition(glm::vec2& pos)
			{
				m_destRect.x = pos.x;
				m_destRect.y = pos.y;
			}

	
			glm::vec2 GetPosition() const
			{
				return glm::vec2(m_destRect.x, m_destRect.y);
			}

			
			float GetPositionX() const
			{
				return m_destRect.x;
			}

			int GetPositionX2() const
			{
				return m_destRect.x;
			}

			float GetPositionY() const
			{
				return m_destRect.y;
			}

			glm::vec2 GetSize() const
			{
				return glm::vec2(m_destRect.z, m_destRect.w);
			}

			float GetSizeZ() const
			{
				return m_destRect.z;
			}

			float GetSizeW() const
			{
				return m_destRect.w;
			}

			glm::vec4 GetBoundingBox() const
			{
				return glm::vec4(GetPosition().x, GetPosition().y, GetPosition().x + GetSize().x, GetPosition().y + GetSize().y);
			}

			const GLTexture& Texture() const
			{
				return m_texture;
			}

			const glm::vec4& DestRect() const
			{
				return m_destRect;
			}

			const glm::vec4& UVRect() const
			{
				return m_uvRect;
			}

			float Depth() const
			{
				return m_depth;
			}

			const ColourRGBA8& Colour() const
			{
				return m_colour;
			}

			float Angle() const
			{
				return m_angle;
			}

			void Flip();
		private:
			GameEngine::Rendering::GLTexture m_texture;
			glm::vec4 m_destRect;
			glm::vec4 m_uvRect;
			float m_depth;
			float m_angle;
			GameEngine::Rendering::ColourRGBA8 m_colour;
		};
	}
}

#endif

