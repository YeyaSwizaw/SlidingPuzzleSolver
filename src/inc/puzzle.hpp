#ifndef SP_PUZZLE_HPP
#define SP_PUZZLE_HPP

#include "defines.hpp"
#include "state.hpp"

#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <queue>

SP_NS

template<int gridSize>
class Puzzle {
public:
	Puzzle<gridSize>();

	void randomize(int moves = 3 * gridSize * gridSize);
	void solve();

	void printCurrentState();

private:
	std::vector<State<gridSize>*> stateVect;

	std::deque<State<gridSize>*> stateQueue;
	std::vector<State<gridSize>*> checkedStates;

	State<gridSize>* currentState;
	State<gridSize> goalState;

	bool solveStep();

}; // class Puzzle;

#include "puzzle.tpp"

SP_NS_END

#endif // SP_PUZZLE_HPP
