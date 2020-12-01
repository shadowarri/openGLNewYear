/*
 * Texture.h
 *
 *  Created on: 16 нояб. 2020 г.
 *      Author: work
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL/gl.h>
#include <GL/glu.h>

class Texture
{
protected:
	GLuint _tex;
public:
	Texture(const char *filename);
	virtual ~Texture();

	void bind();
};

#endif /* TEXTURE_H_ */

