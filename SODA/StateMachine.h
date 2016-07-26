#pragma once

//
// @Author: J Brown (@DrMelon)
// 2016


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

	private:
		bool isPaused = false;
		bool isRunning = false;
};