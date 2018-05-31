#include <game.h>
Game::Game(int moves, std::vector<TileType> availableTileTypes, int numRow,
	int numColumn, std::map<TileType, int> objective)
	: moves(moves), availableTileTypes(availableTileTypes),
	grid(std::vector<Tile>(numRow * numColumn)), objective(objective) {}