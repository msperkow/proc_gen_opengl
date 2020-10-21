#ifndef PROC_GEN_OPENGL_TERRAIN_CONTROL_FRAME_HPP
#define PROC_GEN_OPENGL_TERRAIN_CONTROL_FRAME_HPP


#include <generation_algorithm.hpp>
#include <controller/world_manipulator.hpp>
#include "frame.hpp"
#include "terrain_models_view.hpp"

class TerrainControlFrame : public Frame
{
private:
	WorldManipulator* worldManipulator;
	GenerationAlgorithm currentAlgo;

	//common variables
	float widthTerrain;
	float heightTerrain;
	int nVerticesSide;
	float scale;

	//noise map variables
	float horizontalScale;
	int nOctaves;
	float persistence;
	float lacunarity;
	char seedBuf[256];

	//sinusoidal map variables
	int nWavesWidth;
	int nWavesHeight;

	void mainDraw() override;
	void sendUpdateSignal();
public:
	TerrainControlFrame(TerrainModelsView *view, const std::string &name, WorldManipulator* worldManipulator);
};


#endif //PROC_GEN_OPENGL_TERRAIN_CONTROL_FRAME_HPP
