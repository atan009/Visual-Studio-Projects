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

//-------------------------MOVEMENT + CHECK 0-------------------------//

//counts misplaced tiles
int misplaced(vector<vector<int>> current)
{
	int misplaced = 0;
	if (current.at(0).at(0) != 1)
	{
		misplaced += 1;
	}
	if (current.at(0).at(1) != 2)
	{
		misplaced += 1;
	}
	if (current.at(0).at(2) != 3)
	{
		misplaced += 1;
	}
	if (current.at(1).at(0) != 4)
	{
		misplaced += 1;
	}
	if (current.at(1).at(1) != 5)
	{
		misplaced += 1;
	}
	if (current.at(1).at(2) != 6)
	{
		misplaced += 1;
	}
	if (current.at(2).at(0) != 7)
	{
		misplaced += 1;
	}
	if (current.at(2).at(1) != 8)
	{
		misplaced += 1;
	}
	if (current.at(2).at(2) != 0)
	{
		misplaced += 1;
	}
	return misplaced;
}

int misplaced_2(vector<vector<int>> current)
{
	int misplaced = 0;
	if (current.at(0).at(0) != 1)
	{
		misplaced += 1;
	}
	if (current.at(0).at(1) != 2)
	{
		misplaced += 1;
	}
	if (current.at(0).at(2) != 3)
	{
		misplaced += 1;
	}
	if (current.at(1).at(0) != 8)
	{
		misplaced += 1;
	}
	if (current.at(1).at(1) != 0)
	{
		misplaced += 1;
	}
	if (current.at(1).at(2) != 4)
	{
		misplaced += 1;
	}
	if (current.at(2).at(0) != 7)
	{
		misplaced += 1;
	}
	if (current.at(2).at(1) != 6)
	{
		misplaced += 1;
	}
	if (current.at(2).at(2) != 5)
	{
		misplaced += 1;
	}
	return misplaced;
}


