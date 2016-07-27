//
// @Author: J Brown (@DrMelon)
// 2016

#ifndef _SODA_SODAEVENT_H_
#define _SODA_SODAEVENT_H_

#include <libtcod/libtcod.hpp>

namespace SODA
{
	struct Event
	{
		TCOD_key_t Key;
		TCOD_mouse_t Mouse;
	};
}

#endif