#ifndef SP_STATE_TPP
#define SP_STATE_TPP

template<int gridSize>
State<gridSize>::State()
	: actionUsed(NONE), gapx(gridSize - 1), gapy(gridSize - 1) {

	parentState = NULL;

	for(int y = 0; y < gridSize; ++y) {
		for(int x = 0; x < gridSize; ++x) {
			puzzleGrid[y][x] = (y * gridSize) + x;

		} // for(int x = 0; x < gridSize; ++x);

	} // for(int y = 0; y < gridSize; ++y);

} // State<gridSize>::State();

template<int gridSize>
State<gridSize>::State(State<gridSize>* prev, Action action) {
	parentState = prev;
	actionUsed = action;

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
			--gapy;

			break;

		case GAP_DOWN:
			if(gapy == gridSize - 1) {
				break;

			} // if(gapy == gridSize - 1);

			puzzleGrid[gapy][gapx] = puzzleGrid[gapy + 1][gapx];
			puzzleGrid[gapy + 1][gapx] = gapVal;
			++gapy;

			break;

		case GAP_LEFT:
			if(gapx == 0) {
				break;

			} // if(gapx == 0);

			puzzleGrid[gapy][gapx] = puzzleGrid[gapy][gapx - 1];
			puzzleGrid[gapy][gapx - 1] = gapVal;
			--gapx;

			break;

		case GAP_RIGHT:
			if(gapx == gridSize - 1) {
				break;

			} // if(gapx == gridSize - 1);

			puzzleGrid[gapy][gapx] = puzzleGrid[gapy][gapx + 1];
			puzzleGrid[gapy][gapx + 1] = gapVal;
			++gapx;

			break;

	} // switch(action);

} // void State<gridSize>::applyAction(Action action);

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

