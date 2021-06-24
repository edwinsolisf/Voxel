#include "Application.h"
#include "../Utilities/Logging.h"
//#include "../Voxel/Cube.h"
#include "stm/matrix_transform.h"
#include "../Renderer/OpenGL/OpenGLCallback.h"
#include "../Game/Player.h"
#include "../Game/World.h"

#include <thread>
#include <chrono>

//Renderer Application::renderer;
static World world;

Application::Application(uint32_t width, uint32_t height, const char* title)
	:_window(new Window(width, height, title))
{}

void Application::Init()
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

void Application::Close() const {}

void Application::Run()
{ 
	static Player global_player;
	SetPlayer(&global_player);
	global_player.GetCamera().UpdateProj(45.0f, (float)_window->GetWidth() / (float)_window->GetHeight());

	auto model = stm::translate({ 0.0f });
	const auto& view = global_player.GetCamera().CurrentView();
	const auto& proj = global_player.GetCamera().CurrentProjection();

	auto& shader = *renderer.GetBoundShader();

	_window->Clear();

	shader.Bind();

	shader.SetUniform4f("u_color", { 0.1f, 0.6f, 0.3f , 1.0f});
	
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

	using namespace std::chrono_literals;
	std::this_thread::sleep_for(10ms);
	//_window->Run(); 
}

bool Application::ShouldClose() const { return _window->ShouldClose(); }

Application::~Application()
{
	delete _window;
}