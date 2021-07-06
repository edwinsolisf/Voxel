#include "Game/Voxel.h"
#include <Windows.h>

int main(int argc, char** argv)
{
	ApplicationCommandArgs args = { argc, argv };
	VoxelGame* game = new VoxelGame(args);

	game->Init();

	game->Run();

	game->Close();

	delete game;

	return 0;
}