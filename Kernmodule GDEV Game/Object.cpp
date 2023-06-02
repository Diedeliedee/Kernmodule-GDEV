#include <iostream>
#include "Objects.h"

Object::Object()
{

}

Object::Object(Shape* shape, Vector2 pos)
{
	setPosition(pos);
	m_sprite = shape;
}

Object::~Object()
{
	//	If the object is ever deleted, the sprite variable which is a reference to memory will get deleted as well.
	//	But the memory itself won't. Causing the Shape object to continue existing, without any reference to it.
	delete m_sprite;
}

bool Object::collidesWith(Object& other) 
{
	Vector2 bounds = m_sprite->getBounds();
	Vector2 otherBounds = other.m_sprite->getBounds();

	return	m_position.x + bounds.x / 2 >= other.m_position.x - otherBounds.x / 2 ||
			m_position.x - bounds.x / 2 <= other.m_position.x + otherBounds.x / 2 &&
			m_position.y + bounds.y / 2 >= other.m_position.y - otherBounds.y / 2 ||
			m_position.y - bounds.y / 2 <= other.m_position.y + otherBounds.y / 2;
}

void Object::setPosition(Vector2 pos) 
{
	m_position = pos;
	std::cout << "Object has been set to: (" << m_position.x << "," << m_position.y << ") units." << std::endl;
}

void Object::move(Vector2 offset)
{
	setPosition(m_position + offset);
	std::cout << "Object has been moved by: (" << offset.x << "," << offset.y << ") units." << std::endl;
}

void Object::draw(sf::RenderWindow& window)
{
	m_sprite->draw(window, m_position);
}