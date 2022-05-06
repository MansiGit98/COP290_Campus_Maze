#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Start
{
public:
	Start();
	~Start();

	void init(SDL_Renderer *Rend);
	void handleEvents();
	bool running() { return isRunning; }
	void render();
	void renderConnect();
	void renderExit(const char* file);
	SDL_Renderer *renderer = nullptr;
	bool isRunning = false;
	bool IsStart = false;
	bool IsRule = false;
	bool IsMap = false;
	bool IsControl = false;
	SDL_Surface* tmpSurface;
	SDL_Texture* tex1;
	SDL_Texture* tex2;
	SDL_Texture* tex3;
	SDL_Texture* tex4;
	SDL_Rect posRect;
};

Start::Start()
{}

Start::~Start()
{}

void Start::init(SDL_Renderer *Rend)
{
	renderer = Rend;
	isRunning = true;
	
	tmpSurface = IMG_Load("Res/main.png");
	if(!tmpSurface) {
    		printf("IMG_Load: %s\n", IMG_GetError());
	}
	tex1 = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	tmpSurface = IMG_Load("Res/Rule.png");
	if(!tmpSurface) {
    		printf("IMG_Load: %s\n", IMG_GetError());
	}
	tex2 = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	tmpSurface = IMG_Load("Res/Control.png");
	if(!tmpSurface) {
    		printf("IMG_Load: %s\n", IMG_GetError());
	}
	tex3 = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	tmpSurface = IMG_Load("Res/Map.png");
	if(!tmpSurface) {
    		printf("IMG_Load: %s\n", IMG_GetError());
	}
	tex4 = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	
	posRect.h = 700;
	posRect.w = 1200;
	posRect.x = 0;
	posRect.y = 0;
}

void Start::handleEvents()
{
	SDL_Event event; 

	if (SDL_PollEvent(&event))
	{						
		switch (event.type) 
		{
		case SDL_QUIT:
			isRunning = false;
			IsStart = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_m:
				IsMap = true;
				IsControl = false;
				IsRule = false;
				break;
			case SDLK_c:
				IsControl = true;
				IsRule = false;
				break;
			case SDLK_r:
				IsRule = true;
				break;
			case SDLK_BACKSPACE:
				IsMap = false;
				IsControl = false;
				IsRule = false;
				break;
			case SDLK_RETURN:
				isRunning = false;
				IsStart = true;
				break;
			default:
				break;
			}
		default:
			break;
		}
	}
	
}

void Start::render()
{
	SDL_RenderClear(renderer);
	if(IsRule) SDL_RenderCopy(renderer, tex2, NULL, &posRect); 
	else if(IsControl) SDL_RenderCopy(renderer, tex3, NULL, &posRect); 
	else if(IsMap) SDL_RenderCopy(renderer, tex4, NULL, &posRect);  
	else SDL_RenderCopy(renderer, tex1, NULL, &posRect);  
	SDL_RenderPresent(renderer);
}

void Start::renderConnect()
{
	tmpSurface = IMG_Load("Res/wait.png");  //Waiting others for starting
	if(!tmpSurface) {
    		printf("IMG_Load: %s\n", IMG_GetError());
	}
	tex1 = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, tex1, NULL, &posRect); 
	SDL_RenderPresent(renderer);
}

void Start::renderExit(const char* file)
{
	tmpSurface = IMG_Load(file);  //Declare result
	if(!tmpSurface) {
    		printf("IMG_Load: %s\n", IMG_GetError());
	}
	tex1 = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, tex1, NULL, &posRect); 
	SDL_RenderPresent(renderer);
}


