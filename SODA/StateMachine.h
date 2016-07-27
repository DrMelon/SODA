//
// @Author: J Brown (@DrMelon)
// 2016

#ifndef _SODA_STATEMACHINE_H_
#define _SODA_STATEMACHINE_H_

#include <libtcod/libtcod.hpp>
#include <stack>
#include "IState.h"
#include "SodaEvent.h"

namespace SODA
{

	static const int STATEMACHINE_CON_WIDTH = 160;
	static const int STATEMACHINE_CON_HEIGHT = 100;

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
		IState* CurrentState();

		TCODConsole* stateMachineConsole = nullptr;
		SODA::Event currentEvent;

	private:
		bool isPaused = false;
		bool isRunning = false;


		std::stack<IState*> stateStack;


	};

}

#endif