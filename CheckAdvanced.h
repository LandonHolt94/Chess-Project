#pragma once
#pragma once
bool Check_ADVANCED(char Grid[][8], char x, char y, char j, char z, char player, Button* pieces[])
{
	char piece = Grid[x][y];
	char dest = Grid[j][z];
	bool Castle_Left = false;
	bool Castle_Right = false;
	bool King_Move = false;
	bool check = false;
	char en_passant = 'z';
	char aux, aux_piece;
	int m;
	//Basic movement and Captures
	switch (piece)
	{
	case WHITE_PAWN:
	case BLACK_PAWN:
		//Check backwards movement
		if (piece == WHITE_PAWN && j > x)
			return false;
		else if (piece == BLACK_PAWN && x > j)
			return false;
		//Check posible double move if first time moving pawn
		if (abs(x - j) == 2 && abs(y - z) == 0)
		{
			if (player == WHITE_PLAYER && x == 6)
			{
				en_passant = y;
				goto CHECK_CHECK;
			}
			else if (player == BLACK_PLAYER && x == 1)
			{
				en_passant = y;
				goto CHECK_CHECK;
			}
		}
		//Check en passant
		if (dest == EMPTY_SQUARE && abs(y - z) == 1 && abs(x - j) == 1 && ((player == WHITE_PLAYER && Grid[j + 1][z] == BLACK_PAWN && BLACK_EN_PASSANT == z) || (player == BLACK_PLAYER && Grid[j - 1][z] == WHITE_PAWN && WHITE_EN_PASSANT == z)))
		{
			en_passant = 'k';
			goto CHECK_CHECK;
		}
		//Check that the move is not further than one square and if it goes diagonally there is not an empty square and can t kill enemies just walking forward
		if (abs(y - z) > 1 || abs(x - j) > 1 || ((y != z) && (dest == EMPTY_SQUARE)) || ((y == z) && (dest != EMPTY_SQUARE)))
			return false;
		//Can t capture going horizontally
		if (y - z != 0 && x - j == 0)
			return false;
		//check promote
		if (j == 0 || j == 7)
		{
			std::cout << "What do you want to promote to?" << std::endl;
			std::cout << "Queen (Q/q) Bishop (B/b) Horse (H/h) Rook (R/r)" << std::endl;
			std::cin >> piece;
			bool white_promote = (player == WHITE_PLAYER && (piece == WHITE_HORSE || piece == WHITE_BISHOP || piece == WHITE_QUEEN || piece == WHITE_ROOK));
			bool black_promote = (player == BLACK_PLAYER && (piece == BLACK_HORSE || piece == BLACK_BISHOP || piece == BLACK_QUEEN || piece == BLACK_ROOK));
			bool result = !(white_promote ^ black_promote);
			while (!std::cin.good() || result)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				system("CLS");
				Display_Grid(Grid);
				std::cout << "What do you want to promote to?" << std::endl;
				std::cout << "Queen (Q/q) Bishop (B/b) Horse (H/h) Rook (R/r)" << std::endl;
				std::cout << "Insert Correct data" << std::endl;
				std::cin >> piece;
				white_promote = (player == WHITE_PLAYER && (piece == WHITE_HORSE || piece == WHITE_BISHOP || piece == WHITE_QUEEN || piece == WHITE_ROOK));
				black_promote = (player == BLACK_PLAYER && (piece == BLACK_HORSE || piece == BLACK_BISHOP || piece == BLACK_QUEEN || piece == BLACK_ROOK));
				result = !(white_promote ^ black_promote);
			}
			Grid[x][y] = piece;
		}
		break;
	case WHITE_HORSE:
	case BLACK_HORSE:
		//Basic movement
		if (abs(x - j) == 2 && abs(y - z) == 1)
			goto CHECK_CHECK;
		if (abs(y - z) == 2 && abs(x - j) == 1)
			goto CHECK_CHECK;
		return false;
	case WHITE_QUEEN:
	case BLACK_QUEEN:
	case WHITE_ROOK:
	case BLACK_ROOK:
		//Check Vertical movement
		if (x == j && y != z)
		{
			y < z ? aux = y : aux = z;
			for (int t = 1; t < abs(y - z); t++)
				if (Grid[x][t + aux] != EMPTY_SQUARE)
					return false;
			if (piece == BLACK_ROOK || piece == WHITE_ROOK)
			{
				if (y == 7) Castle_Right = true;
				if (y == 0) Castle_Left = true;
			}
			goto CHECK_CHECK;
		}
		//Check Horizontal movement
		if (z == y && x != j)
		{
			x < j ? aux = x : aux = j;
			for (int t = 1; t < abs(x - j); t++)
				if (Grid[t + aux][y] != EMPTY_SQUARE)
					return false;
			if (piece == BLACK_ROOK || piece == WHITE_ROOK)
			{
				if (y == 7) Castle_Right = true;
				if (y == 0) Castle_Left = true;
			}
			goto CHECK_CHECK;
		}
		if (piece == BLACK_ROOK || piece == WHITE_ROOK)
			return false;
	case WHITE_BISHOP:
	case BLACK_BISHOP:
		//Check diagonal movement
		if (abs(x - j) != abs(y - z) || abs(x - j) == 0)
			return false;
		//Search TOP Left x-- y--
		if (x > j && y > z)
		{
			m = y - 1;
			for (int t = x - 1; t > j; t--)
			{
				if (Grid[t][m] != EMPTY_SQUARE)
					return false;
				m--;
			}
		}
		//Search BOTTOM Right x++ y++
		else if (x < j && y < z)
		{
			m = y + 1;
			for (int t = x + 1; t < j; t++)
			{
				if (Grid[t][m] != EMPTY_SQUARE)
					return false;
				m++;
			}
		}
		//Search BOTTOM Left x++ y--
		else if (x < j && y>z)
		{
			m = y - 1;
			for (int t = x + 1; t < j; t++)
			{
				if (Grid[t][m] != EMPTY_SQUARE)
					return false;
				m--;
			}
		}
		//Search top Right x-- y++
		else
		{
			m = y + 1;
			for (int t = x - 1; t > j; t--)
			{
				if (Grid[t][m] != EMPTY_SQUARE)
					return false;
				m++;
			}
		}
		goto CHECK_CHECK;
		break;
	case WHITE_KING:
	case BLACK_KING:
		//Basic movement
		if (abs(j - x) > 1 || abs(y - z) > 2 || (abs(y - z) > 1 && y != 4))
			return false;
		//Castle
		if (abs(y - z) == 2 && abs(j - x) == 0 && (x == 0 || x == 7) && y == 4)
		{
			if (player == WHITE_PLAYER && WHITE_CASTLE_KING == true && (WHITE_CASTLE_LEFT == true || WHITE_CASTLE_RIGHT == true))
			{
				if (z == 6)//Castle right
				{
					if (Grid[x][5] != EMPTY_SQUARE || Grid[x][6] != EMPTY_SQUARE || WHITE_CASTLE_RIGHT == false)
						return false;
					Grid[x][5] = WHITE_KING;
					Grid[x][7] = EMPTY_SQUARE;
					check = Player_In_Check(Grid, player % 2 + 1);
					if (check == true)
						return false;
					Grid[x][6] = WHITE_KING;
					check = Player_In_Check(Grid, player % 2 + 1);
					if (check == true)
						return false;
					for (int i = 0; i < 32; i++)
					{
						if (pieces[i]->Getpiece() == WHITE_ROOK)
						{
							int xx, yy;
							pieces[i]->Getposition(&xx, &yy);
							if (xx == (7) * 80 && yy == x * 80)
							{
								pieces[i]->Setposition(5 * 80, x * 80);
								break;
							}
						}
					}
					Grid[x][5] = WHITE_ROOK;

					King_Move = true;
					goto CHECK_CHECK;
				}
				if (z == 2)
				{
					if (Grid[x][3] != EMPTY_SQUARE || Grid[x][2] != EMPTY_SQUARE || Grid[x][1] != EMPTY_SQUARE || WHITE_CASTLE_LEFT == false)
						return false;
					Grid[x][3] = WHITE_KING;
					Grid[x][0] = EMPTY_SQUARE;
					check = Player_In_Check(Grid, player % 2 + 1);
					if (check == true)
						return false;
					Grid[x][2] = WHITE_KING;
					check = Player_In_Check(Grid, player % 2 + 1);
					if (check == true)
						return false;
					for (int i = 0; i < 32; i++)
					{
						if (pieces[i]->Getpiece() == WHITE_ROOK)
						{
							int xx, yy;
							pieces[i]->Getposition(&xx, &yy);
							if (xx == 0 && yy == x * 80)
							{
								pieces[i]->Setposition(3 * 80, x * 80);
								break;
							}
						}
					}
					Grid[x][3] = WHITE_ROOK;
					King_Move = true;
					goto CHECK_CHECK;
				}
			}
			if (player == BLACK_PLAYER && BLACK_CASTLE_KING == true && (BLACK_CASTLE_LEFT == true || BLACK_CASTLE_RIGHT == true))
			{
				if (z == 6)//Castle right
				{
					if (Grid[x][5] != EMPTY_SQUARE || Grid[x][6] != EMPTY_SQUARE || BLACK_CASTLE_RIGHT == false)
						return false;
					Grid[x][5] = BLACK_KING;
					Grid[x][7] = EMPTY_SQUARE;
					check = Player_In_Check(Grid, player % 2 + 1);
					if (check == true)
						return false;
					Grid[x][6] = BLACK_KING;
					check = Player_In_Check(Grid, player % 2 + 1);
					if (check == true)
						return false;
					for (int i = 0; i < 32; i++)
					{
						if (pieces[i]->Getpiece() == BLACK_ROOK)
						{
							int xx, yy;
							pieces[i]->Getposition(&xx, &yy);
							if (xx == (7) * 80 && yy == x * 80)
							{
								pieces[i]->Setposition(5 * 80, x * 80);
								break;
							}
						}
					}
					Grid[x][5] = BLACK_ROOK;

					King_Move = true;
					goto CHECK_CHECK;
				}
				if (z == 2)
				{
					if (Grid[x][3] != EMPTY_SQUARE || Grid[x][2] != EMPTY_SQUARE || Grid[x][1] != EMPTY_SQUARE || BLACK_CASTLE_LEFT == false)
						return false;

					Grid[x][3] = BLACK_KING;
					Grid[x][0] = EMPTY_SQUARE;
					check = Player_In_Check(Grid, player % 2 + 1);
					if (check == true)
						return false;
					Grid[x][2] = BLACK_KING;
					check = Player_In_Check(Grid, player % 2 + 1);
					if (check == true)
						return false;
					for (int i = 0; i < 32; i++)
					{
						if (pieces[i]->Getpiece() == BLACK_ROOK)
						{
							int xx, yy;
							pieces[i]->Getposition(&xx, &yy);
							if (xx == 0 && yy == x * 80)
							{
								pieces[i]->Setposition(3 * 80, x * 80);
								break;
							}
						}
					}
					Grid[x][3] = BLACK_ROOK;
					King_Move = true;
					goto CHECK_CHECK;
				}
			}
			return false;
		}
		King_Move = true;
		break;
	}
