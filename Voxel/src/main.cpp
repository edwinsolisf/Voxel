#include "Game/Voxel.h"

int main(int argc, char** argv)
{
	VoxelGame* game = new VoxelGame();

	game->Init();

	game->Run();

	game->Close();

	delete game;

	return 0;
}