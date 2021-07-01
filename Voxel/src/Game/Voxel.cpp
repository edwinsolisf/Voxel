#include "Voxel.h"
#include "../Game/Player.h"
#include "../Game/World.h"
#include "../Utilities/Logging.h"
//#include "../Voxel/Cube.h"
#include "stm/matrix_transform.h"
#include "../Renderer/OpenGL/OpenGLCallback.h"

static World world;
static Player player;

VoxelGame::VoxelGame()
	:Application(default_width, default_height, "Voxel", std::make_unique<VoxelRenderer>()),
	renderer(*dynamic_cast<VoxelRenderer*>(_renderer.get()))
{
}

void VoxelGame::Init()
{
	Log::Init();

	std::shared_ptr<Shader> shader = std::make_shared<Shader>();
	shader->AttachShader("assets/shaders/basic_vertex_shader.shader");
	shader->AttachShader("assets/shaders/basic_fragment_shader.shader");
	renderer.BindShader(shader);

	/*this->renderer.Push(Mesh({
		Vertex({-0.5f, -0.5f, 1.0f }, { 0.0f, 0.0f}),
		Vertex({-0.5f,  0.5f, 1.0f }, { 0.0f, 1.0f}),
		Vertex({ 0.5f,  0.5f, 1.0f }, { 1.0f, 1.0f}),
		Vertex({ 0.5f, -0.5f, 1.0f }, { 1.0f, 0.0f}) }
		, {
			2, 1, 0,
			3, 2, 0
		},
		{ "assets/textures/box.png" })); */

}

void VoxelGame::Process()
{
	static double lastTime = glfwGetTime();
	player.GetCamera().UpdateProj(45.0f, (float)_window->GetWidth() / (float)_window->GetHeight());

	auto model = stm::translate({ 0.0f });
	player.Move(glfwGetTime() - lastTime);
	lastTime = glfwGetTime();

	const auto& view = player.GetCamera().CurrentView();
	const auto& proj = player.GetCamera().CurrentProjection();
	auto& shader = *renderer.GetBoundShader();

	_window->WindowClear();

	shader.Bind();

	shader.SetUniform4f("u_color", { 0.1f, 0.6f, 0.3f , 1.0f });

	shader.SetUniformMat4f("u_view", view);
	shader.SetUniformMat4f("u_projection", proj);
	shader.SetUniform1i("u_texture", 0);

	shader.Bind();
	/*for (unsigned int i = 0; i < 10; ++i)
	{
		auto temp = i;
		model = stm::translate({ (float)temp, (float)temp, (float)temp});
		shader.SetUniformMat4f("u_model", model);
		renderer.Draw();
	}*/
	shader.SetUniformMat4f("u_model", model);

	renderer.RenderWorld(world);

	_window->ProcessEvents();
}

static float sensitivity = 0.005f;
bool VoxelGame::OnMouseMoved(MouseMovedEvent& event)
{
	static double lastX = event.GetPosX(), lastY = event.GetPosY();
	double xpos = event.GetPosX(), ypos = event.GetPosY();
	float xoffset = lastX - xpos, yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;
	
	player.RotatePitch(yoffset * sensitivity);
	player.RotateYaw(xoffset * sensitivity);
	
	return true;
}

bool VoxelGame::OnKeyPressed(KeyPressedEvent& event)
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
		OnEvent(std::make_shared<WindowCloseEvent>());
	}
	return true;
}

bool VoxelGame::OnKeyRepeat(KeyRepeatEvent& event)
{
	return true;
}

bool VoxelGame::OnKeyReleased(KeyReleasedEvent& event)
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

VoxelGame::~VoxelGame()
{
}