//
// @Author: J Brown (@DrMelon)
// 2016

#ifndef _SODA_ENTITY_MANAGER_H_
#define _SODA_ENTITY_MANAGER_H_

#include "Entity.h"

namespace SODA
{

	// The Entity Manager is itself an entity! It doesn't do much other than update/render its child entities.

	class EntityManager : public Entity
	{
		public:
			void Update(float deltaTime, SODA::Event currentEvent) override;
			void Render(TCODConsole* console) override;

		private:
	};

}

#endif