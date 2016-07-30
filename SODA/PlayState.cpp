//
// @Author: J Brown (@DrMelon)
// 2016

#include "PlayState.h"
#include "SpacePlayer.h"

namespace SODA
{
	PlayState::PlayState(StateMachine* parent)
	{
		// Set parent state machine.
		myParent = parent;

		// Create console
		stateConsole = std::make_shared<TCODConsole>(PLAY_CON_WIDTH, PLAY_CON_HEIGHT);

		// Init entity list with blank ent

		thePlayer = std::make_shared<SpacePlayer>(10, 10);
		thePlayer->AddChild(std::make_shared<SpacePlayer>(20, 20));
		entityList.push_back(std::dynamic_pointer_cast<Entity, SpacePlayer>(thePlayer));
	}

	void PlayState::Initialize()
	{
		// Init menu.
	}

	void PlayState::Render()
	{
		// Clear 
		stateConsole->clear();

		// Draw entities
		for (auto ent : entityList)
		{
			ent->Render(stateConsole.get());
		}

		// Blit to state machine console
		TCODConsole::blit(stateConsole.get(), 0, 0, PLAY_CON_WIDTH, PLAY_CON_HEIGHT, myParent->stateMachineConsole, 0, 0);
	}

	void PlayState::Update(float deltaTime, SODA::Event currentEvent)
	{
		// Update all entities
		for (auto ent : entityList)
		{
			ent->Update(deltaTime, currentEvent);
		}

		// get sub-player child ent
		auto list = thePlayer->GetChildrenOfType(SODA_TYPE_TO_STRING(SpacePlayer));
		if (list.size() < 1)
		{
			thePlayer->WorldPosition.x = 60;
		}
	}

	void PlayState::OnPause()
	{

	}

	void PlayState::OnResume()
	{

	}

}