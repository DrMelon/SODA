//
// @Author: J Brown (@DrMelon)
// 2016

#ifndef _SODA_ENTITY_H_
#define _SODA_ENTITY_H_

#include <string>
#include <memory>
#include "SodaEvent.h"
#include <vector>

// The entity class exists to handle all game entities.
// An entity may have child entities, and it may also have components.

// This macro allows the typename of an entity to be used as a filter for finding it.
#define SODA_DECLARE_ENTITY(x) \
	private: const std::string Type = #x; \
	public: inline virtual std::string GetType() { return Type; };

// And this one lets you pass in a typename to find stuff with
#define SODA_TYPE_TO_STRING(x) \
	#x

namespace SODA
{
	class Entity
	{
		public:
			virtual void Update(float deltaTime, SODA::Event currentEvent) = 0;
			virtual void Render(TCODConsole* console) = 0;

			SODA_DECLARE_ENTITY(Entity);

			// Children
			virtual std::vector<std::shared_ptr<Entity>> GetChildren();

			virtual std::vector<std::shared_ptr<Entity>> GetChildrenOfType(std::string type);
			virtual bool HasChildOfType(std::string type);

			virtual void AddChild(std::shared_ptr<Entity> newChild);

			virtual void UpdateChildren(float deltaTime, SODA::Event currentEvent);
			virtual void RenderChildren(TCODConsole* console);

		private:
			std::vector<std::shared_ptr<Entity>> children;

	};

}

#endif