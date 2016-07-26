#pragma once

//
// @Author: J Brown (@DrMelon)
// 2016

// Abstract class for state machine use.
class IState
{
	public:
		virtual void Initialize() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Render() = 0;
		virtual void OnPause() = 0;
		virtual void OnResume() = 0;
};