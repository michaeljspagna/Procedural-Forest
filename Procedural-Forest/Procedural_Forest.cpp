#include <random>
#include <iostream>

#define OLC_PGE_APPLICATION
#include "include/olcPixelGameEngine.h"
#include "src/wyhash_rng.hpp"
#include "src/forest.hpp"

class Procedural_Forest : public olc::PixelGameEngine
{
public:
	Forest forest;
public:
	Procedural_Forest()
	{
		sAppName = "Procedural_Forest";
	}

public:
	bool OnUserCreate() override
	{

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		if(GetKey(olc::UP).bHeld) 
			forest.offset.y -= 50.0f * fElapsedTime;
		if(GetKey(olc::DOWN).bHeld) 
			forest.offset.y += 50.0f * fElapsedTime;
		if(GetKey(olc::LEFT).bHeld) 
			forest.offset.x -= 50.0f * fElapsedTime;
		if(GetKey(olc::RIGHT).bHeld) 
			forest.offset.x += 50.0f * fElapsedTime;

		Clear(olc::Pixel(0,154,23, 150));
		forest.generate_forest(this);
		return true;
	}
};


int main()
{
	Procedural_Forest forest;
	if (forest.Construct(256, 192, 2, 2, false, false)){
		forest.Start();
	}
	return 0;
}

/*
g++ -o forest src/*.cpp Procedural_Forest.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++2a
*/