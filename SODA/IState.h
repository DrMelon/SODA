//
// @Author: J Brown (@DrMelon)
// 2016

#ifndef _SODA_ISTATE_H_
#define _SODA_ISTATE_H_

#include "SodaEvent.h"

namespace SODA
{
	// Abstract class for state machine use.
	class IState
	{
	public:
		virtual void Initialize() = 0;
		virtual void Update(float deltaTime, SODA::Event currentEvent) = 0;
		virtual void Render() = 0;
		virtual void OnPause() = 0;
		virtual void OnResume() = 0;
	};

}

#endif