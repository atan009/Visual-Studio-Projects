#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int choice;

	cout << "Welcome to Alex Tan's 8-puzzle solver." << endl;
	cout << "type \"1\" to use default puzzle, or \"2\" to enter your own puzzle" << endl;

	
	cin >> choice;
	
	if(choice != 1 && choice != 2)
	{
		cout << "invalid choice, exiting" << endl;
		return 0;
	}
		

	cout << choice << " selected" << endl;

	vector<vector<int>>eight_puzzle{ { 0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

	if (choice == 2)
	{
		cout << "Enter your puzzle, use a zero to represent the blank" << endl;
		int holder;

		cout << "Enter the first row, use space or tabs between numbers" << endl;
		cin >> holder;
		eight_puzzle.at(0).at(0) = holder;
		cin >> holder;
		eight_puzzle.at(0).at(1) = holder;
		cin >> holder;
		eight_puzzle.at(0).at(2) = holder;

		cout << "Enter the second row, use space or tabs between numbers" << endl;
		cin >> holder;
		eight_puzzle.at(1).at(0) = holder;
		cin >> holder;
		eight_puzzle.at(1).at(1) = holder;
		cin >> holder;
		eight_puzzle.at(1).at(2) = holder;

		cout << "Enter the third row, use space or tabs between numbers" << endl;
		cin >> holder;
		eight_puzzle.at(2).at(0) = holder;
		cin >> holder;
		eight_puzzle.at(2).at(1) = holder;
		cin >> holder;
		eight_puzzle.at(2).at(2) = holder;
		cout << endl;
	}

	/*
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			cout << eight_puzzle.at(i).at(k) << " ";
		}
		cout << endl;
	}
	*/
	

	cout << "Enter your choice of algorithm" << endl;
	cout << "1. Uniform cost search" << endl;
	cout << "2. A* with misplace tile heuristic" << endl;
	cout << "3. A* with the manhattan distance heuristic" << endl;

	cin >> choice;

	if (choice != 1 && choice != 2 && choice != 3)
	{
		cout << "invalid choice, exiting" << endl;
		return 0;
	}

	//Uniform Cost Search
	if (choice == 1)
	{



	}

	cin.get();

	return 0;
}