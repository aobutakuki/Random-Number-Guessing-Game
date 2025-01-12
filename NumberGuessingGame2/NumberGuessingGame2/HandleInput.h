#pragma once
#include <iostream>
#include <string>
#include <limits>

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class HandleInput //WILL RETURN 0 ON FAILED INPUT
{
private: 

	bool exception = false;



public:

	template <typename T>
	T Handle() {
		T x;
		std::cin >> x;

		if (std::cin.fail() || !std::cin)
		{
			std::cout << "Exception Detected!" << std::endl;
			if (std::cin.eof()) // If the stream was closed
			{
				exception = true;
				std::exit(0); // Shut down the program now
				
			}

			std::cin.clear();
			ignoreLine();

			exception = true;
			return 0;
		
		}
		exception = false;
		return x;
	}
	//-------------
	template <typename T>
	T Handle(int min, int max) {
		T x;
		std::cin >> x;
		//2
		if (min >= x || x <= max) {

			if (std::cin.fail() || !std::cin)
			{
				std::cout << "Exception Detected! (cin.fail)\n\n\n\n" << std::endl;
				if (std::cin.eof()) // If the stream was closed
				{
					exception = true;
					std::exit(0); // Shut down the program now

				}

				std::cin.clear();
				ignoreLine();

				exception = true;
				return 0;

			}
			exception = false;
			return x;
		}
		else
		{
			exception = true;
			std::cout << "Exception Detected! (invalid)\n\n\n\n" << std::endl;
			return 0;
		}
	}

	void handleLoopStart() { exception = true; }
	bool GetException() { return exception; }
	bool SetException(bool value) {
		exception = value;
		return exception;
	}
};