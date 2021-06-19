#include "PerspectiveCamera.h"
#include "stm/matrix_transform.h"
#include "stm/function.h"

PerspectiveCamera::PerspectiveCamera(float FOV, float aspectRatio)
	:_view(stm::lookAt({}, stm::posY, stm::negX, stm::posZ)), _projection(stm::perspective(stm::radians(FOV), aspectRatio, 0.1f, 200.0f))
{
}

void PerspectiveCamera::UpdateView(const stm::vec3f& position, const stm::vec3f& direction, const stm::vec3f& normal)
{
	_view = stm::lookAt(position, normal, stm::crossproduct(direction, normal).UnitVector(), direction);
}

void PerspectiveCamera::UpdateProj(float FOV, float aspectRatio)
{
	_projection = stm::perspective(FOV, aspectRatio, 0.1f, 200.0f);
}