CHECK_CHECK:
	//We simulate the move on the actual Grid but if the move is not posible we goto restore and we change the grid again.
	Grid[x][y] = EMPTY_SQUARE;
	aux_piece = Grid[j][z];
	Grid[j][z] = piece;
	if (player == WHITE_PLAYER)
	{
		//An en passant capture is being tested
		if (en_passant == 'k') Grid[j + 1][z] = EMPTY_SQUARE;

		check = Player_In_Check(Grid, player % 2 + 1);
		if (check == true)
		{
			if (en_passant == 'k') Grid[j + 1][z] = BLACK_PAWN;
			goto restore;
		}
		//If en passant is possible kill pawn visually
		if (en_passant == 'k')
		{
			for (int i = 0; i < 32; i++)
			{
				if (pieces[i]->Getpiece() == BLACK_PAWN)
				{
					int xx, yy;
					pieces[i]->Getposition(&xx, &yy);
					if (yy == (j + 1) * 80 && xx == z * 80)
					{
						pieces[i]->Setdead();
						break;
					}
				}
			}
		}

		//update castle variables
		if (WHITE_CASTLE_KING == true) WHITE_CASTLE_KING = !King_Move;
		if (WHITE_CASTLE_LEFT == true) WHITE_CASTLE_LEFT = !Castle_Left;
		if (WHITE_CASTLE_RIGHT == true) WHITE_CASTLE_RIGHT = !Castle_Right;
		//update en passant column
		if (en_passant != 'z' && en_passant != 'k') WHITE_EN_PASSANT = en_passant;
		BLACK_EN_PASSANT = 'z';
	}
	if (player == BLACK_PLAYER)
	{
		//An en passant capture is being tested
		if (en_passant == 'k') Grid[j - 1][z] = EMPTY_SQUARE;

		check = Player_In_Check(Grid, player % 2 + 1);
		if (check == true)
		{
			if (en_passant == 'k') Grid[j - 1][z] = WHITE_PAWN;
			goto restore;
		}
		//If en passant is possible kill pawn visually
		if (en_passant == 'k')
		{
			for (int i = 0; i < 32; i++)
			{
				if (pieces[i]->Getpiece() == WHITE_PAWN)
				{
					int xx, yy;
					pieces[i]->Getposition(&xx, &yy);
					if (yy == (j + 1) * 80 && xx == z * 80)
					{
						pieces[i]->Setdead();
						break;
					}
				}
			}
		}
		//update castle variables
		if (BLACK_CASTLE_KING == true) BLACK_CASTLE_KING = !King_Move;
		if (BLACK_CASTLE_LEFT == true) BLACK_CASTLE_LEFT = !Castle_Left;
		if (BLACK_CASTLE_RIGHT == true) BLACK_CASTLE_RIGHT = !Castle_Right;
		//update en passant column
		if (en_passant != 'z' && en_passant != 'k') BLACK_EN_PASSANT = en_passant;
		WHITE_EN_PASSANT = 'z';
	}
	//returns false if the move is not possible
	return true;
restore:
	Grid[x][y] = Grid[j][z];
	Grid[j][z] = aux_piece;
	return false;
}