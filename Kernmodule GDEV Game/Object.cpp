#include <iostream>
#include "Objects.h"

Object::Object()
{
	
}

Object::Object(Shape* shape, Vector pos)
{
	setPosition(pos);
	m_sprite = shape;
}

Object::~Object()
{
	///	If the object is ever deleted, the sprite variable which is a reference to memory will get deleted as well.
	///	But the memory itself won't. Causing the Shape object to continue existing, without any reference to it.

	/// That also explained the error on drawing the Player, when the Player was not created as a pointer, not appearing when this was commented out.
	/// If the sprite doesn't get deleted as the player does, it can still technically call the draw function.

	delete m_sprite;
}

bool Object::collidesWith(Object& other) 
{
	return m_sprite->bounds.collidesWith(other.m_sprite->bounds, m_position, other.m_position);
}

void Object::setPosition(Vector pos)
{
	m_position = pos;
	//std::cout << "Object has been set to: (" << m_position.x << "," << m_position.y << ") units." << std::endl;
}

void Object::move(Vector offset)
{
	setPosition(m_position + offset);
	//std::cout << "Object has been moved by: (" << offset.x << "," << offset.y << ") units." << std::endl;
}

void Object::draw(sf::RenderWindow& window)
{
	m_sprite->draw(window, m_position);
}