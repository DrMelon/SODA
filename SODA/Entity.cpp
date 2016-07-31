#include "Entity.h"

namespace SODA
{
	std::vector<std::shared_ptr<Entity>> Entity::GetChildren()
	{
		return children;
	}
	
	std::vector<std::shared_ptr<Entity>> Entity::GetChildrenOfType(std::string type)
	{
		std::vector<std::shared_ptr<Entity>> filteredList;
		for (auto ent : children)
		{
			if (ent->GetType() == type)
			{
				filteredList.push_back(ent);
			}
		}

		return filteredList;
	}

	bool Entity::HasChildOfType(std::string type)
	{
		return(GetChildrenOfType(type).size() > 0);
	}

	void Entity::AddChild(std::shared_ptr<Entity> newChild)
	{
		children.push_back(newChild);
	}

	void Entity::UpdateChildren(float deltaTime, SODA::Event currentEvent)
	{
		for (auto ent : children)
		{
			ent->Update(deltaTime, currentEvent);
		}
	}

	void Entity::RenderChildren(TCODConsole* console)
	{
		for (auto ent : children)
		{
			ent->Render(console);
		}
	}
}
