#pragma once

const int R = 50;
const int C = 120;

class Map
{
public:
	Map(SDL_Renderer *renderer);
	~Map();

	void DrawMap();
	void Draw(SDL_Texture* tex, SDL_Rect dest);
	SDL_Texture* Load(const char* file);
	bool isway(int x, int y, bool* stat);

private:
	SDL_Rect src, dest;
	SDL_Renderer *rend;   //for passing renderer
        SDL_Texture* grass;
	SDL_Texture* Building;
	SDL_Texture* yulu;
	SDL_Texture* shop;
	SDL_Texture* hostel;
	SDL_Texture* path;
	SDL_Texture* ground;
	SDL_Texture* boundary;
	SDL_Texture* work;
	SDL_Texture* lhc;
	SDL_Texture* library;
	SDL_Texture* w1;
	SDL_Texture* w2;
	SDL_Texture* libBorder;
        SDL_Texture* lhcB;
        SDL_Texture* shopB;
        SDL_Texture* lawn;
        SDL_Texture* profH;
        SDL_Texture* bharti;
        SDL_Texture* sac;

	int maze[R][C] = {0};
};

void Map::Draw(SDL_Texture* tex, SDL_Rect dest)
{
	SDL_RenderCopy(rend, tex, &src, &dest);
}

SDL_Texture* Map::Load(const char* file)
{
	SDL_Surface* tmpSurface = IMG_Load(file);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return tex;
}

