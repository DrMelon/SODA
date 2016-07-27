//
// @Author: J Brown (@DrMelon)
// 2016

#ifndef _SODA_EFFECTRAINBOWLINE_H_
#define _SODA_EFFECTRAINBOWLINE_H_

#include "IEffect.h"

namespace SODA
{
	// It's a line! It's a rainbow! It's a rainbow line!
	class EffectRainbowLine : public IEffect
	{
		public:
			EffectRainbowLine(int y, float huePos = 0.0f, float speed = 1.0f);
			void UpdateEffect(float deltaTime) override;
			void DrawEffect(TCODConsole* console) override;

		private:
			int yPos;
			float currentHuePos = 0.0f;
			float changeSpeed = 1.0f;
	};
}

#endif