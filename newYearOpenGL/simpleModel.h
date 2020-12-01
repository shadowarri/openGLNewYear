/*
 * simpleModel.h
 *
 *  Created on: 16 нояб. 2020 г.
 *      Author: work
 */

#ifndef SIMPLEMODEL_H_
#define SIMPLEMODEL_H_

#include <vector>
#include <GL/gl.h>
#include <GL/glu.h>

class simpleModel {
public:
	using Vertex = std::vector<double>;
	using Normal = std::vector<double>;
	using Face = std::vector<int>; //[0] - количество вершин,  остальное - индексы

protected:
	std::vector<Vertex> _vertices;
	std::vector<Face> _faces;
	std::vector<Normal> _normals;
	std::vector<std::vector<Vertex>> _tex_coords;


public:
	simpleModel(
			const std::vector<Vertex> &vertices,
			const std::vector<Face> &faces,
			const std::vector<Normal> &normals,
			const std::vector<std::vector<Vertex>> tex_coords);
	virtual ~simpleModel() = default;

	void draw();

	static simpleModel create_house();
	static simpleModel create_chimney();
	static simpleModel create_down();
};

#endif /* SIMPLEMODEL_H_ */
