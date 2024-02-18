#include "Game/Voxel.h"
#include <Windows.h>

void execute(int argc, char** argv)
{
	ApplicationCommandArgs args = { argc, argv };
	VoxelGame* game = new VoxelGame(args);

	game->Init();

	game->Run();

	game->Close();

	delete game;
}

int main(int argc, char** argv)
{
	execute(argc, argv);

	return 0;
}

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	execute(0, nullptr);

    return 0;
}