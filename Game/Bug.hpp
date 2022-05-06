#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<bits/stdc++.h>
#include "Constant.hpp"

class Bug
{
public:
	Bug(SDL_Renderer *renderer, const char* imgfile);
	~Bug();
	void Update();
	void Render(SDL_Renderer *renderer);
	SDL_Texture* tex;
	bool bugDirection[NUM_BUG];   //Bugs Position store
	SDL_Rect pos[NUM_BUG];
	SDL_Rect* getPos();
};

Bug::Bug(SDL_Renderer *renderer, const char* imgfile)
{
	SDL_Surface* tmpSurface = IMG_Load(imgfile);
	tex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	pos[0].h = pos[1].h = pos[2].h = pos[3].h= pos[4].h= pos[5].h= pos[6].h= pos[7].h = pos[8].h =  pos[9].h =  pos[10].h =  pos[11].h =  pos[12].h =  pos[13].h =  20;
	pos[0].w = pos[1].w = pos[2].w = pos[3].w =pos[4].w =pos[5].w =pos[6].w =pos[7].w = pos[8].w = pos[9].w = pos[10].w =  pos[11].w =  pos[12].w =  pos[13].w =  20;
	pos[0].x = 140;
	pos[0].y = 110;
	pos[1].x = 590;
	pos[1].y = 150;
	pos[2].x = 10;
	pos[2].y = 360;
	pos[3].x = 390;
	pos[3].y = 470;  
	pos[4].x = 490;
	pos[4].y = 420;  
	pos[5].x = 690;
	pos[5].y = 70;  
	pos[6].x = 1020;
	pos[6].y = 390; 
	pos[7].x = 890;
	pos[7].y = 420;  
	pos[8].x = 290;
	pos[8].y = 10; 
	pos[9].x = 430;
	pos[9].y = 240; 
	pos[10].x = 290;
	pos[10].y = 270; 
	pos[11].x = 110;
	pos[11].y = 470; 
	pos[12].x = 650;
	pos[12].y = 150; 
	pos[13].x = 990;
	pos[13].y = 190; 
	
	bugDirection[0] = bugDirection[1] = bugDirection[2] = bugDirection[3] = bugDirection[4] = bugDirection[5] = bugDirection[6] = true;
	bugDirection[7] = bugDirection[8] = bugDirection[9] =  bugDirection[10] = bugDirection[11] = bugDirection[12] =  bugDirection[13] = true;    //true means move down
}
// First update bug then check for collision
void Bug::Update()
{
	if(pos[0].y > 110 && pos[0].y < 350){
		if(bugDirection[0]) pos[0].y += BugVel;
		else pos[0].y -= BugVel;
	}else if(pos[0].y <= 110){
		bugDirection[0] = true;
		pos[0].y += BugVel;
	}else{
		bugDirection[0] = false;
		pos[0].y -= BugVel;
	}
	
	if(pos[1].y > 150 && pos[1].y < 300){
		if(bugDirection[1]) pos[1].y += BugVel;
		else pos[1].y -= BugVel;
	}else if(pos[1].y <= 150){
		bugDirection[1] = true;
		pos[1].y += BugVel;
	}else{
		bugDirection[1] = false;
		pos[1].y -= BugVel;
	}
	if(pos[2].x > 10 && pos[2].x < 130){
		if(bugDirection[2]) pos[2].x += BugVel;
		else pos[2].x -= BugVel;
	}else if(pos[2].x <= 10){
		bugDirection[2] = true;
		pos[2].x += BugVel;
	}else{
		bugDirection[2] = false;
		pos[2].x -= BugVel;
	}
	if(pos[3].y > 390 && pos[3].y < 470){
		if(bugDirection[3]) pos[3].y += BugVel;
		else pos[3].y -= BugVel;
	}else if(pos[3].y <= 390){
		bugDirection[3] = true;
		pos[3].y += BugVel;
	}else{
		bugDirection[3] = false;
		pos[3].y -= BugVel;
	}
	if(pos[4].x > 490 && pos[4].x < 890){
		if(bugDirection[4]) pos[4].x += BugVel;
		else pos[4].x -= BugVel;
	}else if(pos[4].x <= 490){
		bugDirection[4] = true;
		pos[4].x += BugVel;
	}else{
		bugDirection[4] = false;
		pos[4].x -= BugVel;
	}
	if(pos[5].x > 690 && pos[5].x < 1040){
		if(bugDirection[5]) pos[5].x += BugVel;
		else pos[5].x -= BugVel;
	}else if(pos[5].x <= 690){
		bugDirection[5] = true;
		pos[5].x += BugVel;
	}else{
		bugDirection[5] = false;
		pos[5].x -= BugVel;
	}
	if(pos[6].x > 1020 && pos[6].x < 1120){
		if(bugDirection[6]) pos[6].x += BugVel;
		else pos[6].x -= BugVel;
	}else if(pos[6].x <= 1020){
		bugDirection[6] = true;
		pos[6].x += BugVel;
	}else{
		bugDirection[6] = false;
		pos[6].x -= BugVel;
	}
	if(pos[7].y >20 && pos[7].y < 420){
		if(bugDirection[7]) pos[7].y += BugVel;
		else pos[7].y -= BugVel;
	}else if(pos[7].y <= 20){
		bugDirection[7] = true;
		pos[7].y += BugVel;
	}else{
		bugDirection[7] = false;
		pos[7].y -= BugVel;
	}
	if(pos[8].y > 20 && pos[8].y < 270){
		if(bugDirection[8]) pos[8].y += BugVel;
		else pos[8].y -= BugVel;
	}else if(pos[8].y <= 20){
		bugDirection[8] = true;
		pos[8].y += BugVel;
	}else{
		bugDirection[8] = false;
		pos[8].y -= BugVel;
	}
	if(pos[9].y > 110 && pos[9].y < 240){
		if(bugDirection[9]) pos[9].y += BugVel;
		else pos[9].y -= BugVel;
	}else if(pos[9].y <= 110){
		bugDirection[9] = true;
		pos[9].y += BugVel;
	}else{
		bugDirection[9] = false;
		pos[9].y -= BugVel;
	}
	if(pos[10].y > 260 && pos[10].y < 470){
		if(bugDirection[10]) pos[10].y += BugVel;
		else pos[10].y -= BugVel;
	}else if(pos[10].y <= 260){
		bugDirection[10] = true;
		pos[10].y += BugVel;
	}else{
		bugDirection[10] = false;
		pos[10].y -= BugVel;
	}
	if(pos[11].x > 100 && pos[11].x < 280){
		if(bugDirection[11]) pos[11].x += BugVel;
		else pos[11].x -= BugVel;
	}else if(pos[11].x <= 100){
		bugDirection[11] = true;
		pos[11].x += BugVel;
	}else{
		bugDirection[11] = false;
		pos[11].x -= BugVel;
	}
	if(pos[12].x > 640 && pos[12].x < 770){
		if(bugDirection[12]) pos[12].x += BugVel;
		else pos[12].x -= BugVel;
	}else if(pos[12].x <= 640){
		bugDirection[12] = true;
		pos[12].x += BugVel;
	}else{
		bugDirection[12] = false;
		pos[12].x -= BugVel;
	}
	if(pos[13].x > 990 && pos[13].x < 1050){
		if(bugDirection[13]) pos[13].x += BugVel;
		else pos[13].x -= BugVel;
	}else if(pos[13].x <= 990){
		bugDirection[13] = true;
		pos[13].x += BugVel;
	}else{
		bugDirection[13] = false;
		pos[13].x -= BugVel;
	}
	
}

void Bug::Render(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, tex, NULL, &pos[0]);
	SDL_RenderCopy(renderer, tex, NULL, &pos[1]);
	SDL_RenderCopy(renderer, tex, NULL, &pos[2]);
	SDL_RenderCopy(renderer, tex, NULL, &pos[3]);
	SDL_RenderCopy(renderer, tex, NULL, &pos[4]);
	SDL_RenderCopy(renderer, tex, NULL, &pos[5]);
	SDL_RenderCopy(renderer, tex, NULL, &pos[6]);
	SDL_RenderCopy(renderer, tex, NULL, &pos[7]);
	SDL_RenderCopy(renderer, tex, NULL, &pos[8]);
	SDL_RenderCopy(renderer, tex, NULL, &pos[9]);
	SDL_RenderCopy(renderer, tex, NULL, &pos[10]);
	SDL_RenderCopy(renderer, tex, NULL, &pos[11]);
	SDL_RenderCopy(renderer, tex, NULL, &pos[12]);
	SDL_RenderCopy(renderer, tex, NULL, &pos[13]);
}

SDL_Rect* Bug::getPos()
{
	return  pos;
}










