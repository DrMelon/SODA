//
// @Author: J Brown (@DrMelon)
// 2016

#include "MenuState.h"

namespace SODA
{
	MenuState::MenuState(StateMachine* parent)
	{
		// Set parent state machine.
		myParent = parent;

		// Create my console window
		menuConsole = std::make_shared<TCODConsole>(MENU_CON_WIDTH, MENU_CON_HEIGHT);
	}

	void MenuState::Initialize()
	{
		// Init menu.
	}

	void MenuState::Render()
	{
		// Clear menu
		menuConsole->clear();

		// Draw on it
		DrawTitle();

		// Blit to state machine console
		TCODConsole::blit(menuConsole.get(), 0, 0, MENU_CON_WIDTH, MENU_CON_HEIGHT, myParent->stateMachineConsole, 0, 0);
	}

	void MenuState::Update(float deltaTime, SODA::Event currentEvent)
	{

	}

	void MenuState::OnPause()
	{

	}

	void MenuState::OnResume()
	{

	}

	// Private Methods
	void MenuState::DrawTitle()
	{
		TCODConsole::setColorControl(TCOD_COLCTRL_1, TCODColor::white, TCODColor::black);
		TCODConsole::setColorControl(TCOD_COLCTRL_2, TCODColor::darkCyan, TCODColor::black);
		TCODConsole::setColorControl(TCOD_COLCTRL_3, TCODColor::yellow, TCODColor::black);
		TCODConsole::setColorControl(TCOD_COLCTRL_4, TCODColor::green, TCODColor::black);

		menuConsole->printEx(MENU_CON_WIDTH / 2, (MENU_CON_HEIGHT / 6) + 0, TCOD_BKGND_SET, TCOD_alignment_t::TCOD_CENTER, ("%c"+TITLE).c_str(), TCOD_COLCTRL_1);
		menuConsole->printEx(MENU_CON_WIDTH / 2, (MENU_CON_HEIGHT / 6) + 1, TCOD_BKGND_SET, TCOD_alignment_t::TCOD_CENTER, SUBTITLE.c_str());
		menuConsole->printEx(MENU_CON_WIDTH / 2, (MENU_CON_HEIGHT / 6) + 2, TCOD_BKGND_SET, TCOD_alignment_t::TCOD_CENTER, ("%c"+COPYRIGHT).c_str(), TCOD_COLCTRL_2);
		std::string VERSION_STRING = "%cVersion: " + VERSION;
		menuConsole->printEx(0, MENU_CON_HEIGHT - 1, TCOD_BKGND_SET, TCOD_alignment_t::TCOD_LEFT, VERSION_STRING.c_str(), TCOD_COLCTRL_4);
		menuConsole->printEx(MENU_CON_WIDTH - 1, MENU_CON_HEIGHT - 1, TCOD_BKGND_SET, TCOD_alignment_t::TCOD_RIGHT, ("%c"+VERSION_FLAVOUR).c_str(), TCOD_COLCTRL_3);
	}
}