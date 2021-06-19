#include "Application/Application.h"

int main(int argc, char** argv)
{
	const int width = 1600, height = 900;
	const char* title = "Voxel";
	
	Application* game = new Application(width, height, title);

	game->Init();

	while (!game->ShouldClose())
	{
		game->Run();
	}

	game->Close();

	delete game;

	return 0;
}