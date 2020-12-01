#pragma once
#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include "Window.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "simpleModel.h"
#include "Texture.h"

class GameWindow: public Window
{
public:
	using Params = std::vector<double>;
	using Translates = std::vector<double>;
	using SnowmanParts = std::vector<double>;
	using TreeParts = std::vector<double>;


protected:
	double _angle {0.};
	double _camera_z {8.};

	simpleModel _house = simpleModel::create_house();
	simpleModel _chimney = simpleModel::create_chimney();
	simpleModel _down = simpleModel::create_down();

	Texture _house_texture;
	Texture _chimney_texture;
	Texture _grass_texture;
	Texture _snowman_texture;
	Texture _carrot_texture;
	Texture _tree_texture;
	Texture _listva_texture;

	std::vector<Params> _params;
	std::vector<Translates> _translates;
	std::vector<SnowmanParts> _snowman;//0 индекс означает что рисуем, сферу(0) или конус(1)
	std::vector<TreeParts> _tree;//0 индекс означает что рисуем, цилиндр(0) или конус(1)
public:
	GameWindow(	int width = DEFAULT_WIDTH,
				int height = DEFAULT_HEIGHT);
	virtual ~GameWindow() = default;

	virtual void setup();
	virtual void render();
	virtual void do_logic();
};

#endif



