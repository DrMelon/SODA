//
// @Author: J Brown (@DrMelon)
// 2016

#ifndef _SODA_EFFECT_H_
#define _SODA_EFFECT_H_

// Simple effects interface.

#include <libtcod/libtcod.hpp>

namespace SODA
{
	class IEffect
	{
		public:
			virtual void UpdateEffect(float deltaTime) = 0;
			virtual void DrawEffect(TCODConsole* console) = 0;
	};
}

#endif