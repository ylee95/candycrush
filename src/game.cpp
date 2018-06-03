#include <game.h>
#include <iostream>

Game::Game(Bird bird, std::chrono::time_point<std::chrono::system_clock> birthTime) : birthTime(birthTime), hunger(0), needPoop(0), trainNum(0), isTrained(false), isDead(false), bird(bird) {
	// Initialize poops array.
	for (bool &p : poops) {
		p = false;
	}
}

void Game::giveFood(Food foodType) {
	if (foodType == Food::RICE) {
		hunger -= 3;
	}
	else if (foodType == Food::ICECREAM) {
		hunger -= 1;
	}
	else {
		// error case
	}
	if (hunger < 0) hunger = 0;
}

void Game::cleanPoop() {
	for (bool &p : poops) {
		p = false;
	}
}

void Game::pottyTrain() {
	if (needPoop > 6) {
		needPoop = 0;
		trainNum++;
		if (trainNum > numPottyTraining) {
			isTrained = true;
		}
		std::cout << "Pooped!" << std::endl;
	}
	else {
		std::cout << "Cannot poop yet" << std::endl;
	}
}

bool Game::isGameOver() const {
	return isDead;
}