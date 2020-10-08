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

class Mesh
{
private:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	//todo shader should probably not belong to the mesh class
	ShaderProgram shader;

	glm::mat4 modelMatrix;

	VAO vao;
	VBO vbo;
	EBO ebo;
public:
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, GLenum usage);

	virtual ~Mesh();

	void draw(const glm::mat4 &viewMatrix, const glm::mat4 &projectionMatrix);

	void scale(glm::vec3 scale);
	//angle in radians!
	void rotate(float angle, glm::vec3 axis);
	void translate(glm::vec3 trans);

	//angle in radians!; when possible use this function, it has the correct order of matrix operations
	void scaleRotateTranslate(glm::vec3 scale, float angle, glm::vec3 axis, glm::vec3 trans);
};


#endif //PROC_GEN_OPENGL_MESH_HPP