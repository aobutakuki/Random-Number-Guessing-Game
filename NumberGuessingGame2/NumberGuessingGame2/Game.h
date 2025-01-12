#pragma once
#include <iostream>
#include <thread>

class Game
{
private:
	bool m_answer = false;
	bool m_lives = false;
	bool isAlive = true;
	
	int attempt{ 0 };
	int HP{ 3 };

	int answer{ 0 };

	int intervalX = 1;
	int intervalY = 100;


	void GenerateNumber();
	void Number_deRef(int& intX, int& intY);
	void GenerateNumber(int x, int y, bool lives, int livCount);
	void NewAdvanced();

public:

	void NewGame();
	void CheckAnswer();
	void DisplayInfo();
	void DisplayInfo(bool lives);

	bool checkAlive() { return isAlive; }
	bool checkAnswer() { return m_answer; }
	bool checkGameLives() { return m_lives; }
};