//counts Manhattan distance of all tiles
int Manhattan(vector<vector<int>> current)
{
	int Manhattan = 0;

	if (current.at(0).at(0) == 1)
	{
		Manhattan += 0;
	}

	else if (current.at(0).at(0) == 2 || current.at(0).at(0) == 4)
	{
		Manhattan += 1;
	}

	else if (current.at(0).at(0) == 3 || current.at(0).at(0) == 7 || current.at(0).at(0) == 5)
	{
		Manhattan += 2;
	}

	else if (current.at(0).at(0) == 6 || current.at(0).at(0) == 8)
	{
		Manhattan += 3;
	}

	else if (current.at(0).at(0) == 0)
	{
		Manhattan += 4;
	}


	if (current.at(0).at(1) == 2)
	{
		Manhattan += 0;
	}

	else if (current.at(0).at(1) == 1 || current.at(0).at(1) == 3 || current.at(0).at(1) == 5)
	{
		Manhattan += 1;
	}

	else if (current.at(0).at(1) == 4 || current.at(0).at(1) == 6 || current.at(0).at(1) == 8)
	{
		Manhattan += 2;
	}

	else if (current.at(0).at(1) == 7 || current.at(0).at(1) == 0)
	{
		Manhattan += 3;
	}


	if (current.at(0).at(2) == 3)
	{
		Manhattan += 0;
	}

	else if (current.at(0).at(2) == 2 || current.at(0).at(2) == 6)
	{
		Manhattan += 1;
	}

	else if (current.at(0).at(2) == 1 || current.at(0).at(2) == 5 || current.at(0).at(2) == 0)
	{
		Manhattan += 2;
	}

	else if (current.at(0).at(2) == 4 || current.at(0).at(2) == 8)
	{
		Manhattan += 3;
	}

	else if (current.at(0).at(2) == 7)
	{
		Manhattan += 4;
	}


	if (current.at(1).at(0) == 4)
	{
		Manhattan += 0;
	}

	else if (current.at(1).at(0) == 1 || current.at(1).at(0) == 5 || current.at(1).at(0) == 7)
	{
		Manhattan += 1;
	}

	else if (current.at(1).at(0) == 2 || current.at(1).at(0) == 6 || current.at(1).at(0) == 8)
	{
		Manhattan += 2;
	}

	else if (current.at(1).at(0) == 3 || current.at(1).at(0) == 0)
	{
		Manhattan += 3;
	}

	
	if (current.at(1).at(1) == 5)
	{
		Manhattan += 0;
	}

	else if (current.at(1).at(1) == 2 || current.at(1).at(1) == 4 || current.at(1).at(1) == 6 || current.at(1).at(1) == 8)
	{
		Manhattan += 1;
	}

	else if (current.at(1).at(1) == 1 || current.at(1).at(1) == 3 || current.at(1).at(1) == 7 || current.at(1).at(1) == 0)
	{
		Manhattan += 2;
	}

	
	if (current.at(1).at(2) == 6)
	{
		Manhattan += 0;
	}

	else if (current.at(1).at(2) == 5 || current.at(1).at(2) == 3 || current.at(1).at(2) == 0)
	{
		Manhattan += 1;
	}

	else if (current.at(1).at(2) == 2 || current.at(1).at(2) == 4 || current.at(1).at(2) == 8)
	{
		Manhattan += 2;
	}

	else if (current.at(1).at(2) == 1 || current.at(1).at(2) == 7)
	{
		Manhattan += 3;
	}

	
	if (current.at(2).at(0) == 7)
	{
		Manhattan += 0;
	}

	else if (current.at(2).at(0) == 4 || current.at(2).at(0) == 8)
	{
		Manhattan += 1;
	}

	else if (current.at(2).at(0) == 1 || current.at(2).at(0) == 5 || current.at(2).at(0) == 0)
	{
		Manhattan += 2;
	}

	else if (current.at(2).at(0) == 2 || current.at(2).at(0) == 6)
	{
		Manhattan += 3;
	}

	else if (current.at(2).at(0) == 3)
	{
		Manhattan += 4;
	}


	if (current.at(2).at(1) == 8)
	{
		Manhattan += 0;
	}

	else if (current.at(2).at(1) == 7 || current.at(2).at(1) == 5 || current.at(2).at(1) == 0)
	{
		Manhattan += 1;
	}

	else if (current.at(2).at(1) == 2 || current.at(2).at(1) == 4 || current.at(2).at(1) == 6)
	{
		Manhattan += 2;
	}

	else if (current.at(2).at(1) == 1 || current.at(2).at(1) == 3)
	{
		Manhattan += 3;
	}

	if (current.at(2).at(2) == 0)
	{
		Manhattan += 0;
	}

	else if (current.at(2).at(2) == 8 || current.at(2).at(2) == 6)
	{
		Manhattan += 1;
	}

	else if (current.at(2).at(2) == 3 || current.at(2).at(2) == 5 || current.at(2).at(2) == 7)
	{
		Manhattan += 2;
	}

	else if (current.at(2).at(2) == 2 || current.at(2).at(2) == 4)
	{
		Manhattan += 3;
	}

	else if (current.at(2).at(2) == 1)
	{
		Manhattan += 4;
	}

	return Manhattan;

}

