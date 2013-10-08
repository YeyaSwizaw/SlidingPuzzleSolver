#ifndef SP_PUZZLE_TPP
#define SP_PUZZLE_TPP

template<int gridSize>
Puzzle<gridSize>::Puzzle() {
	stateVect.push_back(State<gridSize>());

	currentState = &(stateVect.back());

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
void Puzzle<gridSize>::printCurrentState() {
	std::cout << currentState->toString();

} // void Puzzle<gridSize>::printCurrentState();

#endif // SP_PUZZLE_TPP
