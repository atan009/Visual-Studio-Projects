#include <iostream>
#include <vector>

using namespace std;

int Z_Pos(int &verPos, int &horPos, vector<vector<int>> cur)
{
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (cur.at(i).at(k) == 0)
			{
				verPos = i;
				horPos = k;
			}
		}
	}
	return 0;
}

vector<vector<int>>up(int verPos, int horPos, vector<vector<int>> cur)
{

	vector<vector<int>> up = cur;
	up.at(verPos).at(horPos) = up.at(verPos -1).at(horPos);
	up.at(verPos - 1).at(horPos) = 0;
	return up;
}

vector<vector<int>>down(int verPos, int horPos, vector<vector<int>> cur)
{

	vector<vector<int>> up = cur;
	up.at(verPos).at(horPos) = up.at(verPos + 1).at(horPos);
	up.at(verPos + 1).at(horPos) = 0;
	return up;
}

vector<vector<int>>left(int verPos, int horPos, vector<vector<int>> cur)
{

	vector<vector<int>> up = cur;
	up.at(verPos).at(horPos) = up.at(verPos).at(horPos - 1);
	up.at(verPos).at(horPos - 1) = 0;
	return up;
}

vector<vector<int>>right(int verPos, int horPos, vector<vector<int>> cur)
{

	vector<vector<int>> up = cur;
	up.at(verPos).at(horPos) = up.at(verPos).at(horPos + 1);
	up.at(verPos).at(horPos + 1) = 0;
	return up;
}

//-------------------------MOVEMENT + CHECK-------------------------//

int main()
{
	int verPos;
	int horPos;
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

	if (choice == 1)
	{
		eight_puzzle.at(0).at(0) = 1;
		eight_puzzle.at(0).at(1) = 5;
		eight_puzzle.at(0).at(2) = 3;

		eight_puzzle.at(0).at(0) = 4;
		eight_puzzle.at(0).at(1) = 0;
		eight_puzzle.at(0).at(2) = 6;

		eight_puzzle.at(0).at(0) = 7;
		eight_puzzle.at(0).at(1) = 2;
		eight_puzzle.at(0).at(2) = 8;
	}
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


	struct node
	{
		int g;
		int h;
		node *next;
		node *prev;
		vector<vector<int>> cur;
	};



	//Uniform Cost Search
	if (choice == 1)
	{
		node init;
		init.cur = eight_puzzle;
		Z_Pos(verPos, horPos, init.cur);

		node current = init;
		current.cur = right(verPos,horPos,init.cur);

		
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				cout << current.cur.at(i).at(k) << " ";
			}
			cout << endl;
		}
		
	}

	/*
	vector<vector<int>>test_puzzle{ { 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } };
	if (eight_puzzle == test_puzzle)
	{
		cout << "test";
	}
	*/

	cin.get();

	return 0;
}