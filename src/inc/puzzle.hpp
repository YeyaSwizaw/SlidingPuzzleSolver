#ifndef SP_PUZZLE_HPP
#define SP_PUZZLE_HPP

#include "defines.hpp"
#include "state.hpp"

#include <ctime>
#include <iostream>
#include <random>

SP_NS

template<int gridSize>
class Puzzle {
public:
	void randomize(int moves = 3 * gridSize * gridSize);

	void printCurrentState();

private:
	State<gridSize> currentState;

}; // class Puzzle;

#include "puzzle.tpp"

SP_NS_END

#endif // SP_PUZZLE_HPP
