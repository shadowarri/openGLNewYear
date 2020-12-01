/*
 * simpleModel.cc
 *
 *  Created on: 16 нояб. 2020 г.
 *      Author: work
 */

#include "simpleModel.h"

static const std::vector<simpleModel::Vertex> s_house_vertices{

	{ 1.7, 1., 1. }, //0
	{ 1.7, -1., 1. }, //1
	{ -1.7, -1., 1. }, //2
	{ -1.7, 1., 1. },//3
	{ 1.7, 1., -1. },//4
	{ 1.7, -1., -1. },//5
	{ -1.7, -1., -1. },//6
	{ -1.7, 1., -1. },//7
	{ 1.7, 0., 2. },//8
	{ -1.7, 0., 2. },//9
};

static const std::vector<simpleModel::Face> s_house_faces{
	{ 5, 1, 8, 0, 4, 5},
	{ 5, 3, 9, 2, 6, 7},
	{ 4, 8, 9, 3, 0 },
	{ 4, 9, 8, 1, 2 },
	{ 4, 6, 5, 4, 7 },
	{ 4, 0, 3, 7, 4 },
	{ 4, 2, 1, 5, 6 },
};

static const std::vector<simpleModel::Normal> s_house_normals {
	{ 1., 0., 0. },
	{ -1., 0., 0. },
	{ 0., 1., 1. },
	{ 0., -1., 1. },
	{ 0., 0., -1. },
	{ 0., 1., 0. },
	{ 0., -1., 0. },
};

static const std::vector<std::vector<simpleModel::Vertex>> s_house_tex_coords{
	{ { 0.00, 0.30 }, { 0.10, 0.00 }, { 0.18, 0.30 }, {0.18, 0.88 }, {0.00, 0.88 } },
	{ { 0.00, 0.30 }, { 0.10, 0.00 }, { 0.18, 0.30 }, {0.18, 0.88 }, {0.00, 0.88 } },
	{ { 0.60, 0.00 }, { 1.00, 0.00 }, { 1.00, 0.50 }, {0.60, 0.50 } },
	{ { 0.60, 0.00 }, { 1.00, 0.00 }, { 1.00, 0.50 }, {0.60, 0.50 } },
	{ { 0.60, 0.50 }, { 1.00, 0.50 }, { 1.00, 1.00 }, {0.60, 1.00 } },
	{ { 0.20, 0.00 }, { 0.60, 0.00 }, { 0.60, 0.50 }, {0.20, 0.50 } },
	{ { 0.20, 0.50 }, { 0.60, 0.50 }, { 0.60, 1.00 }, {0.20, 1.00 } },

};


static const std::vector<simpleModel::Vertex> s_chimney_vertices{

	{ 0., 0.7, 2.5 }, //0
	{ -0.5, 0.7, 2.5 }, //1
	{ -0.5, 0.4, 2.5 }, //2
	{ 0, 0.4, 2.5 },//3
	{ 0., 0.7, 0.8 },//4
	{ -0.5, 0.7, 0.8 },//5
	{ -0.5, 0.4, 0.8 },//6
	{ 0., 0.4, 0.8 },//7
};

static const std::vector<simpleModel::Face> s_chimney_faces{
	{ 4, 3, 2, 1, 0 },
	{ 4, 3, 0, 4, 7 },
	{ 4, 0, 1, 5, 4 },
	{ 4, 1, 2, 6, 5 },
	{ 4, 2, 3, 7, 6 },
};

static const std::vector<simpleModel::Normal> s_chimney_normals {
	{ 0., 0., 1. },
	{ 1., 0., 0. },
	{ 0., 1., 0. },
	{ 0., -1., 0. },
	{ 0., -1., 0. },
};

static const std::vector<std::vector<simpleModel::Vertex>> s_chimney_tex_coords{
	{ { 0.00, 0.00 }, { 0.0001, 0.00 }, { 0.0001, 0.0001 }, {0.00, 0.0001 } },
	{ { 0.00, 0.00 }, { 1.00, 0.00 }, { 1.00, 1.00 }, {0.00, 1.00 } },
	{ { 0.00, 0.00 }, { 1.00, 0.00 }, { 1.00, 1.00 }, {0.00, 1.00 } },
	{ { 0.00, 0.00 }, { 1.00, 0.00 }, { 1.00, 1.00 }, {0.00, 1.00 } },
	{ { 0.00, 0.00 }, { 1.00, 0.00 }, { 1.00, 1.00 }, {0.00, 1.00 } },

};

static const std::vector<simpleModel::Vertex> s_down_vertices{

	{ 20., 20., -1. }, //0
	{-20., 20., -1. }, //1
	{-20., -20., -1. }, //2
	{ 20., -20., -1. },//3
};

static const std::vector<simpleModel::Face> s_down_faces{
	{ 4, 3, 2, 1, 0 },
};

static const std::vector<simpleModel::Normal> s_down_normals {
	{ 0., 0., 1. },
};

static const std::vector<std::vector<simpleModel::Vertex>> s_down_tex_coords{
	{ { 0.00, 0.00 }, { 1.00, 0.00 }, { 1.00, 1.00 }, {0.00, 1.00 } },

};

simpleModel::simpleModel(
		const std::vector<Vertex> &vertices,
		const std::vector<Face> &faces,
		const std::vector<Normal> &normals,
		const std::vector<std::vector<Vertex> > tex_coords)
: _vertices(vertices),
  _faces(faces),
  _normals(normals),
  _tex_coords(tex_coords)
{
}

void simpleModel::draw()
{
	for (unsigned face_idx = 0; face_idx < _faces.size(); ++face_idx){
		int vertices = _faces[face_idx][0];
		if (vertices == 3) {
			glBegin(GL_TRIANGLES);
		} else if (vertices == 4){
			glBegin(GL_QUADS);
		} else {
			glBegin(GL_POLYGON);
		}

		glNormal3dv(&_normals[face_idx][0]);

		for (int i = 0; i < vertices; ++i){
			//TODO текстурные координаты
			glTexCoord2dv(&_tex_coords[face_idx][i][0]);
			glVertex3dv(&_vertices[_faces[face_idx][i+1]][0]);
		}

		glEnd();
	}
}

simpleModel simpleModel::create_house() {
	return simpleModel(s_house_vertices, s_house_faces, s_house_normals, s_house_tex_coords);
}
simpleModel simpleModel::create_chimney() {
	return simpleModel(s_chimney_vertices, s_chimney_faces, s_chimney_normals, s_chimney_tex_coords);
}
simpleModel simpleModel::create_down() {
	return simpleModel(s_down_vertices, s_down_faces, s_down_normals, s_down_tex_coords);
}
