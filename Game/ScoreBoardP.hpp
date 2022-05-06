#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Sound.hpp"
#include "Constant.hpp"
using namespace std;
class ScoreP
{
public:
	ScoreP(SDL_Renderer *renderer);  // X and Y for offset
	~ScoreP();
	
	void Update(SDL_Renderer *renderer, int x, int y);
	void Render(SDL_Renderer *renderer);
	void BugHandle(int x, int y, SDL_Rect* pos);
	void Work(int x, int y);
	const int xOff = 0; 
	const int yOff = 500;
	SDL_Texture* tex[16];
	SDL_Surface* textSurf;
	TTF_Font* font;
	SDL_Color color1;
	SDL_Color color2;
	SDL_Color color3;
	SDL_Color color4;
	SDL_Rect tRect[7];
	int coins = COINS;
	bool getGoggle = false;
	bool getLabCoat = false;
	bool getCopy = false;
	bool getBook = false;
	bool AttendLab = false; 
	bool getPass = false;
	bool AttendEvent = false;
	bool reachGoal = false;
	void initText(SDL_Renderer *renderer);
	Sound* snd = nullptr;	
	string str;
	bool carry = false;   //work for earn coin
};

ScoreP :: ScoreP(SDL_Renderer *renderer)
{
	font = TTF_OpenFont("Res/F3.ttf", 20);
	color1 = { 3, 219, 252, 225 };
	color2 = { 252, 78, 3, 225 };
	color3 = { 224, 216, 56, 225 };
	color4 = { 28, 3, 252, 225 };
	snd = new Sound();
	initText(renderer);
}

void ScoreP::Update(SDL_Renderer *renderer, int x, int y)
{
	if(!getBook)
	{
		if( x>=700 && x<=780 && y>=320 && y<=340)
		{
			snd->play_task();
			getBook = true;
		}
	}
	if(!getGoggle)
	{
		if( (x==10 || x==20) && y==260) 
		{
			if( coins > 50 )
			{
				coins -= 50;
				snd->play_task();
			  	getGoggle = true;
			}
		}
	}
	if(!getLabCoat)
	{
		if( (x==690 || x==700) && y==50)
		{
			if( coins > 200 )
			{
				coins -= 200;
				snd->play_task();
				getLabCoat = true;
			}	
		}
	}
	if(!getCopy)
	{
		if( x==1100 && (y==180 || y==190) )
		{
			if( coins > 50 )
			{
				coins -= 50;
				snd->play_task();
				getCopy = true;
			}
		}
	}
	if(!AttendLab && getBook && getGoggle && getLabCoat && getCopy)
	{
		if( x>=1050 && x<=1070 && y>=230 && y<=300) 
		{
			snd->play_goal();
			AttendLab = true;
		}
	}
	if(!getPass && AttendLab)
	{
		if( x>=620 && x<=750 && y>=170 && y<=230) 
		{
			snd->play_ntask();
			getPass = true;
		}
	}
	if(!reachGoal && getPass)
	{
		if( x>=490 && x<=510 && y>=390 && y<=400) 
		{
			reachGoal = true;
		}
	}
	
	
	
	str = "COINS - ";
	str.append(to_string(coins)); 
	textSurf = TTF_RenderText_Solid(font, str.c_str(), color3);
	tex[8] = SDL_CreateTextureFromSurface(renderer, textSurf);
	SDL_FreeSurface(textSurf);
	SDL_QueryTexture(tex[8],nullptr,nullptr,&tRect[5].w,&tRect[5].h);
}

void ScoreP::Work(int x, int y)
{
	if(carry)
	{ 
		if( ((x==10 || x==20) && y==440) ||  ((y==40 || y==50 || y==60 ) && x==500)  ){
			snd->play_coinGain();
			coins += COINGAIN;
		       carry = false;
		}
		
	}else{
		if( ((x==10 || x==20) && y==410) ||  ((y==40 || y==50 || y==60 ) && x==420)  ){
			snd->play_work();
		       carry = true;
		}
	}
		
}

