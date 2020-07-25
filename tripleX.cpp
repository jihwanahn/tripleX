#include <iostream>
#include <ctime>

void print_introduction(const int difficulty)
{
	std::cout << "\n\nYou are a secret agent breaking into a level " << difficulty;
	std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool play_game(const int difficulty)
{
	print_introduction(difficulty);

	const auto code_a = rand() % difficulty + difficulty;
	const auto code_b = rand() % difficulty + difficulty;
	const auto code_c = rand() % difficulty + difficulty;

	const int code_sum = code_a + code_b + code_c;
	const int code_product = code_a * code_b * code_c;

	// Print CodeSum and CodeProduct to the terminal
	std::cout << "+ There are 3 numbers in the code";
	std::cout << "\n+ The codes add-up to: " << code_sum;
	std::cout << "\n+ The codes multiply to give: " << code_product << std::endl;
	// Store player guess
	int guess_a, guess_b, guess_c;
	std::cin >> guess_a >> guess_b >> guess_c;
	auto guess_sum = guess_a + guess_b + guess_c;
	auto guess_product = guess_a * guess_b * guess_c;
	// Check if the players guess is correct
	if (guess_sum == code_sum && guess_product == code_product)
	{
		std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
		return true;
	}
	else
	{
		std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
		return false;
	}
}

int main()
{
	srand(time(nullptr));

	auto level_difficulty = 1;
	auto const max_difficulty = 3;

	while (level_difficulty <= max_difficulty)
	{
		bool b_level_complete = play_game(level_difficulty);
		std::cin.clear();
		std::cin.ignore();

		if (b_level_complete)
		{
			++level_difficulty;
		}
	}

	std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
	return 0;
}
