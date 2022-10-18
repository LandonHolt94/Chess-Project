#pragma once
//using constant Chars to store the memory of each piece on the grid.
//Upper repersents White Pieces
const char WHITE_ROOK = 'R';
const char WHITE_PAWN = 'P';
const char WHITE_HORSE = 'H';
const char WHITE_BISHOP = 'B';
const char WHITE_QUEEN = 'Q';
const char WHITE_KING = 'K';

//lowercase represents black pieces
const char BLACK_ROOK = 'r';
const char BLACK_PAWN = 'p';
const char BLACK_HORSE = 'h';
const char BLACK_BISHOP = 'b';
const char BLACK_QUEEN = 'q';
const char BLACK_KING = 'k';

bool WHITE_CASTLE_LEFT = true;
bool WHITE_CASTLE_RIGHT = true;
bool WHITE_CASTLE_KING = true;

bool BLACK_CASTLE_LEFT = true;
bool BLACK_CASTLE_RIGHT = true;
bool BLACK_CASTLE_KING = true;

char BLACK_EN_PASSANT;
char WHITE_EN_PASSANT;

const char EMPTY_SQUARE = -2;
const char VERTICAL_LINE = -70;
const char HORIZONTAL_LINE = -51;

const char WHITE_PLAYER = 1;
const char BLACK_PLAYER = 2;

//How we can change our window size to fit the board.
const int SCREEN_H = 640;
const int SCREEN_W = 640;

