#include <iostream>
#include "Objects.h"

Object::Object()
{

}

Object::Object(Shape* shape, Vector pos)
{
	m_sprite = shape;
	setPosition(pos);
}

Object::~Object()
{
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