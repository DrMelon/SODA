//
// @Author: J Brown (@DrMelon)
// 2016

#include "StateMachine.h"

namespace SODA
{

	StateMachine::StateMachine()
	{
		stateMachineConsole = new TCODConsole(STATEMACHINE_CON_WIDTH, STATEMACHINE_CON_HEIGHT);
	}

	StateMachine::~StateMachine()
	{
		Destroy();
	}

	void StateMachine::Initialize()
	{
		isRunning = true;

		if (!stateStack.empty())
		{
			stateStack.top()->Initialize();
		}
	}

	void StateMachine::Render()
	{
		// Clear the state machine's console.
		stateMachineConsole->clear();

		if (!stateStack.empty())
		{
			stateStack.top()->Render();
		}

		// Blit onto the root.
		TCODConsole::blit(stateMachineConsole, 0, 0, STATEMACHINE_CON_WIDTH, STATEMACHINE_CON_HEIGHT, TCODConsole::root, 0, 0);
	}

	void StateMachine::Update(float deltaTime)
	{
		if (!stateStack.empty())
		{
			stateStack.top()->Update(deltaTime, currentEvent);
		}
	}

	void StateMachine::Pause()
	{
		if (!stateStack.empty())
		{
			stateStack.top()->OnPause();
		}
	}

	void StateMachine::Resume()
	{
		if (!stateStack.empty())
		{
			stateStack.top()->OnResume();
		}
	}

	void StateMachine::Destroy()
	{
		while (!stateStack.empty())
		{
			stateStack.pop();
		}
	}

	bool StateMachine::Running()
	{
		return isRunning;
	}

	void StateMachine::AddState(IState* newState)
	{
		stateStack.push(newState);
	}

	void StateMachine::SwitchState(IState* newState)
	{
		while (!stateStack.empty())
		{
			stateStack.pop();
		}

		stateStack.push(newState);
	}

	IState* StateMachine::PopState()
	{
		if (!stateStack.empty())
		{
			IState* topState = stateStack.top();
			stateStack.pop();
			return topState;
		}

		return nullptr;
	}

	IState* StateMachine::CurrentState()
	{
		if (!stateStack.empty())
		{
			return stateStack.top();
		}

		return nullptr;
	}

}