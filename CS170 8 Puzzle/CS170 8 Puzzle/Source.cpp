#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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

vector<vector<int>>mv_up(int verPos, int horPos, vector<vector<int>> cur)
{

	vector<vector<int>> up = cur;
	up.at(verPos).at(horPos) = up.at(verPos -1).at(horPos);
	up.at(verPos - 1).at(horPos) = 0;
	return up;
}

vector<vector<int>>mv_down(int verPos, int horPos, vector<vector<int>> cur)
{

	vector<vector<int>> up = cur;
	up.at(verPos).at(horPos) = up.at(verPos + 1).at(horPos);
	up.at(verPos + 1).at(horPos) = 0;
	return up;
}

vector<vector<int>>mv_left(int verPos, int horPos, vector<vector<int>> cur)
{

	vector<vector<int>> up = cur;
	up.at(verPos).at(horPos) = up.at(verPos).at(horPos - 1);
	up.at(verPos).at(horPos - 1) = 0;
	return up;
}

vector<vector<int>>mv_right(int verPos, int horPos, vector<vector<int>> cur)
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
	vector<vector<int>>goal{ { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 0 } };

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
		int g = 0;
		int h = 0;;
		node *next = NULL;
		node *prev = NULL;
		vector<vector<int>> cur;
	};



	//-------------------------Uniform Cost Search-------------------------//
	if (choice == 1)
	{
		node *given = new node;
		given->cur = eight_puzzle;

		queue <node*> UCS;
		node *init = new node;
		init->cur = eight_puzzle;
		
		//Z_Pos(verPos, horPos, init->cur);

		node *current = init;

		
		UCS.push(init);
		
		while (current->cur != goal)
		{
			current = UCS.front();
			Z_Pos(verPos, horPos, current->cur);
			UCS.pop();

			if (verPos == 0 && horPos == 0)
			{
				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				UCS.push(right);


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				UCS.push(down);
			}

			else if (verPos == 0 && horPos == 1)
			{
				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				UCS.push(left);


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				UCS.push(right);


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				UCS.push(down);
			}

			else if (verPos == 0 && horPos == 2)
			{
				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				UCS.push(left);


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				UCS.push(down);
			}

			else if (verPos == 1 && horPos == 0)
			{
				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				UCS.push(up);


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				UCS.push(right);


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				UCS.push(down);
			}

			else if (verPos == 1 && horPos == 1)
			{
				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				UCS.push(up);


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				UCS.push(right);


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				UCS.push(down);


				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				UCS.push(left);
			}
			
			else if (verPos == 1 && horPos == 2)
			{
				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				UCS.push(up);


				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				UCS.push(left);


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				UCS.push(down);
			}

			else if (verPos == 2 && horPos == 0)
			{
				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				UCS.push(up);


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				UCS.push(right);
			}

			else if (verPos == 2 && horPos == 1)
			{
				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				UCS.push(left);


				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				UCS.push(up);


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				UCS.push(right);
			}

			else if (verPos == 2 && horPos == 2)
			{
				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				UCS.push(left);


				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				UCS.push(up);
			}
		}
		
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				cout << init->cur.at(i).at(k) << " ";
			}
			cout << endl;
		}
		cout << endl;

		stack<vector<vector<int>>> solution;
		while (current->cur != given->cur)
		{
			solution.push(current->cur);
			current = current->prev;
		}

		

		while (solution.empty() != 1)
		{
			node *display = new node;
			display->cur = solution.top();
			solution.pop();

			for (int i = 0; i < 3; i++)
			{
				for (int k = 0; k < 3; k++)
				{
					cout << display->cur.at(i).at(k) << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

	}



	cin.get();

	return 0;
}