# include "universal.h"

using namespace std;

char MAIN_MENU[][20] = {"CREATE ARRANGEMENT", "HELP", "ABOUT", "SETTINGS", "EXIT"};
char HEAD[20] = {"SEAT ARRANGER 1.0"};
char FOOT[]={"PLEASE POINT TO CHOICE"};
PROFILE Default;

int manager (int choice){
	if (choice == 0){
		create_arrangements(Default);
		return 0;
	}
	else if (choice == 1){
		help();
		return 0;
	}
	else if (choice == 2){
		about();
		return 0;
	}
	else if (choice == 3){
		settings(Default);
		return 2;
	}
	else if (choice == 4){
		return 1;
	}
	else{
		return 0;
	}
}

void main (){
	LOAD_DEFAULT_PROFILE (Default);

	char **ptr = new char *[5];
	for (int i = 0; i < 5; i++)
		ptr[i] = MAIN_MENU[i];

menu:		//goto tag
	int k = manager(Menu (ptr, 5, HEAD, FOOT));
	if (k == 0){
		_getch();
		goto menu;
	}
	else if (k == 2){
		goto menu;
	}
	else{
		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\t\t\tThank you for using our services!!";
		cout<<"\n\t\t\t      Hope to see you again!";
	}
	_getch();
	delete [] ptr;
}
