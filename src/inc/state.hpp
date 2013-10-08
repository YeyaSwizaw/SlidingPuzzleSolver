#ifndef SP_STATE_HPP
#define SP_STATE_HPP

#include "defines.hpp"

#include <array>
#include <string>
#include <sstream>

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

	State();
	State(State<gridSize>* prev, Action action);

	void applyAction(Action action);

	bool operator==(State<gridSize> rhs);

	State<gridSize> *parentState;
	Action actionUsed;
	int puzzleGrid[gridSize][gridSize], gapx, gapy;

	std::string toString();

}; // class State;

#include "state.tpp"

SP_NS_END

#endif // SP_STATE_HPP
