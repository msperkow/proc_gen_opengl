#ifndef PROC_GEN_OPENGL_MESH_HPP
#define PROC_GEN_OPENGL_MESH_HPP


#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "vao.hpp"
#include "vbo.hpp"
#include "ebo.hpp"
#include "vertex_shader.hpp"
#include "fragment_shader.hpp"
#include "shader_program.hpp"
#include "vertex.hpp"
#include "light_source.hpp"
#include <memory>

class Mesh
{
private:
	GLenum usage;
	unsigned int indicesSize;
	//todo shader should probably not belong to the mesh class
	ShaderProgram shader;

	glm::vec3 color;

	glm::mat4 modelMatrix;

	std::unique_ptr<VAO> vao;
	std::unique_ptr<VBO> vbo;
	std::unique_ptr<EBO> ebo;
public:
	Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices, GLenum usage);
	Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices, GLenum usage, glm::vec3 color);

	virtual ~Mesh();

	//todo not sure if draw should be in mesh
	void draw(const glm::mat4 &viewMatrix, const glm::mat4 &projectionMatrix, const glm::vec3 &cameraPosition,
		  const LightSource &lightSource);

	void scale(glm::vec3 scale);
	//angle in radians!
	void rotate(float angle, glm::vec3 axis);
	void translate(glm::vec3 trans);

	void update(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices);

	//angle in radians!; when possible use this function, it has the correct order of matrix operations
	void scaleRotateTranslate(glm::vec3 scale, float angle, glm::vec3 axis, glm::vec3 trans);
};


#endif //PROC_GEN_OPENGL_MESH_HPP
