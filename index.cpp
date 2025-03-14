#include<iostream>
#include<string>
#include<cctype>
#include<cwctype>
#include<sstream>
#include<cwchar>
#include<cstdlib>
#include<cfloat>
	
using namespace std;
	
//multidim array bingo chess board
char board[6][7] = { { '-', '-', '-', '-', '-', '-', '-'}, {'-' , '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-'}, {'-', '-', '-', '-', '-', '-', '-'} };

//positioning of 'X' and 'O' on board
void BOARD(int y, int z, char mark) {

	system("Color 0E");
	system("cls");

	board[y][z - 1] = mark;

	cout << "\n\t\t\t\t\t    ----BINGO CHESS---- \n";
	cout << "\n\t\t\t\t\t Player 1(X) - Player 2(O) \n";
	cout << "\t\t\t\t _________________________________________\n";
	cout << "\t\t\t\t|     |     |     |     |     |     |     |\n";
	cout << "\t\t\t\t|  1  |  2  |  3  |  4  |  5  |  6  |  7  |\n";
	cout << "\t\t\t\t|_____|_____|_____|_____|_____|_____|_____|\n";

	for (int i = 0; i < 6; i++) {
		cout << "\t\t\t\t|     |     |     |     |     |     |     |\n";
		cout << "\t\t\t\t|  " << board[i][0] << "  | " << " " << board[i][1] << "  |" << "  " << board[i][2] << "  |" << "  " << board[i][3] << "  |"
			<< "  " << board[i][4] << "  |" << "  " << board[i][5] << "  |" << "  " << board[i][6] << "  | \n";
		cout << "\t\t\t\t|_____|_____|_____|_____|_____|_____|_____|\n";
	}
}

int col1 = 6, col2 = 6, col3 = 6, col4 = 6, col5 = 6, col6 = 6, col7 = 6;

//Check available board slots
int InputtedColumn(int x) {

	if (x == 1) {
		if (col1 > 0) {
			col1--;
			return col1;
		}
		else
			return -1;
	}

	else if (x == 2) {
		if (col2 > 0) {
			col2--;
			return col2;
		}
		else
			return -1;
	}

	else if (x == 3) {
		if (col3 > 0) {
			col3--;
			return col3;
		}
		else
			return -1;
	}

	else if (x == 4) {
		if (col4 > 0) {
			col4--;
			return col4;
		}
		else
			return -1;
	}

	else if (x == 5) {
		if (col5 > 0) {
			col5--;
			return col5;
		}
		else
			return -1;
	}

	else if (x == 6) {
		if (col6 > 0) {
			col6--;
			return col6;
		}
		else
			return -1;
	}

	else if (x == 7) {
		if (col7 > 0) {
			col7--;
			return col7;
		}
		else
			return -1;
	}
	else
		return -1;
}

//Checking Player 1's row for a win 
bool Player1_RowStatus(int y) {

	int counter = 0;

	for (int i = 0; i < 7; i++) {
		if (board[y][i] == 'X') {
			counter++;
			if (counter == 4)
				return true;
		}
		else
			counter = 0;
	}
	return false;

}

//Checking Player 1's column for a win 
bool Player1_ColStatus(int z) {

	int counter = 0;

	z--;

	for (int i = 0; i < 6; i++) {
		if (board[i][z] == 'X') {
			counter++;
			if (counter == 4)
				return true;
		}
		else
			counter = 0;
	}
	return false;
}

//Checking Player 1's Left Diagonal for a win 
bool Player1_LeftDiagonalStatus(int y, int z) {

	int counter = 0;
	z--;
	if (y >= z) {
		y -= z;
		z = 0;
		for (int i = y; i < 6; i++) {
			if (board[i][z] == 'X') {
				counter++;
				if (counter == 4)
					return true;
			}
			else
				counter = 0;
			z++;
		}
	}
	else
	{
		z -= y;
		y = 0;
		for (int j = z; j < 7; j++) {
			if (board[y][j] == 'X') {
				counter++;
				if (counter == 4)
					return true;
			}
			else
				counter = 0;
			y++;
		}
	}
	return false;
}

//Checking Player 1's Right Diagonal for a win 
bool Player1_RightDiagonalStatus(int y, int z) {

	int counter = 0;
	z--;
	int x = y + z;
	if (x < 7 && x>2) {
		z = x;
		y = 0;
		for (int i = y;i < 6;i++) {
			if (board[i][z] == 'X') {
				counter++;
				if (counter == 4)
					return true;
			}
			else
				counter = 0;
			z--;
		}
	}

	else if (x > 6 && x < 9) {
		z = 6;
		y = x - 6;
		for (int j = y;j < 6; j++) {
			if (board[j][z] == 'X') {
				counter++;
				if (counter == 4)
					return true;
			}
			else
				counter = 0;
			z--;
		}
	}
	return false;
}

