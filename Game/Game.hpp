#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "PlayerP.hpp"
#include "PlayerE.hpp"
#include "Map.hpp"
#include "Bug.hpp"
#include "Sound.hpp"
using namespace std;

class Game
{
public:
	Game();
	~Game();

	void init(SDL_Renderer *Rend, bool IsServer);
	void getYourEvents(char* cmds);
	void handleEvents(char events_1[2], char events_2[2]);
	void update();
	bool running() { return isRunning; }
	void render();
	SDL_Renderer *renderer = nullptr;
	bool isRunning = false;
	bool IsYouWon = false;
	PlayerP *player = nullptr;	
	PlayerE *enemy = nullptr;
	Map *maze = nullptr;	
	Bug *bugs = nullptr;
	Sound* snd = nullptr;
	SDL_Rect* pos = nullptr;
	
	int x, y;	
};

Game::Game()
{}

Game::~Game()
{}

void Game::init(SDL_Renderer *Rend, bool IsServer)
{

	renderer = Rend; 
	if(IsServer)
	{
		player = new PlayerP(renderer, "Res/P.png",10,10);
	        enemy = new PlayerE(renderer,"Res/E.png", 60,10);
	}
	else
	{
		player = new PlayerP(renderer, "Res/P.png",60,10);
		enemy = new PlayerE(renderer,"Res/E.png", 10,10);
	}
	
	maze = new Map(renderer);
	bugs = new Bug(renderer, "Res/dog.png");
	snd = new Sound();
	snd->play_Gstart();

}

void Game::getYourEvents(char* cmds)
{
	SDL_Event event; 
	cmds[0] = cmds[1] = '0';

	if (SDL_PollEvent(&event))
	{						
		cmds[0] = '1';
		switch (event.type) 
		{
		case SDL_QUIT:
			cmds[1] = '1';
			break;
		case SDL_KEYDOWN:
			snd->play_move();
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				cmds[1] = '2';
				break;
			case SDLK_DOWN:
				cmds[1] = '3';
				break;
			case SDLK_LEFT:
				cmds[1] = '4';
				break;
			case SDLK_RIGHT:
				cmds[1] = '5';
				break;
			case SDLK_SPACE:
				cmds[1] = '6';
				break;
			case SDLK_ESCAPE:
				cmds[1] = '1';
				break;
			default:
				break;
			}
		default:
			break;
		}
	}
}	



void Game::handleEvents(char events_1[2], char events_2[2])
{
	if (events_1[0] == '1')
	{						
		switch (events_1[1]) 
		{
		case '1':
			isRunning = false;
			IsYouWon = false;
			break;
		case '2':
			player->Y = NEG;
			break;
		case '3':
			player->Y = POS;
			break;
		case '4':
			player->X = NEG;
			break;
		case '5':
			player->X = POS;
			break;
		case '6':
			player->X = STOP;
			player->Y = STOP;
			break;
		default:
			break;
		}
		
	}
	
	if (events_2[0] == '1')
	{						
		switch (events_2[1]) 
		{
		case '1':
			isRunning = false;
			IsYouWon = true;
			break;
		case '2':
			enemy->Y = NEG;
			break;
		case '3':
			enemy->Y = POS;
			break;
		case '4':
			enemy->X = NEG;
			break;
		case '5':
			enemy->X = POS;
			break;
		case '6':
			enemy->X = STOP;
			enemy->Y = STOP;
			break;
		default:
			break;
		}
		
	}
	
	
	switch (player->X)
	{
	case STOP: break;
	case POS:
		if (maze->isway(player->xpos + 20, player->ypos, player->stat) && maze->isway(player->xpos + 20, player->ypos + 10, player->stat))
			player->xpos += PVel;
		break;
	case NEG:
		if (maze->isway(player->xpos - 10, player->ypos, player->stat) && maze->isway(player->xpos - 10, player->ypos + 10, player->stat))
			player->xpos -= PVel;
		break;
	default:
		break;
	}
	switch (player->Y)
	{
	case STOP: break;
	case POS:
		if (maze->isway(player->xpos, player->ypos + 20, player->stat) && maze->isway(player->xpos + 10, player->ypos + 20, player->stat))
			player->ypos += PVel;
		break;
	case NEG:
		if (maze->isway(player->xpos, player->ypos - 10, player->stat) && maze->isway(player->xpos + 10, player->ypos - 10, player->stat))
			player->ypos -= PVel;
		break;
	default:
		break;
	}
	
	switch (enemy->X)
	{
	case STOP: break;
	case POS:
		if (maze->isway(enemy->xpos + 20, enemy->ypos, enemy->stat) && maze->isway(enemy->xpos + 20, enemy->ypos + 10, enemy->stat))
			enemy->xpos += PVel;
		break;
	case NEG:
		if (maze->isway(enemy->xpos - 10, enemy->ypos, enemy->stat) && maze->isway(enemy->xpos - 10, enemy->ypos + 10, enemy->stat))
			enemy->xpos -= PVel;
		break;
	default:
		break;
	}
	switch (enemy->Y)
	{
	case STOP: break;
	case POS:
		if (maze->isway(enemy->xpos, enemy->ypos + 20, enemy->stat) && maze->isway(enemy->xpos + 10, enemy->ypos + 20, enemy->stat))
			enemy->ypos += PVel;
		break;
	case NEG:
		if (maze->isway(enemy->xpos, enemy->ypos - 10, enemy->stat) && maze->isway(enemy->xpos + 10, enemy->ypos - 10, enemy->stat))
			enemy->ypos -= PVel;
		break;
	default:
		break;
	}
}
void Game::update()
{
	bugs->Update();
	pos = bugs->getPos();
	player->Update(renderer, pos);
	enemy->Update(renderer, pos);
	if(player->isOver) 
	{
		isRunning = false;
		if(player->isWon) 
		{
			snd->play_won();
			IsYouWon = true;
		}
		else
		{
			snd->play_lose();
			IsYouWon = false;
		}
	}
	if(enemy->isOver)
	{	
		isRunning = false;
		if(enemy->isWon) 
		{
			snd->play_lose();
			IsYouWon = false;
		}
		else 
		{
			snd->play_won();
			IsYouWon = true;
		}
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	maze->DrawMap();
	bugs->Render(renderer);
	player->Render(renderer);
	enemy->Render(renderer);
	SDL_RenderPresent(renderer);
}