int Manhattan_2(vector<vector<int>> current)
{
	int Manhattan = 0;

	if (current.at(0).at(0) == 1)
	{
		Manhattan += 0;
	}

	else if (current.at(0).at(0) == 2 || current.at(0).at(0) == 8)
	{
		Manhattan += 1;
	}

	else if (current.at(0).at(0) == 3 || current.at(0).at(0) == 0 || current.at(0).at(0) == 7)
	{
		Manhattan += 2;
	}

	else if (current.at(0).at(0) == 4 || current.at(0).at(0) == 6)
	{
		Manhattan += 3;
	}

	else if (current.at(0).at(0) == 5)
	{
		Manhattan += 4;
	}


	if (current.at(0).at(1) == 2)
	{
		Manhattan += 0;
	}

	else if (current.at(0).at(1) == 0 || current.at(0).at(1) == 1 || current.at(0).at(1) == 3)
	{
		Manhattan += 1;
	}

	else if (current.at(0).at(1) == 4 || current.at(0).at(1) == 6 || current.at(0).at(1) == 8)
	{
		Manhattan += 2;
	}

	else if (current.at(0).at(1) == 5 || current.at(0).at(1) == 7)
	{
		Manhattan += 3;
	}


	if (current.at(0).at(2) == 3)
	{
		Manhattan += 0;
	}

	else if (current.at(0).at(2) == 2 || current.at(0).at(2) == 4)
	{
		Manhattan += 1;
	}

	else if (current.at(0).at(2) == 0 || current.at(0).at(2) == 1 || current.at(0).at(2) == 5)
	{
		Manhattan += 2;
	}

	else if (current.at(0).at(2) == 6 || current.at(0).at(2) == 8)
	{
		Manhattan += 3;
	}

	else if (current.at(0).at(2) == 7)
	{
		Manhattan += 4;
	}


	if (current.at(1).at(0) == 8)
	{
		Manhattan += 0;
	}

	else if (current.at(1).at(0) == 0 || current.at(1).at(0) == 1 || current.at(1).at(0) == 7)
	{
		Manhattan += 1;
	}

	else if (current.at(1).at(0) == 2 || current.at(1).at(0) == 4 || current.at(1).at(0) == 6)
	{
		Manhattan += 2;
	}

	else if (current.at(1).at(0) == 3 || current.at(1).at(0) == 5)
	{
		Manhattan += 3;
	}


	if (current.at(1).at(1) == 0)
	{
		Manhattan += 0;
	}

	else if (current.at(1).at(1) == 2 || current.at(1).at(1) == 4 || current.at(1).at(1) == 6 || current.at(1).at(1) == 8)
	{
		Manhattan += 1;
	}

	else if (current.at(1).at(1) == 1 || current.at(1).at(1) == 3 || current.at(1).at(1) == 5 || current.at(1).at(1) == 7)
	{
		Manhattan += 2;
	}


	if (current.at(1).at(2) == 4)
	{
		Manhattan += 0;
	}

	else if (current.at(1).at(2) == 0 || current.at(1).at(2) == 3 || current.at(1).at(2) == 5)
	{
		Manhattan += 1;
	}

	else if (current.at(1).at(2) == 2 || current.at(1).at(2) == 6 || current.at(1).at(2) == 8)
	{
		Manhattan += 2;
	}

	else if (current.at(1).at(2) == 1 || current.at(1).at(2) == 7)
	{
		Manhattan += 3;
	}


	if (current.at(2).at(0) == 7)
	{
		Manhattan += 0;
	}

	else if (current.at(2).at(0) == 6 || current.at(2).at(0) == 8)
	{
		Manhattan += 1;
	}

	else if (current.at(2).at(0) == 0 || current.at(2).at(0) == 1 || current.at(2).at(0) == 5)
	{
		Manhattan += 2;
	}

	else if (current.at(2).at(0) == 2 || current.at(2).at(0) == 4)
	{
		Manhattan += 3;
	}

	else if (current.at(2).at(0) == 3)
	{
		Manhattan += 4;
	}


	if (current.at(2).at(1) == 6)
	{
		Manhattan += 0;
	}

	else if (current.at(2).at(1) == 0 || current.at(2).at(1) == 5 || current.at(2).at(1) == 7)
	{
		Manhattan += 1;
	}

	else if (current.at(2).at(1) == 2 || current.at(2).at(1) == 4 || current.at(2).at(1) == 8)
	{
		Manhattan += 2;
	}

	else if (current.at(2).at(1) == 1 || current.at(2).at(1) == 3)
	{
		Manhattan += 3;
	}

	if (current.at(2).at(2) == 5)
	{
		Manhattan += 0;
	}

	else if (current.at(2).at(2) == 4 || current.at(2).at(2) == 6)
	{
		Manhattan += 1;
	}

	else if (current.at(2).at(2) == 0 || current.at(2).at(2) == 3 || current.at(2).at(2) == 7)
	{
		Manhattan += 2;
	}

	else if (current.at(2).at(2) == 2 || current.at(2).at(2) == 8)
	{
		Manhattan += 3;
	}

	else if (current.at(2).at(2) == 1)
	{
		Manhattan += 4;
	}

	return Manhattan;

}

