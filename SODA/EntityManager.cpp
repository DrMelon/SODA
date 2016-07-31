//
// @Author: J Brown (@DrMelon)
// 2016

#include "EntityManager.h"

namespace SODA
{

	void EntityManager::Update(float deltaTime, SODA::Event currentEvent)
	{
		UpdateChildren(deltaTime, currentEvent);
	}

	void EntityManager::Render(TCODConsole* console)
	{
		RenderChildren(console);
	}

}