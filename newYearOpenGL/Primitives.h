/*
 * Primitives.h
 *
 *  Created on: 30 нояб. 2020 г.
 *      Author: work
 */

#ifndef PRIMITIVES_H_
#define PRIMITIVES_H_

#include <GL/gl.h>


void cart2cyl( 	double x, double y, double z,
				double &r, double &phi, double &cz);
void cyl2cart( 	double r, double phi, double cz,
				double &x, double &y, double &z);

void draw_prism(int sides);
void draw_cylinder(int sides);
void draw_pyramid(int sides);
void draw_cone(int sides);
void draw_sphere(int cols, int rows);
void draw_sphere_smooth(int cols, int rows);




#endif /* PRIMITIVES_H_ */
