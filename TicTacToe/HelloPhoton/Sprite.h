#pragma once
#ifndef _SPRITE_

#include "vector.h"
#include <GLFW/glfw3.h>
#include "bitmap.h"
#include "matrix.h"

struct Color
{
	float r;
	float g;
	float b;

	Color(float red, float green, float blue)
	{
		r = red;
		g = green;
		b = blue;
	}

	Color()
	{
		r = 1.0f;
		g = 1.0f;
		b = 1.0f;
	}
};

class Sprite
{
private:
	unsigned int m_width;
	unsigned int m_height;
	unsigned int m_textureID;

public:
	GLuint Gtexture;
	Sprite();
	Sprite(const std::string& file);
	void TextureLoad(const char* path, GLuint textureID);

	~Sprite();

	void Draw(float x, float y, float rotation, float scale, const Color& color);
};

#endif
