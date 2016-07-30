//
// @Author: J Brown (@DrMelon)
// 2016

#ifndef _SODA_ENTITY_SPACE_PLAYER_H_
#define _SODA_ENTITY_SPACE_PLAYER_H_

// This is the player class, if we're playing in space.

#include "Entity.h"
#include "VectorMath.h"

namespace SODA
{
	// make a subclass of player, which will be a sub of camerarendered entity, for camera offset ops later?
	class SpacePlayer : public Entity
	{
		public:
			SODA_DECLARE_ENTITY(SpacePlayer);

			SpacePlayer();
			SpacePlayer(int startx, int starty);

			Vector2<int> WorldPosition;
			Vector2<int> ScreenPosition;

			void Update(float deltaTime, SODA::Event currentEvent) override;
			void Render(TCODConsole* console) override;

			


		private:
			void SpacePlayer::HandleInput(SODA::Event currentEvent);
			void TakeStep(int x, int y);
			
	};
}


#endif
