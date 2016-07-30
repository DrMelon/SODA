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
}
