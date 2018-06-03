#include <game.h>
#include <iostream>
#include <sstream>
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
	std::stringstream ss;
	ss << "hunger" << " " << hunger << std::endl;
	ss << "needPoop" << " " << needPoop << std::endl;
	ss << "poops";
	for (bool p : poops) {
		ss << p << " ";
	}
	ss << std::endl;
	ss << "trainNum" << " " << trainNum << std::endl;
	ss << "isTrained" << " " << isTrained << std::endl;
	ss << "isDead" << " " << isDead << std::endl;
	ss << "happy" << " " << happy << std::endl;
	return ss.str();
}

void Game::fromString(std::string str) {
	std::stringstream ss(str);
	std::string keyword;

	while (ss >> keyword) {
		if (keyword == "hunger") {
			ss >> hunger;
		}
		else if (keyword == "needPoop") {
			ss >> needPoop;
		}
		else if (keyword == "poops") {
			for (bool &p : poops) {
				ss >> p;
			}
		}
		else if (keyword == "trainNum") {
			ss >> trainNum;
		}
		else if (keyword == "isTrained") {
			ss >> isTrained;
		}
		else if (keyword == "isDead") {
			ss >> isDead;
		}
		else if (keyword == "happy") {
			ss >> happy;
		}
		else {
			// Bad keyword.
		}
	}
}