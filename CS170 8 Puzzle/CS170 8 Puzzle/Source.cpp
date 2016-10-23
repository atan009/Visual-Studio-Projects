#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

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

int misplaced(vector<vector<int>> current)
{
	int misplaced = 0;
	if (current.at(0).at(0) != 1)
	{
		misplaced += 1;
	}
	if (current.at(0).at(0) != 2)
	{
		misplaced += 1;
	}
	if (current.at(0).at(0) != 3)
	{
		misplaced += 1;
	}
	if (current.at(0).at(0) != 4)
	{
		misplaced += 1;
	}
	if (current.at(0).at(0) != 5)
	{
		misplaced += 1;
	}
	if (current.at(0).at(0) != 6)
	{
		misplaced += 1;
	}
	if (current.at(0).at(0) != 7)
	{
		misplaced += 1;
	}
	if (current.at(0).at(0) != 8)
	{
		misplaced += 1;
	}
	return misplaced;
}

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
		eight_puzzle.at(0).at(1) = 2;
		eight_puzzle.at(0).at(2) = 3;

		eight_puzzle.at(1).at(0) = 4;
		eight_puzzle.at(1).at(1) = 8;
		eight_puzzle.at(1).at(2) = 0;

		eight_puzzle.at(2).at(0) = 7;
		eight_puzzle.at(2).at(1) = 6;
		eight_puzzle.at(2).at(2) = 5;
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
		

		node *current = init;

		
		UCS.push(init);
		vector<vector<vector<int>>> traversed;
		traversed.push_back(current->cur);
		


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
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					UCS.push(right);
					traversed.push_back(right->cur);
				}


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					UCS.push(down);
					traversed.push_back(down->cur);
				}
			}

			else if (verPos == 0 && horPos == 1)
			{
				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), left->cur) == traversed.end())
				{
					UCS.push(left);
					traversed.push_back(left->cur);
				}


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					UCS.push(right);
					traversed.push_back(right->cur);
				}


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					UCS.push(down);
					traversed.push_back(down->cur);
				}
			}

			else if (verPos == 0 && horPos == 2)
			{
				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), left->cur) == traversed.end())
				{
					UCS.push(left);
					traversed.push_back(left->cur);
				}


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					UCS.push(down);
					traversed.push_back(down->cur);
				}
			}

			else if (verPos == 1 && horPos == 0)
			{
				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), up->cur) == traversed.end())
				{
					UCS.push(up);
					traversed.push_back(up->cur);
				}


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					UCS.push(right);
					traversed.push_back(right->cur);
				}


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					UCS.push(down);
					traversed.push_back(down->cur);
				}
			}

			else if (verPos == 1 && horPos == 1)
			{
				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), up->cur) == traversed.end())
				{
					UCS.push(up);
					traversed.push_back(up->cur);
				}


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					UCS.push(right);
					traversed.push_back(right->cur);
				}


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					UCS.push(down);
					traversed.push_back(down->cur);
				}


				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), left->cur) == traversed.end())
				{
					UCS.push(left);
					traversed.push_back(left->cur);
				}
			}
			
			else if (verPos == 1 && horPos == 2)
			{
				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					UCS.push(down);
					traversed.push_back(down->cur);
				}


				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), up->cur) == traversed.end())
				{
					UCS.push(up);
					traversed.push_back(up->cur);
				}


				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), left->cur) == traversed.end())
				{
					UCS.push(left);
					traversed.push_back(left->cur);
				}
			}

			else if (verPos == 2 && horPos == 0)
			{
				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), up->cur) == traversed.end())
				{
					UCS.push(up);
					traversed.push_back(up->cur);
				}


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					UCS.push(right);
					traversed.push_back(right->cur);
				}
			}

			else if (verPos == 2 && horPos == 1)
			{

				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), up->cur) == traversed.end())
				{
					UCS.push(up);
					traversed.push_back(up->cur);
				}


				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), left->cur) == traversed.end())
				{
					UCS.push(left);
					traversed.push_back(left->cur);
				}


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					UCS.push(right);
					traversed.push_back(right->cur);
				}
			}

			else if (verPos == 2 && horPos == 2)
			{
				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), left->cur) == traversed.end())
				{
					UCS.push(left);
					traversed.push_back(left->cur);
				}


				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), up->cur) == traversed.end())
				{
					UCS.push(up);
					traversed.push_back(up->cur);
				}
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

	//-------------------------Uniform Cost Search-------------------------//


	//-------------------------A* with the Misplaced Tile Heuristic-------------------------//
	else if (choice == 2)
	{
		node *given = new node;
		given->cur = eight_puzzle;


		node *init = new node;
		init->cur = eight_puzzle;


		node *current = init;


		vector<vector<vector<int>>> traversed;
		traversed.push_back(current->cur);

		vector<queue<node*>>a_misplaced(31+9);//max depth + incorrect nodes
		a_misplaced.at(misplaced(init->cur)).push(init);

		while (current->cur != goal)
		{
			for (int i = 0; i < 40; i++)
			{
				if (!a_misplaced.at(i).empty())
				{
					current = a_misplaced.at(i).front();
					a_misplaced.at(i).pop();
					break;
				}
			}

			/*
			if (!a_misplaced.at(0).empty())
			{
				current = a_misplaced.at(0).front();
				a_misplaced.at(0).pop();
			}

			else if (!a_misplaced.at(1).empty())
			{
				current = a_misplaced.at(1).front();
				a_misplaced.at(1).pop();
			}

			else if (!a_misplaced.at(2).empty())
			{
				current = a_misplaced.at(2).front();
				a_misplaced.at(2).pop();
			}

			else if (!a_misplaced.at(3).empty())
			{
				current = a_misplaced.at(3).front();
				a_misplaced.at(3).pop();
			}

			else if (!a_misplaced.at(4).empty())
			{
				current = a_misplaced.at(4).front();
				a_misplaced.at(4).pop();
			}

			else if (!a_misplaced.at(5).empty())
			{
				current = a_misplaced.at(5).front();
				a_misplaced.at(5).pop();
			}

			else if (!a_misplaced.at(6).empty())
			{
				current = a_misplaced.at(6).front();
				a_misplaced.at(6).pop();
			}

			else if (!a_misplaced.at(7).empty())
			{
				current = a_misplaced.at(7).front();
				a_misplaced.at(7).pop();
			}

			else if (!a_misplaced.at(8).empty())
			{
				current = a_misplaced.at(8).front();
				a_misplaced.at(8).pop();
			}
			*/
			Z_Pos(verPos, horPos, current->cur);


			if (verPos == 0 && horPos == 0)
			{
				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					right->g += 1;
					right->h = misplaced(right->cur);
					if (right->g + right->h < 40)
					{
						a_misplaced.at(right->g + right->h).push(right);
						traversed.push_back(right->cur);
					}
				}


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					down->g += 1;
					down->h = misplaced(down->cur);
					if (down->g + down->h < 40)
					{
						a_misplaced.at(down->g + down->h).push(down);
						traversed.push_back(down->cur);
					}
				}
			}

			else if (verPos == 0 && horPos == 1)
			{
				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), left->cur) == traversed.end())
				{
					left->g += 1;
					left->h = misplaced(left->cur);
					if (left->g + left->h < 40)
					{
						a_misplaced.at(left->g + left->h).push(left);
						traversed.push_back(left->cur);
					}
				}


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					right->g += 1;
					right->h = misplaced(right->cur);
					if (right->g + right->h < 40)
					{
						a_misplaced.at(right->g + right->h).push(right);
						traversed.push_back(right->cur);
					}
				}


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					down->g += 1;
					down->h = misplaced(right->cur);
					if (down->g + down->h < 40)
					{
						a_misplaced.at(down->g + down->h).push(down);
						traversed.push_back(down->cur);
					}
				}
			}

			else if (verPos == 0 && horPos == 2)
			{
				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), left->cur) == traversed.end())
				{
					left->g += 1;
					left->h = misplaced(left->cur);
					if (left->g + left->h < 40)
					{
						a_misplaced.at(left->g + left->h).push(left);
						traversed.push_back(left->cur);
					}
				}


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					down->g += 1;
					down->h = misplaced(down->cur);
					if (down->g + down->h < 40)
					{
						a_misplaced.at(down->g + down->h).push(down);
						traversed.push_back(down->cur);
					}
				}
			}

			else if (verPos == 1 && horPos == 0)
			{
				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), up->cur) == traversed.end())
				{
					up->g += 1;
					up->h = misplaced(up->cur);
					if (up->g + up->h < 40)
					{
						a_misplaced.at(up->g + up->h).push(up);
						traversed.push_back(up->cur);
					}
				}


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					right->g += 1;
					right->h = misplaced(right->cur);
					if (right->g + right->h < 40)
					{
						a_misplaced.at(right->g + right->h).push(right);
						traversed.push_back(right->cur);
					}
				}


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					down->g += 1;
					down->h = misplaced(down->cur);
					if (down->g + down->h < 40)
					{
						a_misplaced.at(down->g + down->h).push(down);
						traversed.push_back(down->cur);
					}
				}
			}

			else if (verPos == 1 && horPos == 1)
			{
				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), up->cur) == traversed.end())
				{
					up->g += 1;
					up->h = misplaced(up->cur);
					if (up->g + up->h < 40)
					{
						a_misplaced.at(up->g + up->h).push(up);
						traversed.push_back(up->cur);
					}
				}


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					right->g += 1;
					right->h = misplaced(right->cur);
					if (right->g + right->h < 40)
					{
						a_misplaced.at(right->g + right->h).push(right);
						traversed.push_back(right->cur);
					}
				}


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					down->g += 1;
					down->h = misplaced(down->cur);
					if (down->g + down->h < 40)
					{
						a_misplaced.at(down->g + down->h).push(down);
						traversed.push_back(down->cur);
					}
				}


				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), left->cur) == traversed.end())
				{
					left->g += 1;
					left->h = misplaced(left->cur);
					if (left ->g + left->h < 40)
					{
						a_misplaced.at(left->g + left->h).push(left);
						traversed.push_back(left->cur);
					}
				}
			}

			else if (verPos == 1 && horPos == 2)
			{
				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					down->g += 1;
					down->h = misplaced(down->cur);
					if (down->g + down->h < 40)
					{
						a_misplaced.at(down->g + down->h).push(down);
						traversed.push_back(down->cur);
					}
				}


				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), up->cur) == traversed.end())
				{
					up->g += 1;
					up->h = misplaced(up->cur);
					if (up->g + up->h < 40)
					{
						a_misplaced.at(up->g + up->h).push(up);
						traversed.push_back(up->cur);
					}
				}


				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), left->cur) == traversed.end())
				{
					left->g += 1;
					left->h = misplaced(left->cur);
					if (left->g + left->h < 40)
					{
						a_misplaced.at(left->g + left->h).push(left);
						traversed.push_back(left->cur);
					}
				}
			}

			else if (verPos == 2 && horPos == 0)
			{
				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), up->cur) == traversed.end())
				{
					up->g += 1;
					up->h = misplaced(up->cur);
					if (up->g + up->h < 40)
					{
						a_misplaced.at(up->g + up->h).push(up);
						traversed.push_back(up->cur);
					}
				}


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					right->g += 1;
					right->h = misplaced(right->cur);
					if (right->g + right->h < 40)
					{
						a_misplaced.at(right->g + right->h).push(right);
						traversed.push_back(right->cur);
					}
				}
			}

			else if (verPos == 2 && horPos == 1)
			{

				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), up->cur) == traversed.end())
				{
					up->g += 1;
					up->h = misplaced(up->cur);
					if (up->g + up->h < 40)
					{
						a_misplaced.at(up->g + up->h).push(up);
						traversed.push_back(up->cur);
					}
				}


				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), left->cur) == traversed.end())
				{
					left->g += 1;
					left->h = misplaced(left->cur);
					if (left->g + left->h < 40)
					{
						a_misplaced.at(left->g + left->h).push(left);
						traversed.push_back(left->cur);
					}
				}


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					right->g += 1;
					right->h = misplaced(right->cur);
					if (right->g + right->h < 40)
					{
						a_misplaced.at(right->g + right->h).push(right);
						traversed.push_back(right->cur);
					}
				}
			}

			else if (verPos == 2 && horPos == 2)
			{
				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), left->cur) == traversed.end())
				{
					left->g += 1;
					left->h = misplaced(left->cur);
					if (left->g + left->h < 40)
					{
						a_misplaced.at(left->g + left->h).push(left);
						traversed.push_back(left->cur);
					}
				}


				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), up->cur) == traversed.end())
				{
					up->g += 1;
					up->h = misplaced(up->cur);
					if (up->g + up->h < 40)
					{
						a_misplaced.at(up->g + up->h).push(up);
						traversed.push_back(up->cur);
					}
				}
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
	//-------------------------A* with the Misplaced Tile Heuristic-------------------------//

	cin.get();

	return 0;
}