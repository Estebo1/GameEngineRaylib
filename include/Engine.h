#pragma once
#include "../Ball.h"
#include <vector>


class Engine
{
public:
	void Initialize();	
	void Run();
	void Shutdown();
private:
	std::vector<Ball*> balls;
	void GenerateBalls(int ballNumber);

};

