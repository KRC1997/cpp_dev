# include "universal.h"

using namespace std;

# define DEFAULT_NO_OF_GRADES 12
# define DEFAULT_NO_OF_SECTIONS 4
# define DEFAULT_NO_OF_COLUMNS 5
# define DEFAULT_NO_OF_ROWS 5
# define DEFAULT_NO_OF_SEATS_PER_TABLE 2
# define DEFAULT_STUDENTS 40
# define MENU_SIZE 8

void flush_stream (){
	cin.clear();
	while (cin.get() != '\n') {
		continue;
	}
}

void WRITE_DEFAULT_PROFILE (PROFILE &object){
	fstream file;
	file.open ("defaultprofile.dat", ios::out, ios::binary);
	file.write ((char *)&object, sizeof(object));
	file.close();
}

void LOAD_DEFAULT_PROFILE (PROFILE &object){
	fstream file;
	file.open ("defaultprofile.dat", ios::in, ios::binary);
	if (!file){
		strcpy_s(object.name, "Default\0");
		object.number_of_grades = DEFAULT_NO_OF_GRADES;
		for (int i  = 0; i < object.number_of_grades; i++){
			char ch = 'A';
			object.Grade[i].input_GRADE(i+1);
			object.Grade[i].input_NUMBER_OF_SECTIONS(DEFAULT_NO_OF_SECTIONS);
			for (int j = 0; j < object.Grade[i].number_of_sections; j++){
				object.Grade[i].Classroom[j].input_CLASS(object.Grade[i].grade);
				object.Grade[i].Classroom[j].input_STUDENTS(DEFAULT_STUDENTS);
				object.Grade[i].Classroom[j].input_ROOM_columns(DEFAULT_NO_OF_COLUMNS);
				object.Grade[i].Classroom[j].input_ROOM_rows(DEFAULT_NO_OF_ROWS);
				object.Grade[i].Classroom[j].input_ROOM_seats_per_table(DEFAULT_NO_OF_SEATS_PER_TABLE);
				object.Grade[i].Classroom[j].input_ROOM_section(ch++);
			}
		}
		ofstream file1;
		file1.open ("defaultprofile.dat", ios::binary);
		file1.write ((char *)&object, sizeof(object));
		file1.close();
	}
	else{
		file.read((char *)&object, sizeof(object));
		file.close();
	}
}

void REMOVE_FILE (PROFILE &object){
start:
	system("cls");
	cout<<"\n\n\t====================================";
	cout<<"\n\tAre you sure you want to reset? (y/n): ";
	char ch = _getche ();
	if (ch == 'y' || ch == 'Y'){
		remove ("defaultprofile.dat");
		LOAD_DEFAULT_PROFILE (object);
		cout<<"\n\nSETTINGS RESET";
		_getch();
	}
	else if (ch == 'n' || ch == 'N'){
		return;
	}
	else{
		goto start;
	}
}

int settings_manager (PROFILE &object, int choice){
	if (choice == 0){
		object.update_NUMBER_OF_GRADES ();
		return 0;
	}
	else if (choice == 1){
		object.update_SECTIONS ();
		return 0;
	}
	else if (choice == 2){
		object.update_COLUMNS ();
		return 0;
	}
	else if (choice == 3){
		object.update_ROWS ();
		return 0;
	}
	else if (choice == 4){
		object.update_SEATS_PER_TABLE ();
		return 0;
	}
	else if (choice == 5){
		object.update_STUDENTS ();
		return 0;
	}
	else if (choice == 6){
		REMOVE_FILE (object);
		return 0;
	}
	else if (choice == 7){
		//exit saving changes
		WRITE_DEFAULT_PROFILE(object);
		return 1;
	}
	else{
		return 0;
	}
}

void settings (PROFILE &object){
/*
	system("cls");
	cout<<"\n\n\t\tUNDER DEVELOPMENT";
*/
	char menu[MENU_SIZE][25]={"NUMBER OF CLASSES",
		"NUMBER OF SECTIONS",
		"COLUMNS PER CLASS",
		"ROWS PER CLASS",
		"SEATS PER TABLE",
		"NUMBER OF STUDENTS",
		"RESET DEFAULT SETTINGS",
		"EXIT SAVING CHANGES"};
	char Head[]={"SETTINGS"};
	char Foot[]={"PLEASE POINT TO CHOICE"};
	char **ptr = new char *[MENU_SIZE];
	for (int i = 0; i < MENU_SIZE; i++)
		ptr[i] = menu[i];
menu:
	int flag = settings_manager (object, Menu(ptr, MENU_SIZE, Head, Foot));
	if (flag == 0){
		//_getch();
		goto menu;
	}		
	else{
		return;
	}
}