Map::Map(SDL_Renderer *renderer)
{
	rend = renderer;
	
	grass = Load("Res/grass.png");
	Building = Load("Res/Building.png");
	yulu = Load("Res/p6.png");
	shop = Load("Res/shop.png");
	hostel = Load("Res/p1.png");
	path = Load("Res/c1.png");
	ground = Load("Res/hostel.png");
	boundary = Load("Res/boundary.png");
	library = Load("Res/p2.png");
	lhc = Load("Res/p4.png");
	work = Load("Res/c2.png");
	lawn = Load("Res/ground.png");
	w1 = Load("Res/boundary.png");
	w2 = Load("Res/Building.png");
        libBorder = Load("Res/p3.png");
       lhcB = Load("Res/p5.png");
	shopB = Load("Res/p7.png");
	profH = Load("Res/s1.png");
	bharti = Load("Res/c4.png");
	sac = Load("Res/library.png");
	src.w = src.h = 10;
	src.x = src.y = 0;
	
	dest.w = dest.h = 10;
	dest.x = dest.y = 0;
	
	for (int column = 0; column < 15; column++)  maze[12][column] = maze[11][column] = 1;
	for (int column = 14; column < 30; column++)  maze[17][column] = maze[16][column] = 1;
	for (int column = 29; column < 60; column++)  maze[25][column] = maze[24][column] = 1;
	for (int column = 59; column < 90; column++)  maze[16][column] = maze[15][column] = 1;
	for (int column = 104; column < 113; column++)  maze[16][column] = maze[15][column] = 1;
	for (int column = 69; column < 104; column++)  maze[8][column] = maze[7][column] = 1;
	for (int column = 59; column < 84; column++)  maze[31][column] = maze[30][column] = 1;
	for (int column = 83; column < 105; column++)  maze[28][column] = maze[27][column] = 1;
	for (int column = 49; column < 91; column++)  maze[43][column] = maze[42][column] = 1;
	for (int column = 102; column < 113; column++)  maze[40][column] = maze[39][column] = 1;
	for (int column = 0; column < 15; column++)  maze[25][column] = maze[24][column] = 1;
	for (int column = 0; column < 16; column++)  maze[37][column] = maze[36][column] = 1;
	for (int column = 39; column < 49; column++) maze[39][column] = maze[40][column] = 1;
	for (int column = 29; column < 39; column++) maze[42][column] = maze[43][column] = 1;
	for (int column = 9; column < 29; column++) maze[47][column] = maze[48][column] = 1;
	for (int column = 80; column < 104; column++) maze[47][column] = maze[48][column] = 1;
	for (int column = 30; column < 40; column++) maze[8][column] = maze[9][column] = 1;
	for (int column = 45; column < 60; column++) maze[18][column] = maze[17][column] = 1;
	for (int column = 16; column < 23; column++) maze[30][column] = maze[31][column] = 1;
	for (int column = 23; column < 29; column++) maze[37][column] = maze[38][column] = 1;
	for (int column = 65; column < 90; column++) maze[1][column] = maze[2][column] = 1;
	for (int column = 54; column < 63; column++) maze[8][column] = maze[9][column] = 1;
	for (int column = 16; column < 30; column++) maze[1][column] = maze[2][column] = 1;
	for (int column = 100; column < 110; column++) maze[19][column] = maze[20][column] = 1;
	for (int column = 40; column < 63; column++) maze[48][column] = maze[47][column] = 1;	
	for (int row = 42; row < 49; row++)  maze[row][80] = maze[row][81] = 1;
	for (int row = 11; row < 37; row++)  maze[row][14] = maze[row][15] = 1;
	for (int row = 0; row < 50; row++)  maze[row][29] = maze[row][30] = 1;
	for (int row = 17; row < 31; row++)  maze[row][59] = maze[row][60] = 1;
	for (int row = 24; row < 39; row++)  maze[row][49] = maze[row][50] = 1;
	for (int row = 0; row < 42; row++)  maze[row][89] = maze[row][90] = 1;
	for (int row = 0; row < 16; row++)  maze[row][104] = maze[row][105] = 1;
	for (int row = 15; row < 41; row++)  maze[row][112] = maze[row][113] = 1;
	for (int row = 39; row < 50; row++)  maze[row][103] = maze[row][102] = 1;
	for (int row = 27; row < 32; row++)  maze[row][83] = maze[row][84] = 1;
	for (int row = 7; row < 15; row++)  maze[row][69] = maze[row][70] = 1;
	for (int row = 41; row < 50; row++)  maze[row][39] = maze[row][40] = 1;
	for (int row = 38; row < 50; row++)  maze[row][9] = maze[row][10] = 1;
	for (int row = 11; row < 24; row++)  maze[row][43] = maze[row][44] = 1;
	for (int row = 32; row < 48; row++)  maze[row][21] = maze[row][22] = 1;
	for (int row = 32; row < 40; row++)  maze[row][107] = maze[row][106] = 1;
	for (int row = 1; row < 10; row++)  maze[row][63] = maze[row][64] = 1;
	for (int row = 19; row < 27; row++)  maze[row][99] = maze[row][100] = 1;
	for (int row = 44; row < 50; row++)  maze[row][62] = maze[row][63] = 1;
	for (int row = 36; row < 39; row++)  maze[row][43] = maze[row][44] = 1;
	for (int row = 23; row < 32; row++)  //LHC
		for (int column = 105; column < 109; column++) maze[row][column] = 8;
	for(int row = 22;row<33;row++) {
	        maze[row][109] = 14;
	        if(row !=27 &&  row != 28){
	            maze[row][104] = 14;
	        }
	}
	for(int column = 104; column<110;column++) {maze[22][column] = maze[32][column] = 14; }
	maze[32][106] = maze[32][107] = 1;	
	for (int row = 17; row < 25; row++)  //Main Building
		for (int column = 62; column < 77; column++) maze[row][column] = 3;
	 //Library
	for (int row = 32; row < 36; row++) 
		for (int column = 70; column < 80; column++) maze[row][column] = 11;
	maze[32][69] = maze[33][69] = maze[34][69] =	maze[35][69] = maze[36][69] = 13;
	maze[32][80] = maze[33][80] = maze[34][80] =	maze[35][80] = maze[36][80] = 13;
	maze[32][74] = maze[32][75]  = 13;
	for(int column = 70; column<80; column++) maze[36][column] = 13; 
	for (int column = 49; column < 53; column++) maze[39][column] = maze[40][column] = maze[41][column] = 7; //Ground 
	for (int row = 0; row < 50; row++)  maze[row][0] = maze[row][119] = 2;        //Boundary
	for (int column = 0; column < 120; column++) { maze[0][column] = maze[49][column] = 2;}
	maze[21][41] = maze[21][42] = maze[22][41] = maze[22][42] = maze[23][41] = maze[23][42] = 6;  
	maze[15][41] = maze[15][42] = maze[16][41] = maze[16][42] = maze[17][41] = maze[17][42] = 6; 
	maze[31][91] = maze[32][91] = maze[31][92] = maze[32][92] = maze[33][91] = maze[33][92] = 6;
	maze[33][59] = maze[33][60] = maze[33][61] = maze[32][59] = maze[32][60] = maze[32][61] = 6;
	//shops-------------
	maze[26][1] = maze[27][1] = maze[26][2] = maze[27][2] = maze[26][3] = maze[27][3] = 12;    
	maze[6][69] = maze[6][70] = maze[6][71] = maze[5][69] = maze[5][70] = maze[5][71] = 12;
	maze[18][110] = maze[19][110] = maze[20][110] = maze[18][111] = maze[19][111] = maze[20][111] = 12;
	for (int row = 38; row < 49; row++)  //workshop 1
		for (int column = 1; column < 7; column++) maze[row][column] = 5;
	maze[39][1] = maze[40][2] = maze[39][3] = maze[40][1] = maze[39][2] = maze[40][3] = 9;
	maze[46][1] = maze[46][2] = maze[46][3] = maze[47][1] = maze[47][2] = maze[47][3] = 10;
	for (int row = 4; row < 11; row++)  //workshop 2
		for (int column = 40; column < 54; column++) maze[row][column] = 5;
	maze[5][40] = maze[6][41] = maze[7][40] = maze[5][41] = maze[6][40] = maze[7][41] = maze[4][41] = maze[4][40] = 9;
	maze[5][52] = maze[6][53] = maze[7][52] = maze[5][53] = maze[6][52] = maze[7][53] = maze[4][53] = maze[4][52] = 10;
	for (int row = 1; row < 11; row++)  //Hostels
		for (int column = 1; column < 8; column++) maze[row][column] = 4;
	for (int row = 1; row < 6; row++)  //Hostels
		for (int column = 1; column < 16; column++) maze[row][column] = 4;
	for (int row = 1; row < 5; row++)  //Hostels
		for (int column = 92; column < 102; column++) maze[row][column] = 4;
	//Lawn
	for (int row = 9; row < 15; row++)  
		for (int column = 71; column < 89; column++) maze[row][column] = 16;
	//ProfH
	for (int row = 1; row < 14; row++)  
		for (int column = 109; column < 119; column++) maze[row][column] = 17;
	//Research Park
	for (int row = 45; row < 49; row++)  
		for (int column = 65; column < 70; column++) maze[row][column] = 17;
	//Bharti Building
	for (int row = 20; row < 24; row++)  
		for (int column = 45; column < 53; column++) maze[row][column] = 18;
	//SAC
	for (int row = 28; row < 36; row++)  
		for (int column = 37; column < 48; column++) maze[row][column] = 19;
	//Nalanda ground
	for (int row = 20; row < 29; row++)  
		for (int column = 21; column < 29; column++) maze[row][column] = 6;
}

