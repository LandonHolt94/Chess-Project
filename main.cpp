#include <cstdlib>
#include "Button.h"
#include "Constants.h"
#include "CreateGrid.h"
#include "DisplayGrid.h"
#include "CheckStart.h"
#include "PlayerInCheck.h"
#include "CheckAdvanced.h"
#include "CheckEnd.h"
#include "CheckWin.h"

int main(int argc, char* argv[])
{

	char player, Grid[8][8];
	bool win, tie;
	int end;

	win = false;
	tie = false;
	player = WHITE_PLAYER;

	//Creats our grid for the board
	Create_Grid(Grid);
	Display_Grid(Grid);

	SDL_Window* window = nullptr;

	window = SDL_CreateWindow("Chess Game Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = nullptr;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Surface* surface = SDL_LoadBMP("images/board640px.bmp");
	if (surface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "images/board640px.bmp", SDL_GetError());
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	// Create a board
	SDL_Rect board;
	board.x = 0;
	board.y = 0;
	board.w = 640;
	board.h = 640;
	//Mouse
	SDL_Rect mouse;
	mouse.w = 1;
	mouse.h = 1;
	//Create the pieces
	Button* pieces[32];
	//Black pieces local variables
	{
		pieces[0] = new Button(80 * 5, 0, renderer); //Render piece through button function
		pieces[0]->Setpiece('r'); //Shows where the pieces are assigned too. 
		pieces[0]->Setposition(0, 0);

		pieces[7] = new Button(80 * 5, 0, renderer);
		pieces[7]->Setpiece('r');
		pieces[7]->Setposition(80 * 7, 0);

		pieces[1] = new Button(80 * 1, 0, renderer);
		pieces[1]->Setpiece('h');
		pieces[1]->Setposition(80, 0);

		pieces[6] = new Button(80 * 1, 0, renderer);
		pieces[6]->Setpiece('h');
		pieces[6]->Setposition(80 * 6, 0);

		pieces[3] = new Button(0, 0, renderer);
		pieces[3]->Setpiece('b');
		pieces[3]->Setposition(80 * 2, 0);

		pieces[5] = new Button(0, 0, renderer);
		pieces[5]->Setpiece('b');
		pieces[5]->Setposition(80 * 5, 0);

		pieces[4] = new Button(80 * 3, 0, renderer);
		pieces[4]->Setpiece('q');
		pieces[4]->Setposition(80 * 3, 0);

		pieces[2] = new Button(80 * 2, 0, renderer);
		pieces[2]->Setpiece('k');
		pieces[2]->Setposition(80 * 4, 0);
	}
	for (int i = 8; i < 16; i++)
	{
		pieces[i] = new Button(80 * 4, 0, renderer);
		pieces[i]->Setpiece('p');
		pieces[i]->Setposition(80 * (i - 8), 80);
	}
	//White pieces local variables
	{
		pieces[16] = new Button(80 * 5, 0, renderer, 'w');
		pieces[16]->Setpiece('R');
		pieces[16]->Setposition(0, 80 * 7);

		pieces[17] = new Button(80 * 5, 0, renderer, 'w');
		pieces[17]->Setpiece('R');
		pieces[17]->Setposition(80 * 7, 80 * 7);

		pieces[18] = new Button(80 * 1, 0, renderer, 'w');
		pieces[18]->Setpiece('H');
		pieces[18]->Setposition(80, 80 * 7);

		pieces[19] = new Button(80 * 1, 0, renderer, 'w');
		pieces[19]->Setpiece('H');
		pieces[19]->Setposition(80 * 6, 80 * 7);

		pieces[20] = new Button(0, 0, renderer, 'w');
		pieces[20]->Setpiece('B');
		pieces[20]->Setposition(80 * 2, 80 * 7);

		pieces[21] = new Button(0, 0, renderer, 'w');
		pieces[21]->Setpiece('B');
		pieces[21]->Setposition(80 * 5, 80 * 7);

		pieces[22] = new Button(80 * 3, 0, renderer, 'w');
		pieces[22]->Setpiece('Q');
		pieces[22]->Setposition(80 * 3, 80 * 7);

		pieces[23] = new Button(80 * 2, 0, renderer, 'w');
		pieces[23]->Setpiece('K');
		pieces[23]->Setposition(80 * 4, 80 * 7);
	}
	for (int i = 24; i < 32; i++)
	{
		pieces[i] = new Button(80 * 4, 0, renderer, 'w');
		pieces[i]->Setpiece('P');
		pieces[i]->Setposition(80 * (i - 24), 80 * 6);
	}

	// Infinite loop for our application
	bool gameIsRunning = true;
	int pieceSelected = -1;
	bool cont = false;
	bool checkclick = false;
	SDL_Event event;
	int mouseX, mouseY, x, y, First_X, First_Y, posx, posy, i, j;
	char piece;
	//First iteration draw

	//Draw Board
	SDL_RenderCopy(renderer, texture, NULL, &board);
	//Draw pieces
	for (int i = 0; i < 32; i++)
		pieces[i]->draw(renderer);

	// Finally show what we've drawn
	SDL_RenderPresent(renderer);

	// Main application loop
	while (!win && !tie && gameIsRunning)
	{
		SDL_GetMouseState(&mouseX, &mouseY);
		mouse.x = mouseX;
		mouse.y = mouseY;

		cont = false;
		// Event loop
		while (SDL_PollEvent(&event))
		{
			// Handle each event on grid
			if (event.type == SDL_QUIT)
			{
				gameIsRunning = false;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					checkclick = true;
					std::cout << "Left click down" << std::endl;
				}
			}
		}
		if (checkclick == true)
		{
			x = (mouseY / 80) % 10;
			y = (mouseX / 80) % 10;
			if (pieceSelected == -1 && Check_Start(Grid, x, y, player))
			{
				if (player == WHITE_PLAYER)
					std::cout << "---White to move---" << std::endl;
				else std::cout << "---Black to move---" << std::endl;

				std::cout << "Choose the piece you want to move:  " << std::endl;

				for (int i = 0; i < 32; i++)
				{
					if (pieces[i]->collision(mouse) == SDL_TRUE)
					{
						std::cout << "Piece identified:" << pieces[i]->Getpiece() << std::endl;
						SDL_Texture* t = pieces[i]->Getstexture();
						pieces[i]->Settexture(t);
						pieceSelected = i;
						break;
					}
				}
				First_X = x;
				First_Y = y;
			}
			else
			{
				if (First_X == x && First_Y == y)
				{
					SDL_Texture* t = pieces[pieceSelected]->Getauxtexture();
					pieces[pieceSelected]->Settexture(t);
					pieceSelected = -1;
				}
				else if (pieceSelected != -1 && Check_END(Grid, First_X, First_Y, x, y, player, pieces))
				{
					piece = pieces[pieceSelected]->Getpiece();
					posx = mouseX;
					posy = mouseY;
					i = -1;
					j = -1;
					while (posx > 0)
					{
						posx = posx - 80;
						i++;
					}
					while (posy > 0)
					{
						posy = posy - 80;
						j++;
					}
					pieces[pieceSelected]->Setposition(80 * i, 80 * j);
					for (int z = 0; z < 32; z++)
					{
						pieces[z]->Getposition(&posx, &posy);
						if (posx == 80 * i && posy == 80 * j && z != pieceSelected)
							pieces[z]->Setdead();
					}
					SDL_Texture* t = pieces[pieceSelected]->Getauxtexture();
					pieces[pieceSelected]->Settexture(t);
					//Provisional Promotion Change Of Texture
					if (player == WHITE_PLAYER && piece == WHITE_PAWN && (Grid[x][y] == WHITE_BISHOP || Grid[x][y] == WHITE_HORSE || Grid[x][y] == WHITE_ROOK || Grid[x][y] == WHITE_QUEEN))
					{
						int px, py, aux;
						piece = Grid[x][y];
						piece == 'H' ? aux = 1 : (piece == 'Q' ? aux = 3 : (piece == 'R' ? aux = 5 : (piece == 'B' ? aux == 2 : aux = 7)));
						pieces[pieceSelected]->Getposition(&px, &py);
						pieces[pieceSelected] = new Button(80 * aux, 0, renderer, 'w');
						pieces[pieceSelected]->Setpiece(piece);
						pieces[pieceSelected]->Setposition(px, py);
					}
					if (player == BLACK_PLAYER && piece == BLACK_PAWN && (Grid[x][y] == BLACK_BISHOP || Grid[x][y] == BLACK_HORSE || Grid[x][y] == BLACK_ROOK || Grid[x][y] == BLACK_QUEEN))
					{
						int px, py, aux;
						piece = Grid[x][y];
						piece == 'h' ? aux = 1 : (piece == 'q' ? aux = 3 : (piece == 'r' ? aux = 5 : (piece == 'b' ? aux == 2 : aux = 7)));
						pieces[pieceSelected]->Getposition(&px, &py);
						pieces[pieceSelected] = new Button(80 * aux, 0, renderer);
						pieces[pieceSelected]->Setpiece(piece);
						pieces[pieceSelected]->Setposition(px, py);
					}
					Grid[x][y] = pieces[pieceSelected]->Getpiece();
					Grid[First_X][First_Y] = EMPTY_SQUARE;
					Display_Grid(Grid);
					pieceSelected = -1;
					cont = true;
				}
			}
			checkclick = false;
		}
		//Draw Board
		SDL_RenderCopy(renderer, texture, NULL, &board);
		//Draw pieces
		for (int i = 0; i < 32; i++)
			pieces[i]->draw(renderer);

		// Finally show what we've drawn
		SDL_RenderPresent(renderer);

		//Player_Choice(Grid, player);
		//Display_Grid(Grid);
		if (cont == true)
		{
			win = Check_Win(Grid, player);
			player = player % 2 + 1;
		}
	}
	//Checks each piece location to determine if game is "which player has won or if game has been tied.

	Display_Grid(Grid);
	if (gameIsRunning == true)
	{
		if (tie == true)
			std::cout << "Tied Game" << std::endl;
		else
		{
			if (player == WHITE_PLAYER && win == true)
				std::cout << "Black Player has WON! CHECKMATE!" << std::endl;
			else
				std::cout << "White Player has WON! CHECKMATE!" << std::endl;
		}
	}
	system("pause");
	return 0;
}