#pragma once

#include "../Entity/Entity.h"
#include "../Renderer/PerspectiveCamera.h"

class Player : public Entity
{
public:
	Player();

	void Move(float deltaTime);
	void MoveForward(float step);
	void MoveRight(float step);
	void MoveUp(float step);

	void RotatePitch(float angle);
	void RotateYaw(float angle);
	void RotateRoll(float angle);

	PerspectiveCamera& GetCamera() { return _camera; }

	void SetSpeed(float x, float y, float z) { _speed = { x, y, z }; }
	void SetRotation(float x, float y, float z) { _rotation = { x, y, z }; }

	const stm::vec3f& GetSpeed() const { return _speed; }
	const stm::vec3f& GetRotation() const { return _rotation; }
private:
	stm::vec3f _position;
	stm::vec3f _direction;
	stm::vec3f _normal;

	stm::vec3f _speed;
	stm::vec3f _rotation;

	bool _freeMovement;
	PerspectiveCamera _camera;
};