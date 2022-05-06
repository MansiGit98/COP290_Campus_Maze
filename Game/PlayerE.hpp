#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "ScoreBoardE.hpp"
#include "Constant.hpp"

using namespace std;

class PlayerE
{
public:
	PlayerE(SDL_Renderer *renderer, const char* file, int x, int y);
	~PlayerE();
	void Update(SDL_Renderer *renderer, SDL_Rect* pos);
	void Render(SDL_Renderer *renderer);
	int xpos, ypos;
	SDL_Texture* tex;
	SDL_Rect posRect;
	bool stat[2];
	int X;
	int Y;
	bool color = true;
	bool isOver = false;
	bool isWon = false; 
	ScoreE* score = nullptr;
};

PlayerE::PlayerE(SDL_Renderer *renderer, const char* file, int x, int y)
{
	SDL_Surface* tmpSurface = IMG_Load(file);
	tex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	if( x%10 != 0 || y%10 != 0){
		cerr << "PlayerE's coordinate is wrong" << endl;
		exit(0);
	}
	xpos = x;
	ypos = y;
	X = 0;
	y = 0;
	posRect.h = 20;
	posRect.w = 20;
	score = new ScoreE(renderer);
}

void PlayerE::Update(SDL_Renderer *renderer, SDL_Rect* pos)
{
	posRect.x = xpos;
	posRect.y = ypos;
	//cout << "X - " << xpos << " Y - " << ypos << endl;
	//cout << "XB - " << xPosB << " YB - " << yPosB << endl;
	score->Update(renderer, xpos, ypos); 
	score->BugHandle(xpos, ypos, pos);
	score->Work(xpos, ypos);
	stat[0] = (score->getGoggle && score->getLabCoat && score->getCopy && score->getBook);
	stat[1] = score->getPass;
	if(score->reachGoal || (score->coins <= 0))
	{
		isOver = true;
		if(score->reachGoal) isWon = true;
	}
}

void PlayerE::Render(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, tex, NULL, &posRect);
	score->Render(renderer);
}











