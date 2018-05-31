#ifndef CANDYCRUSH_GAME_H
#define CANDYCRUSH_GAME_H
#include <map>
#include <vector>
enum struct TileColor { RED, BLUE, GREEN };

enum struct TileType { EMPTY, PLAIN };

struct Tile {
	TileColor color;
	TileType type;
};

class Game {
public:
	Game(int moves, std::vector<TileType> availableTileTypes, int numRow,
		int numColumn, std::map<TileType, int> objective);
	// Get number of available moves left for the player.
	int getMoves() const;
	// Get a copy of the grid.
	std::vector<Tile> getGrid() const;
	// Return true if game is over.
	bool isGameOver() const;
	// Swap (row1,col1) tile and (row2,col2) tile.
	void move(int row1, int col1, int row2, int col2);

private:
	// Number of moves left until game over.
	int moves;
	// Types of tiles that can be generated in this game.
	std::vector<TileType> availableTileTypes;
	// 1 dimensional representation of 2D game grid.
	std::vector<Tile> grid;
	// Number of each tile type to be destroyed.
	std::map<TileType, int> objective;
};
#endif // CANDYCRUSH_GAME_H