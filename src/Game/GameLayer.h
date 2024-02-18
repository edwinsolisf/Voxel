#pragma once

#include "../Renderer/Layer.h"

#include "../EventSystem/KeyEvent.h"
#include "../EventSystem/MouseEvent.h"
#include "../EventSystem/WindowEvent.h"

#include "../Application/Application.h"

#include "Player.h"

class GameLayer : public Layer
{
public:
	GameLayer(Application& application, Player& player);

	void OnAttach() override;
	void OnDettach() override;
	void OnUpdate() override;
	void OnEvent(std::shared_ptr<Event> event) override;

private:
	bool OnMouseMoved(MouseMovedEvent& event);
	bool OnKeyPressed(KeyPressedEvent& event);
	bool OnKeyReleased(KeyReleasedEvent& event);
	bool OnKeyRepeat(KeyRepeatEvent& event);

	Application& application;
	Player& player;
};