#include "Shapes.h"

Sprite::Sprite(sf::String textureName)
{
	m_texture.loadFromFile("Resources\\Textures\\" + textureName);
	m_sprite.setTexture(m_texture);
	m_sprite.setScale(Vector(upscaleAmount, upscaleAmount).cast());

	bounds = Bounds(m_texture.getSize().x * upscaleAmount, m_texture.getSize().y * upscaleAmount);
}

Sprite& Sprite::operator=(const Sprite& other)
{
	bounds = other.bounds;
	m_texture = other.m_texture;
	m_sprite.setTexture(m_texture);
	return *this;
}

void Sprite::draw(sf::RenderWindow& window, Vector pos)
{
	m_sprite.setColor(m_color);
	m_sprite.setPosition(bounds.getOffset(pos, Vector(-1, -1)).cast());
	window.draw(m_sprite);
}