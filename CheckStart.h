#pragma once
//Keeps track oh the starting button clicked.
bool Check_Start(char Grid[][8], char x, char y, char player)
{
	char pos = Grid[x][y];

	//Check piece existence
	if (pos == EMPTY_SQUARE)
	{
		return false;
	}

	//Check if it is your piece
	if (player == WHITE_PLAYER)
	{
		if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_KING && pos != WHITE_QUEEN && pos != WHITE_PAWN)
			return false;
	}
	else
	{
		if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_KING && pos != BLACK_QUEEN && pos != BLACK_PAWN)
			return false;
	}
	//Returns false if the starting position is wrong
	return true;
}