void ScoreP::BugHandle(int x, int y, SDL_Rect* pos)
{
	for(int i=0; i < NUM_BUG; ++i)
	{
		if( x > pos[i].x - 20 && x < pos[i].x + 20 && y > pos[i].y - 20 && y < pos[i].y + 20  )  //Condition for collision
		{
			coins -= 10;
			snd->play_BugCollision();
			break;	
		}
	}
}

void ScoreP:: Render(SDL_Renderer *renderer)
{
	
	SDL_RenderCopy(renderer, tex[8], NULL, &tRect[5]);
	SDL_RenderCopy(renderer, tex[15], NULL, &tRect[6]);
	
	if(!AttendLab)
	{
		if(getBook) SDL_RenderCopy(renderer, tex[12], NULL, &tRect[0]);
		else SDL_RenderCopy(renderer, tex[0], NULL, &tRect[0]);
		
		if(getCopy) SDL_RenderCopy(renderer, tex[11], NULL, &tRect[1]);
		else SDL_RenderCopy(renderer, tex[1], NULL, &tRect[1]);
			
		if(getGoggle) SDL_RenderCopy(renderer, tex[10], NULL, &tRect[2]);
		else SDL_RenderCopy(renderer, tex[2], NULL, &tRect[2]);
		
		if(getLabCoat) SDL_RenderCopy(renderer, tex[9], NULL, &tRect[3]);
		else SDL_RenderCopy(renderer, tex[3], NULL, &tRect[3]);
		
		if(getBook && getGoggle && getLabCoat && getCopy)   SDL_RenderCopy(renderer, tex[4], NULL, &tRect[4]);
	}
	else if(!getPass)
	{
		SDL_RenderCopy(renderer, tex[5], NULL, &tRect[4]);
		SDL_RenderCopy(renderer, tex[13], NULL, &tRect[1]);
	}	
	else 
	{
		SDL_RenderCopy(renderer, tex[6], NULL, &tRect[4]);
		SDL_RenderCopy(renderer, tex[14], NULL, &tRect[1]);
	}
	if( coins < 50  || (getLabCoat == false && coins <= 200))
	{
		SDL_RenderCopy(renderer, tex[7], NULL, &tRect[4]);
	}
}

