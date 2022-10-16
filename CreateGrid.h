#pragma once

void Create_Grid(char Grid[][8])
{
	//Create Empty Board
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Grid[i][j] = EMPTY_SQUARE;
		}
	}
	//Setup Pieces
	for (int i = 0; i < 8; i++)
	{
		Grid[1][i] = BLACK_PAWN;
		Grid[6][i] = WHITE_PAWN;
	}
	Grid[0][0] = BLACK_ROOK;
	Grid[0][1] = BLACK_HORSE;
	Grid[0][2] = BLACK_BISHOP;
	Grid[0][3] = BLACK_QUEEN;
	Grid[0][4] = BLACK_KING;
	Grid[0][5] = BLACK_BISHOP;
	Grid[0][6] = BLACK_HORSE;
	Grid[0][7] = BLACK_ROOK;

	Grid[7][0] = WHITE_ROOK;
	Grid[7][1] = WHITE_HORSE;
	Grid[7][2] = WHITE_BISHOP;
	Grid[7][3] = WHITE_QUEEN;
	Grid[7][4] = WHITE_KING;
	Grid[7][5] = WHITE_BISHOP;
	Grid[7][6] = WHITE_HORSE;
	Grid[7][7] = WHITE_ROOK;
}