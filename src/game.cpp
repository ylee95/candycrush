#include <game.h>
#include <iostream>
#include <string>

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

std::string Game::toString() {
	std::string ret = "";
	ret += "hunger " + std::to_string(hunger) + "\n";
	ret += "needPoop " + std::to_string(needPoop) + "\n";
	ret += "poops";
	for (bool p : poops) {
		std::string str = p ? "true" : "false";
		ret += " " + str;
	}
	ret += "\n";
	ret += "trainNum " + std::to_string(trainNum) + "\n";
	std::string str = isTrained ? "true" : "false";
	ret += "isTrained " + str + "\n";
	str = isDead ? "true" : "false";
	ret += "isDead " + str;
}

Game fromString(std::string str) {
	// ?? not know what to do?
}