void ScoreP::initText(SDL_Renderer *renderer)
{
	tRect[0].h = tRect[1].h = tRect[2].h = tRect[3].h = tRect[6].h = 20; 
	tRect[0].w = tRect[1].w = tRect[2].w = tRect[3].w = tRect[6].w = 40; 
	tRect[6].x = 20 + xOff;
	tRect[6].y = 10 + yOff;   //For player name
	
	tRect[5].h = 30;
	tRect[5].w = 30;
	tRect[5].x = 100;
	tRect[5].y = 70;   //For coins
	
	tRect[0].x = 20 + xOff;
	tRect[0].y = 50 + yOff;
	textSurf = TTF_RenderText_Solid(font, "Task: Get Book", color2);
	tex[0] = SDL_CreateTextureFromSurface(renderer, textSurf);
	SDL_FreeSurface(textSurf);
	SDL_QueryTexture(tex[0], nullptr, nullptr, &tRect[0].w, &tRect[0].h);
	
	textSurf = TTF_RenderText_Solid(font, "Get Book: Done", color1);   //tex 0 and 12 have 0 as rect
	tex[12] = SDL_CreateTextureFromSurface(renderer, textSurf);
	SDL_FreeSurface(textSurf);
	SDL_QueryTexture(tex[12], nullptr, nullptr, &tRect[0].w, &tRect[0].h);
	
	tRect[1].x = 20 + xOff;
	tRect[1].y = 90 + yOff;
	textSurf = TTF_RenderText_Solid(font, "Task: Buy Copy", color2);
	tex[1] = SDL_CreateTextureFromSurface(renderer, textSurf);
	SDL_FreeSurface(textSurf);
	SDL_QueryTexture(tex[1], nullptr, nullptr, &tRect[1].w, &tRect[1].h);
	
	textSurf = TTF_RenderText_Solid(font, "Buy Copy: Done", color1);
	tex[11] = SDL_CreateTextureFromSurface(renderer, textSurf);
	SDL_FreeSurface(textSurf);
	SDL_QueryTexture(tex[11], nullptr, nullptr, &tRect[1].w, &tRect[1].h);
	
	tRect[2].x = 20 + xOff;
	tRect[2].y = 130 + yOff;
	textSurf = TTF_RenderText_Solid(font, "Task: Buy Goggle", color2);
	tex[2] = SDL_CreateTextureFromSurface(renderer, textSurf);
	SDL_FreeSurface(textSurf);
	SDL_QueryTexture(tex[2], nullptr, nullptr, &tRect[2].w, &tRect[2].h);
	
	textSurf = TTF_RenderText_Solid(font, "Buy Goggle: Done", color1);
	tex[10] = SDL_CreateTextureFromSurface(renderer, textSurf);
	SDL_FreeSurface(textSurf);
	SDL_QueryTexture(tex[10], nullptr, nullptr, &tRect[2].w, &tRect[2].h);
	
	tRect[3].x = 20 + xOff;
	tRect[3].y = 170 + yOff;
	textSurf = TTF_RenderText_Solid(font, "Task: Buy LabCoat", color2);
	tex[3] = SDL_CreateTextureFromSurface(renderer, textSurf);
	SDL_FreeSurface(textSurf);
	SDL_QueryTexture(tex[3], nullptr, nullptr, &tRect[3].w, &tRect[3].h);	
	
	textSurf = TTF_RenderText_Solid(font, "Buy LabCoat: Done", color1);
	tex[9] = SDL_CreateTextureFromSurface(renderer, textSurf);
	SDL_FreeSurface(textSurf);
	SDL_QueryTexture(tex[9], nullptr, nullptr, &tRect[3].w, &tRect[3].h);
	
	textSurf = TTF_RenderText_Solid(font, "Attendence Marked", color1);
	tex[13] = SDL_CreateTextureFromSurface(renderer, textSurf);
	SDL_FreeSurface(textSurf);
	SDL_QueryTexture(tex[13], nullptr, nullptr, &tRect[1].w, &tRect[1].h);
	
	textSurf = TTF_RenderText_Solid(font, "Pass Booked", color1);
	tex[14] = SDL_CreateTextureFromSurface(renderer, textSurf);
	SDL_FreeSurface(textSurf);
	SDL_QueryTexture(tex[14], nullptr, nullptr, &tRect[1].w, &tRect[1].h);
	
	textSurf = TTF_RenderText_Solid(font, "Player", color4);
	tex[15] = SDL_CreateTextureFromSurface(renderer, textSurf);
	SDL_FreeSurface(textSurf);
	SDL_QueryTexture(tex[15], nullptr, nullptr, &tRect[6].w, &tRect[6].h);
	
	tRect[4].x = 500 + xOff;
	tRect[4].y = 20 + yOff;
	tRect[4].w = 200;
	tRect[4].h = 150;
		
	textSurf = IMG_Load("Res/T1.png");
	tex[4] = SDL_CreateTextureFromSurface(renderer, textSurf);
	SDL_FreeSurface(textSurf);
	
	textSurf = IMG_Load("Res/T2.png");
	tex[5] = SDL_CreateTextureFromSurface(renderer, textSurf);
	SDL_FreeSurface(textSurf);
	
	textSurf = IMG_Load("Res/T3.png");
	tex[6] = SDL_CreateTextureFromSurface(renderer, textSurf);
	SDL_FreeSurface(textSurf);	
	
	textSurf = IMG_Load("Res/T4.png");
	tex[7] = SDL_CreateTextureFromSurface(renderer, textSurf);
	SDL_FreeSurface(textSurf);
}































	
