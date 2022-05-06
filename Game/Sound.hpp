#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class Sound
{
public:
	Sound();
	~Sound();
	
	Mix_Chunk *move = nullptr;
	Mix_Chunk *task = nullptr;
	Mix_Chunk *ntask = nullptr;
	Mix_Chunk *goal = nullptr;
	Mix_Chunk *coinGain = nullptr;
	Mix_Chunk *BugCollision = nullptr;
	Mix_Chunk *work = nullptr;
	Mix_Chunk *won = nullptr;
	Mix_Chunk *Gstart = nullptr;
	Mix_Chunk *lose = nullptr;
	
	void play_move();
	void play_task();
	void play_ntask();
	void play_goal();
	void play_coinGain();
	void play_BugCollision();
	void play_work();
	void play_won();
	void play_Gstart();
	void play_lose();
	
	void close();
	
};

Sound :: Sound()
{
	move = Mix_LoadWAV( "Res/s2.wav" );
    	if( move == NULL )
    	{
        	std::cerr << "Error in loading sound file 1" << std::endl;
    	}
    	task = Mix_LoadWAV( "Res/s7.wav" );
    	if( task == NULL )
    	{
        	std::cerr << "Error in loading sound file 2" << std::endl;
    	}
    	ntask = Mix_LoadWAV( "Res/s10.wav" );
    	if( ntask == NULL )
    	{
        	std::cerr << "Error in loading sound file 3" << std::endl;
    	}
    	goal = Mix_LoadWAV( "Res/s3.wav" );
    	if( goal == NULL )
    	{
        	std::cerr << "Error in loading sound file 4" << std::endl;
    	}
    	coinGain = Mix_LoadWAV( "Res/s4.wav" );
    	if( coinGain == NULL )
    	{
        	std::cerr << "Error in loading sound file 5" << std::endl;
    	}
    	BugCollision = Mix_LoadWAV( "Res/s8.wav" );
    	if( BugCollision == NULL )
    	{
        	std::cerr << "Error in loading sound file 6" << std::endl;
    	}
    	work = Mix_LoadWAV( "Res/s9.wav" );
    	if( work == NULL )
    	{
        	std::cerr << "Error in loading sound file 7" << std::endl;
    	}
    	won = Mix_LoadWAV( "Res/s10.wav" );
    	if( won == NULL )
    	{
        	std::cerr << "Error in loading sound file 8" << std::endl;
    	}
    	Gstart = Mix_LoadWAV( "Res/s6.wav" );
    	if( Gstart == NULL )
    	{
        	std::cerr << "Error in loading sound file 9" << std::endl;
    	}
    	lose = Mix_LoadWAV( "Res/s1.wav" );
    	if( lose == NULL )
    	{
        	std::cerr << "Error in loading sound file 10" << std::endl;
    	}
    
}

void Sound::play_move()
{
	Mix_PlayChannel( -1, move, 0 );
}

void Sound::play_task()
{
	Mix_PlayChannel( -1, task, 0 );
}

void Sound::play_ntask()
{
	Mix_PlayChannel( -1, ntask, 0 );
}

void Sound::play_goal()
{
	Mix_PlayChannel( -1, goal, 0 );
}

void Sound::play_coinGain()
{
	Mix_PlayChannel( -1, coinGain, 0 );
}

void Sound::play_BugCollision()
{
	Mix_PlayChannel( -1, BugCollision, 0 );
}

void Sound::play_work()
{
	Mix_PlayChannel( -1, work, 0 );
}

void Sound::play_won()
{
	Mix_PlayChannel( -1, won, 0 );
}

void Sound::play_Gstart()
{
	Mix_PlayChannel( -1, Gstart, 0 );
}

void Sound::play_lose()
{
	Mix_PlayChannel( -1, lose, 0 );
}

void Sound::close()
{
	Mix_FreeChunk( move );
	Mix_FreeChunk( task );
	Mix_FreeChunk( ntask );
	Mix_FreeChunk( goal );
	Mix_FreeChunk( coinGain );
	Mix_FreeChunk( BugCollision );
	Mix_FreeChunk( work );
	Mix_FreeChunk( won );
	Mix_FreeChunk( Gstart );
	Mix_FreeChunk( lose );
}

