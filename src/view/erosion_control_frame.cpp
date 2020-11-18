#include "view/erosion_control_frame.hpp"

ErosionControlFrame::ErosionControlFrame(Scene3D *view, const std::string &name, WorldManipulator *worldManipulator)
: Frame(view, name), worldManipulator(worldManipulator)
{
	width = 200;
	height = 200;
	seedBuf[0] = '\0';
}

void ErosionControlFrame::mainDraw()
{
	ImGui::SetWindowSize(ImVec2(width, height));
	ImGui::Columns(1);
	ImGui::Text("Seed");
	ImGui::InputText("", seedBuf, sizeof(seedBuf) / sizeof(char));
	if (ImGui::Button("Erode"))
		sendUpdateSignal();
}

void ErosionControlFrame::sendUpdateSignal()
{
	worldManipulator->erodeTerrainHydraulic(seedBuf, 70000, 100, 1, 1);
}
