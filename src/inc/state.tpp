#ifndef SP_STATE_TPP
#define SP_STATE_TPP

template<int gridSize>
State<gridSize>::State()
	: id(nextId++), actionUsed(NONE), gapx(gridSize - 1), gapy(gridSize - 1),
	  pathCost(0), heuristic(0) {

	parentState = NULL;

	for(int y = 0; y < gridSize; ++y) {
		for(int x = 0; x < gridSize; ++x) {
			puzzleGrid[y][x] = (y * gridSize) + x;

		} // for(int x = 0; x < gridSize; ++x);

	} // for(int y = 0; y < gridSize; ++y);

} // State<gridSize>::State();

template<int gridSize>
State<gridSize>::State(State<gridSize>* prev, Action action)
	: id(nextId++) {

	parentState = prev;
	actionUsed = action;

	pathCost = prev->pathCost + 1;

	for(int y = 0; y < gridSize; ++y) {
		for(int x = 0; x < gridSize; ++x) {
			puzzleGrid[y][x] = prev->puzzleGrid[y][x];

		} // for(int x = 0; x < gridSize; ++x);

	} // for(int y = 0; y < gridSize; ++y);

	gapx = prev->gapx;
	gapy = prev->gapy;

	applyAction(action);

} // State<gridSize>::State(State<gridSize>* prev, Action action);

template<int gridSize>
void State<gridSize>::applyAction(Action action) {
	switch(action) {
		case GAP_UP:
			if(gapy == 0) {
				break;

			} // if(prev->gapy == 0);

			puzzleGrid[gapy][gapx] = puzzleGrid[gapy - 1][gapx];
			puzzleGrid[gapy - 1][gapx] = gapVal;

			calcHeuristic(puzzleGrid[gapy][gapx], gapx, gapy, gapx, gapy - 1);

			--gapy;

			break;

		case GAP_DOWN:
			if(gapy == gridSize - 1) {
				break;

			} // if(gapy == gridSize - 1);

			puzzleGrid[gapy][gapx] = puzzleGrid[gapy + 1][gapx];
			puzzleGrid[gapy + 1][gapx] = gapVal;

			calcHeuristic(puzzleGrid[gapy][gapx], gapx, gapy, gapx, gapy + 1);

			++gapy;

			break;

		case GAP_LEFT:
			if(gapx == 0) {
				break;

			} // if(gapx == 0);

			puzzleGrid[gapy][gapx] = puzzleGrid[gapy][gapx - 1];
			puzzleGrid[gapy][gapx - 1] = gapVal;

			calcHeuristic(puzzleGrid[gapy][gapx], gapx, gapy, gapx - 1, gapy);

			--gapx;

			break;

		case GAP_RIGHT:
			if(gapx == gridSize - 1) {
				break;

			} // if(gapx == gridSize - 1);

			puzzleGrid[gapy][gapx] = puzzleGrid[gapy][gapx + 1];
			puzzleGrid[gapy][gapx + 1] = gapVal;

			calcHeuristic(puzzleGrid[gapy][gapx], gapx, gapy, gapx + 1, gapy);

			++gapx;

			break;

	} // switch(action);

} // void State<gridSize>::applyAction(Action action);

template<int gridSize>
void State<gridSize>::calcHeuristic(int num, int x1, int y1, int x2, int y2) {
	int goalX = (num > 0) ? (num % gridSize) : 0;
	int goalY = (num > 0) ? (num / gridSize) : 0;

	// std::cout << num << ": (" << x << " - " << goalX << ") + (" << y << " - " << goalY << ")" << std::endl;

	heuristic = (abs(goalX - x1) - abs(goalX - x2)) + (abs(goalY - y1) - abs(goalY - y2)) + 1;

} // void State<gridSize>::calcHeuristic(int num, int x, int y);

template<int gridSize>
bool State<gridSize>::operator==(State<gridSize> rhs) {
	for(int y = 0; y < gridSize; ++y) {
		for(int x = 0; x < gridSize; ++x) {
			if(puzzleGrid[y][x] != rhs.puzzleGrid[y][x]) {
				return false;

			} // if(puzzleGrid[y][x] != rhs.puzzleGrid[y][x]);

		} // for(int x = 0; x < gridSize; ++x);

	} // for(int y = 0; y < gridSize; ++y);

	return true;

} // bool State<gridSize>::operator==(State<gridSize> rhs);

template<int gridSize>
std::string State<gridSize>::toString() {
	std::stringstream sstream;

	if(parentState) {
		sstream << parentState->id << "->";

	} // if(parentState);

	sstream << id << "(" << pathCost << " + " << heuristic << "):" << std::endl;

	for(int y = 0; y < gridSize; ++y) {
		for(int x = 0; x < gridSize; ++x) {
			if(puzzleGrid[y][x] == (gridSize * gridSize - 1)) {
				sstream << "   ";


			} // if(puzzleGrid[y][x] == (gridSize ^ 2));
			else {
				if(puzzleGrid[y][x] < 10) {
					sstream << " ";

				} // if(puzzleGrid[y][x] < 10);

				sstream << puzzleGrid[y][x] << " ";

			} // else;

		} // for(int x = 0; x < gridSize; ++x);

		sstream << std::endl;

	} // for(int y = 0; y < gridSize; ++y);

	return sstream.str();

} // std::string State<gridSize>::toString();

#endif // SP_STATE_TPP

