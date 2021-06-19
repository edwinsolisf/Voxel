#pragma once

#include "../Entity/Entity.h"
#include "../Renderer/PerspectiveCamera.h"

class Player : public Entity
{
public:
	Player();

	void MoveForward(float step);
	void MoveRight(float step);
	void MoveUp(float step);

	void RotatePitch(float angle);
	void RotateYaw(float angle);
	void RotateRoll(float angle);

	PerspectiveCamera& GetCamera() { return _camera; }

private:
	stm::vec3f _position;
	stm::vec3f _direction;
	stm::vec3f _normal;

	bool _freeMovement;
	PerspectiveCamera _camera;
};