bool Map::isway(int x, int y, bool* stat)
{
	//if( x%10 != 0 || y%10 != 0){
	//	cerr << "Player's next coordinate is wrong -- In Map.h" << endl;
		//exit(0);
	//}
	int a = y/10;
	int b = x/10;
	int m = maze[a][b] ;
	if( m == 1 || m == 5 ||m == 12 || m == 11 || m == 4 ) return true;
	else if(m == 3 || m == 8 )
	{
		if(stat[0] == true) return true; else return false;
	}
	else if(m == 7)
	{
		if(stat[1] == true) return true; else return false;
	}
	return false;
}

void Map::DrawMap()
{
	int type = 0;
	for (int row = 0; row < R; row++)
	{
		for (int column = 0; column < C; column++)
		{
			type = maze[row][column];

			dest.x = column * 10;
			dest.y = row * 10;

			switch (type)
			{
			case 0:
				Draw(grass, dest);
				break;
			case 1:
				Draw(path,dest);
				break;
			case 2:
				Draw(boundary, dest);
				break;
			case 3:
				Draw(Building, dest);
				break;
			case 4:
				Draw(hostel, dest);
				break;
			case 5:
				Draw(work,  dest);
				break;
			case 6:
				Draw(yulu, dest);
				break;
			case 7:
				Draw(ground, dest);
				break;
			case 8:
				Draw(lhc, dest);
				break;
			case 9:
				Draw(w2, dest);
				break;
			case 10:
				Draw(w1, dest);
				break;
			case 11:
				Draw(library, dest);
				break;
			case 12:
				Draw(shop, dest);
				break;
			case 13:
			       Draw(libBorder, dest);
			       break;	
			case 14:
			       Draw(lhcB, dest);
			       break;
			case 15:
			       Draw(shopB, dest);
			       break;  
			case 16:
			       Draw(lawn, dest);
			       break; 
			case 17:
			       Draw(profH, dest);
			       break;  
			case 18:
			       Draw(bharti, dest);
			       break; 
			case 19:
			       Draw(sac, dest);
			       break;             
			default:
				break;
			}
		}
	}
}

