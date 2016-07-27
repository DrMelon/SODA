//
// @Author: J Brown (@DrMelon)
// 2016

#include "EffectRainbowLine.h"

namespace SODA
{
	EffectRainbowLine::EffectRainbowLine(int y, float huePos, float speed)
	{
		yPos = y;
		currentHuePos = huePos;
		changeSpeed = speed;
	}

	void EffectRainbowLine::UpdateEffect(float deltaTime)
	{
		currentHuePos += deltaTime * changeSpeed;
		if (currentHuePos > 360.0f)
		{
			currentHuePos = 0.0f;
		}
	}

	void EffectRainbowLine::DrawEffect(TCODConsole* console)
	{
		// Draw colours based on hue pos.
		for (int i = 0; i < console->getWidth(); i++)
		{
			float cellCurrentPositionDelta = ((float)i / (float)console->getWidth() * 360.0f);
			TCODColor cellCurrentCol;
			cellCurrentCol.setHSV(currentHuePos + cellCurrentPositionDelta, 1.0, 1.0);
			console->setCharBackground(i, yPos, cellCurrentCol);
		}
	}
}