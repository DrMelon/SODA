//
// @Author: J Brown (@DrMelon)
// 2016

#include "StateMachine.h"

StateMachine::StateMachine()
{

}

StateMachine::~StateMachine()
{
	Destroy();
}

void StateMachine::Initialize()
{
	isRunning = true;
}

void StateMachine::Render()
{

}

void StateMachine::Update(float deltaTime)
{

}

void StateMachine::Pause()
{

}

void StateMachine::Resume()
{

}

void StateMachine::Destroy()
{

}

bool StateMachine::Running()
{
	return isRunning;
}