//Checking Player 2's row for a win
bool Player2_RowStatus(int y) {

	int counter = 0;

	for (int i = 0; i < 7; i++) {
		if (board[y][i] == 'O') {
			counter++;
			if (counter == 4)
				return true;
		}
		else
			counter = 0;
	}
	return false;

}

//Checking Player 2's column for a win	
bool Player2_ColStatus(int z) {

	int counter = 0;
	z--;

	for (int i = 0; i < 6; i++) {
		if (board[i][z] == 'O') {
			counter++;
			if (counter == 4)
				return true;
		}
		else
			counter = 0;
	}
	return false;
}

//Checking Player 2's Left Diagonal for a win 
bool Player2_LeftDiagonalStatus(int y, int z) {

	int counter = 0;

	z--;

	if (y >= z) {
		y -= z;
		z = 0;
		for (int i = y;i < 6;i++) {
			if (board[i][z] == 'O') {
				counter++;
				if (counter == 4)
					return true;
			}
			else
				counter = 0;
			z++;
		}
	}
	else
	{
		z -= y;
		y = 0;
		for (int j = z;j < 7;j++) {
			if (board[y][j] == 'O') {
				counter++;
				if (counter == 4)
					return true;
			}
			else
				counter = 0;
			y++;
		}
	}
	return false;
}

//Checking Player 2's Right Diagonal for a win 
bool Player2_RightDiagonalStatus(int y, int z) {

	int counter = 0;

	z--;

	int x = y + z;
	if (x < 7 && x>2) {
		z = x;
		y = 0;
		for (int i = y;i < 6;i++) {
			if (board[i][z] == 'O') {
				counter++;
				if (counter == 4)
					return true;
			}
			else
				counter = 0;
			z--;
		}
	}

	else if (x > 6 && x < 9) {
		z = 6;
		y = x - 6;
		for (int j = y;j < 6; j++) {
			if (board[j][z] == 'O') {
				counter++;
				if (counter == 4)
					return true;
			}
			else
				counter = 0;
			z--;
		}
	}
	return false;
}

//Checks if Column is full
bool Column_is_Full(int z) {

	int counter = 0;

	z--;

	for (int i = 0; i < 6; i++) {
		if (board[i][z] == 'X' || board[i][z] == 'O') {
			counter++;
			if (counter == 6)
				return true;
		}
		else
			counter = 0;
	}
	return false;
}

int Menu_ToPlayAgain_InputVal() {

	string userStringNum = "";

	int isNum = 0;
	int decimalCount = 0;
	int userConvertedNum = 0;

	bool willBreak = 0;
	bool contains_spaces = false;

	do {
		cout << "\n\n\t\t\t\t\tChoose between [1-3]";
		cout << "\n\t\t\t\t\tChoice: ";
		getline(cin, userStringNum);

		for (int i = 0; i < userStringNum.size(); i++) {
			if (isspace(userStringNum[i])) {
				contains_spaces = true;
			}
		}

		if (userStringNum[0] == '-') {
			isNum = 0;
		}
		else {
			for (int i = 0; i < userStringNum.size(); i++) {
				if (isdigit(userStringNum[i])) {
					isNum++;
				}
				if (userStringNum[i] == '-') {
					decimalCount++;
				}
			}
		}
		if (decimalCount >= 1) {
			isNum = 0;
		}
		if (isNum == userStringNum.size()) {
			stringstream str_stream_object(userStringNum);
			str_stream_object >> userConvertedNum;
			willBreak = 1;
		}
		else {
			willBreak = 0;
			isNum = 0;
			decimalCount = 0;
			contains_spaces = false;
		}

	} while (willBreak = 0);

	return userConvertedNum;
}

