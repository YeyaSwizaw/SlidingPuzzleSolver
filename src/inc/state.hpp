#ifndef SP_STATE_HPP
#define SP_STATE_HPP

#include "defines.hpp"

#include <cmath>
#include <array>
#include <string>
#include <sstream>
#include <iostream>

SP_NS

enum Action {
	GAP_UP,
	GAP_DOWN,
	GAP_LEFT,
	GAP_RIGHT,

	NONE

}; // enum Action;

template<int gridSize>
class State {
public:
	static const int gapVal = gridSize * gridSize - 1;

	static int nextId;
	int id;

	State();
	State(State<gridSize>* prev, Action action);

	void applyAction(Action action);

	void calcHeuristic(int num, int x1, int y1, int x2, int y2);

	bool operator==(State<gridSize> rhs);

	State<gridSize> *parentState;
	Action actionUsed;
	int puzzleGrid[gridSize][gridSize], gapx, gapy;

	int pathCost, heuristic;

	std::string toString();

}; // class State;

template<int gridSize>
struct HeuristicCheck {
	bool operator()(State<gridSize>* lhs, State<gridSize>* rhs) {
		return (lhs->heuristic + lhs->pathCost) < (rhs->heuristic + rhs->pathCost);

	} // bool operator()(State<gridSize>* lhs, State<gridSize>* rhs);

}; // struct heuristicCheck<gridSize>;

template<int gridSize>
int State<gridSize>::nextId = 0;

#include "state.tpp"

SP_NS_END

#endif // SP_STATE_HPP