//-------------------------The two A* algorithms-------------------------//

bool solvable(vector<vector<int>> current)
{
	vector<int> linear;
	int s = 0;
	int zero = 0, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			linear.push_back(current.at(i).at(k));
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (linear.at(i) == 0)
		{
			zero = 1;
		}

		else if (linear.at(i) == 1)
		{
			one = 1;
		}

		else if (linear.at(i) == 2)
		{
			two = 1;
		}

		else if (linear.at(i) == 3)
		{
			three = 1;
		}

		else if (linear.at(i) == 4)
		{
			four = 1;
		}

		else if (linear.at(i) == 5)
		{
			five = 1;
		}

		else if (linear.at(i) == 6)
		{
			six = 1;
		}

		else if (linear.at(i) == 7)
		{
			seven = 1;
		}

		else if (linear.at(i) == 8)
		{
			eight = 1;
		}
	}
	
	for (int l = 0; l < 8; l++)
	{
		for (int m = l + 1; m < 9; m++)
		{

			if (linear.at(m) < linear.at(l) && linear.at(m) != 0)
			{
				s += 1;
			}
		}

	}



	if (s % 2 == 0 && zero == 1 && one == 1 && two == 1 && three == 1 && four == 1 && five == 1 && six == 1 && seven == 1 && eight == 1)
	{
		return 1;
	}

	else
	{
		return 0;
	}

}

