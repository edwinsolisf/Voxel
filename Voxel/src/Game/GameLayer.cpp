#include "GameLayer.h"

GameLayer::GameLayer(Application& _application, Player& _player)
	:application(_application), player(_player)
{
}

void GameLayer::OnAttach()
{
}

void GameLayer::OnDettach()
{

}

void GameLayer::OnUpdate()
{

}

void GameLayer::OnEvent(std::shared_ptr<Event> event)
{
	EventDispatcher dispatcher(*event);
	
	dispatcher.Dispatch<MouseMovedEvent >(std::bind(&GameLayer::OnMouseMoved, this, std::placeholders::_1));
	dispatcher.Dispatch<KeyPressedEvent >(std::bind(&GameLayer::OnKeyPressed, this, std::placeholders::_1));
	dispatcher.Dispatch<KeyReleasedEvent>(std::bind(&GameLayer::OnKeyReleased, this, std::placeholders::_1));
	dispatcher.Dispatch<KeyRepeatEvent  >(std::bind(&GameLayer::OnKeyRepeat, this, std::placeholders::_1));
}

bool GameLayer::OnMouseMoved(MouseMovedEvent& event)
{
	static float sensitivity = 0.005f;
	static double lastX = event.GetPosX(), lastY = event.GetPosY();
	double xpos = event.GetPosX(), ypos = event.GetPosY();
	float xoffset = lastX - xpos, yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	player.RotatePitch(yoffset * sensitivity);
	player.RotateYaw(xoffset * sensitivity);

	return true;
}

bool GameLayer::OnKeyPressed(KeyPressedEvent& event)
{
	float speed = 10.f;
	stm::vec3f s = player.GetSpeed();
	stm::vec3f r = player.GetRotation();
	switch (event.GetKeyCode())
	{
	case KeyCode::W:
		player.SetSpeed(s.x, s.y, speed);
		break;
	case KeyCode::A:
		player.SetSpeed(-speed, s.y, s.z);
		break;
	case KeyCode::S:
		player.SetSpeed(s.x, s.y, -speed);
		break;
	case KeyCode::D:
		player.SetSpeed(speed, s.y, s.z);
		break;
	case KeyCode::Space:
		player.SetSpeed(s.x, speed, s.z);
		break;
	case KeyCode::LeftShift:
		player.SetSpeed(s.x, -speed, s.z);
		break;
	case KeyCode::Q:
		player.SetRotation(r.x, r.y, -speed);
		break;
	case KeyCode::E:
		player.SetRotation(r.x, r.y, speed);
		break;
	case KeyCode::Escape:
		application.OnEvent(std::make_shared<WindowCloseEvent>());
	}
	return true;
}

bool GameLayer::OnKeyReleased(KeyReleasedEvent& event)
{
	float speed = 0.f;
	stm::vec3f s = player.GetSpeed();
	stm::vec3f r = player.GetRotation();
	switch (event.GetKeyCode())
	{
	case KeyCode::W:
		player.SetSpeed(s.x, s.y, speed);
		break;
	case KeyCode::A:
		player.SetSpeed(-speed, s.y, s.z);
		break;
	case KeyCode::S:
		player.SetSpeed(s.x, s.y, -speed);
		break;
	case KeyCode::D:
		player.SetSpeed(speed, s.y, s.z);
		break;
	case KeyCode::Space:
		player.SetSpeed(s.x, speed, s.z);
		break;
	case KeyCode::LeftShift:
		player.SetSpeed(s.x, -speed, s.z);
		break;
	case KeyCode::Q:
		player.SetRotation(r.x, r.y, -speed);
		break;
	case KeyCode::E:
		player.SetRotation(r.x, r.y, speed);
		break;
	}

	return true;
}

bool GameLayer::OnKeyRepeat(KeyRepeatEvent& event)
{
	return true;
}
