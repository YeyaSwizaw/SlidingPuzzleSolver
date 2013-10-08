#include "inc/puzzle.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
	sp::Puzzle<4> puzzle;

	std::cout << "Goal State:" << std::endl;
	puzzle.printCurrentState();

	std::cout << std::endl << "Initial State:" << std::endl;
	puzzle.randomize();
	puzzle.printCurrentState();

	return 0;

} // int main(int argc, char* argv[]);
