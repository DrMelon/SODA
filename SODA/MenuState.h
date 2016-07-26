#pragma once
//
// @Author: J Brown (@DrMelon)
// 2016

#include "IState.h"
#include "StateMachine.h"

class MenuState : public IState
{
	public:
		MenuState(StateMachine* parent);
		void Initialize() override;
		void Update(float deltaTime) override;
		void Render() override;
		void OnPause() override;
		void OnResume() override;

		StateMachine* myParent;
};