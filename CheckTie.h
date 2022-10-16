#pragma once
bool Check_Tie(char Grid[][8], char player)
{
	char piece, aux, obj1, obj2;
	//Check all the pieces of the player until one can move
	if (Player_In_Check(Grid, player) == true)
	{
		return false;
	}
	if (player == BLACK_PLAYER)
	{
		for (int x = 0; x < 8; x++)
		{
			for (int y = 0; y < 8; y++)
			{
				piece = Grid[x][y];
				if (piece == WHITE_PAWN)
				{
					//check normal movement then  finally check if en passant is posible
					if (Grid[x - 1][y] == EMPTY_SQUARE)
					{
						Grid[x][y] = EMPTY_SQUARE;
						Grid[x - 1][y] = piece;
						if (Player_In_Check(Grid, player) == false)
						{
							Grid[x - 1][y] = EMPTY_SQUARE;
							Grid[x][y] = piece;
							return false;
						}
						Grid[x - 1][y] = EMPTY_SQUARE;
						Grid[x][y] = piece;
					}
					//check capture right + en passant right
					if (y + 1 < 8)
					{
						obj1 = Grid[x - 1][y + 1];
						if (obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x - 1][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x - 1][y + 1] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x - 1][y + 1] = obj1;
						}
						//check en passant
						if (obj1 == EMPTY_SQUARE && x == 3 && (Grid[x][y + 1] == BLACK_PAWN && BLACK_EN_PASSANT == y + 1))
						{
							aux = Grid[x][y + 1];
							Grid[x - 1][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x][y + 1] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y + 1] = EMPTY_SQUARE;
								Grid[x][y] = piece;
								Grid[x][y + 1] = aux;
								return false;
							}
							Grid[x - 1][y + 1] = EMPTY_SQUARE;
							Grid[x][y] = piece;
							Grid[x][y + 1] = aux;
						}
					}
					//check capture left + en passant left
					if (y - 1 >= 0)
					{
						obj2 = Grid[x - 1][y - 1];
						if (obj2 == BLACK_PAWN || obj2 == BLACK_ROOK || obj2 == BLACK_HORSE || obj2 == BLACK_BISHOP || obj2 == BLACK_QUEEN)
						{
							Grid[x - 1][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x - 1][y - 1] = obj2;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x - 1][y - 1] = obj2;
						}
						//check en passant
						if (obj2 == EMPTY_SQUARE && x == 3 && (Grid[x][y - 1] == BLACK_PAWN && BLACK_EN_PASSANT == y - 1))
						{
							aux = Grid[x][y - 1];
							Grid[x - 1][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x][y - 1] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y - 1] = EMPTY_SQUARE;
								Grid[x][y] = piece;
								Grid[x][y - 1] = aux;
								return false;
							}
							Grid[x - 1][y - 1] = EMPTY_SQUARE;
							Grid[x][y] = piece;
							Grid[x][y - 1] = aux;
						}
					}
				}
				if (piece == WHITE_HORSE)
				{
					//Check all its moves until one can be done
					if (x + 2 < 8 && y + 1 < 8)
					{
						obj1 = Grid[x + 2][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x + 2][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 2][y + 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 2][y + 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x + 2 < 8 && y - 1 >= 0)
					{
						obj1 = Grid[x + 2][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x + 2][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 2][y - 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 2][y - 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 2 >= 0 && y + 1 < 8)
					{
						obj1 = Grid[x - 2][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x - 2][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 2][y + 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 2][y + 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 2 >= 0 && y - 1 >= 0)
					{
						obj1 = Grid[x - 2][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x - 2][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 2][y - 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 2][y - 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x + 1 < 8 && y + 2 < 8)
					{
						obj1 = Grid[x + 1][y + 2];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x + 1][y + 2] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y + 2] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 1][y + 2] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x + 1 < 8 && y - 2 >= 0)
					{
						obj1 = Grid[x + 1][y - 2];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x + 1][y - 2] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y - 2] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 1][y - 2] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 1 >= 0 && y + 2 < 8)
					{
						obj1 = Grid[x - 1][y + 2];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x - 1][y + 2] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y + 2] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 1][y + 2] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 1 >= 0 && y - 2 >= 0)
					{
						obj1 = Grid[x - 1][y - 2];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x - 1][y - 2] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y - 2] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 1][y - 2] = obj1;
							Grid[x][y] = piece;
						}
					}
				}
				if (piece == WHITE_BISHOP || piece == WHITE_QUEEN || piece == WHITE_KING)
				{
					//Check one square diagonal distance if any of these is allowed stop looking
					if (x + 1 < 8 && y + 1 < 8)
					{
						obj1 = Grid[x + 1][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x + 1][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y + 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 1][y + 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x + 1 < 8 && y - 1 >= 0)
					{
						obj1 = Grid[x + 1][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x + 1][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y - 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 1][y - 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 1 >= 0 && y + 1 < 8)
					{
						obj1 = Grid[x - 1][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x - 1][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y + 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 1][y + 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 1 >= 0 && y - 1 >= 0)
					{
						obj1 = Grid[x - 1][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x - 1][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y - 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 1][y - 1] = obj1;
							Grid[x][y] = piece;
						}
					}
				}
				if (piece == WHITE_ROOK || piece == WHITE_QUEEN || piece == WHITE_KING)
				{
					//Check one square distance both vertically and horizontally if the move is allowed stop looking
					if (y + 1 < 8)
					{
						obj1 = Grid[x][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x][y + 1] = piece;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x][y + 1] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x][y + 1] = obj1;
						}
					}
					if (y - 1 >= 0)
					{
						obj1 = Grid[x][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x][y - 1] = piece;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x][y - 1] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x][y - 1] = obj1;
						}
					}
					if (x + 1 < 8)
					{
						obj1 = Grid[x + 1][y];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x + 1][y] = piece;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x + 1][y] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x + 1][y] = obj1;
						}
					}
					if (x - 1 >= 0)
					{
						obj1 = Grid[x - 1][y];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x - 1][y] = piece;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x - 1][y] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x - 1][y] = obj1;
						}
					}
				}
			}
		}
	}
	else
	{
		for (int x = 0; x < 8; x++)
		{
			for (int y = 0; y < 8; y++)
			{
				piece = Grid[x][y];
				if (piece == BLACK_PAWN)
				{
					//check normal movement then  finally check if en passant is posible
					if (Grid[x + 1][y] == EMPTY_SQUARE)
					{
						Grid[x][y] = EMPTY_SQUARE;
						Grid[x + 1][y] = piece;
						if (Player_In_Check(Grid, player) == false)
						{
							Grid[x + 1][y] = EMPTY_SQUARE;
							Grid[x][y] = piece;
							return false;
						}
						Grid[x + 1][y] = EMPTY_SQUARE;
						Grid[x][y] = piece;
					}
					//check capture right + en passant right
					if (y + 1 < 8)
					{
						obj1 = Grid[x + 1][y + 1];
						if (obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x + 1][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x + 1][y + 1] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x + 1][y + 1] = obj1;
						}
						//check en passant
						if (obj1 == EMPTY_SQUARE && x == 4 && (Grid[x][y + 1] == WHITE_PAWN && WHITE_EN_PASSANT == y + 1))
						{
							aux = Grid[x][y + 1];
							Grid[x + 1][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x][y + 1] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y + 1] = EMPTY_SQUARE;
								Grid[x][y] = piece;
								Grid[x][y + 1] = aux;
								return false;
							}
							Grid[x + 1][y + 1] = EMPTY_SQUARE;
							Grid[x][y] = piece;
							Grid[x][y + 1] = aux;
						}
					}
					//check capture left + en passant left
					if (y - 1 > 0)
					{
						obj2 = Grid[x + 1][y - 1];
						if (obj2 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x + 1][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x + 1][y - 1] = obj2;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x + 1][y - 1] = obj2;
						}
						//check en passant
						if (obj2 == EMPTY_SQUARE && x == 4 && (Grid[x][y - 1] == WHITE_PAWN && WHITE_EN_PASSANT == y - 1))
						{
							aux = Grid[x][y - 1];
							Grid[x + 1][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x][y - 1] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y - 1] = EMPTY_SQUARE;
								Grid[x][y] = piece;
								Grid[x][y - 1] = aux;
								return false;
							}
							Grid[x + 1][y - 1] = EMPTY_SQUARE;
							Grid[x][y] = piece;
							Grid[x][y - 1] = aux;
						}
					}
				}
				if (piece == BLACK_HORSE)
				{
					if (x + 2 < 8 && y + 1 < 8)
					{
						obj1 = Grid[x + 2][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x + 2][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 2][y + 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 2][y + 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x + 2 < 8 && y - 1 >= 0)
					{
						obj1 = Grid[x + 2][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x + 2][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 2][y - 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 2][y - 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 2 >= 0 && y + 1 < 8)
					{
						obj1 = Grid[x - 2][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x - 2][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 2][y + 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 2][y + 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 2 >= 0 && y - 1 >= 0)
					{
						obj1 = Grid[x - 2][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x - 2][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 2][y - 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 2][y - 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x + 1 < 8 && y + 2 < 8)
					{
						obj1 = Grid[x + 1][y + 2];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x + 1][y + 2] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y + 2] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 1][y + 2] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x + 1 < 8 && y - 2 >= 0)
					{
						obj1 = Grid[x + 1][y - 2];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x + 1][y - 2] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y - 2] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 1][y - 2] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 1 >= 0 && y + 2 < 8)
					{
						obj1 = Grid[x - 1][y + 2];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x - 1][y + 2] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y + 2] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 1][y + 2] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 1 >= 0 && y - 2 >= 0)
					{
						obj1 = Grid[x - 1][y - 2];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x - 1][y - 2] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y - 2] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 1][y - 2] = obj1;
							Grid[x][y] = piece;
						}
					}
				}
				if (piece == BLACK_BISHOP || piece == BLACK_QUEEN || piece == BLACK_KING)
				{
					//Check one square diagonal distance if any of these is allowed stop looking
					if (x + 1 < 8 && y + 1 < 8)
					{
						obj1 = Grid[x + 1][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x + 1][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y + 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 1][y + 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x + 1 < 8 && y - 1 >= 0)
					{
						obj1 = Grid[x + 1][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x + 1][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y - 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 1][y - 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 1 >= 0 && y + 1 < 8)
					{
						obj1 = Grid[x - 1][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x - 1][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y + 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 1][y + 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 1 >= 0 && y - 1 >= 0)
					{
						obj1 = Grid[x - 1][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x - 1][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y - 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 1][y - 1] = obj1;
							Grid[x][y] = piece;
						}
					}
				}
				if (piece == BLACK_ROOK || piece == BLACK_QUEEN || piece == BLACK_KING)
				{
					//Check one square distance both vertically and horizontally if the move is allowed stop looking
					if (y + 1 < 8)
					{
						obj1 = Grid[x][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x][y + 1] = piece;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x][y + 1] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x][y + 1] = obj1;
						}
					}
					if (y - 1 >= 0)
					{
						obj1 = Grid[x][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x][y - 1] = piece;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x][y - 1] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x][y - 1] = obj1;
						}
					}
					if (x + 1 < 8)
					{
						obj1 = Grid[x + 1][y];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x + 1][y] = piece;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x + 1][y] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x + 1][y] = obj1;
						}
					}
					if (x - 1 >= 0)
					{
						obj1 = Grid[x - 1][y];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x - 1][y] = piece;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x - 1][y] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x - 1][y] = obj1;
						}
					}
				}
			}
		}
	}
	return true;
}