int main()
{
	int verPos;//for determining X/Y of Zero
	int horPos;
	int choice;

	cout << "Welcome to Alex Tan's 8-puzzle solver." << endl;

	int goal_state;
	cout << "1 for default goal state, 2 for blank in center." << endl;
	cin >> goal_state;

	cout << "type \"1\" to use default puzzle, or \"2\" to enter your own puzzle" << endl;

	
	cin >> choice;
	
	if(choice != 1 && choice != 2)
	{
		cout << "invalid choice, exiting" << endl;
		return 0;
	}
		

	cout << choice << " selected" << endl;

	vector<vector<int>>eight_puzzle{ { 0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

	if (goal_state != 1 && goal_state != 2)
	{
		cout << "Non-valid input, exitting" << endl;
		return 0;
	}


	vector<vector<int>>goal{ { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 0 } };
	if (goal_state == 2)
	{
		goal = { { 1, 2, 3 },{ 8, 0, 4 },{ 7, 6, 5 } };
	}

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

	if (!solvable(eight_puzzle) && goal_state == 1)
	{
		cout << "Not solvable." << endl;
		cin.get();
		return 0;
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
		int g = 0;//depth
		int h = 0;//depends on what method is used
		node *next = NULL;//ended up not using this
		node *prev = NULL;//track previous nodes for solution
		vector<vector<int>> cur;//current state of puzzle
	};

	int max_q = 0;

	//-------------------------Uniform Cost Search-------------------------//
	if (choice == 1)
	{
		node *given = new node;
		given->cur = eight_puzzle;//stores the give puzzle state

		queue <node*> UCS;//used to store all braches
		node *init = new node;//starting node
		init->cur = eight_puzzle;
		

		node *current = init;

		
		UCS.push(init);
		vector<vector<vector<int>>> traversed;//used to store previously traversed states
		traversed.push_back(current->cur);
		

		//performs the UCS search (BFS).
		while (current->cur != goal)
		{
			if (UCS.size() > max_q)
			{
				max_q = UCS.size();
			}

			current = UCS.front();//start from first node
			Z_Pos(verPos, horPos, current->cur);//determine where 0 is
			UCS.pop();//start unqueueing

			if (verPos == 0 && horPos == 0)//checks all possible movements, requeue and repeat
			{
				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					right->g = current->g + 1;
					UCS.push(right);
					traversed.push_back(right->cur);
				}


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					down->g = current->g + 1;
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
					left->g = current->g + 1;
					UCS.push(left);
					traversed.push_back(left->cur);
				}


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					right->g = current->g + 1;
					UCS.push(right);
					traversed.push_back(right->cur);
				}


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					down->g = current->g + 1;
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
					left->g = current->g + 1;
					UCS.push(left);
					traversed.push_back(left->cur);
				}


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					down->g = current->g + 1;
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
					up->g = current->g + 1;
					UCS.push(up);
					traversed.push_back(up->cur);
				}


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					right->g = current->g + 1;
					UCS.push(right);
					traversed.push_back(right->cur);
				}


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					down->g = current->g + 1;
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
					up->g = current->g + 1;
					UCS.push(up);
					traversed.push_back(up->cur);
				}


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					right->g = current->g + 1;
					UCS.push(right);
					traversed.push_back(right->cur);
				}


				node *down = new node;
				down->prev = current;
				down->cur = mv_down(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), down->cur) == traversed.end())
				{
					down->g = current->g + 1;
					UCS.push(down);
					traversed.push_back(down->cur);
				}


				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), left->cur) == traversed.end())
				{
					left->g = current->g + 1;
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
					down->g = current->g + 1;
					UCS.push(down);
					traversed.push_back(down->cur);
				}


				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), up->cur) == traversed.end())
				{
					up->g = current->g + 1;
					UCS.push(up);
					traversed.push_back(up->cur);
				}


				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), left->cur) == traversed.end())
				{
					left->g = current->g + 1;
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
					up->g = current->g + 1;
					UCS.push(up);
					traversed.push_back(up->cur);
				}


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					right->g = current->g + 1;
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
					up->g = current->g + 1;
					UCS.push(up);
					traversed.push_back(up->cur);
				}


				node *left = new node;
				left->prev = current;
				left->cur = mv_left(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), left->cur) == traversed.end())
				{
					left->g = current->g + 1;
					UCS.push(left);
					traversed.push_back(left->cur);
				}


				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					right->g = current->g + 1;
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
					left->g = current->g + 1;
					UCS.push(left);
					traversed.push_back(left->cur);
				}


				node *up = new node;
				up->prev = current;
				up->cur = mv_up(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), up->cur) == traversed.end())
				{
					up->g = current->g + 1;
					UCS.push(up);
					traversed.push_back(up->cur);
				}
			}
		}

		cout << "expanding state " << endl; //Starts to display

		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				cout << init->cur.at(i).at(k) << " ";
			}
			cout << endl;
		}
		cout << endl;

		stack<node*> solution;
		while (current->cur != given->cur)
		{
			solution.push(current);
			current = current->prev;
		}



		while (solution.empty() != 1)
		{
			node *display = new node;
			display = solution.top();
			solution.pop();

			if (display->cur != goal)
			{
				cout << "Expanding this node. g(n) = " << display->g << endl;
			}
			else
			{
				cout << "Goal!" << endl;
			}

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

		cout << "# of nodes traversed: " << traversed.size() << endl;
		cout << "Max number of nodes in queue: " << max_q << endl;
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

			int temp = 0;
			for (int i = 0; i < a_misplaced.size(); i++)
			{
				temp += a_misplaced.at(i).size();
			}
			if (temp > max_q)
			{
				max_q = temp;
			}

			for (int i = 0; i < 40; i++)
			{
				if (!a_misplaced.at(i).empty())
				{
					current = a_misplaced.at(i).front();
					a_misplaced.at(i).pop();
					break;
				}
			}

			
			Z_Pos(verPos, horPos, current->cur);

			//exactly the same as UCS but now we use misplaced tiles as a weight
			if (verPos == 0 && horPos == 0)
			{
				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					right->g = current->g+1;
					right->h = misplaced(right->cur);
					if (goal_state == 2)
					{
						right->h = misplaced_2(right->cur);
					}

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
					down->g = current->g + 1 ;
					down->h = misplaced(down->cur);
					if (goal_state == 2)
					{
						down->h = misplaced_2(down->cur);
					}
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
					left->g = current->g + 1;
					left->h = misplaced(left->cur);
					if (goal_state == 2)
					{
						left->h = misplaced_2(left->cur);
					}
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
					right->g = current->g + 1;
					right->h = misplaced(right->cur);
					if (goal_state == 2)
					{
						right->h = misplaced_2(right->cur);
					}
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
					down->g = current->g + 1;
					down->h = misplaced(right->cur);
					if (goal_state == 2)
					{
						down->h = misplaced_2(down->cur);
					}
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
					left->g = current->g + 1;
					left->h = misplaced(left->cur);
					if (goal_state == 2)
					{
						left->h = misplaced_2(left->cur);
					}
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
					down->g = current->g + 1;
					down->h = misplaced(down->cur);
					if (goal_state == 2)
					{
						down->h = misplaced_2(down->cur);
					}
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
					up->g = current->g + 1;
					up->h = misplaced(up->cur);
					if (goal_state == 2)
					{
						up->h = misplaced_2(up->cur);
					}
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
					right->g = current->g + 1;
					right->h = misplaced(right->cur);
					if (goal_state == 2)
					{
						right->h = misplaced_2(right->cur);
					}
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
					down->g = current->g + 1;
					down->h = misplaced(down->cur);
					if (goal_state == 2)
					{
						down->h = misplaced_2(down->cur);
					}
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
					up->g = current->g + 1;
					up->h = misplaced(up->cur);
					if (goal_state == 2)
					{
						up->h = misplaced_2(up->cur);
					}
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
					right->g = current->g + 1;
					right->h = misplaced(right->cur);
					if (goal_state == 2)
					{
						right->h = misplaced_2(right->cur);
					}
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
					down->g = current->g + 1;
					down->h = misplaced(down->cur);
					if (goal_state == 2)
					{
						down->h = misplaced_2(down->cur);
					}
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
					left->g = current->g + 1;
					left->h = misplaced(left->cur);
					if (goal_state == 2)
					{
						left->h = misplaced_2(left->cur);
					}
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
					down->g = current->g + 1;
					down->h = misplaced(down->cur);
					if (goal_state == 2)
					{
						down->h = misplaced_2(down->cur);
					}
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
					up->g = current->g + 1;
					up->h = misplaced(up->cur);
					if (goal_state == 2)
					{
						up->h = misplaced_2(up->cur);
					}
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
					left->g = current->g + 1;
					left->h = misplaced(left->cur);
					if (goal_state == 2)
					{
						left->h = misplaced_2(left->cur);
					}
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
					up->g = current->g + 1;
					up->h = misplaced(up->cur);
					if (goal_state == 2)
					{
						up->h = misplaced_2(up->cur);
					}
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
					right->g = current->g + 1;
					right->h = misplaced(right->cur);
					if (goal_state == 2)
					{
						right->h = misplaced_2(right->cur);
					}
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
					up->g = current->g + 1;
					up->h = misplaced(up->cur);
					if (goal_state == 2)
					{
						up->h = misplaced_2(up->cur);
					}
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
					left->g = current->g + 1;
					left->h = misplaced(left->cur);
					if (goal_state == 2)
					{
						left->h = misplaced_2(left->cur);
					}
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
					right->g = current->g + 1;
					right->h = misplaced(right->cur);
					if (goal_state == 2)
					{
						right->h = misplaced_2(right->cur);
					}
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
					left->g = current->g + 1;
					left->h = misplaced(left->cur);
					if (goal_state == 2)
					{
						left->h = misplaced_2(left->cur);
					}
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
					up->g = current->g + 1;
					up->h = misplaced(up->cur);
					if (goal_state == 2)
					{
						up->h = misplaced_2(up->cur);
					}
					if (up->g + up->h < 40)
					{
						a_misplaced.at(up->g + up->h).push(up);
						traversed.push_back(up->cur);
					}
				}
			}
		}

		cout << "expanding state " << endl; //Starts to display

		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				cout << init->cur.at(i).at(k) << " ";
			}
			cout << endl;
		}
		cout << endl;

		stack<node*> solution;
		while (current->cur != given->cur)
		{
			solution.push(current);
			current = current->prev;
		}



		while (solution.empty() != 1)
		{
			node *display = new node;
			display = solution.top();
			solution.pop();

			if (display->cur != goal)
			{
				cout << "Expanding this node. g(n) = " << display->g << " h(n) = " << display->h << endl;
			}
			else
			{
				cout << "Goal!" << endl;
			}

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

		cout << "# of nodes traversed: " << traversed.size() << endl;
		cout << "Max nodes in queue: " << max_q << endl;

	}
	//-------------------------A* with the Misplaced Tile Heuristic-------------------------//


	//-------------------------A* with the Misplaced Tile Heuristic-------------------------//
	else if (choice == 3)
	{
		node *given = new node;
		given->cur = eight_puzzle;


		node *init = new node;
		init->cur = eight_puzzle;


		node *current = init;


		vector<vector<vector<int>>> traversed;
		traversed.push_back(current->cur);

		vector<queue<node*>>a_misplaced(31 + (4 * 9));//max depth + (Max Mdist * 9 numbers == 67)
		a_misplaced.at(misplaced(init->cur)).push(init);

		while (current->cur != goal)
		{

			int temp = 0;
			for (int i = 0; i < a_misplaced.size(); i++)
			{
				temp += a_misplaced.at(i).size();
			}
			if (temp > max_q)
			{
				max_q = temp;
			}

			for (int i = 0; i < 67; i++)
			{
				if (!a_misplaced.at(i).empty())
				{
					current = a_misplaced.at(i).front();
					a_misplaced.at(i).pop();
					break;
				}
			}


			Z_Pos(verPos, horPos, current->cur);

			//exactly the same as A* w/ misplaced, but now we use Manhattan distance as weight
			if (verPos == 0 && horPos == 0)
			{
				node *right = new node;
				right->prev = current;
				right->cur = mv_right(verPos, horPos, current->cur);
				if (find(traversed.begin(), traversed.end(), right->cur) == traversed.end())
				{
					right->g = current->g + 1;
					right->h = Manhattan(right->cur);
					if (goal_state == 2)
					{
						right->h = Manhattan_2(right->cur);
					}
					if (right->g + right->h < 67)
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
					down->g = current->g + 1;
					down->h = Manhattan(down->cur);
					if (goal_state == 2)
					{
						down->h = Manhattan_2(down->cur);
					}
					if (down->g + down->h < 67)
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
					left->g = current->g + 1;
					left->h = Manhattan(left->cur);
					if (goal_state == 2)
					{
						left->h = Manhattan_2(left->cur);
					}
					if (left->g + left->h < 67)
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
					right->g = current->g + 1;
					right->h = Manhattan(right->cur);
					if (goal_state == 2)
					{
						right->h = Manhattan_2(right->cur);
					}
					if (right->g + right->h < 67)
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
					down->g = current->g + 1;
					down->h = Manhattan(right->cur);
					if (goal_state == 2)
					{
						down->h = Manhattan_2(down->cur);
					}
					if (down->g + down->h < 67)
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
					left->g = current->g + 1;
					left->h = Manhattan(left->cur);
					if (goal_state == 2)
					{
						left->h = Manhattan_2(left->cur);
					}
					if (left->g + left->h < 67)
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
					down->g = current->g + 1;
					down->h = Manhattan(down->cur);
					if (goal_state == 2)
					{
						down->h = Manhattan_2(down->cur);
					}
					if (down->g + down->h < 67)
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
					up->g = current->g + 1;
					up->h = Manhattan(up->cur);
					if (goal_state == 2)
					{
						up->h = Manhattan_2(up->cur);
					}
					if (up->g + up->h < 67)
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
					right->g = current->g + 1;
					right->h = Manhattan(right->cur);
					if (goal_state == 2)
					{
						right->h = Manhattan_2(right->cur);
					}
					if (right->g + right->h < 67)
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
					down->g = current->g + 1;
					down->h = Manhattan(down->cur);
					if (goal_state == 2)
					{
						down->h = Manhattan_2(down->cur);
					}
					if (down->g + down->h < 67)
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
					up->g = current->g + 1;
					up->h = Manhattan(up->cur);
					if (goal_state == 2)
					{
						up->h = Manhattan_2(up->cur);
					}
					if (up->g + up->h < 67)
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
					right->g = current->g + 1;
					right->h = Manhattan(right->cur);
					if (goal_state == 2)
					{
						right->h = Manhattan_2(right->cur);
					}
					if (right->g + right->h < 67)
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
					down->g = current->g + 1;
					down->h = Manhattan(down->cur);
					if (goal_state == 2)
					{
						down->h = Manhattan_2(down->cur);
					}
					if (down->g + down->h < 67)
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
					left->g = current->g + 1;
					left->h = Manhattan(left->cur);
					if (goal_state == 2)
					{
						left->h = Manhattan_2(left->cur);
					}
					if (left->g + left->h < 67)
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
					down->g = current->g + 1;
					down->h = Manhattan(down->cur);
					if (goal_state == 2)
					{
						down->h = Manhattan_2(down->cur);
					}
					if (down->g + down->h < 67)
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
					up->g = current->g + 1;
					up->h = Manhattan(up->cur);
					if (goal_state == 2)
					{
						up->h = Manhattan_2(up->cur);
					}
					if (up->g + up->h < 67)
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
					left->g = current->g + 11;
					left->h = Manhattan(left->cur);
					if (goal_state == 2)
					{
						left->h = Manhattan_2(left->cur);
					}
					if (left->g + left->h < 67)
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
					up->g = current->g + 1;
					up->h = Manhattan(up->cur);
					if (goal_state == 2)
					{
						up->h = Manhattan_2(up->cur);
					}
					if (up->g + up->h < 67)
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
					right->g = current->g + 1;
					right->h = Manhattan(right->cur);
					if (goal_state == 2)
					{
						right->h = Manhattan_2(right->cur);
					}
					if (right->g + right->h < 67)
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
					up->g = current->g + 1;
					up->h = Manhattan(up->cur);
					if (goal_state == 2)
					{
						up->h = Manhattan_2(up->cur);
					}
					if (up->g + up->h < 67)
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
					left->g = current->g + 1;
					left->h = Manhattan(left->cur);
					if (goal_state == 2)
					{
						left->h = Manhattan_2(left->cur);
					}
					if (left->g + left->h < 67)
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
					right->g = current->g + 1;
					right->h = Manhattan(right->cur);
					if (goal_state == 2)
					{
						right->h = Manhattan_2(right->cur);
					}
					if (right->g + right->h < 67)
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
					left->g = current->g + 1;
					left->h = Manhattan(left->cur);
					if (goal_state == 2)
					{
						left->h = Manhattan_2(left->cur);
					}
					if (left->g + left->h < 67)
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
					up->g = current->g + 1;
					up->h = Manhattan(up->cur);
					if (goal_state == 2)
					{
						up->h = Manhattan_2(up->cur);
					}
					if (up->g + up->h < 67)
					{
						a_misplaced.at(up->g + up->h).push(up);
						traversed.push_back(up->cur);
					}
				}
			}
		}

		cout << "expanding state " << endl; //Starts to display

		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				cout << init->cur.at(i).at(k) << " ";
			}
			cout << endl;
		}
		cout << endl;

		stack<node*> solution;
		while (current->cur != given->cur)
		{
			solution.push(current);
			current = current->prev;
		}



		while (solution.empty() != 1)
		{
			node *display = new node;
			display = solution.top();
			solution.pop();

			if (display->cur != goal)
			{
				cout << "Expanding this node. g(n) = " << display->g << " h(n) = " << display->h << endl;
			}
			else
			{
				cout << "Goal!" << endl;
			}

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

		cout << "# of nodes traversed: " << traversed.size() << endl;
		cout << "Max nodes in queue: " << max_q << endl;

	}
	//-------------------------A* with the Misplaced Tile Heuristic-------------------------//




	cin.get();

	return 0;
}