//Game Main Menu	
int Main_Menu() {

	system("cls");
	system("Color 06");

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;               
	cfi.dwFontSize.Y = 20;                  
	cfi.FontFamily = FF_MODERN;
	cfi.FontWeight = FW_ULTRABOLD;
	wcscpy_s(cfi.FaceName, L"Verdana"); 
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	cout << "\n\n\n\t\t\t\t\t ----- MAIN MENU ----- \n\n";

	int choice = 0;

	cout << "\n\t\t\t\t\t 1. Start \n";
	cout << "\n\t\t\t\t\t 2. How to Play \n";
	cout << "\n\t\t\t\t\t 3. About \n";
	choice = Menu_ToPlayAgain_InputVal();

	switch (choice) {
	case 1:
		break;
	case 2:
		system("cls");
		system("Color 0E");
		cout << "\n\n\n\n\t\t\t\t\t\t HOW TO PLAY \n\n\n\t\t\t - The game pieces are represented by 'X' for Player 1 and 'O' for Player 2."
			<< "\n\n\t\t\t - Each player has 21 turns, should it exceed, it will result to a draw."
			<< "\n\n\t\t\t - The first player to make a connected 4 pieces whether horizontal, vertical,"
			<< "\n\t\t\t   or diagonal wins."
			<< endl << endl << endl << "\t\t\t ";
		system("pause");
		break;

	case 3:
		system("cls");
		system("Color 0E");
		cout << "\n\n\n\t\t\t\t\t ABOUT THE GAME";
		cout << "\n\n\n\t\t\t Developed by:\n\n\t\t\t Carl Tabuso\n\t\t\t Aedriel Velando\n\t\t\t Apolo Trasmonte\n\t\t\t Jeri Mae Rosario\n\t\t\t Blessed King Redondo"
			<< "\n\n\n\t\t\t Under the supervision of:\n\n\t\t\t Prof. Arwin Nucum"
			<< endl << endl << endl << "\t\t\t ";
		system("pause");
		break;

	default:
		cout << "\n\n\t\t\t\t\tInvalid Input.\n";
		cout << "\n\t\t\t\t\tInput must NOT have decimal number/s.";
		cout << "\n\t\t\t\t\tInput must NOT have string or letter/s.";
		cout << "\n\t\t\t\t\tInput must NOT have space/s.";
		cout << "\n\t\t\t\t\tInput must not have special character/s.";
		cout << endl << endl << endl << "\t\t\t\t\t";
		system("pause");
	}
	return choice;
}

