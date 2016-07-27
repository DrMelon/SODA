//
// @Author: J Brown (@DrMelon)
//
//_____/\\\\\\\\\\\_______________/\\\\\___________ /\\\\\\\\\\\\_____________ /\\\\\\\\\_____________
//____/\\\/////////\\\___________/\\\///\\\__________\/\\\////////\\\__________/\\\\\\\\\\\\\_________
//____\//\\\______\///__________/\\\/__\///\\\________\/\\\______\//\\\________/\\\/////////\\\_______
//______\////\\\________________/\\\______\//\\\_______\/\\\_______\/\\\_______\/\\\_______\/\\\______ 
//__________\////\\\____________\/\\\_______\/\\\_______\/\\\_______\/\\\_______\/\\\\\\\\\\\\\\\_____
//______________\////\\\_________\//\\\______/\\\________\/\\\_______\/\\\_______\/\\\/////////\\\____
//________/\\\______\//\\\_________\///\\\__/\\\__________\/\\\_______/\\\________\/\\\_______\/\\\___
//________\///\\\\\\\\\\\/____/\\\____\///\\\\\/______/\\\_\/\\\\\\\\\\\\/____/\\\_\/\\\_______\/\\\__
//___________\///////////_____\///_______\/////_______\///__\////////////_____\///__\///________\///__
//
//  ------------------------(c) DrMelon 2016 -----------S. O. D. A. --------------------------------
//  ------------------------------------------------------------------------------------------------
//  -- A ROGUELIKE THAT I MADE IN MY SPARE TIME DURING MY FIRST GAMEDEV JOB. THE NAME STANDS FOR: --
//  --                          "(S)OMETHING (O)DD, (D)AYS (A)WAY"                                --
//  ------------------------------------------------------------------------------------------------
//  ------------------------------------------------------------------------------------------------
//
//  Source Code, Ver. 0.0.1: July 2016
//  Dependencies: libtcod
// 
//

#include <libtcod/libtcod.hpp>
#include <memory>
#include "SodaEvent.h"

#include "StateMachine.h"
#include "MenuState.h"

// Application Entry Point: Here we kick off the state machine.

#define CON_WIDTH 160
#define CON_HEIGHT 100

int main()
{
	// Create state machine.
	std::shared_ptr<SODA::StateMachine> stateMachine = std::make_shared<SODA::StateMachine>();

	// Init state machine.
	stateMachine->Initialize();

	// Create root console.
	TCODConsole::initRoot(CON_WIDTH, CON_HEIGHT, "S. O. D. A", false);

	// Create menu state.
	stateMachine->AddState(new SODA::MenuState(stateMachine.get()));
	stateMachine->CurrentState()->Initialize();

	// Main Loop
	while (stateMachine->Running() && !TCODConsole::isWindowClosed())
	{
		// Get deltaTime!
		float deltaTime = TCODSystem::getLastFrameLength();

		// Clear root console.
		TCODConsole::root->clear();

		// Check for events
		TCODSystem::checkForEvent(TCOD_EVENT_ANY, &stateMachine->currentEvent.Key, &stateMachine->currentEvent.Mouse);

		stateMachine->Update(deltaTime);
		stateMachine->Render();

		// Flip root console frame buffer.
		TCODConsole::flush();
	}

	// End
	

	return 0;
}