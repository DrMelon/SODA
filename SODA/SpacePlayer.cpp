//
// @Author: J Brown (@DrMelon)
// 2016

#include "SpacePlayer.h"

namespace SODA
{
	SpacePlayer::SpacePlayer()
	{
		WorldPosition.x = 0;
		WorldPosition.y = 0;
	}

	SpacePlayer::SpacePlayer(int startx, int starty)
	{
		WorldPosition.x = startx;
		WorldPosition.y = starty;
	}

	void SpacePlayer::Update(float deltaTime, SODA::Event currentEvent)
	{
		HandleInput(currentEvent);

		ScreenPosition.x = WorldPosition.x;
		ScreenPosition.y = WorldPosition.y;
	}

	void SpacePlayer::Render(TCODConsole* console)
	{
		console->setChar(ScreenPosition.x, ScreenPosition.y, '@');
	}

	void SpacePlayer::TakeStep(int x, int y)
	{
		WorldPosition.x += x;
		WorldPosition.y += y;
	}

	void SpacePlayer::HandleInput(SODA::Event currentEvent)
	{
		if (currentEvent.Key.pressed && currentEvent.Key.vk == TCODK_UP)
		{
			TakeStep(0, -1);
		}
		if (currentEvent.Key.pressed && currentEvent.Key.vk == TCODK_DOWN)
		{
			TakeStep(0, 1);
		}
		if (currentEvent.Key.pressed && currentEvent.Key.vk == TCODK_LEFT)
		{
			TakeStep(-1, 0);
		}
		if (currentEvent.Key.pressed && currentEvent.Key.vk == TCODK_RIGHT)
		{
			TakeStep(1, 0);
		}
	}

}