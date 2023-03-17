#include<iostream>
#include<fstream>
#include<cstring>
#include<windows.h>
#include<conio.h>
using namespace std;
#include <chrono> 
using namespace std::chrono;

void Setcolor(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
void pboard(char board[8][8])
{
	char alpha[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	int num[] = { 8, 7, 6, 5, 4, 3, 2, 1 };
	//print board
	for (int i = 0; i < 8; i++)
	{
		if (i == 0)
			cout << "     ";
		cout << alpha[i] << "   ";
	}
	cout << endl;
	cout << "    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";

	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << num[i] << "   ";
		for (int j = 0; j < 8; j++)
		{
			if (j < 7)
			{
				cout << "|";
				cout<< board[i][j] << "  ";
			}
			else if (j == 7)
			{
				
				cout << "|";
				cout<< board[i][j] << "  | ";
			}
		}
		cout << "  " << num[i] << "    ";
		cout << endl;
		if (i < 7)
		{
			cout << "    ---------------------------------    ";
			cout << endl;
		}
	}
	cout << "    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		if (i == 0)
			cout << "     ";
		cout << alpha[i] << "   ";
	}
	cout << endl;
}
void choicee(string choice, int& c1, int& c2, int& c3, int& c4)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			if (choice[i] == 'a')
				c1 = 0;
			if (choice[i] == 'b')
				c1 = 1;
			if (choice[i] == 'c')
				c1 = 2;
			if (choice[i] == 'd')
				c1 = 3;
			if (choice[i] == 'e')
				c1 = 4;
			if (choice[i] == 'f')
				c1 = 5;
			if (choice[i] == 'g')
				c1 = 6;
			if (choice[i] == 'h')
				c1 = 7;
		}
		else if (i == 1)
		{
			if (choice[i] == '1')
				c2 = 7;
			if (choice[i] == '2')
				c2 = 6;
			if (choice[i] == '3')
				c2 = 5;
			if (choice[i] == '4')
				c2 = 4;
			if (choice[i] == '5')
				c2 = 3;
			if (choice[i] == '6')
				c2 = 2;
			if (choice[i] == '7')
				c2 = 1;
			if (choice[i] == '8')
				c2 = 0;
		}
		else if (i == 2)
		{
			if (choice[i] == 'a')
				c3 = 0;
			if (choice[i] == 'b')
				c3 = 1;
			if (choice[i] == 'c')
				c3 = 2;
			if (choice[i] == 'd')
				c3 = 3;
			if (choice[i] == 'e')
				c3 = 4;
			if (choice[i] == 'f')
				c3 = 5;
			if (choice[i] == 'g')
				c3 = 6;
			if (choice[i] == 'h')
				c3 = 7;
		}
		else if (i == 3)
		{
			if (choice[i] == '1')
				c4 = 7;
			if (choice[i] == '2')
				c4 = 6;
			if (choice[i] == '3')
				c4 = 5;
			if (choice[i] == '4')
				c4 = 4;
			if (choice[i] == '5')
				c4 = 3;
			if (choice[i] == '6')
				c4 = 2;
			if (choice[i] == '7')
				c4 = 1;
			if (choice[i] == '8')
				c4 = 0;
		}

	}
}
bool moveisvalid(char board[8][8], int c1, int c2, int c3, int c4, int turn, string choice)
{
	bool valid = false;
	int len = 0, i = 0;
	while (choice[i] != '\0')
	{
		len++;
		i++;
	}

	if (len < 5 && turn % 2 == 0)
	{
		if ((choice[0] >= 97 && choice[0] <= 104) && (choice[1] >= 49 && choice[1] <= 56))
		{
			if (board[c2][c1] != ' ')
			{
				if (board[c2][c1] == 'P' || board[c2][c1] == 'R' || board[c2][c1] == 'N' || board[c2][c1] == 'B' || board[c2][c1] == 'K' || board[c2][c1] == 'Q')
				{
					if (board[c4][c3] != 'P' && board[c4][c3] != 'R' && board[c4][c3] != 'N' && board[c4][c3] != 'B' && board[c4][c3] != 'K' && board[c4][c3] != 'Q')
						valid = true;
					else
						valid = false;
				}
				else
					valid = false;
			}
			else
				valid = false;
		}
		else valid = false;
	}

	else if (len < 5 && turn % 2 == 1)
	{
		if ((choice[0] >= 97 && choice[0] <= 104) && (choice[1] >= 49 && choice[1] <= 56))
		{
			if (board[c2][c1] != ' ')
			{
				if (board[c2][c1] == 'p' || board[c2][c1] == 'r' || board[c2][c1] == 'n' || board[c2][c1] == 'b' || board[c2][c1] == 'k' || board[c2][c1] == 'q')
				{
					if (board[c4][c3] != 'p' && board[c4][c3] != 'r' && board[c4][c3] != 'n' && board[c4][c3] != 'b' && board[c4][c3] != 'k' && board[c4][c3] != 'q')
						valid = true;
					else
						valid = false;
				}
				else
					valid = false;
			}
			else
				valid = false;
		}
		else
			valid = false;
	}
	return valid;
}
string indentify(char board[8][8], int c1, int c2, int turn)
{
	string piece;
	if (turn % 2 == 0)
	{

		if (board[c2][c1] == 'P')
			piece = "PAWN";
		if (board[c2][c1] == 'R')
			piece = "ROOK";
		if (board[c2][c1] == 'N')
			piece = "KNIGHT";
		if (board[c2][c1] == 'B')
			piece = "BISHOP";
		if (board[c2][c1] == 'K')
			piece = "KING";
		if (board[c2][c1] == 'Q')
			piece = "QUEEN";
	}
	else if (turn % 2 == 1)
	{
		if (board[c2][c1] == 'p')
			piece = "pawn";
		if (board[c2][c1] == 'r')
			piece = "rook";
		if (board[c2][c1] == 'n')
			piece = "knight";
		if (board[c2][c1] == 'b')
			piece = "bishop";
		if (board[c2][c1] == 'k')
			piece = "king";
		if (board[c2][c1] == 'q')
			piece = "queen";
	}
	return piece;
}
char PawnPromotion(int turn)
{
	char piece;
	if (turn % 2 == 0)
	{
		cout << "PAWN PROMOTION " << endl
			<< "Press R for Rook" << endl
			<< "Press Q for Queen" << endl
			<< "Press B for Bishop" << endl
			<< "Press N for Knight" << endl;
		cin >> piece;
		if (piece == 'R'|| piece == 'r')
			return 'R';
		if (piece == 'Q'|| piece == 'q')
			return 'Q';
		if (piece == 'B'|| piece == 'b')
			return 'B';
		if (piece == 'N'||piece == 'n')
			return 'N';
	}
	if (turn % 2 == 1)
	{
		cout << "PAWN PROMOTION " << endl
			<< "Press r for rook" << endl
			<< "Press q for queen" << endl
			<< "Press b for Bishop" << endl
			<< "Press n for Knight" << endl;
		cin >> piece;
		if (piece == 'R' || piece == 'r')
			return 'r';
		if (piece == 'Q' || piece == 'q')
			return 'q';
		if (piece == 'B' || piece == 'b')
			return 'b';
		if (piece == 'N' || piece == 'n')
			return 'n';
	}
}
bool PAWN(char board[8][8], int c1, int c2, int c3, int c4, int turn,bool &promotion)
{
	bool valid=false;
	if (turn % 2 == 0)//player 1
	{
		if (c2 == 6 )//for first movement
		{
			if (c1 == c3)
			{
				if (c4 == (c2 - 2))
				{
					if (board[c4 + 1][c3] != 'p' && board[c4 + 1][c3] != 'r' && board[c4 + 1][c3] != 'n' && board[c4 + 1][c3] != 'b' && board[c4 + 1][c3] != 'k' && board[c4 + 1][c3] != 'q'&&
						board[c4 + 1][c3] != 'P' && board[c4 + 1][c3] != 'R' && board[c4 + 1][c3] != 'N' && board[c4 + 1][c3] != 'B' && board[c4 + 1][c3] != 'K' && board[c4 + 1][c3] != 'Q')
					{
						if (board[c4][c3] != 'p' && board[c4][c3] != 'r' && board[c4][c3] != 'n' && board[c4][c3] != 'b' && board[c4][c3] != 'k' && board[c4][c3] != 'q')
						{
							valid = true;
						}
						else
							valid = false;
					}
					else
						valid = false;
				}

				else if (c4 == (c2 - 1))
				{
					if (board[c4][c3] != 'p' && board[c4][c3] != 'r' && board[c4][c3] != 'n' && board[c4][c3] != 'b' && board[c4][c3] != 'k' && board[c4][c3] != 'q')
					{
						valid = true;
					}
					else
						valid = false;
				}
			}
				else if (c1 == (c3 + 1) || c1 == (c3 - 1))//for capture
				{
					if (board[c4][c3] == 'p' || board[c4][c3] == 'r' || board[c4][c3] == 'n' || board[c4][c3] == 'b' || board[c4][c3]|| board[c4][c3] == 'q')
					{
						valid = true;
					}
					else
						valid = false;
				}
				else
					valid = false;
		}
		else if (c2 == 5 || c2 == 4 || c2 == 3 || c2 == 2 || c2 == 1)//after first movement
		{
			if (c1 == c3)
			{
				if (c4 == (c2 - 1))
				{
					if (board[c4][c3] != 'p' && board[c4][c3] != 'r' && board[c4][c3] != 'n' && board[c4][c3] != 'b' && board[c4][c3] != 'k' && board[c4][c3] != 'q')
					{
						valid = true;
					}
					else
						valid = false;
				}
				else
					valid = false;
			}
			else if (c1 == (c3 + 1) || c1 == (c3 - 1))//for capture
			{
				if (board[c4][c3] == 'p' || board[c4][c3] == 'r' || board[c4][c3] == 'n' || board[c4][c3] == 'b' || board[c4][c3] == 'q')
				{
					valid = true;
				}
				else
					valid = false;
			}
		}
		else
			valid = false;
	}

	if (turn % 2 == 1)//player 2
	{
		if (c2 == 1 )//for first movement
		{
			if (c1 == c3)
			{
				if (c4 == (c2 + 2))
				{
					if (board[c4 - 1][c3] != 'P' && board[c4 - 1][c3] != 'R' && board[c4 - 1][c3] != 'N' && board[c4 - 1][c3] != 'B' && board[c4 - 1][c3] != 'K' && board[c4 - 1][c3] != 'Q' &&
						board[c4 - 1][c3] != 'p' && board[c4 - 1][c3] != 'r' && board[c4 - 1][c3] != 'n' && board[c4 - 1][c3] != 'b' && board[c4 - 1][c3] != 'k' && board[c4 - 1][c3] != 'q')
					{
						if (board[c4][c3] != 'P' && board[c4][c3] != 'R' && board[c4][c3] != 'N' && board[c4][c3] != 'B' && board[c4][c3] != 'K' && board[c4][c3] != 'Q')
						{
							valid = true;
						}
						else
							valid = false;
					}
					else
						valid = false;
				}
			

			   else if (c4 == (c2 + 1))
			   {
				if (board[c4][c3] != 'P' && board[c4][c3] != 'R' && board[c4][c3] != 'N' && board[c4][c3] != 'B' && board[c4][c3] != 'K' && board[c4][c3] != 'Q')
				{
					valid = true;
				}
				else
					valid = false;
			   }
			}
			else if (c1 == (c3 + 1) || c1 == (c3 - 1))//for capture
			{
				if (board[c4][c3] == 'P' || board[c4][c3] == 'R' || board[c4][c3] == 'N' || board[c4][c3] == 'B' || board[c4][c3] == 'Q')
				{
					valid = true;
				}
				else
					valid = false;
			}
			else
				valid = false;
		}
		else if (c2 == 2 || c2 == 3 || c2 == 4 || c2 == 5 || c2 == 6)//after first movement
		{
			if (c1 == c3)
			{
				if (c4 == (c2 + 1))
				{
					if (board[c4][c3] != 'P' && board[c4][c3] != 'R' && board[c4][c3] != 'N' && board[c4][c3] != 'B' && board[c4][c3] != 'K' && board[c4][c3] != 'Q')
					{
						valid = true;
					}
					else
						valid = false;
				}
				else
					valid = false;
			}
			else if (c1 == (c3 + 1) || c1 == (c3 - 1))//for capture
			{
				if (board[c4][c3] == 'P' || board[c4][c3] == 'R' || board[c4][c3] == 'N' || board[c4][c3] == 'B' || board[c4][c3] == 'Q')
				{
					valid = true;
				}
				else
					valid = false;
			}
		}
		else
			valid = false;
	}
	//for pawn promotion
	if (turn % 2 == 0)
	{
		if (c4 == 0)
		{
			promotion = true;
		}
	}
	if (turn % 2 == 1)
	{
		if (c4 == 7)
		{
			promotion = true;
		}
	}
	if (board[c4][c3] == 'k' || board[c4][c3] == 'K')
	{
		valid = false;
	}
	return valid;
}
bool BISHOP(char board[8][8], int c1, int c2, int c3, int c4, int turn)
{
	bool valid = false, validity = true;
		for (int i = 0; i < 8; i++)
		{
			if (valid == false && validity == true)
			{
				validity = true;
				if ((c1 + i) == c3 && (c2 + i) == c4)
				{
					valid = true;
				}

				if (i > 0 && i < 7 && valid == false)
				{
					if (board[c2 + i][c1 + i] == 'p' || board[c2 + i][c1 + i] == 'P' || board[c2 + i][c1 + i] == 'R' || board[c2 + i][c1 + i] == 'r' || board[c2 + i][c1 + i] == 'n' || board[c2 + i][c1 + i] == 'N'
						|| board[c2 + i][c1 + i] == 'B' || board[c2 + i][c1 + i] == 'b' || board[c2 + i][c1 + i] == 'k' || board[c2 + i][c1 + i] == 'K' || board[c2 + i][c1 + i] == 'Q' || board[c2 + i][c1 + i] == 'q')
					{
						validity = false;
					}
				}
							
			}
		}
		if(valid==false)
		validity = true;
		for (int i = 0; i < 8; i++)
		{
			if (valid == false && validity == true)
			{
				validity = true;
				if ((c1 - i) == c3 && (c2 - i) == c4)
					valid = true;
				if (i > 0 && i < 7 && valid == false)
				{
					if (board[c2 - i][c1 - i] == 'p' || board[c2 - i][c1 - i] == 'P' || board[c2 - i][c1 - i] == 'R' || board[c2 - i][c1 - i] == 'r' || board[c2 - i][c1 - i] == 'n' || board[c2 - i][c1 - i] == 'N'
						|| board[c2 - i][c1 - i] == 'B' || board[c2 - i][c1 - i] == 'b' || board[c2 - i][c1 - i] == 'k' || board[c2 - i][c1 - i] == 'K' || board[c2 - i][c1 - i] == 'Q' || board[c2 - i][c1 - i] == 'q')
					{
						validity = false;
					}
				}
			}
		}
		if (valid == false)
			validity = true;
		for (int i = 0; i < 8; i++)
		{
			if (valid == false && validity == true)
			{
				if ((c1 - i) == c3 && (c2 + i) == c4)
					valid = true;
				if (i > 0 && i < 7 && valid == false)
				{
					if (board[c2 + i][c1 - i] == 'p' || board[c2 + i][c1 - i] == 'P' || board[c2 + i][c1 - i] == 'R' || board[c2 + i][c1 - i] == 'r' || board[c2 + i][c1 - i] == 'n' || board[c2 + i][c1 - i] == 'N'
						|| board[c2 + i][c1 - i] == 'B' || board[c2 + i][c1 - i] == 'b' || board[c2 + i][c1 - i] == 'k' || board[c2 + i][c1 - i] == 'K' || board[c2 + i][c1 - i] == 'Q' || board[c2 + i][c1 - i] == 'q')
					{
						validity = false;
					}
				}
			}
		}
		if (valid == false)
			validity = true;
		for (int i = 0; i < 8; i++)
		{
			if (valid == false && validity == true)
			{
				if ((c1 + i) == c3 && (c2 - i) == c4)
					valid = true;
				if (i > 0 && i < 7 && valid == false)
				{
					if (board[c2 - i][c1 + i] == 'p' || board[c2 - i][c1 + i] == 'P' || board[c2 - i][c1 + i] == 'R' || board[c2 - i][c1 + i] == 'r' || board[c2 - i][c1 + i] == 'n' || board[c2 - i][c1 + i] == 'N'
						|| board[c2 - i][c1 + i] == 'B' || board[c2 - i][c1 + i] == 'b' || board[c2 - i][c1 + i] == 'k' || board[c2 - i][c1 + i] == 'K' || board[c2 - i][c1 + i] == 'Q' || board[c2 - i][c1 + i] == 'q')
					{
						validity = false;
					}
				}
			}
		}
	
	if (board[c4][c3] == 'k' || board[c4][c3] == 'K')
	{
		validity = false;
	}
	if (valid == true && validity == true)
	{
		return true;
	}
	else
		return false;
}
bool ROOK(char board[8][8], int c1, int c2, int c3, int c4,int turn)
{
	bool valid = false, validity = true;
	if ((c1 + 1) == c3 || (c1 + 2) == c3 || (c1 + 3) == c3 || (c1 + 4) == c3 || (c1 + 5) == c3 || (c1 + 6) == c3 || (c1 + 7) == c3)
	{
		if (c2 == c4)
		{
			valid = true;
		}
		for (int i = c1+1; i < c3; i++)
		{
			if (valid == true)
			{
				if (board[c2][i] == 'p' || board[c2][i] == 'P' || board[c2][i] == 'R' || board[c2][i] == 'r' || board[c2][i] == 'B' || board[c2][i] == 'b' ||
					board[c2][i] == 'N' || board[c2][i] == 'n' || board[c2][i] == 'K' || board[c2][i] == 'k' || board[c2][i] == 'Q' || board[c2][i] == 'q')
				{
					validity = false;
				}
			}
		}
	}
	else if ((c1 - 1) == c3 || (c1 - 2) == c3 || (c1 - 3) == c3 || (c1 - 4) == c3 || (c1 - 5) == c3 || (c1 - 6) == c3 || (c1 - 7) == c3)
	{
		if (c2 == c4)
		{
			valid = true;
		}
		for (int i = c1-1; i > c3; i--)
		{
			if (valid == true)
			{
				if (board[c2][i] == 'p' || board[c2][i] == 'P' || board[c2][i] == 'R' || board[c2][i] == 'r' || board[c2][i] == 'B' || board[c2][i] == 'b' ||
					board[c2][i] == 'N' || board[c2][i] == 'n' || board[c2][i] == 'K' || board[c2][i] == 'k' || board[c2][i] == 'Q' || board[c2][i] == 'q')
				{
					validity = false;
				}
			}
		}
	}
	else if ((c2 + 1) == c4 || (c2 + 2) == c4|| (c2 + 3) == c4|| (c2 + 4) == c4|| (c2 + 5) == c4|| (c2 + 6) == c4|| (c2 + 7) == c4)
	{
		if (c1 == c3)
		{
			valid = true;
		}
		for (int i = c2+1; i < c4; i++)
		{
			if (valid == true)
			{
				if (board[i][c1] == 'p' || board[i][c1] == 'P' || board[i][c1] == 'R' || board[i][c1] == 'r' || board[i][c1] == 'B' || board[i][c1] == 'b' ||
					board[i][c1] == 'N' || board[i][c1] == 'n' || board[i][c1] == 'K' || board[i][c1] == 'k' || board[i][c1] == 'Q' || board[i][c1] == 'q')
				{
					validity = false;
				}
			}
		}
	}
	else if ((c2 - 1) == c4 || (c2 - 2) == c4 || (c2 - 3) == c4 || (c2 - 4) == c4 || (c2 - 5) == c4 || (c2 - 6) == c4 || (c2 - 7) == c4)
	{
		if (c1 == c3)
		{
			valid = true;
		}
		for (int i = c2-1; i > c4; i--)
		{
			if (valid == true)
			{
				if (board[i][c1] == 'p' || board[i][c1] == 'P' || board[i][c1] == 'R' || board[i][c1] == 'r' || board[i][c1] == 'B' || board[i][c1] == 'b' ||
					board[i][c1] == 'N' || board[i][c1] == 'n' || board[i][c1] == 'K' || board[i][c1] == 'k' || board[i][c1] == 'Q' || board[i][c1] == 'q')
				{
					validity = false;
				}
			}
		}
	}
	if (board[c4][c3] == 'k' || board[c4][c3] == 'K')
	{
		validity = false;
	}
	if (valid == true && validity == true)
		return true;
	else
		return false;
}
bool QUEEN(char board[8][8], int c1, int c2, int c3, int c4, int turn)
{
	bool valid = false;

	valid = ROOK(board, c1, c2, c3, c4,turn);
	if (valid == false)
	valid = BISHOP(board, c1, c2, c3, c4, turn);

		return valid;
}
bool KING(char board[8][8], int c1, int c2, int c3, int c4, int turn)
{
	bool valid = false;
	if (c1 == c3)
	{
		if ((c2 + 1) == c4 || (c2 - 1) == c4)
			valid = true;
	}
	else if (c2 == c4)
	{
		if ((c1 + 1) == c3 || (c1 - 1) == c3)
			valid = true;
	}
	else if ((c2 + 1) == c4)
	{
		if ((c1 + 1) == c3 || (c1 - 1) == c3)
			valid = true;
	}
	else if ((c2 - 1) == c4)
	{
		if ((c1 + 1) == c3 || (c1 - 1) == c3)
			valid = true;
	}
	return valid;
}
bool KNIGHT(char board[8][8], int c1, int c2, int c3, int c4, int turn)
{
	bool valid = false;
	if ((c2 + 2) == c4)
	{
		if ((c1 + 1) == c3 || (c1 - 1) == c3)
		valid=true;
	}
	else if ((c2 - 2) == c4)
	{
		if ((c1 + 1) == c3 || (c1 - 1) == c3)
			valid = true;
	}
	else if ((c1 + 2) == c3)
	{
		if ((c2 + 1) == c4 || (c2 - 1) == c4)
			valid = true;
	}
	else if ((c1 - 2) == c3)
	{
		if ((c2 + 1) == c4 || (c2 - 1) == c4)
			valid = true;
	}
	if (board[c4][c3] == 'k' || board[c4][c3] == 'K')
	{
		valid = false;
	}
	return valid;
}
bool specificpiece(string piece, char board[8][8], int c1, int c2, int c3, int c4, int turn,bool &promotion)
{
	bool valid2=false;
	if (piece == "PAWN" || piece == "pawn")
		valid2 = PAWN(board, c1, c2, c3, c4, turn,promotion);

	else if (piece == "BISHOP" || piece == "bishop")
		valid2 = BISHOP(board, c1, c2, c3, c4, turn);

	else if (piece == "ROOK" || piece == "rook")
		valid2 = ROOK(board, c1, c2, c3, c4, turn);

	else if (piece == "QUEEN" || piece == "queen")
		valid2 = QUEEN(board, c1, c2, c3, c4, turn);

	else if(piece=="KING"|| piece=="king")
		valid2=KING(board, c1, c2, c3, c4, turn);

	else if(piece == "KNIGHT" || piece == "knight")
		valid2=KNIGHT(board, c1, c2, c3, c4, turn);

	return valid2;
}
bool Handshake(int turn, string choice)
{
	int play = turn % 2;
	play++;
	if (choice[0] == 'q' || choice[0] == 'Q')
	{
		cout << "Player " << play << "has quit the game";
		return true;
	}
	else if (choice[0] == 'H' || choice[0] == 'H')
	{
		char choicee;
		cout << "Player " << play << "has offered Handshake" << endl
			<< "Do You accept" << endl
			<< "Press Y for Yes " << endl
			<< "Press N for NO  ";
		cin >> choicee;
		if (choicee == 'Y' || choicee == 'y')
		{
			cout << "Hand Shake!! It's a draw" << endl;
			return true;
		}
		else if (choicee == 'N' || choicee == 'n')
		{
			cout << "Player has rejected handshake" << endl
				<< "Press Q to Quit the Game  ";
			cin >> choicee;
			if (choicee == 'Q' || choicee == 'q')
			{
				cout << "Player " << play << "has quit the game";
				return true;
			}
			else
				return false;
		}
	}
}
void saveprogress(char save[],int i)
{
	ofstream save1("save1.txt");
	ofstream save2("save2.txt");
	ofstream save3("save3.txt");
	char choice;
	char c;
	cout << "Press 1 to save progress in slot 1"<<endl
		<< "Press 2 to save progress in slot 2" << endl
		<< "Press 3 to save progress in slot 3";
	cin >> choice;
	if (choice == '1')
	{
		for (int j = 0; j < i; j++)
		{
			if (j != 0)
			{
				if (j % 4 == 0)
					save1 << endl;
			}
			save1 << save[j];
		}
		save1.close();
	}
	else if (choice == '2')
	{
		for (int j = 0; j < i; j++)
		{

			if (j != 0)
			{
				if (j % 4 == 0)
					save2 << endl;
			}

			save2 << save[j];
		}
		save2.close();
	}
	else if (choice == '3')
	{
		for (int j = 0; j < i; j++)
		{

			if (j != 0)
			{
				if (j % 4 == 0)
					save3 << endl;
			}

			save3 << save[j];
		}
		save3.close();
	}
}
bool check(char board[8][8], int turn)
{
	bool chekp = false, chekr = false, chekn = false, chekb = false, chekq = false,promo;
	bool cheek = false;
	int c1, c2,c3,c4;
	if (turn % 2 == 1)
	{
		for (int i=0; i < 8; i++)
		{
			for (int j=0; j < 8; j++)
			{
				if (board[i][j] == 'K')
				{
					c2 = i;
					c1 = j;
				}
			}
		}
		//for check by pawn
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'p')
				{
					c4 = i;
					c3 = j;
					chekp = PAWN(board, c1, c2, c3, c4, turn, promo);
				}
			}

		}
		//for check by queen
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'q')
				{
					c4 = i;
					c3 = j;
					chekq = QUEEN(board, c1, c2, c3, c4, turn);
				}
			}

		}
		//for check by bishop
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'b')
				{
					c4 = i;
					c3 = j;
					chekb = BISHOP(board, c1, c2, c3, c4, turn);
				}
			}

		}
		//for check by rook
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'r')
				{
					c4 = i;
					c3 = j;
					chekr = ROOK(board, c1, c2, c3, c4, turn);
				}
			}

		}
		//for check by knight
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'n')
				{
					c4 = i;
					c3 = j;
					chekn = KNIGHT(board, c1, c2, c3, c4, turn);
				}
			}

		}
		if (chekp == true|| chekr == true|| chekn == true|| chekb == true|| chekq == true)
		{
			cheek = true;
		}
		else
		{
			cheek = false;
		}
	}

	if (turn % 2 == 0)//player 2
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'k')
				{
					c2 = i;
					c1 = j;
				}
			}
		}
		//for check by pawn
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'P')
				{
					c4 = i;
					c3 = j;
					chekp = PAWN(board, c1, c2, c3, c4, turn, promo);
				}
			}

		}
		//for check by queen
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'Q')
				{
					c4 = i;
					c3 = j;
					chekq = QUEEN(board, c1, c2, c3, c4, turn);
				}
			}

		}
		//for check by bishop
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'B')
				{
					c4 = i;
					c3 = j;
					chekb = BISHOP(board, c1, c2, c3, c4, turn);
				}
			}

		}
		//for check by rook
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'R')
				{
					c4 = i;
					c3 = j;
					chekr = ROOK(board, c1, c2, c3, c4, turn);
				}
			}

		}
		//for check by knight
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'N')
				{
					c4 = i;
					c3 = j;
					chekn = KNIGHT(board, c1, c2, c3, c4, turn);
				}
			}

		}
		if (chekp == true || chekr == true || chekn == true || chekb == true || chekq == true)
		{
			cheek = true;
		}
		else
		{
			cheek = false;
		}
	}
	return cheek;
}
bool checkmove(char board[8][8], int a, int b, int c, int d, string choice,int turn)
{
	int tur;
	tur = turn + 1;
	char boardreplica1[8][8];
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			boardreplica1[x][y] = board[x][y];
		}
	}
	char source, destination;
	source = boardreplica1[b][a];
	boardreplica1[d][c] = source;
	boardreplica1[b][a] = 32;

	bool chekp = false, chekr = false, chekn = false, chekb = false, chekq = false, promo;
	bool cheek = false;
	int c1, c2, c3, c4;
	if (tur % 2 == 1)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (boardreplica1[i][j] == 'K')
				{
					c2 = i;
					c1 = j;
				}
			}
		}
		//for check by pawn
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (boardreplica1[i][j] == 'p')
				{
					c4 = i;
					c3 = j;
					chekp = PAWN(boardreplica1, c1, c2, c3, c4, tur, promo);
				}
			}

		}
		//for check by queen
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'q')
				{
					c4 = i;
					c3 = j;
					chekq = QUEEN(boardreplica1, c1, c2, c3, c4, tur);
				}
			}

		}
		//for check by bishop
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'b')
				{
					c4 = i;
					c3 = j;
					chekb = BISHOP(boardreplica1, c1, c2, c3, c4, tur);
				}
			}

		}
		//for check by rook
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'r')
				{
					c4 = i;
					c3 = j;
					chekr = ROOK(boardreplica1, c1, c2, c3, c4, tur);
				}
			}

		}
		//for check by knight
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'n')
				{
					c4 = i;
					c3 = j;
					chekn = KNIGHT(boardreplica1, c1, c2, c3, c4, tur);
				}
			}

		}
		if (chekp == true || chekr == true || chekn == true || chekb == true || chekq == true)
		{
			cheek = true;
		}
		else
		{
			cheek = false;
		}
	}

	if (tur % 2 == 0)//player 2
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (boardreplica1[i][j] == 'k')
				{
					c2 = i;
					c1 = j;
				}
			}
		}
		//for check by pawn
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'P')
				{
					c4 = i;
					c3 = j;
					chekp = PAWN(boardreplica1, c1, c2, c3, c4, tur, promo);
				}
			}

		}
		//for check by queen
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (boardreplica1[i][j] == 'Q')
				{
					c4 = i;
					c3 = j;
					chekq = QUEEN(boardreplica1, c1, c2, c3, c4, tur);
				}
			}

		}
		//for check by bishop
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'B')
				{
					c4 = i;
					c3 = j;
					chekb = BISHOP(boardreplica1, c1, c2, c3, c4, tur);
				}
			}

		}
		//for check by rook
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'R')
				{
					c4 = i;
					c3 = j;
					chekr = ROOK(boardreplica1, c1, c2, c3, c4, tur);
				}
			}

		}
		//for check by knight
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'N')
				{
					c4 = i;
					c3 = j;
					chekn = KNIGHT(boardreplica1, c1, c2, c3, c4, tur);
				}
			}

		}
		if (chekp == true || chekr == true || chekn == true || chekb == true || chekq == true)
		{
			cheek = true;
		}
		else
		{
			cheek = false;
		}
	}
	return cheek;
	
}
void converter(char board[8][8], char &c1, char &c2, char &c3, char &c4, int i,int j,int k,int l,string &choice)
{
	for (int z = 0; z < 4; z++)
	{
		if (z == 0)
		{
			if (i == 0)
				c2 = '8';
			if (i == 1)
				c2 = '7';
			if (i == 2)
				c2 = '6';
			if (i == 3)
				c2 = '5';
			if (i == 4)
				c2 = '4';
			if (i == 5)
				c2 = '3';
			if (i == 6)
				c2 = '2';
			if (i == 7)
				c2 = '1';
		}
		else if (z == 1)
		{
			if (j == 0)
				c1 = 'a';
			if (j == 1)
				c1 = 'b';
			if (j == 2)
				c1 = 'c';
			if (j == 3)
				c1 = 'd';
			if (j == 4)
				c1 = 'e';
			if (j == 5)
				c1 = 'f';
			if (j == 6)
				c1 = 'g';
			if (j == 7)
				c1 = 'h';
		}
		else if (z == 2)
		{
			if (k == 0)
				c4 = '8';
			if (k == 1)
				c4 = '7';
			if (k == 2)
				c4 = '6';
			if (k == 3)
				c4 = '5';
			if (k == 4)
				c4 = '4';
			if (k == 5)
				c4 = '3';
			if (k == 6)
				c4 = '2';
			if (k == 7)
				c4 = '1';
		}
		else if (z == 3)
		{
			if (l == 0)
				c3 = 'a';
			if (l == 1)
				c3 = 'b';
			if (l== 2)
				c3 = 'c';
			if (l == 3)
				c3 = 'd';
			if (l == 4)
				c3 = 'e';
			if (l == 5)
				c3 = 'f';
			if (l == 6)
				c3 = 'g';
			if (l == 7)
				c3 = 'h';
		}

	}
	choice = choice + c1;
	choice = choice + c2;
	choice = choice + c3;
	choice = choice + c4;
	
}
bool checkmate(char board[8][8], int turn)
{
	bool checkmat =true,catc,promo,valid;
	bool checkmatp =true, checkmatb = true, checkmatr = true, checkmatn = true, checkmatk = true, checkmatq = true;
	char c1, c2, c3, c4;
	char boardreplica1[8][8], boardreplica2[8][8], boardreplica3[8][8], boardreplica4[8][8], boardreplica5[8][8], boardreplica6[8][8], boardreplica7[8][8];
	turn++;
	return false;
}
int main()
{
	char mainchoice;
	cout<<"Chess Game"<<endl
		<< "Press N for New Game" << endl
		<< "Press L to load Game" << endl
		<< "Press E to Exit the Game  ";
	cin >> mainchoice;
	if (mainchoice == 'N' || mainchoice == 'n')
	{
		char mode;
		system("cls");
		cout << "GAME MODES" << endl
			<< "Press C for Classical mode" << endl
			<< "Press R for Rapid mode" << endl
			<< "Press B for Blitz mode  "<<endl
			<<"Press L for Lightning mode  ";
		cin >> mode;
		if (mode == 'C')
		{

			bool checkmat = false, chek = false;
			ofstream save1("save1.txt");
			ofstream save2("save2.txt");
			ofstream save3("save3.txt");
			char save[1000];
			int saveindex = 0;
			bool incheck;
			system("cls");
			char board[8][8] =
			{ 'r', 'n', 'b', 'q', 'k','b', 'n', 'r',
			'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
			'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R', };
			//to print board
			pboard(board);
			//for movement
			
			int turn = 0;
			int player1time = 0, player2time = 0;
			while (turn <= 150)
			{
				string choice;
				
				if (turn % 2 == 0)
				{

					cout << "Press H for HandShake" << endl;
					cout << "Press Q to Quit the Game" << endl;
					cout << "Press Save to save the Progress" << endl;
					cout << "Player 1 Enter the source and destination  " << endl;
					cin >> choice;
				}
				else if (turn % 2 == 1)
				{
					cout << "Press H for HandShake" << endl;
					cout << "Press Q to Quit the Game" << endl;
					cout << "Press Save to save the Progress" << endl;
					cout << "Player 2 Enter the source and destination  " << endl;

					cin >> choice;
					
					

				}
				int c1, c2, c3, c4;
				bool promotion = false, hand = false;
				//for handshake and Quit
				if (choice[0] == 'H' || choice[0] == 'h' || choice[0] == 'q' || choice[0] == 'Q')
				{
					hand = Handshake(turn, choice);
					if (hand == true)
						return 0;
				}
				// to save the progress
				if (choice[0] == 'S' || choice[0] == 's')
				{
					saveprogress(save, saveindex);//save function
					return 0;
				}
				//
				//choice
				choicee(choice, c1, c2, c3, c4);
				bool valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
				incheck = checkmove(board, c1, c2, c3, c4, choice, turn);
				while (valid == false || incheck == true)
				{
					if (turn % 2 == 0)
					{
						cout << "Player 1 Enter Valid source and destination  ";
						cin >> choice;
						//for handshake and Quit
						if (choice[0] == 'h' || choice[0] == 'H' || choice[0] == 'q' || choice[0] == 'Q')
						{
							hand = Handshake(turn, choice);
							if (hand == true)
								return 0;
						}
						// to save the progress
						if (choice[0] == 'S' || choice[0] == 's')
						{
							saveprogress(save, saveindex);//save function
							return 0;
						}

						choicee(choice, c1, c2, c3, c4);
						valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
						incheck = checkmove(board, c1, c2, c3, c4, choice, turn);

					}
					else if (turn % 2 == 1)
					{
						cout << "Player 2 Enter valid source and destination  ";
						cin >> choice;
						//for handshake and Quit
						if (choice[0] == 'H' || choice[0] == 'h' || choice[0] == 'q' || choice[0] == 'Q')
						{
							hand = Handshake(turn, choice);
							if (hand == true)
								return 0;
						}
						// to save the progress
						if (choice[0] == 'S' || choice[0] == 's')
						{
							saveprogress(save, saveindex);//save function
							return 0;
						}
						choicee(choice, c1, c2, c3, c4);
						valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
						incheck = checkmove(board, c1, c2, c3, c4, choice, turn);
					}
				}
				//to identify
				string piece;
				piece = indentify(board, c1, c2, turn);
				//for calling specific piece
				bool valid2;
				valid2 = specificpiece(piece, board, c1, c2, c3, c4, turn, promotion);
				while (valid2 == false || incheck == true)
				{
					cout << "Enter valid source and destination  ";
					cin >> choice;
					//for handshake and Quit
					if (choice[0] == 'H' || choice[0] == 'h' || choice[0] == 'q' || choice[0] == 'Q')
					{
						hand = Handshake(turn, choice);
						if (hand == true)
							return 0;
					}
					// to save the progress
					// to save the progress
					if (choice[0] == 'S' || choice[0] == 's')
					{
						saveprogress(save, saveindex);//save function
						return 0;
					}
					choicee(choice, c1, c2, c3, c4);
					valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
					piece = indentify(board, c1, c2, turn);
					incheck = checkmove(board, c1, c2, c3, c4, choice, turn);
					valid2 = specificpiece(piece, board, c1, c2, c3, c4, turn, promotion);
				}
				//for pawn promotion 
				if (promotion == true)
				{
					char source, destination;
					source = PawnPromotion(turn);
					board[c4][c3] = source;
					board[c2][c1] = 32;
					//
					//to save
					save[saveindex] = choice[0];
					saveindex++;
					save[saveindex] = choice[1];
					saveindex++;
					save[saveindex] = choice[2];
					saveindex++;
					save[saveindex] = choice[3];
					saveindex++;
					system("cls");
					pboard(board);
					turn++;
				}

				else
				{
					system("cls");
					char source, destination;
					source = board[c2][c1];
					board[c4][c3] = source;
					board[c2][c1] = 32;
					//to save
					save[saveindex] = choice[0];
					saveindex++;
					save[saveindex] = choice[1];
					saveindex++;
					save[saveindex] = choice[2];
					saveindex++;
					save[saveindex] = choice[3];
					saveindex++;
					//

					pboard(board);
					cout << "The piece was  " << piece << endl;
					chek = check(board, turn);
					if (chek == true)
					{
						if (turn % 2 == 1)
							cout << "Player 1 your king is in check" << endl << endl;
						if (turn % 2 == 0)
							cout << "Player 2 your king is in check" << endl << endl;
					}
					if (chek == true)
					{
						checkmat = checkmate(board, turn);
						if (checkmat == true)
						{
							system("cls");
							if (turn % 2 == 1)
							{

								pboard(board);
								cout << "CheckMate" << endl;
								cout << "Player 2 wins" << endl;

								return 0;
							}
							if (turn % 2 == 0)
							{
								pboard(board);
								cout << "CheckMate" << endl;
								cout << "Player 1 wins" << endl;
								return 0;
							}
						}
					}

					turn++;
					string choice;

				}
			}
			system("pause");
			return 0;
		}

		if (mode == 'R')
		{
			bool checkmat = false, chek = false;
			ofstream save1("save1.txt");
			ofstream save2("save2.txt");
			ofstream save3("save3.txt");
			char save[1000];
			int saveindex = 0;
			bool incheck;
			system("cls");
			char board[8][8] =
			{ 'r', 'n', 'b', 'q', 'k','b', 'n', 'r',
			'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
			'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R', };
			//to print board
			pboard(board);
			//for movement

			int turn = 0;
			int player1time = 600, player2time = 600;
			while (turn <= 150)
			{
				string choice;

				if (turn % 2 == 0)
				{
					char cho[4];
					cout << "Player 1 Enter the source and destination  " << endl;
					int inputcount = 0;
					
					while (inputcount < 5)
					{
						Sleep(1000);
						player1time--;
						cout << '\r';
						cout << "player 1 time" << player1time / 60 << ":" << player1time % 60<<"                                                                  ";
						for (int i = 0; i < inputcount; i++)
						{
							cout << cho[i];

						}
						if (_kbhit())
						{
							char ch = _getch();
							if (ch == '\b')
							{
								inputcount--;
							}
							else
							{
								cho[inputcount] = ch;
								inputcount++;
							}
                			if (player1time == 0)
							{
								cout << endl;
								cout << "Player 1 Time's up!!!!"<<endl
									<<"Player 2 Wins"<<endl;
								return 0;

								inputcount = 4;
							}
						}
						if (player1time == 0)
						{
							cout << endl;
							cout << "Player 1 Time's up!!!!" << endl
								<< "Player 2 Wins" << endl;
							return 0;

							inputcount = 4;
						}
					}

					for (int i = 0; i < 4; i++)
					{
						choice = choice + cho[i];
					}
				}
				else if (turn % 2 == 1)
				{
					char cho[4];
					cout<<endl << "Player 2 Enter the source and destination  " << endl;
					int inputcount = 0;

					while (inputcount < 5)
					{
						Sleep(1000);
						player2time--;
						cout << '\r';
						cout << "player 2 time" << player2time / 60 << ":" << player2time % 60 << "                                                        ";
						for (int i = 0; i < inputcount; i++)
						{
							cout << cho[i];

						}
						if (_kbhit())
						{
							char ch = _getch();
							if (ch == '\b')
							{
								cho[inputcount] = 32;
								inputcount--;
							}
							else
							{
								cho[inputcount] = ch;
								inputcount++;
							}
							if (player2time == 0)
							{
								cout << endl;
								cout << "Player 2 Time's up!!!!" << endl
									<< "Player 1 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}
						if (player2time == 0)
						{
							cout << endl;
							cout << "Player 2 Time's up!!!!" << endl
								<< "Player 1 Wins" << endl;
							return 0;

							inputcount = 4;
						}
					}
					for (int i = 0; i < 4; i++)
					{
						choice = choice + cho[i];
					}

				}
				int c1, c2, c3, c4;
				bool promotion = false, hand = false;

				//choice
				choicee(choice, c1, c2, c3, c4);
				bool valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
				incheck = checkmove(board, c1, c2, c3, c4, choice, turn);
				while (valid == false || incheck == true)
				{
					if (turn % 2 == 0)
					{
						string choice;
						cout << endl << "Player 1 Enter Valid source and destination  "<<endl;
						char cho[4];
						int inputcount = 0;

						while (inputcount < 5)
						{
							Sleep(1000);
							player1time--;
							cout << '\r';
							cout << "player 1 time" << player1time / 60 << ":" << player1time % 60 << "                                                                  ";
							for (int i = 0; i < inputcount; i++)
							{
								cout << cho[i];

							}
							if (_kbhit())
							{
								char ch = _getch();
								if (ch == '\b')
								{
									inputcount--;
								}
								else
								{
									cho[inputcount] = ch;
									inputcount++;
								}
								if (player1time == 0)
								{
									cout << endl;
									cout << "Player 1 Time's up!!!!" << endl
										<< "Player 2 Wins" << endl;
									return 0;

									inputcount = 4;
								}
							}
							if (player1time == 0)
							{
								cout << endl;
								cout << "Player 1 Time's up!!!!" << endl
									<< "Player 2 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}

						for (int i = 0; i < 4; i++)
						{
							choice = choice + cho[i];
						}
						
						choicee(choice, c1, c2, c3, c4);
						valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
						incheck = checkmove(board, c1, c2, c3, c4, choice, turn);

					}
					else if (turn % 2 == 1)
					{
						string choice;
						cout << endl << "Player 2 Enter valid source and destination  "<<endl;
						char cho[4];
						int inputcount = 0;

						while (inputcount < 5)
						{
							Sleep(1000);
							player2time--;
							cout << '\r';
							cout << "player 2 time" << player2time / 60 << ":" << player2time % 60 << "                                                        ";
							for (int i = 0; i < inputcount; i++)
							{
								cout << cho[i];

							}
							if (_kbhit())
							{
								char ch = _getch();
								if (ch == '\b')
								{
									cho[inputcount] = 32;
									inputcount--;
								}
								else
								{
									cho[inputcount] = ch;
									inputcount++;
								}
								if (player2time == 0)
								{
									cout << endl;
									cout << "Player 2 Time's up!!!!" << endl
										<< "Player 1 Wins" << endl;
									return 0;

									inputcount = 4;
								}
							}
							if (player2time == 0)
							{
								cout << endl;
								cout << "Player 2 Time's up!!!!" << endl
									<< "Player 1 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}
						for (int i = 0; i < 4; i++)
						{
							choice = choice + cho[i];
						}


						choicee(choice, c1, c2, c3, c4);
						valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
						incheck = checkmove(board, c1, c2, c3, c4, choice, turn);
					}
				}
				//to identify
				string piece;
				piece = indentify(board, c1, c2, turn);
				//for calling specific piece
				bool valid2;
				valid2 = specificpiece(piece, board, c1, c2, c3, c4, turn, promotion);
				while (valid2 == false || incheck == true)
				{
					if (turn % 2 == 0)
					{
						string choice;
						cout << endl << "Player 1 Enter Valid source and destination  " << endl;
						char cho[4];
						int inputcount = 0;

						while (inputcount < 5)
						{
							Sleep(1000);
							player1time--;
							cout << '\r';
							cout  << "player 1 time" << player1time / 60 << ":" << player1time % 60 << "                                                                  ";
							for (int i = 0; i < inputcount; i++)
							{
								cout << cho[i];

							}
							if (_kbhit())
							{
								char ch = _getch();
								if (ch == '\b')
								{
									inputcount--;
								}
								else
								{
									cho[inputcount] = ch;
									inputcount++;
								}
								if (player1time == 0)
								{
									cout << endl;
									cout << "Player 1 Time's up!!!!" << endl
										<< "Player 2 Wins" << endl;
									return 0;

									inputcount = 4;
								}
							}
							if (player1time == 0)
							{
								cout << endl;
								cout << "Player 1 Time's up!!!!" << endl
									<< "Player 2 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}

						for (int i = 0; i < 4; i++)
						{
							choice = choice + cho[i];
						}
						
					}
					if (turn % 2 == 1)
					{
						string choice;
						cout << endl << "Player 2 Enter valid source and destination  " << endl;
						char cho[4];
						int inputcount = 0;

						while (inputcount < 5)
						{
							Sleep(1000);
							player2time--;
							cout << '\r';
							cout << "player 2 time" << player2time / 60 << ":" << player2time % 60 << "                                                        ";
							for (int i = 0; i < inputcount; i++)
							{
								cout << cho[i];

							}
							if (_kbhit())
							{
								char ch = _getch();
								if (ch == '\b')
								{
									cho[inputcount] = 32;
									inputcount--;
								}
								else
								{
									cho[inputcount] = ch;
									inputcount++;
								}
								if (player2time == 0)
								{
									cout << endl;
									cout << "Player 2 Time's up!!!!" << endl
										<< "Player 1 Wins" << endl;
									return 0;

									inputcount = 4;
								}
							}
							if (player2time == 0)
							{
								cout << endl;
								cout << "Player 2 Time's up!!!!" << endl
									<< "Player 1 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}
						for (int i = 0; i < 4; i++)
						{
							choice = choice + cho[i];
						}
					}
					
					//for handshake and Quit
					choicee(choice, c1, c2, c3, c4);
					valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
					piece = indentify(board, c1, c2, turn);
					incheck = checkmove(board, c1, c2, c3, c4, choice, turn);
					valid2 = specificpiece(piece, board, c1, c2, c3, c4, turn, promotion);
				}
				//for pawn promotion 
				if (promotion == true)
				{
					char source, destination;
					source = PawnPromotion(turn);
					board[c4][c3] = source;
					board[c2][c1] = 32;
					
					system("cls");
					pboard(board);
					turn++;
				}

				else
				{
					system("cls");
					char source, destination;
					source = board[c2][c1];
					board[c4][c3] = source;
					board[c2][c1] = 32;
					
					pboard(board);
					cout << "The piece was  " << piece << endl;
					chek = check(board, turn);
					if (chek == true)
					{
						if (turn % 2 == 1)
							cout << "Player 1 your king is in check" << endl << endl;
						if (turn % 2 == 0)
							cout << "Player 2 your king is in check" << endl << endl;
					}
					/*if (chek == true)
					{
						checkmat = checkmate(board, turn);
						if (checkmat == true)
						{
							system("cls");
							if (turn % 2 == 1)
							{

								pboard(board);
								cout << "CheckMate" << endl;
								cout << "Player 2 wins" << endl;

								return 0;
							}
							if (turn % 2 == 0)
							{
								pboard(board);
								cout << "CheckMate" << endl;
								cout << "Player 1 wins" << endl;
								return 0;
							}
						}
					}*/
					if (turn % 2 == 0)
					{
						player1time = player1time + 10;
					}
					if (turn % 2 == 1)
					{
						player2time = player2time + 10;
					}
					turn++;
					string choice;

				}
			}
			system("pause");
			return 0;
		}
		if (mode == 'B')
		{
			bool checkmat = false, chek = false;
			ofstream save1("save1.txt");
			ofstream save2("save2.txt");
			ofstream save3("save3.txt");
			char save[1000];
			int saveindex = 0;
			bool incheck;
			system("cls");
			char board[8][8] =
			{ 'r', 'n', 'b', 'q', 'k','b', 'n', 'r',
			'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
			'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R', };
			//to print board
			pboard(board);
			//for movement

			int turn = 0;
			int player1time = 300, player2time = 300;
			while (turn <= 150)
			{
				string choice;

				if (turn % 2 == 0)
				{
					char cho[4];
					cout << "Player 1 Enter the source and destination  " << endl;
					int inputcount = 0;

					while (inputcount < 5)
					{
						Sleep(1000);
						player1time--;
						cout << '\r';
						cout << "player 1 time" << player1time / 60 << ":" << player1time % 60 << "                                                                  ";
						for (int i = 0; i < inputcount; i++)
						{
							cout << cho[i];

						}
						if (_kbhit())
						{
							char ch = _getch();
							if (ch == '\b')
							{
								inputcount--;
							}
							else
							{
								cho[inputcount] = ch;
								inputcount++;
							}
							if (player1time == 0)
							{
								cout << endl;
								cout << "Player 1 Time's up!!!!" << endl
									<< "Player 2 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}
						if (player1time == 0)
						{
							cout << endl;
							cout << "Player 1 Time's up!!!!" << endl
								<< "Player 2 Wins" << endl;
							return 0;

							inputcount = 4;
						}
					}

					for (int i = 0; i < 4; i++)
					{
						choice = choice + cho[i];
					}
				}
				else if (turn % 2 == 1)
				{
					char cho[4];
					cout << endl << "Player 2 Enter the source and destination  " << endl;
					int inputcount = 0;

					while (inputcount < 5)
					{
						Sleep(1000);
						player2time--;
						cout << '\r';
						cout << "player 2 time" << player2time / 60 << ":" << player2time % 60 << "                                                        ";
						for (int i = 0; i < inputcount; i++)
						{
							cout << cho[i];

						}
						if (_kbhit())
						{
							char ch = _getch();
							if (ch == '\b')
							{
								cho[inputcount] = 32;
								inputcount--;
							}
							else
							{
								cho[inputcount] = ch;
								inputcount++;
							}
							if (player2time == 0)
							{
								cout << endl;
								cout << "Player 2 Time's up!!!!" << endl
									<< "Player 1 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}
						if (player2time == 0)
						{
							cout << endl;
							cout << "Player 2 Time's up!!!!" << endl
								<< "Player 1 Wins" << endl;
							return 0;

							inputcount = 4;
						}
					}
					for (int i = 0; i < 4; i++)
					{
						choice = choice + cho[i];
					}

				}
				int c1, c2, c3, c4;
				bool promotion = false, hand = false;

				//choice
				choicee(choice, c1, c2, c3, c4);
				bool valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
				incheck = checkmove(board, c1, c2, c3, c4, choice, turn);
				while (valid == false || incheck == true)
				{
					if (turn % 2 == 0)
					{
						string choice;
						cout << endl << "Player 1 Enter Valid source and destination  " << endl;
						char cho[4];
						int inputcount = 0;

						while (inputcount < 5)
						{
							Sleep(1000);
							player1time--;
							cout << '\r';
							cout << "player 1 time" << player1time / 60 << ":" << player1time % 60 << "                                                                  ";
							for (int i = 0; i < inputcount; i++)
							{
								cout << cho[i];

							}
							if (_kbhit())
							{
								char ch = _getch();
								if (ch == '\b')
								{
									inputcount--;
								}
								else
								{
									cho[inputcount] = ch;
									inputcount++;
								}
								if (player1time == 0)
								{
									cout << endl;
									cout << "Player 1 Time's up!!!!" << endl
										<< "Player 2 Wins" << endl;
									return 0;

									inputcount = 4;
								}
							}
							if (player1time == 0)
							{
								cout << endl;
								cout << "Player 1 Time's up!!!!" << endl
									<< "Player 2 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}

						for (int i = 0; i < 4; i++)
						{
							choice = choice + cho[i];
						}

						choicee(choice, c1, c2, c3, c4);
						valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
						incheck = checkmove(board, c1, c2, c3, c4, choice, turn);

					}
					else if (turn % 2 == 1)
					{
						string choice;
						cout << endl << "Player 2 Enter valid source and destination  " << endl;
						char cho[4];
						int inputcount = 0;

						while (inputcount < 5)
						{
							Sleep(1000);
							player2time--;
							cout << '\r';
							cout << "player 2 time" << player2time / 60 << ":" << player2time % 60 << "                                                        ";
							for (int i = 0; i < inputcount; i++)
							{
								cout << cho[i];

							}
							if (_kbhit())
							{
								char ch = _getch();
								if (ch == '\b')
								{
									cho[inputcount] = 32;
									inputcount--;
								}
								else
								{
									cho[inputcount] = ch;
									inputcount++;
								}
								if (player2time == 0)
								{
									cout << endl;
									cout << "Player 2 Time's up!!!!" << endl
										<< "Player 1 Wins" << endl;
									return 0;

									inputcount = 4;
								}
							}
							if (player2time == 0)
							{
								cout << endl;
								cout << "Player 2 Time's up!!!!" << endl
									<< "Player 1 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}
						for (int i = 0; i < 4; i++)
						{
							choice = choice + cho[i];
						}


						choicee(choice, c1, c2, c3, c4);
						valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
						incheck = checkmove(board, c1, c2, c3, c4, choice, turn);
					}
				}
				//to identify
				string piece;
				piece = indentify(board, c1, c2, turn);
				//for calling specific piece
				bool valid2;
				valid2 = specificpiece(piece, board, c1, c2, c3, c4, turn, promotion);
				while (valid2 == false || incheck == true)
				{
					if (turn % 2 == 0)
					{
						string choice;
						cout << endl << "Player 1 Enter Valid source and destination  " << endl;
						char cho[4];
						int inputcount = 0;

						while (inputcount < 5)
						{
							Sleep(1000);
							player1time--;
							cout << '\r';
							cout << "player 1 time" << player1time / 60 << ":" << player1time % 60 << "                                                                  ";
							for (int i = 0; i < inputcount; i++)
							{
								cout << cho[i];

							}
							if (_kbhit())
							{
								char ch = _getch();
								if (ch == '\b')
								{
									inputcount--;
								}
								else
								{
									cho[inputcount] = ch;
									inputcount++;
								}
								if (player1time == 0)
								{
									cout << endl;
									cout << "Player 1 Time's up!!!!" << endl
										<< "Player 2 Wins" << endl;
									return 0;

									inputcount = 4;
								}
							}
							if (player1time == 0)
							{
								cout << endl;
								cout << "Player 1 Time's up!!!!" << endl
									<< "Player 2 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}

						for (int i = 0; i < 4; i++)
						{
							choice = choice + cho[i];
						}

					}
					if (turn % 2 == 1)
					{
						string choice;
						cout << endl << "Player 2 Enter valid source and destination  " << endl;
						char cho[4];
						int inputcount = 0;

						while (inputcount < 5)
						{
							Sleep(1000);
							player2time--;
							cout << '\r';
							cout << "player 2 time" << player2time / 60 << ":" << player2time % 60 << "                                                        ";
							for (int i = 0; i < inputcount; i++)
							{
								cout << cho[i];

							}
							if (_kbhit())
							{
								char ch = _getch();
								if (ch == '\b')
								{
									cho[inputcount] = 32;
									inputcount--;
								}
								else
								{
									cho[inputcount] = ch;
									inputcount++;
								}
								if (player2time == 0)
								{
									cout << endl;
									cout << "Player 2 Time's up!!!!" << endl
										<< "Player 1 Wins" << endl;
									return 0;

									inputcount = 4;
								}
							}
							if (player2time == 0)
							{
								cout << endl;
								cout << "Player 2 Time's up!!!!" << endl
									<< "Player 1 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}
						for (int i = 0; i < 4; i++)
						{
							choice = choice + cho[i];
						}
					}

					//for handshake and Quit
					choicee(choice, c1, c2, c3, c4);
					valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
					piece = indentify(board, c1, c2, turn);
					incheck = checkmove(board, c1, c2, c3, c4, choice, turn);
					valid2 = specificpiece(piece, board, c1, c2, c3, c4, turn, promotion);
				}
				//for pawn promotion 
				if (promotion == true)
				{
					char source, destination;
					source = PawnPromotion(turn);
					board[c4][c3] = source;
					board[c2][c1] = 32;

					system("cls");
					pboard(board);
					turn++;
				}

				else
				{
					system("cls");
					char source, destination;
					source = board[c2][c1];
					board[c4][c3] = source;
					board[c2][c1] = 32;

					pboard(board);
					cout << "The piece was  " << piece << endl;
					chek = check(board, turn);
					if (chek == true)
					{
						if (turn % 2 == 1)
							cout << "Player 1 your king is in check" << endl << endl;
						if (turn % 2 == 0)
							cout << "Player 2 your king is in check" << endl << endl;
					}
					/*if (chek == true)
					{
						checkmat = checkmate(board, turn);
						if (checkmat == true)
						{
							system("cls");
							if (turn % 2 == 1)
							{

								pboard(board);
								cout << "CheckMate" << endl;
								cout << "Player 2 wins" << endl;

								return 0;
							}
							if (turn % 2 == 0)
							{
								pboard(board);
								cout << "CheckMate" << endl;
								cout << "Player 1 wins" << endl;
								return 0;
							}
						}
					}*/
					turn++;
					string choice;

				}
			}
			system("pause");
			return 0;
		}
		if (mode == 'L')
		{
			bool checkmat = false, chek = false;
			ofstream save1("save1.txt");
			ofstream save2("save2.txt");
			ofstream save3("save3.txt");
			char save[1000];
			int saveindex = 0;
			bool incheck;
			system("cls");
			char board[8][8] =
			{ 'r', 'n', 'b', 'q', 'k','b', 'n', 'r',
			'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
			'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R', };
			//to print board
			pboard(board);
			//for movement

			int turn = 0;
			
			while (turn <= 150)
			{
				int player1time = 15, player2time = 15;
				string choice;

				if (turn % 2 == 0)
				{
					char cho[4];
					cout << "Player 1 Enter the source and destination  " << endl;
					int inputcount = 0;

					while (inputcount < 5)
					{
						Sleep(1000);
						player1time--;
						cout << '\r';
						cout << "player 1 time" << player1time / 60 << ":" << player1time % 60 << "                                                                  ";
						for (int i = 0; i < inputcount; i++)
						{
							cout << cho[i];

						}
						if (_kbhit())
						{
							char ch = _getch();
							if (ch == '\b')
							{
								inputcount--;
							}
							else
							{
								cho[inputcount] = ch;
								inputcount++;
							}
							if (player1time == 0)
							{
								cout << endl;
								cout << "Player 1 Time's up!!!!" << endl
									<< "Player 2 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}
						if (player1time == 0)
						{
							cout << endl;
							cout << "Player 1 Time's up!!!!" << endl
								<< "Player 2 Wins" << endl;
							return 0;

							inputcount = 4;
						}
					}

					for (int i = 0; i < 4; i++)
					{
						choice = choice + cho[i];
					}
				}
				else if (turn % 2 == 1)
				{
					char cho[4];
					cout << endl << "Player 2 Enter the source and destination  " << endl;
					int inputcount = 0;

					while (inputcount < 5)
					{
						Sleep(1000);
						player2time--;
						cout << '\r';
						cout << "player 2 time" << player2time / 60 << ":" << player2time % 60 << "                                                        ";
						for (int i = 0; i < inputcount; i++)
						{
							cout << cho[i];

						}
						if (_kbhit())
						{
							char ch = _getch();
							if (ch == '\b')
							{
								cho[inputcount] = 32;
								inputcount--;
							}
							else
							{
								cho[inputcount] = ch;
								inputcount++;
							}
							if (player2time == 0)
							{
								cout << endl;
								cout << "Player 2 Time's up!!!!" << endl
									<< "Player 1 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}
						if (player2time == 0)
						{
							cout << endl;
							cout << "Player 2 Time's up!!!!" << endl
								<< "Player 1 Wins" << endl;
							return 0;

							inputcount = 4;
						}
					}
					for (int i = 0; i < 4; i++)
					{
						choice = choice + cho[i];
					}

				}
				int c1, c2, c3, c4;
				bool promotion = false, hand = false;

				//choice
				choicee(choice, c1, c2, c3, c4);
				bool valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
				incheck = checkmove(board, c1, c2, c3, c4, choice, turn);
				while (valid == false || incheck == true)
				{
					if (turn % 2 == 0)
					{
						string choice;
						cout << endl << "Player 1 Enter Valid source and destination  " << endl;
						char cho[4];
						int inputcount = 0;

						while (inputcount < 5)
						{
							Sleep(1000);
							player1time--;
							cout << '\r';
							cout << "player 1 time" << player1time / 60 << ":" << player1time % 60 << "                                                                  ";
							for (int i = 0; i < inputcount; i++)
							{
								cout << cho[i];

							}
							if (_kbhit())
							{
								char ch = _getch();
								if (ch == '\b')
								{
									inputcount--;
								}
								else
								{
									cho[inputcount] = ch;
									inputcount++;
								}
								if (player1time == 0)
								{
									cout << endl;
									cout << "Player 1 Time's up!!!!" << endl
										<< "Player 2 Wins" << endl;
									return 0;

									inputcount = 4;
								}
							}
							if (player1time == 0)
							{
								cout << endl;
								cout << "Player 1 Time's up!!!!" << endl
									<< "Player 2 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}

						for (int i = 0; i < 4; i++)
						{
							choice = choice + cho[i];
						}

						choicee(choice, c1, c2, c3, c4);
						valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
						incheck = checkmove(board, c1, c2, c3, c4, choice, turn);

					}
					else if (turn % 2 == 1)
					{
						string choice;
						cout << endl << "Player 2 Enter valid source and destination  " << endl;
						char cho[4];
						int inputcount = 0;

						while (inputcount < 5)
						{
							Sleep(1000);
							player2time--;
							cout << '\r';
							cout << "player 2 time" << player2time / 60 << ":" << player2time % 60 << "                                                        ";
							for (int i = 0; i < inputcount; i++)
							{
								cout << cho[i];

							}
							if (_kbhit())
							{
								char ch = _getch();
								if (ch == '\b')
								{
									cho[inputcount] = 32;
									inputcount--;
								}
								else
								{
									cho[inputcount] = ch;
									inputcount++;
								}
								if (player2time == 0)
								{
									cout << endl;
									cout << "Player 2 Time's up!!!!" << endl
										<< "Player 1 Wins" << endl;
									return 0;

									inputcount = 4;
								}
							}
							if (player2time == 0)
							{
								cout << endl;
								cout << "Player 2 Time's up!!!!" << endl
									<< "Player 1 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}
						for (int i = 0; i < 4; i++)
						{
							choice = choice + cho[i];
						}


						choicee(choice, c1, c2, c3, c4);
						valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
						incheck = checkmove(board, c1, c2, c3, c4, choice, turn);
					}
				}
				//to identify
				string piece;
				piece = indentify(board, c1, c2, turn);
				//for calling specific piece
				bool valid2;
				valid2 = specificpiece(piece, board, c1, c2, c3, c4, turn, promotion);
				while (valid2 == false || incheck == true)
				{
					if (turn % 2 == 0)
					{
						string choice;
						cout << endl << "Player 1 Enter Valid source and destination  " << endl;
						char cho[4];
						int inputcount = 0;

						while (inputcount < 5)
						{
							Sleep(1000);
							player1time--;
							cout << '\r';
							cout << "player 1 time" << player1time / 60 << ":" << player1time % 60 << "                                                                  ";
							for (int i = 0; i < inputcount; i++)
							{
								cout << cho[i];

							}
							if (_kbhit())
							{
								char ch = _getch();
								if (ch == '\b')
								{
									inputcount--;
								}
								else
								{
									cho[inputcount] = ch;
									inputcount++;
								}
								if (player1time == 0)
								{
									cout << endl;
									cout << "Player 1 Time's up!!!!" << endl
										<< "Player 2 Wins" << endl;
									return 0;

									inputcount = 4;
								}
							}
							if (player1time == 0)
							{
								cout << endl;
								cout << "Player 1 Time's up!!!!" << endl
									<< "Player 2 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}

						for (int i = 0; i < 4; i++)
						{
							choice = choice + cho[i];
						}

					}
					if (turn % 2 == 1)
					{
						string choice;
						cout << endl << "Player 2 Enter valid source and destination  " << endl;
						char cho[4];
						int inputcount = 0;

						while (inputcount < 5)
						{
							Sleep(1000);
							player2time--;
							cout << '\r';
							cout << "player 2 time" << player2time / 60 << ":" << player2time % 60 << "                                                        ";
							for (int i = 0; i < inputcount; i++)
							{
								cout << cho[i];

							}
							if (_kbhit())
							{
								char ch = _getch();
								if (ch == '\b')
								{
									cho[inputcount] = 32;
									inputcount--;
								}
								else
								{
									cho[inputcount] = ch;
									inputcount++;
								}
								if (player2time == 0)
								{
									cout << endl;
									cout << "Player 2 Time's up!!!!" << endl
										<< "Player 1 Wins" << endl;
									return 0;

									inputcount = 4;
								}
							}
							if (player2time == 0)
							{
								cout << endl;
								cout << "Player 2 Time's up!!!!" << endl
									<< "Player 1 Wins" << endl;
								return 0;

								inputcount = 4;
							}
						}
						for (int i = 0; i < 4; i++)
						{
							choice = choice + cho[i];
						}
					}

					//for handshake and Quit
					choicee(choice, c1, c2, c3, c4);
					valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
					piece = indentify(board, c1, c2, turn);
					incheck = checkmove(board, c1, c2, c3, c4, choice, turn);
					valid2 = specificpiece(piece, board, c1, c2, c3, c4, turn, promotion);
				}
				//for pawn promotion 
				if (promotion == true)
				{
					char source, destination;
					source = PawnPromotion(turn);
					board[c4][c3] = source;
					board[c2][c1] = 32;

					system("cls");
					pboard(board);
					turn++;
				}

				else
				{
					system("cls");
					char source, destination;
					source = board[c2][c1];
					board[c4][c3] = source;
					board[c2][c1] = 32;

					pboard(board);
					cout << "The piece was  " << piece << endl;
					chek = check(board, turn);
					if (chek == true)
					{
						if (turn % 2 == 1)
							cout << "Player 1 your king is in check" << endl << endl;
						if (turn % 2 == 0)
							cout << "Player 2 your king is in check" << endl << endl;
					}
					/*if (chek == true)
					{
						checkmat = checkmate(board, turn);
						if (checkmat == true)
						{
							system("cls");
							if (turn % 2 == 1)
							{

								pboard(board);
								cout << "CheckMate" << endl;
								cout << "Player 2 wins" << endl;

								return 0;
							}
							if (turn % 2 == 0)
							{
								pboard(board);
								cout << "CheckMate" << endl;
								cout << "Player 1 wins" << endl;
								return 0;
							}
						}
					}*/
					turn++;
					string choice;

				}
			}
			system("pause");
			return 0;


		}
	}
   else if (mainchoice == 'L' || mainchoice == 'l')
   {
		system("cls");
		char choicce;
		char a[100];
		int turn = 0;
		bool checkmat = false, chek = false;
		ifstream save01("save1.txt");
		ifstream save02("save2.txt");
		ifstream save03("save3.txt");
		cout << "Select the file to load" << endl
			<< "Press 1 to load file 1" << endl
			<< "Press 2 to load file 2" << endl
			<< "Press 2 to load file 2" << endl;

		cin >> choicce;
		char board[8][8] =
		{ 'r', 'n', 'b', 'q', 'k','b', 'n', 'r',
		'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
		'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R', };
		if (choicce == '1')
		{
			
			//to print board
			pboard(board);
			Sleep(1000);
			while (save01.getline(a, 500))
			{
				int len = strlen(a);

				//for movement
				char choiceee[4];
				string choice;
				int c1, c2, c3, c4;
				for (int i = 0; i < len; i++)
				{
					choice = choice + a[i];
					if (i > 0 && i == 3)
					{
						system("cls");
						choicee(choice, c1, c2, c3, c4);
						char source, destination;
						source = board[c2][c1];
						board[c4][c3] = source;
						board[c2][c1] = 32;
						//
						pboard(board);
						if (_kbhit())
						{
						}
						else
						{
							Sleep(1000);
						}
						 turn++;
					}
				}
			}

		}
		else if (choicce == '2')
		{
			//to print board
			pboard(board);
			Sleep(1000);
			while (save02.getline(a, 500))
			{
				int len = strlen(a);

				//for movement
				char choiceee[4];
				string choice;
				int c1, c2, c3, c4;
				for (int i = 0; i < len; i++)
				{
					choice = choice + a[i];
					if (i > 0 && i == 3)
					{
						system("cls");
						choicee(choice, c1, c2, c3, c4);
						char source, destination;
						source = board[c2][c1];
						board[c4][c3] = source;
						board[c2][c1] = 32;
						//
						pboard(board);
						if (_kbhit())
						{
						}
						else
						{
							Sleep(1000);
						}
						turn++;
					}
				}
			}
		}
		else if (choicce == '3')
		{
			//to print board
			pboard(board);
			Sleep(1000);
			while (save03.getline(a, 500))
			{
				int len = strlen(a);

				//for movement
				char choiceee[4];
				string choice;
				int c1, c2, c3, c4;
				for (int i = 0; i < len; i++)
				{
					choice = choice + a[i];
					if (i > 0 && i == 3)
					{
						system("cls");
						choicee(choice, c1, c2, c3, c4);
						char source, destination;
						source = board[c2][c1];
						board[c4][c3] = source;
						board[c2][c1] = 32;
						//
						pboard(board);
						if (_kbhit())
						{
						}
						else
						{
							Sleep(1000);
						}
						turn++;
					}
				}
			}
		}
		// game
		ofstream save1("save1.txt");
		ofstream save2("save2.txt");
		ofstream save3("save3.txt");
		char save[1000];
		int saveindex = 0;
		//for movement
		string choice;
		
		while (turn <= 150)
		{

			if (turn % 2 == 0)
			{
				cout << "Press H for HandShake" << endl;
				cout << "Press Q to Quit the Game" << endl;
				cout << "Press S to save the Progress" << endl;
				cout << "Player 1 Enter the source and destination  ";
			}

			else if (turn % 2 == 1)
			{
				cout << "Press H for HandShake" << endl;
				cout << "Press Q to Quit the Game" << endl;
				cout << "Press S to save the Progress" << endl;
				cout << "Player 2 Enter the source and destination  ";
			}


			cin >> choice;
			int c1, c2, c3, c4;
			bool promotion = false, hand = false;
			//for handshake and Quit
			if (choice[0] == 'H' || choice[0] == 'h' || choice[0] == 'q' || choice[0] == 'Q')
			{
				hand = Handshake(turn, choice);
				if (hand == true)
					return 0;
			}
			// to save the progress
			if (choice[0] == 'S' || choice[0] == 's')
			{
				saveprogress(save, saveindex);//save function
				return 0;
			}
			//
			//choice
			choicee(choice, c1, c2, c3, c4);
			bool valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
			while (valid == false)
			{
				if (turn % 2 == 0)
				{
					cout << "Player 1 Enter Valid source and destination  ";
					cin >> choice;
					//for handshake and Quit
					if (choice[0] == 'h' || choice[0] == 'H' || choice[0] == 'q' || choice[0] == 'Q')
					{
						hand = Handshake(turn, choice);
						if (hand == true)
							return 0;
					}
					// to save the progress
					if (choice[0] == 'S' || choice[0] == 's')
					{
						saveprogress(save, saveindex);//save function
						return 0;
					}
					choicee(choice, c1, c2, c3, c4);
					valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
				}
				else if (turn % 2 == 1)
				{
					cout << "Player 2 Enter valid source and destination  ";
					cin >> choice;
					//for handshake and Quit
					if (choice[0] == 'H' || choice[0] == 'h' || choice[0] == 'q' || choice[0] == 'Q')
					{
						hand = Handshake(turn, choice);
						if (hand == true)
							return 0;
					}
					// to save the progress
					if (choice[0] == 'S' || choice[0] == 's')
					{
						saveprogress(save, saveindex);//save function
						return 0;
					}
					choicee(choice, c1, c2, c3, c4);
					valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
				}
			}
			//to identify
			string piece;
			piece = indentify(board, c1, c2, turn);
			//for calling specific piece
			bool valid2;
			valid2 = specificpiece(piece, board, c1, c2, c3, c4, turn, promotion);
			while (valid2 == false)
			{
				cout << "Enter valid source and destination  ";
				cin >> choice;
				//for handshake and Quit
				if (choice[0] == 'H' || choice[0] == 'h' || choice[0] == 'q' || choice[0] == 'Q')
				{
					hand = Handshake(turn, choice);
					if (hand == true)
						return 0;
				}
				// to save the progress
				// to save the progress
				if (choice[0] == 'S' || choice[0] == 's')
				{
					saveprogress(save, saveindex);//save function
					return 0;
				}
				choicee(choice, c1, c2, c3, c4);
				valid = moveisvalid(board, c1, c2, c3, c4, turn, choice);
				piece = indentify(board, c1, c2, turn);
				valid2 = specificpiece(piece, board, c1, c2, c3, c4, turn, promotion);
			}

			//for pawn promotion 
			if (promotion == true)
			{
				char source, destination;
				source = PawnPromotion(turn);
				board[c4][c3] = source;
				board[c2][c1] = 32;
				//
				//to save
				save[saveindex] = choice[0];
				saveindex++;
				save[saveindex] = choice[1];
				saveindex++;
				save[saveindex] = choice[2];
				saveindex++;
				save[saveindex] = choice[3];
				saveindex++;
				system("cls");
				pboard(board);
				turn++;
			}

			else
			{
				system("cls");
				char source, destination;
				source = board[c2][c1];
				board[c4][c3] = source;
				board[c2][c1] = 32;
				//to save
				save[saveindex] = choice[0];
				saveindex++;
				save[saveindex] = choice[1];
				saveindex++;
				save[saveindex] = choice[2];
				saveindex++;
				save[saveindex] = choice[3];
				saveindex++;
				//

				pboard(board);
				cout << "The piece was  " << piece << endl;
				chek = check(board, turn);
				if (chek == true)
				{
					if (turn % 2 == 1)
						cout << "Player 1 your king is in check" << endl << endl;
					if (turn % 2 == 0)
						cout << "Player 2 your king is in check" << endl << endl;
				}
				/*if (chek == true)
				{
					checkmat = checkmate(board, turn);
					if (checkmat == true)
					{
						system("cls");
						if (turn % 2 == 1)
						{

							pboard(board);
							cout << "CheckMate" << endl;
							cout << "Player 2 wins" << endl;

							return 0;
						}
						if (turn % 2 == 0)
						{
							pboard(board);
							cout << "CheckMate" << endl;
							cout << "Player 1 wins" << endl;
							return 0;
						}
					}
				}*/

				turn++;
			}
			
		}
		system("pause");
		return 0;
	}

	//to exit the game
	else if (mainchoice == 'E' || mainchoice == 'e')
	{
	return 0;
	}
}
