#ifndef DAMAGOCHI_GAME_H
#define DAMAGOCHI_GAME_H
#include <array>
#include <chrono>
#include <map>
#include <vector>
enum struct BirdColor {RED, BLUE, GREEN};
enum struct BirdDev {EGG, CHILD, ADULT};
enum struct BirdStatus { HUNGRY, HAPPY, DISCIPLINE };
enum struct Food {RICE, ICECREAM};

struct Bird {
	BirdColor color;
	BirdDev dev;
	BirdStatus status;
};

class Game {
public:
	Game(Bird bird, std::chrono::time_point<std::chrono::system_clock> birthTime);
	// Return true if game is over.
	bool isGameOver() const;
	// Feed the bird
	void giveFood(Food foodType);
	// Clean the poop
	void cleanPoop();
	// Potty Training
	void pottyTrain();

private:
	static const int numPoop = 10;
	static const int numPottyTraining = 3;

	// System time of birth
	std::chrono::time_point<std::chrono::system_clock> birthTime;
	// Status of Hunger 9: die - 0: full
	int hunger;
	// Status of Poop-need 9: will poop soon - 0: do not need to poop
	int needPoop;
	// Array of poops
	std::array<bool, numPoop> poops;
	// Potty Trained? if all true, is trained
	std::array<bool, numPottyTraining> isTrained;

};
#endif // DAMAGOCHI_GAME_H
