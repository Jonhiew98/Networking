#pragma once
#ifndef _GAME_OBJECT_

#include <iostream>
#include "vector.h"
#include "Sprite.h"

enum enumBlend
{
	NONE,
	ADDITIVE,
	ADDITIVE_ALPHA,
	MULTIPLICATIVE,
	ALPHA,
};

class GameObject
{
private:
	Sprite* m_sprites;
	Vector m_position;
	float m_rotation;
	float m_scale;
	Color m_color;
	enumBlend m_blendMode;

public:
	GameObject();
	GameObject(Sprite* sprite);

	void SetPos(Vector pos);
	const Vector& GetPos();

	void SetColor(Color color);
	Color& getColor();
	void SetRotation(float rotate);
	float GetRotation();
	void SetScale(float scale);
	float GetScale();
	void SetSprite(Sprite* sprite);
	Sprite* getSprite();

	void setEnumBlend(enumBlend blend);
	enumBlend getEnumBlend();
	void draw();
};

#endif