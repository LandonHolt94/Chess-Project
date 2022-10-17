#pragma once
bool Check_Win(char Grid[][8], char player)
{
	if (Player_In_Check(Grid, player) == true)
	{
		if (player == BLACK_PLAYER) std::cout << "White player (UPERCASE/ALL CAPS) is in CHECK! " << std::endl;
		else std::cout << "Black player (LOWER CASE) is in CHECK! " << std::endl;

		//Anlaisis Checkmate
		//look all king moves and all the other pieces moves to see if they can cover the check
		int x, y, s, t;
		char pos, prev;
		if (player == WHITE_PLAYER)
		{
			//First locate the king
			for (x = 0; x < 8; x++)
				for (y = 0; y < 8; y++)
					if (Grid[x][y] == BLACK_KING)
						goto found;
		found:
			//Check King moves
			if (x + 1 < 8)
			{
				pos = Grid[x + 1][y];
				if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN)
				{
					Grid[x + 1][y] = BLACK_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x + 1][y] = pos;
						Grid[x][y] = BLACK_KING;
						return false;
					}
					Grid[x + 1][y] = pos;
					Grid[x][y] = BLACK_KING;
				}
			}
			if (x + 1 < 8 && y - 1 >= 0)
			{
				pos = Grid[x + 1][y - 1];
				if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN)
				{
					Grid[x + 1][y - 1] = BLACK_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x + 1][y - 1] = pos;
						Grid[x][y] = BLACK_KING;
						return false;
					}
					Grid[x + 1][y - 1] = pos;
					Grid[x][y] = BLACK_KING;
				}
			}
			if (x + 1 < 8 && y + 1 < 8)
			{
				pos = Grid[x + 1][y + 1];
				if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN)
				{
					Grid[x + 1][y + 1] = BLACK_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x + 1][y + 1] = pos;
						Grid[x][y] = BLACK_KING;
						return false;
					}
					Grid[x + 1][y + 1] = pos;
					Grid[x][y] = BLACK_KING;
				}
			}
			if (y + 1 < 8)
			{
				pos = Grid[x][y + 1];
				if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN)
				{
					Grid[x][y + 1] = BLACK_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x][y + 1] = pos;
						Grid[x][y] = BLACK_KING;
						return false;
					}
					Grid[x][y + 1] = pos;
					Grid[x][y] = BLACK_KING;
				}
			}
			if (y - 1 >= 0)
			{
				pos = Grid[x][y - 1];
				if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN)
				{
					Grid[x][y - 1] = BLACK_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x][y - 1] = pos;
						Grid[x][y] = BLACK_KING;
						return false;
					}
					Grid[x][y - 1] = pos;
					Grid[x][y] = BLACK_KING;
				}
			}
			if (x - 1 >= 0)
			{
				pos = Grid[x - 1][y];
				if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN)
				{
					Grid[x - 1][y] = BLACK_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x - 1][y] = pos;
						Grid[x][y] = BLACK_KING;
						return false;
					}
					Grid[x - 1][y] = pos;
					Grid[x][y] = BLACK_KING;
				}
			}
			if (x - 1 >= 0 && y - 1 >= 0)
			{
				pos = Grid[x - 1][y - 1];
				if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN)
				{
					Grid[x - 1][y - 1] = BLACK_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x - 1][y - 1] = pos;
						Grid[x][y] = BLACK_KING;
						return false;
					}
					Grid[x - 1][y - 1] = pos;
					Grid[x][y] = BLACK_KING;
				}
			}
			if (x - 1 >= 0 && y + 1 < 8)
			{
				pos = Grid[x - 1][y + 1];
				if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN)
				{
					Grid[x - 1][y + 1] = BLACK_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x - 1][y + 1] = pos;
						Grid[x][y] = BLACK_KING;
						return false;
					}
					Grid[x - 1][y + 1] = pos;
					Grid[x][y] = BLACK_KING;
				}
			}
			//Check the movement of the other pieces
			for (int j = 0; j < 8; j++)
			{
				for (int q = 0; q < 8; q++)
				{
					if (Grid[j][q] != EMPTY_SQUARE)
					{
						if (Grid[j][q] == BLACK_PAWN)
						{
							//Forward Pawn Move (havent checked if double starting move works)
							if (j + 1 < 8 && Grid[j + 1][q] == EMPTY_SQUARE)
							{
								Grid[j + 1][q] = BLACK_PAWN;
								Grid[j][q] = EMPTY_SQUARE;
								if (Player_In_Check(Grid, player) == false)
								{
									Grid[j + 1][q] = EMPTY_SQUARE;
									Grid[j][q] = BLACK_PAWN;
									return false;
								}
								Grid[j + 1][q] = EMPTY_SQUARE;
								Grid[j][q] = BLACK_PAWN;
							}
							//Capture left
							if (j + 1 < 8 && q - 1 >= 0)
							{
								pos = Grid[j + 1][q - 1];
								if (pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN)
								{
									Grid[j + 1][q - 1] = BLACK_PAWN;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 1][q - 1] = pos;
										Grid[j][q] = BLACK_PAWN;
										return false;
									}
									Grid[j + 1][q - 1] = pos;
									Grid[j][q] = BLACK_PAWN;
								}
							}
							//Capture right
							if (j + 1 < 8 && q + 1 < 8)
							{
								pos = Grid[j + 1][q + 1];
								if (pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN)
								{
									Grid[j + 1][q + 1] = BLACK_PAWN;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 1][q + 1] = pos;
										Grid[j][q] = BLACK_PAWN;
										return false;
									}
									Grid[j + 1][q + 1] = pos;
									Grid[j][q] = BLACK_PAWN;
								}
							}

						}
						else if (Grid[j][q] == BLACK_HORSE)
						{
							if (j + 2 < 8 && q + 1 < 8)
							{
								pos = Grid[j + 2][q + 1];
								if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN && pos != BLACK_KING)
								{
									Grid[j + 2][q + 1] = BLACK_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 2][q + 1] = pos;
										Grid[j][q] = BLACK_HORSE;
										return false;
									}
									Grid[j + 2][q + 1] = pos;
									Grid[j][q] = BLACK_HORSE;
								}
							}
							if (j + 2 < 8 && q - 1 >= 0)
							{
								pos = Grid[j + 2][q - 1];
								if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN && pos != BLACK_KING)
								{
									Grid[j + 2][q - 1] = BLACK_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 2][q - 1] = pos;
										Grid[j][q] = BLACK_PAWN;
										return false;
									}
									Grid[j + 2][q - 1] = pos;
									Grid[j][q] = BLACK_PAWN;
								}
							}
							if (j - 2 >= 0 && q + 1 < 8)
							{
								pos = Grid[j - 2][q + 1];
								if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN && pos != BLACK_KING)
								{
									Grid[j - 2][q + 1] = BLACK_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j - 2][q + 1] = pos;
										Grid[j][q] = BLACK_HORSE;
										return false;
									}
									Grid[j - 2][q + 1] = pos;
									Grid[j][q] = BLACK_HORSE;
								}
							}
							if (j - 2 >= 0 && q - 1 >= 0)
							{
								pos = Grid[j - 2][q - 1];
								if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN && pos != BLACK_KING)
								{
									Grid[j - 2][q - 1] = BLACK_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j - 2][q - 1] = pos;
										Grid[j][q] = BLACK_HORSE;
										return false;
									}
									Grid[j - 2][q - 1] = pos;
									Grid[j][q] = BLACK_HORSE;
								}
							}
							if (j + 1 < 8 && q + 2 < 8)
							{
								pos = Grid[j + 1][q + 2];
								if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN && pos != BLACK_KING)
								{
									Grid[j + 1][q + 2] = BLACK_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 1][q + 2] = pos;
										Grid[j][q] = BLACK_HORSE;
										return false;
									}
									Grid[j + 1][q + 2] = pos;
									Grid[j][q] = BLACK_HORSE;
								}
							}
							if (j + 1 < 8 && q - 2 >= 0)
							{
								pos = Grid[j + 1][q - 2];
								if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN && pos != BLACK_KING)
								{
									Grid[j + 1][q - 2] = BLACK_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 1][q - 2] = pos;
										Grid[j][q] = BLACK_HORSE;
										return false;
									}
									Grid[j + 1][q - 2] = pos;
									Grid[j][q] = BLACK_HORSE;
								}
							}
							if (j - 1 >= 0 && q + 2 < 8)
							{
								pos = Grid[j - 1][q + 2];
								if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN && pos != BLACK_KING)
								{
									Grid[j - 1][q + 2] = BLACK_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j - 1][q + 2] = pos;
										Grid[j][q] = BLACK_HORSE;
										return false;
									}
									Grid[j - 1][q + 2] = pos;
									Grid[j][q] = BLACK_HORSE;
								}
							}
							if (j - 1 >= 0 && q - 2 >= 0)
							{
								pos = Grid[j - 1][q - 2];
								if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN && pos != BLACK_KING)
								{
									Grid[j - 1][q - 2] = BLACK_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j - 1][q - 2] = pos;
										Grid[j][q] = BLACK_HORSE;
										return false;
									}
									Grid[j - 1][q - 2] = pos;
									Grid[j][q] = BLACK_HORSE;
								}
							}
						}
						else if (Grid[j][q] == BLACK_BISHOP || Grid[j][q] == BLACK_QUEEN)
						{
							//Look on all directions
							//Search TOP Left x-- y--
							s = q - 1;
							t = j - 1;
							if (t >= 0 && s >= 0)
							{
								while (t >= 0 && s >= 0)
								{
									pos = Grid[t][s];
									prev = Grid[j][q];
									if (pos != EMPTY_SQUARE && ((abs(t - x) != abs(s - y)) && x != t && y != s))
										break;
									else if ((pos == EMPTY_SQUARE || pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN) && ((abs(t - x) == abs(s - y)) || x == t || y == s))
									{
										Grid[t][s] = Grid[j][q];
										Grid[j][q] = EMPTY_SQUARE;
										if (Player_In_Check(Grid, player) == false)
										{
											Grid[t][s] = pos;
											Grid[j][q] = prev;
											return false;
										}
										Grid[t][s] = pos;
										Grid[j][q] = prev;
									}
									s--;
									t--;
								}
							}
							//Search BOTTOM Right x++ y++
							s = q + 1;
							t = j + 1;
							if (t < 8 && s < 8)
							{
								while (t < 8 && s < 8)
								{
									pos = Grid[t][s];
									prev = Grid[j][q];
									if (pos != EMPTY_SQUARE && ((abs(t - x) != abs(s - y)) || x == t || y == s))
										break;
									else if ((pos == EMPTY_SQUARE || pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN) && ((abs(t - x) == abs(s - y)) || x == t || y == s))
									{
										Grid[t][s] = Grid[j][q];
										Grid[j][q] = EMPTY_SQUARE;
										if (Player_In_Check(Grid, player) == false)
										{
											Grid[t][s] = pos;
											Grid[j][q] = prev;
											return false;
										}
										Grid[t][s] = pos;
										Grid[j][q] = prev;
									}
									else break;
									s++;
									t++;
								}
							}
							//Search BOTTOM Left x++ y--
							s = q - 1;
							t = j + 1;
							if (s >= 0 && t < 8)
							{
								while (s >= 0 && t < 8)
								{
									pos = Grid[t][s];
									prev = Grid[j][q];
									if (pos != EMPTY_SQUARE && ((abs(t - x) != abs(s - y)) || x == t || y == s))
										break;
									else if ((pos == EMPTY_SQUARE || pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN) && ((abs(t - x) == abs(s - y)) || x == t || y == s))
									{
										Grid[t][s] = Grid[j][q];
										Grid[j][q] = EMPTY_SQUARE;
										if (Player_In_Check(Grid, player) == false)
										{
											Grid[t][s] = pos;
											Grid[j][q] = prev;
											return false;
										}
										Grid[t][s] = pos;
										Grid[j][q] = prev;
									}
									else break;
									s--;
									t++;
								}
							}
							//Search top Right x-- y++
							s = q + 1;
							t = j - 1;
							if (s < 8 && t >= 0)
							{
								while (s < 8 && t >= 0)
								{
									pos = Grid[t][s];
									prev = Grid[j][q];
									if (pos != EMPTY_SQUARE && ((abs(t - x) != abs(s - y)) || x == t || y == s))
										break;
									else if ((pos == EMPTY_SQUARE || pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN) && ((abs(t - x) == abs(s - y)) || x == t || y == s))
									{
										Grid[t][s] = Grid[j][q];
										Grid[j][q] = EMPTY_SQUARE;
										if (Player_In_Check(Grid, player) == false)
										{
											Grid[t][s] = pos;
											Grid[j][q] = prev;
											return false;
										}
										Grid[t][s] = pos;
										Grid[j][q] = prev;
									}
									else break;
									s++;
									t--;
								}
							}
						}
						if (Grid[j][q] == BLACK_ROOK || Grid[j][q] == BLACK_QUEEN)
						{
							//Look Right
							for (int t = q + 1; t < 8; t++)
							{
								pos = Grid[j][t];
								prev = Grid[j][q];
								if (pos != EMPTY_SQUARE && ((abs(j - x) != abs(t - y)) || x == j || y == t))
									break;
								else if ((pos == EMPTY_SQUARE || pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN) && ((abs(j - x) != abs(t - y)) || x == j || y == t))
								{
									Grid[j][t] = Grid[j][q];
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j][t] = pos;
										Grid[j][q] = prev;
										return false;
									}
									Grid[j][t] = pos;
									Grid[j][q] = prev;
								}
								else break;
							}
							//Look Left
							for (int t = q - 1; t >= 0; t--)
							{
								pos = Grid[j][t];
								prev = Grid[j][q];
								if (pos != EMPTY_SQUARE && ((abs(j - x) != abs(t - y)) || x == j || y == t))
									break;
								else if ((pos == EMPTY_SQUARE || pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN) && ((abs(j - x) != abs(t - y)) || x == j || y == t))
								{
									Grid[j][t] = Grid[j][q];
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j][t] = pos;
										Grid[j][q] = prev;
										return false;
									}
									Grid[j][t] = pos;
									Grid[j][q] = prev;
								}
								else break;
							}
							//Look Up
							for (int t = j + 1; t < 8; t++)
							{
								pos = Grid[t][q];
								prev = Grid[j][q];
								if (pos != EMPTY_SQUARE && ((abs(j - x) != abs(t - y)) || x == t || y == q))
									break;
								else if ((pos == EMPTY_SQUARE || pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN) && ((abs(j - x) != abs(t - y)) || x == t || y == q))
								{
									Grid[t][q] = Grid[j][q];
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[t][q] = pos;
										Grid[j][q] = prev;
										return false;
									}
									Grid[t][q] = pos;
									Grid[j][q] = prev;
								}
								else break;
							}
							//Look Down
							for (int t = j - 1; t >= 0; t--)
							{
								pos = Grid[t][q];
								prev = Grid[j][q];
								if (pos != EMPTY_SQUARE && ((abs(j - x) != abs(t - y)) || x == t || y == q))
									break;
								else if ((pos == EMPTY_SQUARE || pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN) && ((abs(j - x) != abs(t - y)) || x == t || y == q))
								{
									Grid[t][q] = Grid[j][q];
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[t][q] = pos;
										Grid[j][q] = prev;
										return false;
									}
									Grid[t][q] = pos;
									Grid[j][q] = prev;
								}
								else break;
							}
						}
					}
				}
			}
		}
		else if (player == BLACK_PLAYER)
		{
			for (x = 7; x >= 0; x--)
				for (y = 0; y < 8; y++)
					if (Grid[x][y] == WHITE_KING)
						goto found2;
		found2:
			//Check King moves
			if (x + 1 < 8)
			{
				pos = Grid[x + 1][y];
				if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN)
				{
					Grid[x + 1][y] = WHITE_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x + 1][y] = pos;
						Grid[x][y] = WHITE_KING;
						return false;
					}
					Grid[x + 1][y] = pos;
					Grid[x][y] = WHITE_KING;
				}
			}
			if (x + 1 < 8 && y - 1 >= 0)
			{
				pos = Grid[x + 1][y - 1];
				if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN)
				{
					Grid[x + 1][y - 1] = WHITE_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x + 1][y - 1] = pos;
						Grid[x][y] = WHITE_KING;
						return false;
					}
					Grid[x + 1][y - 1] = pos;
					Grid[x][y] = WHITE_KING;
				}
			}
			if (x + 1 < 8 && y + 1 < 8)
			{
				pos = Grid[x + 1][y + 1];
				if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN)
				{
					Grid[x + 1][y + 1] = WHITE_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x + 1][y + 1] = pos;
						Grid[x][y] = WHITE_KING;
						return false;
					}
					Grid[x + 1][y + 1] = pos;
					Grid[x][y] = WHITE_KING;
				}
			}
			if (y + 1 < 8)
			{
				pos = Grid[x][y + 1];
				if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN)
				{
					Grid[x][y + 1] = WHITE_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x][y + 1] = pos;
						Grid[x][y] = WHITE_KING;
						return false;
					}
					Grid[x][y + 1] = pos;
					Grid[x][y] = WHITE_KING;
				}
			}
			if (y - 1 >= 0)
			{
				pos = Grid[x][y - 1];
				if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN)
				{
					Grid[x][y - 1] = WHITE_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x][y - 1] = pos;
						Grid[x][y] = WHITE_KING;
						return false;
					}
					Grid[x][y - 1] = pos;
					Grid[x][y] = WHITE_KING;
				}
			}
			if (x - 1 >= 0)
			{
				pos = Grid[x - 1][y];
				if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN)
				{
					Grid[x - 1][y] = WHITE_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x - 1][y] = pos;
						Grid[x][y] = WHITE_KING;
						return false;
					}
					Grid[x - 1][y] = pos;
					Grid[x][y] = WHITE_KING;
				}
			}
			if (x - 1 >= 0 && y - 1 >= 0)
			{
				pos = Grid[x - 1][y - 1];
				if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN)
				{
					Grid[x - 1][y - 1] = WHITE_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x - 1][y - 1] = pos;
						Grid[x][y] = WHITE_KING;
						return false;
					}
					Grid[x - 1][y - 1] = pos;
					Grid[x][y] = WHITE_KING;
				}
			}
			if (x - 1 >= 0 && y + 1 < 8)
			{
				pos = Grid[x - 1][y + 1];
				if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN)
				{
					Grid[x - 1][y + 1] = WHITE_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x - 1][y + 1] = pos;
						Grid[x][y] = WHITE_KING;
						return false;
					}
					Grid[x - 1][y + 1] = pos;
					Grid[x][y] = WHITE_KING;
				}
			}
			//Check the movement of the other pieces
			for (int j = 0; j < 8; j++)
			{
				for (int q = 0; q < 8; q++)
				{
					if (Grid[j][q] != EMPTY_SQUARE)
					{
						if (Grid[j][q] == WHITE_PAWN)
						{
							//Forward Pawn Move (haven t checked if double starting move works)
							if (j + 1 < 8 && Grid[j + 1][q] == EMPTY_SQUARE)
							{
								Grid[j + 1][q] = WHITE_PAWN;
								Grid[j][q] = EMPTY_SQUARE;
								if (Player_In_Check(Grid, player) == false)
								{
									Grid[j + 1][q] = EMPTY_SQUARE;
									Grid[j][q] = WHITE_PAWN;
									return false;
								}
								Grid[j + 1][q] = EMPTY_SQUARE;
								Grid[j][q] = WHITE_PAWN;
							}
							//Capture left
							if (j + 1 < 8 && q - 1 >= 0)
							{
								pos = Grid[j + 1][q - 1];
								if (pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN)
								{
									Grid[j + 1][q - 1] = WHITE_PAWN;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 1][q - 1] = pos;
										Grid[j][q] = WHITE_PAWN;
										return false;
									}
									Grid[j + 1][q - 1] = pos;
									Grid[j][q] = WHITE_PAWN;
								}
							}
							//Capture right
							if (j + 1 < 8 && q + 1 < 8)
							{
								pos = Grid[j + 1][q + 1];
								if (pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN)
								{
									Grid[j + 1][q + 1] = WHITE_PAWN;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 1][q + 1] = pos;
										Grid[j][q] = WHITE_PAWN;
										return false;
									}
									Grid[j + 1][q + 1] = pos;
									Grid[j][q] = WHITE_PAWN;
								}
							}
						}
						else if (Grid[j][q] == WHITE_HORSE)
						{
							if (j + 2 < 8 && q + 1 < 8)
							{
								pos = Grid[j + 2][q + 1];
								if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN && pos != WHITE_KING)
								{
									Grid[j + 2][q + 1] = WHITE_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 2][q + 1] = pos;
										Grid[j][q] = WHITE_HORSE;
										return false;
									}
									Grid[j + 2][q + 1] = pos;
									Grid[j][q] = WHITE_HORSE;
								}
							}
							if (j + 2 < 8 && q - 1 >= 0)
							{
								pos = Grid[j + 2][q - 1];
								if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN && pos != WHITE_KING)
								{
									Grid[j + 2][q - 1] = WHITE_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 2][q - 1] = pos;
										Grid[j][q] = WHITE_PAWN;
										return false;
									}
									Grid[j + 2][q - 1] = pos;
									Grid[j][q] = WHITE_PAWN;
								}
							}
							if (j - 2 >= 0 && q + 1 < 8)
							{
								pos = Grid[j - 2][q + 1];
								if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN && pos != WHITE_KING)
								{
									Grid[j - 2][q + 1] = WHITE_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j - 2][q + 1] = pos;
										Grid[j][q] = WHITE_HORSE;
										return false;
									}
									Grid[j - 2][q + 1] = pos;
									Grid[j][q] = WHITE_HORSE;
								}
							}
							if (j - 2 >= 0 && q - 1 >= 0)
							{
								pos = Grid[j - 2][q - 1];
								if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN && pos != WHITE_KING)
								{
									Grid[j - 2][q - 1] = WHITE_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j - 2][q - 1] = pos;
										Grid[j][q] = WHITE_HORSE;
										return false;
									}
									Grid[j - 2][q - 1] = pos;
									Grid[j][q] = WHITE_HORSE;
								}
							}
							if (j + 1 < 8 && q + 2 < 8)
							{
								pos = Grid[j + 1][q + 2];
								if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN && pos != WHITE_KING)
								{
									Grid[j + 1][q + 2] = WHITE_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 1][q + 2] = pos;
										Grid[j][q] = WHITE_HORSE;
										return false;
									}
									Grid[j + 1][q + 2] = pos;
									Grid[j][q] = WHITE_HORSE;
								}
							}
							if (j + 1 < 8 && q - 2 >= 0)
							{
								pos = Grid[j + 1][q - 2];
								if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN && pos != WHITE_KING)
								{
									Grid[j + 1][q - 2] = WHITE_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 1][q - 2] = pos;
										Grid[j][q] = WHITE_HORSE;
										return false;
									}
									Grid[j + 1][q - 2] = pos;
									Grid[j][q] = WHITE_HORSE;
								}
							}
							if (j - 1 >= 0 && q + 2 < 8)
							{
								pos = Grid[j - 1][q + 2];
								if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN && pos != WHITE_KING)
								{
									Grid[j - 1][q + 2] = WHITE_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j - 1][q + 2] = pos;
										Grid[j][q] = WHITE_HORSE;
										return false;
									}
									Grid[j - 1][q + 2] = pos;
									Grid[j][q] = WHITE_HORSE;
								}
							}
							if (j - 1 >= 0 && q - 2 >= 0)
							{
								pos = Grid[j - 1][q - 2];
								if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN && pos != WHITE_KING)
								{
									Grid[j - 1][q - 2] = WHITE_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j - 1][q - 2] = pos;
										Grid[j][q] = WHITE_HORSE;
										return false;
									}
									Grid[j - 1][q - 2] = pos;
									Grid[j][q] = WHITE_HORSE;
								}
							}
						}
						else if (Grid[j][q] == WHITE_BISHOP || Grid[j][q] == WHITE_QUEEN)
						{
							//Look on all directions
							//Search TOP Left x-- y--
							s = q - 1;
							t = j - 1;
							if (t >= 0 && s >= 0)
							{
								while (t >= 0 && s >= 0)
								{
									pos = Grid[t][s];
									prev = Grid[j][q];
									if (pos != EMPTY_SQUARE && ((abs(t - x) != abs(s - y)) && x != t && y != s))
										break;
									else if ((pos == EMPTY_SQUARE || pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN) && ((abs(t - x) == abs(s - y)) || x == t || y == s))
									{
										Grid[t][s] = Grid[j][q];
										Grid[j][q] = EMPTY_SQUARE;
										if (Player_In_Check(Grid, player) == false)
										{
											Grid[t][s] = pos;
											Grid[j][q] = prev;
											return false;
										}
										Grid[t][s] = pos;
										Grid[j][q] = prev;
									}
									else break;
									s--;
									t--;
								}
							}
							//Search BOTTOM Right x++ y++
							s = q + 1;
							t = j + 1;
							if (t < 8 && s < 8)
							{
								while (t < 8 && s < 8)
								{
									pos = Grid[t][s];
									prev = Grid[j][q];
									if (pos != EMPTY_SQUARE && ((abs(t - x) != abs(s - y)) || x == t || y == s))
										break;
									else if ((pos == EMPTY_SQUARE || pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN) && ((abs(t - x) == abs(s - y)) || x == t || y == s))
									{
										Grid[t][s] = Grid[j][q];
										Grid[j][q] = EMPTY_SQUARE;
										if (Player_In_Check(Grid, player) == false)
										{
											Grid[t][s] = pos;
											Grid[j][q] = prev;
											return false;
										}
										Grid[t][s] = pos;
										Grid[j][q] = prev;
									}
									else break;
									s++;
									t++;
								}
							}
							//Search BOTTOM Left x++ y--
							s = q - 1;
							t = j + 1;
							if (s >= 0 && t < 8)
							{
								while (s >= 0 && t < 8)
								{
									pos = Grid[t][s];
									prev = Grid[j][q];
									if (pos != EMPTY_SQUARE && ((abs(t - x) != abs(s - y)) || x == t || y == s))
										break;
									else if ((pos == EMPTY_SQUARE || pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN) && ((abs(t - x) == abs(s - y)) || x == t || y == s))
									{
										Grid[t][s] = Grid[j][q];
										Grid[j][q] = EMPTY_SQUARE;
										if (Player_In_Check(Grid, player) == false)
										{
											Grid[t][s] = pos;
											Grid[j][q] = prev;
											return false;
										}
										Grid[t][s] = pos;
										Grid[j][q] = prev;
									}
									else break;
									s--;
									t++;
								}
							}
							//Search top Right x-- y++
							s = q + 1;
							t = j - 1;
							if (s < 8 && t >= 0)
							{
								while (s < 8 && t >= 0)
								{
									pos = Grid[t][s];
									prev = Grid[j][q];
									if (pos != EMPTY_SQUARE && ((abs(t - x) != abs(s - y)) || x == t || y == s))
										break;
									else if ((pos == EMPTY_SQUARE || pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN) && ((abs(t - x) == abs(s - y)) || x == t || y == s))
									{
										Grid[t][s] = Grid[j][q];
										Grid[j][q] = EMPTY_SQUARE;
										if (Player_In_Check(Grid, player) == false)
										{
											Grid[t][s] = pos;
											Grid[j][q] = prev;
											return false;
										}
										Grid[t][s] = pos;
										Grid[j][q] = prev;
									}
									else break;
									s++;
									t--;
								}
							}
						}
						if (Grid[j][q] == WHITE_ROOK || Grid[j][q] == WHITE_QUEEN)
						{
							//Look Right
							for (int t = q + 1; t < 8; t++)
							{
								pos = Grid[j][t];
								prev = Grid[j][q];
								if (pos != EMPTY_SQUARE && ((abs(j - x) != abs(t - y)) || x == j || y == t))
									break;
								else if ((pos == EMPTY_SQUARE || pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN) && ((abs(j - x) != abs(t - y)) || x == j || y == t))
								{
									Grid[j][t] = Grid[j][q];
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j][t] = pos;
										Grid[j][q] = prev;
										return false;
									}
									Grid[j][t] = pos;
									Grid[j][q] = prev;
								}
								else break;
							}
							//Look Left
							for (int t = q - 1; t >= 0; t--)
							{
								pos = Grid[j][t];
								prev = Grid[j][q];
								if (pos != EMPTY_SQUARE && ((abs(j - x) != abs(t - y)) || x == j || y == t))
									break;
								else if ((pos == EMPTY_SQUARE || pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN) && ((abs(j - x) != abs(t - y)) || x == j || y == t))
								{
									Grid[j][t] = Grid[j][q];
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j][t] = pos;
										Grid[j][q] = prev;
										return false;
									}
									Grid[j][t] = pos;
									Grid[j][q] = prev;
								}
								else break;
							}
							//Look Up
							for (int t = j + 1; t < 8; t++)
							{
								pos = Grid[t][q];
								prev = Grid[j][q];
								if (pos != EMPTY_SQUARE && ((abs(j - x) != abs(t - y)) || x == t || y == q))
									break;
								else if ((pos == EMPTY_SQUARE || pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN) && ((abs(j - x) != abs(t - y)) || x == t || y == q))
								{
									Grid[t][q] = Grid[j][q];
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[t][q] = pos;
										Grid[j][q] = prev;
										return false;
									}
									Grid[t][q] = pos;
									Grid[j][q] = prev;
								}
								else break;
							}
							//Look Down
							for (int t = j - 1; t >= 0; t--)
							{
								pos = Grid[t][q];
								prev = Grid[j][q];
								if (pos != EMPTY_SQUARE && ((abs(j - x) != abs(t - y)) || x == t || y == q))
									break;
								else if ((pos == EMPTY_SQUARE || pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN) && ((abs(j - x) != abs(t - y)) || x == t || y == q))
								{
									Grid[t][q] = Grid[j][q];
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[t][q] = pos;
										Grid[j][q] = prev;
										return false;
									}
									Grid[t][q] = pos;
									Grid[j][q] = prev;
								}
								else break;
							}
						}
					}
				}
			}
		}
		return true;
	}
	return false;
}