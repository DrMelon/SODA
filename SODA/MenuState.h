//
// @Author: J Brown (@DrMelon)
// 2016

#ifndef _SODA_MENUSTATE_H_
#define _SODA_MENUSTATE_H_

#include <memory>
#include <string>

#include "IState.h"
#include "StateMachine.h"

namespace SODA
{

	static const int MENU_CON_WIDTH = 160;
	static const int MENU_CON_HEIGHT = 100;

	static const std::string VERSION = "0.0.1";
	static const std::string VERSION_FLAVOUR = "Salt & Vinegar Sticks at 3 in the Morning";
	static const std::string TITLE = "=========  Something Odd, Days Away   =========";
	static const std::string SUBTITLE = "A Roguelike Adventure for your Personal Computer!";
	static const std::string COPYRIGHT = "(c) 2016 J. Brown (@DrMelon)";

	class MenuState : public IState
	{
		public:
			MenuState(StateMachine* parent);
			void Initialize() override;
			void Update(float deltaTime, SODA::Event currentEvent) override;
			void Render() override;
			void OnPause() override;
			void OnResume() override;

			StateMachine* myParent;

			std::shared_ptr<TCODConsole> menuConsole;

		private:
			void DrawTitle();

	};

}

#endif