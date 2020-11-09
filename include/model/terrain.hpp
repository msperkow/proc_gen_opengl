#ifndef PROC_GEN_OPENGL_TERRAIN_HPP
#define PROC_GEN_OPENGL_TERRAIN_HPP


#include <vector>
#include <glm/glm.hpp>
#include <memory>
#include "height_map.hpp"
#include "entity.hpp"

//terrain translates 2d heightmap to 3d terrain
class Terrain : public Entity
{
private:
protected:
	float length; //z axis
	float width; //x axis
	float level; //y axis
	float scale; //amplitude

	std::unique_ptr<HeightMap> heightMap;

	void calculatePoints();
public:
	Terrain(float width, float length, float scale, float level);

	void setHeightMap(std::unique_ptr<HeightMap> heightMap);

	void setLength(float length);

	void setWidth(float width);

	void setLevel(float level);

	void setScale(float scale);

	float getLength() const;

	float getWidth() const;

	float getLevel() const;

	unsigned int getNPointsLength() const;

	unsigned int getNPointsWidth() const;

};


#endif //PROC_GEN_OPENGL_TERRAIN_HPP
