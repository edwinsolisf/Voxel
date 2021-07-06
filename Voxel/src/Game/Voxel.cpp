#include "Voxel.h"
#include "../Game/Player.h"
#include "../Game/World.h"
#include "../Utilities/Logging.h"
//#include "../Voxel/Cube.h"
#include "stm/matrix_transform.h"
#include "../Renderer/OpenGL/OpenGLCallback.h"

static World world;
static Player player;
static std::shared_ptr<Shader> shader;

VoxelGame::VoxelGame(ApplicationCommandArgs cmdArgs)
	:Application(default_width, default_height, "Voxel", cmdArgs, std::make_unique<VoxelRenderer>()),
	renderer(*dynamic_cast<VoxelRenderer*>(_renderer.get())), _gameLayer(std::make_shared<GameLayer>(*this, player)),
	_interfaceLayer(std::make_shared<InterfaceLayer>(renderer, *_window))
{
}

void VoxelGame::Init()
{
	Log::Init();

	shader = std::make_shared<Shader>();
	shader->AttachShader("assets/shaders/basic_vertex_shader.shader");
	shader->AttachShader("assets/shaders/basic_fragment_shader.shader");
	renderer.BindShader(shader);

	_layerStack.PushLayer(_gameLayer);
	_layerStack.PushOverlay(_interfaceLayer);

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

void VoxelGame::OnUpdate(float timeStep)
{
	player.GetCamera().UpdateProj(45.0f, (float)_window->GetWidth() / (float)_window->GetHeight());

	auto model = stm::translate({ 0.0f });
	player.Move(timeStep);

	const auto& view = player.GetCamera().CurrentView();
	const auto& proj = player.GetCamera().CurrentProjection();

	_window->WindowClear();
	Shader& gameshader = *shader;
	renderer.BindShader(shader);

	gameshader.SetUniform4f("u_color", { 0.1f, 0.6f, 0.3f , 1.0f });

	gameshader.SetUniformMat4f("u_view", view);
	gameshader.SetUniformMat4f("u_projection", proj);
	//gameshader.SetUniform1i("u_texture", 0);

	//gameshader.Bind();
	/*for (unsigned int i = 0; i < 10; ++i)
	{
		auto temp = i;
		model = stm::translate({ (float)temp, (float)temp, (float)temp});
		shader.SetUniformMat4f("u_model", model);
		renderer.Draw();
	}*/
	gameshader.SetUniformMat4f("u_model", model);

	renderer.RenderWorld(world);

}

bool VoxelGame::OnMouseMoved(MouseMovedEvent& event)
{
	return false;
}

bool VoxelGame::OnKeyPressed(KeyPressedEvent& event)
{
	return false;
}

bool VoxelGame::OnKeyRepeat(KeyRepeatEvent& event)
{
	return false;
}

bool VoxelGame::OnKeyReleased(KeyReleasedEvent& event)
{
	return false;
}

VoxelGame::~VoxelGame()
{
}