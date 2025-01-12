#include "Game.h"

#include "Random.h"
#include "HandleInput.h"

HandleInput handle;

void Game::GenerateNumber() {

	//Default values are 1-100
	Game::answer = Random::get(1, 100);

	std::cout << "Number being generated in default conditions\n";


}

void Game::GenerateNumber(int x, int y, bool lives, int livCount) {

	Game::answer = Random::get(x, y);
	m_lives = lives;
	HP = livCount;

	std::cout << "Number generated in user-specified conditions >> \n" << "Interval: " << x << " - " << y << std::endl;

	if (lives) {
		std::cout << "New game will be created with >> " << livCount << " LIVES" << std::endl;

		
		HP = livCount;
	}

}

void Game::Number_deRef(int& intX, int& intY)
{
	std::cout << "Loading Parameters...";
	intervalX = intX;
	intervalY = intY;
	std::this_thread::sleep_for(std::chrono::milliseconds(4000));

}


void Game::CheckAnswer() {
	
	attempt++;
	int userInput = 0;


	handle.handleLoopStart();
	while (handle.GetException())
	{
		std::cout << "\nEnter your guess: ";
		int uInput = handle.Handle<int>(intervalX,intervalY);

		if (handle.GetException() || intervalX < uInput  && uInput > intervalY) {
			std::cout << "INVALID GUESS! Guess must be an integer between " << intervalX << " and " << intervalY;
		}
		else {
			userInput = uInput;
			break;
		}
	}


	if (isAlive) {

		if (userInput == answer)
		{
			m_answer = true;

			std::cout << "\nCongratulations! You've won!\n" << std::endl;


		}
		else
		{
			if (userInput > answer)
			{
				std::cout << "\nThe answer is a lower number" << std::endl;
				return;
			}
			if (userInput < answer)
			{
				std::cout << "\nThe answer is a bigger number" << std::endl;
				return;
			}


		}

	}

}

void Game::DisplayInfo() 
{
	if (!m_answer) {
		std::cout << attempt << " Attempt(s)!\n";
	}
	if (m_answer)
	{
		system("cls");
		std::cout << "Answer found in " << attempt << " Attempt(s)";
	}
}

void Game::DisplayInfo(bool lives) 
{
	HP--;

	
	if (!m_answer) {
		if (HP <= 0)
		{
			isAlive = false;
		}
		if (isAlive)
		{
			std::cout << attempt << " Attempt(s)!\n";
			std::cout << HP << " Lives left!\n";
			

		}
		else if (!isAlive)
		{
			std::cout << "Game Over!\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout << "The answer was: " << answer << std::endl;
			std::cout << "\n\n\n\n";
		}
	}

	if (m_answer)
	{
		system("cls");
		std::cout << "Answer found in " << attempt << " Attempt(s)";
	}
}

void Game::NewGame()
{
	handle.handleLoopStart();
	while (handle.GetException()) {
		std::cout << "Number Guessing Game!\n";
		std::cout << "Enter <1> for Default Mode or <2> for Advanced Mode\n";

		int input = handle.Handle<int>(1,2);

		if (input == 1)
		{
			system("cls");
			std::cout << "Game will start in Default Mode...\n" <<
				"On Default Mode, the number of guesses is unlimited!\n" <<
				"The answer number ranges from 1 to 100\n" <<
				"Good Luck!\n";

			GenerateNumber();
			std::this_thread::sleep_for(std::chrono::milliseconds(4000));
			break;
		}
		if (input == 2)
		{
			system("cls");
			std::cout << "Game will start in Advanced Mode...\n" <<
				"For Advanced Mode you can set the values for the game\n";

			NewAdvanced();
			
			break;
		}
		else
		{
			std::cout << "\n\n\n\nInvalid Input!\n *Must be a integer value 1 or 2*\n";
		}

	}



}


void Game::NewAdvanced() 
{
	bool menuTrue = true;
	while (menuTrue) {
		system("cls");
		std::cout << "Advanced Setup Menu\n";

		static int numberX = 1;
		static int numberY = 100;

		std::cout << "1. Set Number Value " << "(NOW: " << numberX << " - " << numberY << " )\n";

		static int lifeCount = 5;
		static bool Elives = true;
		if (Elives) {
			std::cout << "2. Set Lives " << "(NOW: " << lifeCount << " Lives" << " )\n";
		}
		else if (!Elives)
		{
			std::cout << "2. Set Lives " << "(NOW: DISABLED)\n";
		}

		std::cout << "3. Start Game\n";


		handle.handleLoopStart();
		while (handle.GetException()) {
			std::cout << ">: ";
			int input = handle.Handle<int>(1, 3);

			if (input == 1)
			{
				system("cls");
				std::cout << "1. Set Number Value " << "(NOW: " << numberX << " - " << numberY << " )\n";
				std::cout << "Enter two values: \n";

				handle.handleLoopStart();
				while (handle.GetException())
				{
					std::cout << "Value 1: ";
					int input1 = handle.Handle<int>(1, 1000);
					std::cout << std::endl;

					std::cout << "Value 2: ";
					int input2 = handle.Handle<int>(1, 1000);
					std::cout << std::endl;

					if (input1 == input2)
					{
						std::cout << "Error Code 2: The values cannot be the same!\n";
						handle.SetException(true);
					}
					else if (input1 <= 0 || input1 > 1000 || input2 <= 0 || input2 > 1000)
					{
						std::cout << "Error Code 3: The values must be between 1 and 1000";
						handle.SetException(true);
					}
					else if (!handle.GetException())
					{
						numberX = input1;
						numberY = input2;
						std::cout << "Numbers changed!";
						break;
					}
					else
						std::cout << "Error code 10: Unexpected Fail on handle.Handle()";
				}


			}
			if (input == 2)
			{
				system("cls");
				if (Elives) {
					std::cout << "2. Set Lives " << "(NOW: " << lifeCount << " Lives" << " )\n";
				}
				else if (!Elives)
				{
					std::cout << "2. Set Lives " << "(NOW: DISABLED)\n";
				}

				std::cout << "Enter the number of lives desired (OR) <0> to disable!\n";

				handle.handleLoopStart();
				while (handle.GetException())
				{
					std::cout << "Value: ";
					int input1 = handle.Handle<int>(1, 20);
					std::cout << std::endl;

					if (input1 == 0)
					{
						m_lives = false;
						Elives = false;
						std::cout << "Lives have now been disabled!\n";

					}
					if (input1 < 0 || input1 > 20) {
						std::cout << "Error Code 3: The values must be between 1 and 20";
						handle.SetException(true);
					}
					else if (!handle.GetException())
					{
						HP = input1;
						lifeCount = HP;
						std::cout << "Lives have now been changed to " << HP << "!\n";
					}
					else
						std::cout << "Error code 10: Unexpected Fail on handle.Handle()";
					
				}

			}
			if (input == 3) 
			{
				Game::Number_deRef(numberX, numberY);
				system("cls");
				Game::GenerateNumber(numberX, numberY, Elives, lifeCount);
				menuTrue = false;
				break;
			}
			else
			{
				std::cout << "\n\n\n\nInvalid Input!\n *Must be a integer value 1, 2 or 3*\n";

			}
			
		}
		
	}
}