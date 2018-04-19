#include "stdafx.h"
#include "IGame.h"

void IGame::Run()
{
	Init();

	while (CanRun())
	{
		Update(0.1);
		Render();
	}

	Shutdown();
}
