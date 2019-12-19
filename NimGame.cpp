#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool playerTurn = true;

bool winGame(vector <int>& vrow)
{
	if (vrow.empty()) // Checks if the vector is empty
	{
		system("CLS");

		if (playerTurn == true) //Depending who makes the last move, the other player will win
		{
			cout << "    PLAYER 2 WINS!!!" << endl << endl;
		}
		else
		{
			cout << "    PLAYER 1 WINS!!!" << endl << endl;
		}
		return false; //winGame() will become, ending the while loop in the main function
	}
	return true;
}

void displayBoard(vector <int>& vrow)
{
	system("CLS");
	cout << "     NIM GAME" << endl << endl;

	if (playerTurn == true)	// Inside the condition, the boolean will shift everytime displayBoard() is called
	{
		cout << "   PLAYER 1 TURN" << endl << endl;
		playerTurn = !playerTurn;
	}
	else
	{
		cout << "   PLAYER 2 TURN" << endl << endl;
		playerTurn = !playerTurn;
	}

	cout << "   ROW    " << "TOKENS" << endl << endl;

	for (int i = 0; i < vrow.size(); i++) // Display the row's number
	{
		cout << "   [" << i + 1 << "]      " << vrow[i] << endl << endl;
	}
}

int inputCheck(int input, string text)
{
	cout << "INVALID INPUT" << endl;
	cin.clear();	// Clears the error in the input stream
	cin.ignore(1); // Ignores any characters from the current stream
	cout << text << endl << endl;
	cin >> input;
	return input;
}

void Move(vector <int>& vrow, int rnum)
{
	int rowSelected;
	int tTaken;

	cout << "Enter which row you want to take from:" << endl << endl;
	cin >> rowSelected;

	while (rowSelected > rnum || rowSelected <= 0)
	{
		rowSelected = inputCheck(rowSelected, "Enter which row you want to take from again:"); //Calls a function to check if the input was valid
	}

	cout << "Tokens to take:" << endl << endl;
	cin >> tTaken;

	while (tTaken <= 0)
	{
		tTaken = inputCheck(tTaken, "Enter tokens to take again:");
	}

	vrow[rowSelected - 1] -= tTaken; // The value in the selected position is subtracted by the number of tokens selected

	if (vrow[rowSelected - 1] <= 0)
	{
		vrow.erase(vrow.begin() + (rowSelected - 1)); // Once a row has been completely emptied, it will be erased
	}
}

void inputBoard(vector<int>& vrow)
{
	int rnum;  //Number of rows
	int tnum; //Number of tokens

	cout << "Enter number of rows:" << endl;
	cin >> rnum;

	while (rnum <= 0)
	{
		rnum = inputCheck(rnum, "Enter number of rows again:"); //Calls a function to check if the input was valid
	}

	for (int i = 0; i < rnum; i++) // For every row declared before, a token number will be introduced for each one
	{
		cout << "Enter number of tokens:" << endl;
		cin >> tnum;

		while (tnum <= 0)
		{
			tnum = inputCheck(tnum, "Enter number of tokens again:");
		}
		vrow.push_back(tnum); // Put each token to the last value of the vector
	}
	displayBoard(vrow);
}

int main()
{
	vector <int> vrow; // Vector that the board uses
	cout << "     NIM GAME" << endl << endl;
	inputBoard(vrow);

	while (winGame(vrow)) // When the boolean becomes false the game will end
	{
		Move(vrow, vrow.size());
		displayBoard(vrow);
	}
	system("PAUSE");
}