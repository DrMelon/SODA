//
// @Author: J Brown (@DrMelon)
// 2016

#ifndef _SODA_PLAYSTATE_H_
#define _SODA_PLAYSTATE_H_

#include <memory>
#include <string>

#include "IState.h"
#include "SodaEvent.h"
#include "StateMachine.h"
#include "Entity.h"
#include "SpacePlayer.h"

namespace SODA
{
	// Constants
	static const int PLAY_CON_WIDTH = 160;
	static const int PLAY_CON_HEIGHT = 100;

	// Whoa! The gameplay lives here. Wow.
	// Pretty crazy, right?
	class PlayState : public IState
	{
		public:
			PlayState(StateMachine* parent);
			void Initialize() override;
			void Update(float deltaTime, SODA::Event currentEvent) override;
			void Render() override;
			void OnPause() override;
			void OnResume() override;

			StateMachine* myParent;

			std::shared_ptr<TCODConsole> stateConsole;

			// entity list
			std::vector<std::shared_ptr<Entity>> entityList;
			Entity* entityListEnt;

		private:
			// The player.
			std::shared_ptr<SpacePlayer> thePlayer;
			

	};
}

#endif
