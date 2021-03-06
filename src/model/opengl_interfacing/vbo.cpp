#include <GL/glew.h>
#include "model/opengl_interfacing/vbo.hpp"

VBO::VBO()
{
	glGenBuffers(1, &id);
}

VBO::~VBO()
{
	glDeleteBuffers(1, &id);
}


void VBO::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::loadVertices(const std::vector<Vertex> &vertices, GLenum usage)
{
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), usage);
}