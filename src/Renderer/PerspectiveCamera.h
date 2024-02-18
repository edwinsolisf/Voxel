#pragma once

#include "stm/math.h"

class PerspectiveCamera
{
public:
	PerspectiveCamera(float FOV, float aspectRatio);
	void UpdateView(const stm::vec3f& position, const stm::vec3f& direction, const stm::vec3f& normal);
	void UpdateProj(float FOV, float aspectRatio);

	const stm::mat4f& CurrentView() const { return _view; }
	const stm::mat4f& CurrentProjection() const { return _projection; }
private:
	stm::mat4f _view;
	stm::mat4f _projection;
};