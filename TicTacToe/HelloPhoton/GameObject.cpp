#include <iostream>
#include "GameObject.h"

using namespace std;

GameObject::GameObject()
{
	m_sprites = new Sprite();
}

GameObject::GameObject(Sprite* sprite)
{
	m_sprites = sprite;
	m_color = Color(1.0, 1.0f, 1.0f);
}

void GameObject::SetPos(Vector pos)
{
	m_position = pos;
}

const Vector& GameObject::GetPos()
{
	return m_position;
}

void GameObject::SetRotation(float rotate)
{
	m_rotation = rotate;
}

float GameObject::GetRotation()
{
	return m_rotation;
}

void GameObject::SetScale(float scale)
{
	m_scale = scale;
}

float GameObject::GetScale()
{
	return m_scale;
}

void GameObject::SetColor(Color color)
{
	m_color = color;
}

Color& GameObject::getColor()
{
	return m_color;
}

void GameObject::SetSprite(Sprite* sprite)
{
	m_sprites = sprite;
}

Sprite* GameObject::getSprite()
{
	return m_sprites;
}

void GameObject::setEnumBlend(enumBlend blend)
{
	m_blendMode = blend;
}

enumBlend GameObject::getEnumBlend()
{
	return m_blendMode;
}

void GameObject::draw()
{
	m_sprites->Draw(m_position.mVal[0], m_position.mVal[1],m_rotation,m_scale,m_color);

}