//Player vs. player
int Multiplayer() {

	system("cls");
	system("Color 0E");

	cout << "\n\t\t\t\t\t    ----BINGO CHESS---- \n";
	cout << "\n\t\t\t\t\t Player 1(X) - Player 2(O) \n";
	cout << "\t\t\t\t _________________________________________\n";
	cout << "\t\t\t\t|     |     |     |     |     |     |     |\n";
	cout << "\t\t\t\t|  1  |  2  |  3  |  4  |  5  |  6  |  7  |\n";
	cout << "\t\t\t\t|_____|_____|_____|_____|_____|_____|_____|\n";

	for (int i = 0; i < 6; i++) {
		cout << "\t\t\t\t|     |     |     |     |     |     |     |\n";
		cout << "\t\t\t\t|  " << board[i][0] << "  | " << " " << board[i][1] << "  |" << "  " << board[i][2] << "  |" << "  " << board[i][3] << "  |"
			<< "  " << board[i][4] << "  |" << "  " << board[i][5] << "  |" << "  " << board[i][6] << "  | \n";
		cout << "\t\t\t\t|_____|_____|_____|_____|_____|_____|_____|\n";
	}

	int counter = 0;

	while (counter < 21) {
		int player1 = 0, player2 = 0;
		int choice = 0;
		int row = 0;

		while (player1 < 1) {
			cout << "\n\t Player 1, Choose a number: ";
			cin >> choice;
			row = InputtedColumn(choice);

			while (cin.good() == false || choice < 1 || choice > 7) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "\n\t Invalid Input. Choose between [1-7]: ";
				cin >> choice;
				row = InputtedColumn(choice);
			}

			while (Column_is_Full(choice) == true) {
				cout << "\n\t This Column is already full.";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "\n\t Choose another: ";
				cin >> choice;
				row = InputtedColumn(choice);
			}

			BOARD(row, choice, 'X');

			player1++;
		}
		if (Player1_RowStatus(row) == true) {
			system("Color 0E");
			cout << "\n\n\t\t\t\t\t\t Player 1 Wins!\n\n\n";
			col1 = 6, col2 = 6, col3 = 6, col4 = 6, col5 = 6, col6 = 6, col7 = 6;
			break;
		}
		if (Player1_ColStatus(choice) == true) {
			system("Color 0E");
			cout << " \n\n\t\t\t\t\t\t Player 1 Wins!\n\n\n";
			col1 = 6, col2 = 6, col3 = 6, col4 = 6, col5 = 6, col6 = 6, col7 = 6;
			break;
		}
		if (Player1_LeftDiagonalStatus(row, choice) == true) {
			system("Color 0E");
			cout << " \n\n\t\t\t\t\t\t Player 1 Wins!\n\n\n";
			col1 = 6, col2 = 6, col3 = 6, col4 = 6, col5 = 6, col6 = 6, col7 = 6;
			break;
		}
		if (Player1_RightDiagonalStatus(row, choice) == true) {
			system("Color 0E");
			cout << " \n\n\t\t\t\t\t\t Player 1 Wins!\n\n\n";
			col1 = 6, col2 = 6, col3 = 6, col4 = 6, col5 = 6, col6 = 6, col7 = 6;
			break;
		}

		while (player2 < 1) {
			cout << "\n\t Player 2, Choose a number: ";
			cin >> choice;
			row = InputtedColumn(choice);

			while (cin.good() == false || choice < 1 || choice > 7) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "\n\t Invalid Input. Choose between [1-7]: ";
				cin >> choice;
				row = InputtedColumn(choice);
			}

			while (Column_is_Full(choice) == true) {
				cout << "\n\t This Column is already full.";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "\n\t Choose another: ";
				cin >> choice;
				row = InputtedColumn(choice);
			}

			BOARD(row, choice, 'O');

			player2++;
		}

		if (Player2_RowStatus(row) == true) {
			system("Color 0E");
			cout << "\n\n\t\t\t\t\t\t Player 2 Wins!\n\n\n";
			col1 = 6, col2 = 6, col3 = 6, col4 = 6, col5 = 6, col6 = 6, col7 = 6;
			break;
		}
		if (Player2_ColStatus(choice) == true) {
			system("Color 0E");
			cout << "\n\n\t\t\t\t\t\t Player 2 Wins!\n\n\n";
			col1 = 6, col2 = 6, col3 = 6, col4 = 6, col5 = 6, col6 = 6, col7 = 6;
			break;
		}
		if (Player2_LeftDiagonalStatus(row, choice) == true) {
			system("Color 0E");
			cout << " \n\n\t\t\t\t\t\t Player 2 Wins!\n\n\n";
			col1 = 6, col2 = 6, col3 = 6, col4 = 6, col5 = 6, col6 = 6, col7 = 6;
			break;
		}
		if (Player2_RightDiagonalStatus(row, choice) == true) {
			system("Color 0E");
			cout << " \n\n\t\t\t\t\t\t Player 2 Wins!\n\n\n";
			col1 = 6, col2 = 6, col3 = 6, col4 = 6, col5 = 6, col6 = 6, col7 = 6;
			break;
		}

		counter++;

		if (counter == 21) {
			cout << "\n\n\t\t\t\t\t\t Game is DRAW.\n";
		}
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	//removes marked boxes on board
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			board[i][j] = '-';
		}
	}
	system("pause>0");
	return 1;
}

//Asks if to play again
int ToPlayAgain() {

	int playAgain = 0;

	system("Color 06");
	system("cls");

	cout << "\n\n\n\n\t\t\t\t\t ----- PLAY AGAIN? -----";
	cout << "\n\n\n\t\t\t\t\t 1. Main Menu";
	cout << "\n\n\t\t\t\t\t 2. Yes";
	cout << "\n\n\t\t\t\t\t 3. Quit\n";
	playAgain = Menu_ToPlayAgain_InputVal();

	switch (playAgain) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;

	default:
		cout << "\n\n\t\t\t\t\tInvalid Input.\n";
		cout << "\n\t\t\t\t\tInput must NOT have decimal number/s.";
		cout << "\n\t\t\t\t\tInput must NOT have string or letter/s.";
		cout << "\n\t\t\t\t\tInput must NOT have space/s.";
		cout << "\n\t\t\t\t\tInput must not have special character/s.";
		cout << endl << endl << endl << "\t\t\t\t\t";
		system("pause");
	}

	return playAgain;
}

//main function
int main()
{
	int again = 0;

	while (Main_Menu() != 1) {
	}
	Multiplayer();

	do {
		again = ToPlayAgain();

		if (again == 1) {
			main(); break;
		}
		else if (again == 2) {
			Multiplayer();
		}
	} while (again != 3);

	system("cls");
	system("Color 0E");
	cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t----xxxx---- THANK YOU PLAYER :)) ----oooo----";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	return 0;
}	  
