#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
class Button
{

	//Accessible from outside of the class.
public:

	Button(int x, int y, SDL_Renderer* renderer);
	Button(int x, int y, SDL_Renderer* renderer, char white);

	void Setpiece(char piece);
	char Getpiece();

	void Setposition(int x, int y);
	void Getposition(int* x, int* y);

	SDL_Texture* Getmtexture();
	SDL_Texture* Getstexture();
	SDL_Texture* Getauxtexture();
	void Settexture(SDL_Texture* t);

	void Setselected(bool sel);
	bool Getselected();

	void Setdead();

	SDL_bool collision(SDL_Rect mouse);
	//Draw
	void draw(SDL_Renderer* renderer);
	
	//Cannot be viewed outside of class.
private: 

	bool m_selected;
	char m_piece;
	SDL_Rect m_sRect, m_dRect;
	SDL_Texture* m_T;//main texture
	SDL_Texture* m_Ts;//secondart texture
	SDL_Texture* m_aux;//auxiliar texture
};