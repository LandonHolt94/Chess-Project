#pragma once
bool Player_In_Check(char Grid[][8], char player)
{
	int s, t, x, y;
	if (player == BLACK_PLAYER)
	{
		for (int p = 0; p < 8; p++)
		{
			for (int m = 0; m < 8; m++)
			{
				if (Grid[p][m] == BLACK_BISHOP || Grid[p][m] == BLACK_QUEEN)
				{
					//Look on all directions
					//Search TOP Left x-- y--
					s = m - 1;
					t = p - 1;
					while (t >= 0 && s >= 0)
					{
						if (Grid[t][s] != EMPTY_SQUARE && Grid[t][s] != WHITE_KING)
							break;
						else if (Grid[t][s] == WHITE_KING)
							return true;
						s--;
						t--;
					}
					//Search BOTTOM Right x++ y++
					s = m + 1;
					t = p + 1;
					while (t < 8 && s < 8)
					{
						if (Grid[t][s] != EMPTY_SQUARE && Grid[t][s] != WHITE_KING)
							break;
						else if (Grid[t][s] == WHITE_KING)
							return true;
						s++;
						t++;
					}
					//Search BOTTOM Left x++ y--
					s = m - 1;
					t = p + 1;
					while (s >= 0 && t < 8)
					{
						if (Grid[t][s] != EMPTY_SQUARE && Grid[t][s] != WHITE_KING)
							break;
						else if (Grid[t][s] == WHITE_KING)
							return true;
						s--;
						t++;
					}
					//Search top Right x-- y++
					s = m + 1;
					t = p - 1;
					while (s < 8 && t >= 0)
					{
						if (Grid[t][s] != EMPTY_SQUARE && Grid[t][s] != WHITE_KING)
							break;
						else if (Grid[t][s] == WHITE_KING)
							return true;
						s++;
						t--;
					}
				}
				if (Grid[p][m] == BLACK_ROOK || Grid[p][m] == BLACK_QUEEN)
				{
					//Look Right
					for (int t = m + 1; t < 8; t++)
					{
						if (Grid[p][t] != EMPTY_SQUARE && Grid[p][t] != WHITE_KING)
							break;
						else if (Grid[p][t] == WHITE_KING)
							return true;
					}
					//Look Left
					for (int t = m - 1; t >= 0; t--)
					{
						if (Grid[p][t] != EMPTY_SQUARE && Grid[p][t] != WHITE_KING)
							break;
						else if (Grid[p][t] == WHITE_KING)
							return true;
					}
					//Look Up
					for (int t = p + 1; t < 8; t++)
					{
						if (Grid[t][m] != EMPTY_SQUARE && Grid[t][m] != WHITE_KING)
							break;
						else if (Grid[t][m] == WHITE_KING)
							return true;
					}
					//Look Down
					for (int t = p - 1; t >= 0; t--)
					{
						if (Grid[t][m] != EMPTY_SQUARE && Grid[t][m] != WHITE_KING)
							break;
						else if (Grid[t][m] == WHITE_KING)
							return true;
					}
				}
				if (Grid[p][m] == BLACK_HORSE)
				{
					if (p + 2 < 8 && m + 1 < 8 && Grid[p + 2][m + 1] == WHITE_KING)
						return true;
					if (p + 2 < 8 && m - 1 >= 0 && Grid[p + 2][m - 1] == WHITE_KING)
						return true;
					if (p - 2 >= 0 && m + 1 < 8 && Grid[p - 2][m + 1] == WHITE_KING)
						return true;
					if (p - 2 >= 0 && m - 1 >= 0 && Grid[p - 2][m - 1] == WHITE_KING)
						return true;
					if (p + 1 < 8 && m + 2 < 8 && Grid[p + 1][m + 2] == WHITE_KING)
						return true;
					if (p + 1 < 8 && m - 2 >= 0 && Grid[p + 1][m - 2] == WHITE_KING)
						return true;
					if (p - 1 >= 0 && m + 2 < 8 && Grid[p - 1][m + 2] == WHITE_KING)
						return true;
					if (p - 1 >= 0 && m - 2 >= 0 && Grid[p - 1][m - 2] == WHITE_KING)
						return true;
				}
				else if (Grid[p][m] == BLACK_PAWN)
				{
					if (m + 1 < 8 && p + 1 < 8 && Grid[p + 1][m + 1] == WHITE_KING)
						return true;
					if (m - 1 > 0 && p + 1 < 8 && Grid[p + 1][m - 1] == WHITE_KING)
						return true;
				}
			}
		}
	}
	else if (player == WHITE_PLAYER)
	{
		for (int p = 0; p < 8; p++)
		{
			for (int m = 0; m < 8; m++)
			{
				if (Grid[p][m] == WHITE_BISHOP || Grid[p][m] == WHITE_QUEEN)
				{
					//Look on all directions
					//Search TOP Left x-- y--
					s = m - 1;
					t = p - 1;
					while (t >= 0 && s >= 0)
					{
						if (Grid[t][s] != EMPTY_SQUARE && Grid[t][s] != BLACK_KING)
							break;
						else if (Grid[t][s] == BLACK_KING)
							return true;
						s--;
						t--;
					}
					//Search BOTTOM Right x++ y++
					s = m + 1;
					t = p + 1;
					while (t < 8 && s < 8)
					{
						if (Grid[t][s] != EMPTY_SQUARE && Grid[t][s] != BLACK_KING)
							break;
						else if (Grid[t][s] == BLACK_KING)
							return true;
						s++;
						t++;
					}
					//Search BOTTOM Left x++ y--
					s = m - 1;
					t = p + 1;
					while (s >= 0 && t < 8)
					{
						if (Grid[t][s] != EMPTY_SQUARE && Grid[t][s] != BLACK_KING)
							break;
						else if (Grid[t][s] == BLACK_KING)
							return true;
						s--;
						t++;
					}
					//Search top Right x-- y++
					s = m + 1;
					t = p - 1;
					while (s < 8 && t >= 0)
					{
						if (Grid[t][s] != EMPTY_SQUARE && Grid[t][s] != BLACK_KING)
							break;
						else if (Grid[t][s] == BLACK_KING)
							return true;
						s++;
						t--;
					}
				}
				if (Grid[p][m] == WHITE_ROOK || Grid[p][m] == WHITE_QUEEN)
				{
					//Look Right
					for (int t = m + 1; t < 8; t++)
					{
						if (Grid[p][t] != EMPTY_SQUARE && Grid[p][t] != BLACK_KING)
							break;
						else if (Grid[p][t] == BLACK_KING)
							return true;
					}
					//Look Left
					for (int t = m - 1; t >= 0; t--)
					{
						if (Grid[p][t] != EMPTY_SQUARE && Grid[p][t] != BLACK_KING)
							break;
						else if (Grid[p][t] == BLACK_KING)
							return true;
					}
					//Look Up
					for (int t = p + 1; t < 8; t++)
					{
						if (Grid[t][m] != EMPTY_SQUARE && Grid[t][m] != BLACK_KING)
							break;
						else if (Grid[t][m] == BLACK_KING)
							return true;
					}
					//Look Down
					for (int t = p - 1; t >= 0; t--)
					{
						if (Grid[t][m] != EMPTY_SQUARE && Grid[t][m] != BLACK_KING)
							break;
						else if (Grid[t][m] == BLACK_KING)
							return true;
					}
				}
				if (Grid[p][m] == WHITE_HORSE)
				{
					if (p + 2 < 8 && m + 1 < 8 && Grid[p + 2][m + 1] == BLACK_KING)
						return true;
					if (p + 2 < 8 && m - 1 >= 0 && Grid[p + 2][m - 1] == BLACK_KING)
						return true;
					if (p - 2 >= 0 && m + 1 < 8 && Grid[p - 2][m + 1] == BLACK_KING)
						return true;
					if (p - 2 >= 0 && m - 1 >= 0 && Grid[p - 2][m - 1] == BLACK_KING)
						return true;
					if (p + 1 < 8 && m + 2 < 8 && Grid[p + 1][m + 2] == BLACK_KING)
						return true;
					if (p + 1 < 8 && m - 2 >= 0 && Grid[p + 1][m - 2] == BLACK_KING)
						return true;
					if (p - 1 >= 0 && m + 2 < 8 && Grid[p - 1][m + 2] == BLACK_KING)
						return true;
					if (p - 1 >= 0 && m - 2 >= 0 && Grid[p - 1][m - 2] == BLACK_KING)
						return true;
				}
				else if (Grid[p][m] == WHITE_PAWN)
				{
					if (m + 1 < 8 && p - 1 > 0 && Grid[p - 1][m + 1] == BLACK_KING)
						return true;
					if (m - 1 > 0 && p - 1 > 0 && Grid[p - 1][m - 1] == BLACK_KING)
						return true;
				}
			}
		}
	}
	//Check that both kings are not in direct contact

	//First locate the kings
	for (s = 0; s < 8; s++)
		for (t = 0; t < 8; t++)
			if (Grid[s][t] == BLACK_KING)
				goto fd;
fd:

	for (x = 0; x < 8; x++)
		for (y = 0; y < 8; y++)
			if (Grid[x][y] == WHITE_KING)
				goto fd2;
fd2:
	//Then we check if they are close
	if (abs(x - s) <= 1 && abs(y - t) <= 1)
		return true;
	return false;
}