#pragma once
bool Check_END(char Grid[][8], char x, char y, char j, char z, char player, Button* pieces[])
{
	char pos = Grid[j][z];

	//Check if destination is empty
	if (pos == EMPTY_SQUARE)
	{
		return Check_ADVANCED(Grid, x, y, j, z, player, pieces);
	}

	//Check if destination is one of your pieces
	if (player == WHITE_PLAYER)
	{
		if (pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_ROOK || pos == WHITE_KING || pos == WHITE_QUEEN || pos == WHITE_PAWN)
			return false;
	}
	else
	{
		if (pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_ROOK || pos == BLACK_KING || pos == BLACK_QUEEN || pos == BLACK_PAWN)
			return false;
	}
	return Check_ADVANCED(Grid, x, y, j, z, player, pieces);
}
