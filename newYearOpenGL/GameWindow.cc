#include "GameWindow.h"
#include <cmath>
#include "Primitives.h"
#include <iostream>

double coeffJump = 0.035;
double coeffStepX = 0.04;
double coeffStepY = 0.04;
double coeffCarrotX = 0.002;
double coeffCarrotY = 0.002;

GameWindow::GameWindow(int width, int height)
: Window(width, height),
	_house_texture("house_new_year_texture.png"),
	_chimney_texture("chimney_tex.png"),
	_grass_texture("grass_tex.png"),
	_snowman_texture("snowman_tex.png"),
	_carrot_texture("carrot_tex.png"),
	_tree_texture("tree_tex.png"),
	_listva_texture("listva_tex.png"),
 	_params{
		{0., -5., 0.},
		{-5., 0., 0.},
		{0., 5., 0.},
		{5., 0., 0.},
	},
	_translates{
		{0., 0., 0., 1.},
		{270., 0., 0., 1.},
		{180., 0., 0., 1.},
		{90., 0., 0., 1.},
	},
	_snowman{
		{0, -0.5, 1.3, -0.8 },
		{0, -0.5, 1.3, -0.45 },
		{0, -0.5, 1.3, -0.1 },
		{1, -0.5, 1.5, -0.05 },
	},
	_tree {
		{0, 0., 0., -0.8 },
		{1, 0., 0., -0.2 },
		{1, 0., 0., 0.3 },
		{1, 0., 0., 0.8 },
	}
{

}

void GameWindow::setup()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE);


	glClearColor(0.2f, 0.35f, 0.45f, 1.0f);

	glMatrixMode(GL_PROJECTION);

	gluPerspective(45, ((double) width()) / ((double) height()), 0.1, 100.);

	glMatrixMode(GL_MODELVIEW);

}

void GameWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(
			10., 10., _camera_z,
			0., 0., 0.,
			0., 0., 1.);
	_grass_texture.bind();
	_down.draw();

	glEnable(GL_TEXTURE_2D);

	for (unsigned param_id = 0; param_id < _params.size(); ++param_id){
		glPushMatrix();
		glTranslated(_params[param_id][0], _params[param_id][1], _params[param_id][2]);
		glRotated(_translates[param_id][0], _translates[param_id][1], _translates[param_id][2], _translates[param_id][3]);
		_house_texture.bind();
		_house.draw();
		_chimney_texture.bind();
		_chimney.draw();
		for (unsigned part_id = 0; part_id < _snowman.size(); ++part_id){
			glPushMatrix();
			glTranslated(_snowman[part_id][1], _snowman[part_id][2], _snowman[part_id][3]);
			if (_snowman[part_id][0] == 0){
				glScaled(0.2, 0.2, 0.2);
				_snowman_texture.bind();
				draw_sphere_smooth(30, 15);
			} else if (_snowman[part_id][0] == 1){
				glRotated(_angle, 0., 0., 1.);
				glRotated(180., 0., 1., 1.);
				glScaled(0.045, 0.045, 0.3);
				_carrot_texture.bind();
				draw_cone(15);
			}
			glPopMatrix();
		}
		glPopMatrix();
	}

	for (unsigned part_id = 0; part_id < _tree.size(); ++part_id){
		glPushMatrix();
		glTranslated(_tree[part_id][1], _tree[part_id][2], _tree[part_id][3]);
		if (_tree[part_id][0] == 0){
			glScaled(0.2, 0.2, 0.6);
			_tree_texture.bind();
			draw_cylinder(10);
		} else if (_tree[part_id][0] == 1){
			glScaled(0.8, 0.8, 1.);
			_listva_texture.bind();
			draw_cone(15);
		}
		glPopMatrix();
	}
}

void GameWindow::do_logic() {

	_angle += 1.;
	if (_angle>=360.){
		_angle -=360.;
	}

	for (unsigned part_id = 0; part_id < _snowman.size(); ++part_id){
		if (_snowman[part_id][0] == 0){
			_snowman[part_id][1] += coeffStepX;
			_snowman[part_id][2] += coeffStepY;
		} else {
			_snowman[part_id][1] += coeffStepX-coeffCarrotX;
			_snowman[part_id][2] += coeffStepY-coeffCarrotY;
		}
		_snowman[part_id][3] += coeffJump;
	}
	if ((_snowman[0][1] > 3.6 && coeffStepX > 0) || (_snowman[0][1] < -3.6 && coeffStepX < 0)){
		coeffStepX *= -1;
		coeffCarrotX *= -1;
	}
	if ((_snowman[0][2] > 8.6 && coeffStepY > 0) || (_snowman[0][2] < 1.3 && coeffStepY < 0)){
		coeffStepY *= -1;
		coeffCarrotY *= -1;
	}
	if ( _snowman[0][3] < -0.8 || _snowman[0][3] > -0.5){
		coeffJump *= -1;
	}
}
