#ifndef SP_PUZZLE_TPP
#define SP_PUZZLE_TPP

template<int gridSize>
Puzzle<gridSize>::Puzzle()
	: goalState() {

	stateVect.push_back(new State<gridSize>());

	currentState = stateVect.back();

} // Puzzle<gridSize>::Puzzle();

template<int gridSize>
void Puzzle<gridSize>::randomize(int moves) {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> dist(0, 3);

	generator.seed(time(NULL));

	State<gridSize> prev = *currentState;

	for(int i = 0; i < moves; ++i) {
		while(*currentState == prev) {
			currentState->applyAction((Action)dist(generator));

		} // while(currentState == prev);

		prev = *currentState;

	} // for(int i = 0; i < moves; ++i);

} // void Puzzle<gridSize>::randomize(int moves);

template<int gridSize>
bool Puzzle<gridSize>::solveStep() {
	while(true) {
		stateVect.push_back(currentState);

		if(*currentState == goalState) {
			return true;

		} // if(*currentState == goalState);

		for(int i = 0; i < 4; ++i) {
			State<gridSize>* newState = new State<gridSize>(currentState, (Action)i);
			if(!(*currentState == *newState)) {
				bool checked = false;
				bool inQueue = false;
				for(State<gridSize>* s : checkedStates) {
					if(*newState == *s) {
						checked = true;
						break;

					} // if(*newState == *s);

				} // for(State<gridSize>* s : checkedStates);

				if(!checked) {
					for(State<gridSize>* s : stateVect) {
						if(*newState == *s) {
							inQueue = true;

							if(newState->pathCost < s->pathCost) {
								s = newState;

							} // if(newState->pathCost < s->pathCost);

							break;

						} // if(*newState == *s);

					} // for(State<gridSize>* s : stateQueue);

					if(!inQueue) {
						stateQueue.push_back(newState);

					} // if(!inQueue);
	
				} // if(!checked);

			} // if(!(*currentState == newState));

		} // for(int i = 0; i < 4; ++i);

		std::sort(stateQueue.begin(), stateQueue.end(), HeuristicCheck<gridSize>());
		currentState = stateQueue.front();
		stateQueue.pop_front();
	
		// std::cout << currentState->toString() << std::endl;

	} // while(true);

} // bool Puzzle<gridSize>::solveStep();

template<int gridSize>
void Puzzle<gridSize>::solve() {
	solveStep();

	std::cout << "Solved!" << std::endl;

	std::deque<State<gridSize>*> path;

	while(true) {
		path.push_front(currentState);
		if(currentState->parentState) {
			currentState = currentState->parentState;

		} // if(currentState->parentState);
		else {
			break;

		} // else;

	} // while(true);

	for(State<gridSize>* s : path) {
		std::cout << s->toString() << std::endl;

	} // for(State<gridSize>* s : path);

} // void Puzzle<gridSize>::solve();

template<int gridSize>
void Puzzle<gridSize>::printCurrentState() {
	std::cout << currentState->toString();

} // void Puzzle<gridSize>::printCurrentState();

#endif // SP_PUZZLE_TPP
