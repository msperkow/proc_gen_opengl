#ifndef PROC_GEN_OPENGL_VORONOI_MAP_HPP
#define PROC_GEN_OPENGL_VORONOI_MAP_HPP


#include <random>
#include "height_map.hpp"

class VoronoiMap : public HeightMap
{
private:
	std::mt19937 generator;
	std::uniform_real_distribution<float> heightDistribution;
	std::uniform_int_distribution<unsigned int> widthDistribution;
	std::uniform_int_distribution<unsigned int> lengthDistribution;

	//returns index of the closes to points x, y from points vector
	unsigned getClosest(unsigned x, unsigned y, const std::vector<std::pair<unsigned, unsigned>>& points);

	//returns distance between two points
	float getDist(unsigned x1, unsigned y1, unsigned x2, unsigned y2);
public:
	VoronoiMap(unsigned int width, unsigned int length, unsigned int seed, unsigned int nRandomPoints,
	    float levelDiff);

};


#endif //PROC_GEN_OPENGL_VORONOI_MAP_HPP
