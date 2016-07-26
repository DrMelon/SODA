#pragma once

//
// @Author: J Brown (@DrMelon)
// 2016
#include <libtcod/libtcod.hpp>
#include <stack>
#include "IState.h"

//
// A simple FSM; just used for keeping all the game states in order!
//
class StateMachine
{
	public:
		StateMachine();
		~StateMachine();
		void Initialize();
		void Update(float deltaTime);
		void Render();
		void Pause();
		void Resume();
		void Destroy();
		bool Running();
		void AddState(IState* newState);
		IState* PopState();
		void SwitchState(IState* newState);

		TCODConsole* stateMachineConsole = nullptr;

	private:
		bool isPaused = false;
		bool isRunning = false;

		std::stack<IState*> stateStack;

		
};