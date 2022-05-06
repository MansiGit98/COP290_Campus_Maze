#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Game.hpp"
#include "Start.hpp"
#include "Constant.hpp"
#include "Client.hpp"
#include "Server.hpp"

Game *game = nullptr;
Start *start = nullptr;
Server *server = nullptr;
Client *client = nullptr;

int main(int argc, char *argv[])
{
	bool IsServer = false;
	bool IsClient = false;
	char *IP;	
	string str = argv[1];
    	if (str.compare("S") == 0)
    	{
        	if (argc != 2)
        	{
         	   cout << "Error: Server Command is not typed correctly" << endl;
         	   return 0;
        	}
        	IsServer = true;
    	}
    	else if (str.compare("C") == 0)
    	{
        	if (argc != 3)
        	{
          		cout << "Error:Client Command is not typed correctly" << endl;
            		return 0;
        	}
        	IsClient = true;
        	IP = argv[2];
    	}else{
    	 	cout << "Correctly Enter C for Client or S for Server" << endl;
            	return 0;
    	}
	
	const int FPS = 50;
	const int frameDelay = 10000 / FPS;

	Uint32 frameStart;
	int frameTime;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cerr << "SDL fail to initialise" << endl;
		exit(0);
	}
	SDL_Window *window = SDL_CreateWindow("Maze Runner", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	if (window == 0) {
		cerr << "SDL fail to create window" << endl;
		exit(0);
	}
	if (renderer == 0)
	{
		cerr << "SDL fail to create renderer" << endl;
		exit(0);
	}
	SDL_SetRenderDrawColor(renderer, 225, 225, 225, 255);
	
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
        	cerr << "SDL fail to Initialise Image" << endl;
		exit(0);
        }
        if ( TTF_Init() < 0 ) 
        {
		cerr << "SDL fail to Initialise TTF" << endl;
		exit(0);
	}
	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) 
	{
                cerr << "SDL fail to initialise Mixer" << endl;
		 exit(0);
        }
        
	char check[2] = {'0', '0'};
	
	if(IsClient)
	{
		bool IsConnected = false;
		client = new Client(IP);
		
		while(!IsConnected)
		{
			IsConnected = client->connect_to_server();
			//SDL_Delay(10*frameDelay);
		}
		check[0] = 'Y';
		client->send_to_server(check);	
	}
	else if(IsServer)
	{
		server = new Server();
		server->connect_to_client();
		server->get_from_client(check);
		if(check[0] == 'Y')
		{
			cout << "Client Connected Successfully" << endl;
		}
		else
		{
			cout << "Server not get Start signal" << endl;
			exit(0);
		}
	}
	else
	{
		cout << "Input about client server is wrong" << endl;
	}
	
	start = new Start();
	start->init(renderer);

	while (start->running())
	{
		start->handleEvents();
		start->render();
	}
	start->renderConnect();
	
	if(IsClient)
	{
	 	check[0] = 'S';
	 	client->send_to_server(check);
	 	check[0] = '0';
	 	client->get_from_server(check);
	 	if(check[0] == 'S') cout << "Start signal recived" << endl;
	}
	else 
	{
		check[0] = '0';
		server->get_from_client(check);
		if(check[0] == 'S') cout << "Start signal recived" << endl;
	 	server->send_to_client(check);
	}
	
	
	game = new Game();
	game->init(renderer, IsServer);
	if(start->IsStart) game->isRunning = true;
	
	char Events_1[2];
	char Events_2[2];
	
	while (game->running())
	{
		frameStart = SDL_GetTicks();
		game->getYourEvents(Events_1);
		
		if(IsClient)
		{
		 	client->send_to_server(Events_1);
		 	client->get_from_server(Events_2);
		}
		else if(IsServer)
		{
			server->get_from_client(Events_2);
		 	server->send_to_client(Events_1);
		}
		else
		{
			cout << "Input about client server is wrong in loop" << endl;
		}
		
		
		game->handleEvents(Events_1, Events_2);
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	if(game->IsYouWon)
	{
		start->renderExit("Res/win.png");
	}else
	{
		start->renderExit("Res/lose.png");
	}
	SDL_Delay(40*frameDelay);
	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	IMG_Quit();
	Mix_Quit();
	
	return 0;
}
