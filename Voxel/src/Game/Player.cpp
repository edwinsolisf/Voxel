#include "Player.h"

#include "stm/matrix_transform.h"

static const auto& worldY = stm::posY;

Player::Player()
	:Entity(), _position(), _direction(stm::posZ), _normal(stm::posY), _freeMovement(false), _camera(45.0f, 16.0f/9.0f)
{}

void Player::MoveForward(float step)
{
	if (_freeMovement)
	{
		_position += _direction * step;
	}
	else
	{
		auto right = stm::crossproduct(_direction, _normal).UnitVector();
		auto forward = stm::crossproduct(worldY, right).UnitVector();
		_position += forward * step;
	}
	
	_camera.UpdateView(_position, _direction, _normal);
}

void Player::MoveRight(float step)
{
	_position += stm::crossproduct(_direction, _normal).UnitVector() * step;
	_camera.UpdateView(_position, _direction, _normal);
}

void Player::MoveUp(float step)
{
	if (_freeMovement)
		_position += _normal * step;
	else
		_position += worldY * step;

	_camera.UpdateView(_position, _direction, _normal);
}

void Player::RotatePitch(float angle)
{
	
	if (!_freeMovement)
	{
		float currentAngle = stm::angle(_direction, worldY);

		if (((currentAngle - angle) > stm::radians(0.1f) && (currentAngle - angle) < stm::radians(179.9f)))
		{
			auto right = stm::crossproduct(_direction, _normal).UnitVector();

			auto newDir = stm::rotation(_direction, right, angle).UnitVector();
			auto newNorm = stm::rotation(_normal, right, angle).UnitVector();

			_direction = newDir;
			_normal = newNorm;
		}

	}
	else
	{
		auto right = stm::crossproduct(_direction, _normal).UnitVector();

		auto newDir = stm::rotation(_direction, right, angle).UnitVector();
		auto newNorm = stm::rotation(_normal, right, angle).UnitVector();

		_direction = newDir;
		_normal = newNorm;
	}
	_camera.UpdateView(_position, _direction, _normal);
}

void Player::RotateYaw(float angle)
{
	if (_freeMovement)
		_direction = stm::rotation(_direction, _normal, angle).UnitVector();
	else
	{
		_direction = stm::rotation(_direction, worldY, angle).UnitVector();
		_normal = stm::rotation(_normal, worldY, angle).UnitVector();
	}

	_camera.UpdateView(_position, _direction, _normal);
}

void Player::RotateRoll(float angle)
{
	if (_freeMovement)
	{
		_normal = stm::rotation(_normal, _direction, angle).UnitVector();
		_camera.UpdateView(_position, _direction, _normal);
	}
}
