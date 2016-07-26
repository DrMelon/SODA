#pragma once
//
// @Author: J Brown (@DrMelon)
// 2016

#include "IState.h"

class MenuState : public IState
{
	public:
		void Initialize() override;
		void Update(float deltaTime) override;
		void Render() override;
		void OnPause() override;
		void OnResume() override;

};