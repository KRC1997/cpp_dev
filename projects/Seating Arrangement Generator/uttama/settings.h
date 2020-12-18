# ifndef _SETTINGS_H_
# define _SETTINGS_H_

# include "universal.h"

using namespace std;

# define NUMBER_OF_grades 12
# define DEFAULT_GRADE_MAX 15

void flush_stream ();

class PROFILE{
public:
	char name[50];
	int number_of_grades;
	GRADE Grade[DEFAULT_GRADE_MAX];

	void update_NUMBER_OF_GRADES (){
		while (1){
			system ("cls");
			cout<<"\n\n\t====================================(MAXIMUM 15)";
			cout<<"\n\t|Number of grades: "<<number_of_grades;
			cout<<"\n\t|Enter new value: ";
			int x;
			cin>>x;
			cout<<"\nSave and exit?(y/n): ";
			char ch = 'a';
			cin>>ch;
			if (ch == 'y' || ch == 'Y'){
				number_of_grades= x;
				flush_stream ();
				break;
			}
			else if (ch == 'n' || ch == 'N'){
				flush_stream ();
				break;
			}
			else {
				continue;
			}
		}
	}

	void update_SECTIONS (){
		system ("cls");
		int pointer = 0;
		char ch = '0';
		while (1){
			cout<<"\n\n\t====================================";
			cout<<"\n\tPress Enter to choose\n";
			for (int i = 0; i < number_of_grades; i++){
				if (pointer == i){
					cout<<"             ->\t|Class: "<<Grade[i].grade<<"\n";
				}
				else{
					cout<<"\t\t|Class: "<<Grade[i].grade<<"\n";
				}
			}
			ch = _getch();

			/*
			ASCII of arrow keys
				up arrow: 72
				down arrow: 80
			*/
			if (ch == (char)72){
				if(pointer == 0)
					pointer = number_of_grades-1;
				else
					pointer--;
			}
			else if (ch == (char)80){
				if(pointer != number_of_grades-1)
					pointer++;
				else
					pointer = 0;
			}
			else if (ch == (char)13){
				system("cls");
				Grade[pointer].updateSECTIONS();
				break;
			}
			system("cls");
		}
	}

	void update_COLUMNS (){
		system ("cls");
		int pointer = 0;
		char ch = '0';
		while (1){
			cout<<"\n\n\t====================================";
			cout<<"\n\tPress Enter to choose\n";
			for (int i = 0; i < number_of_grades; i++){
				if (pointer == i){
					cout<<"             ->\t|Class: "<<Grade[i].grade<<"\n";
				}
				else{
					cout<<"\t\t|Class: "<<Grade[i].grade<<"\n";
				}
			}
			ch = _getch();

			/*
			ASCII of arrow keys
				up arrow: 72
				down arrow: 80
			*/
			if (ch == (char)72){
				if(pointer == 0)
					pointer = number_of_grades-1;
				else
					pointer--;
			}
			else if (ch == (char)80){
				if(pointer != number_of_grades-1)
					pointer++;
				else
					pointer = 0;
			}
			else if (ch == (char)13){
				system("cls");
				Grade[pointer].updateCOLUMNS();
				break;
			}
			system("cls");
		}
	}

	void update_ROWS (){
		system ("cls");
		int pointer = 0;
		char ch = '0';
		while (1){
			cout<<"\n\n\t====================================";
			cout<<"\n\tPress Enter to choose\n";
			for (int i = 0; i < number_of_grades; i++){
				if (pointer == i){
					cout<<"             ->\t|Class: "<<Grade[i].grade<<"\n";
				}
				else{
					cout<<"\t\t|Class: "<<Grade[i].grade<<"\n";
				}
			}
			ch = _getch();

			/*
			ASCII of arrow keys
				up arrow: 72
				down arrow: 80
			*/
			if (ch == (char)72){
				if(pointer == 0)
					pointer = number_of_grades-1;
				else
					pointer--;
			}
			else if (ch == (char)80){
				if(pointer != number_of_grades-1)
					pointer++;
				else
					pointer = 0;
			}
			else if (ch == (char)13){
				system("cls");
				Grade[pointer].updateROWS();
				break;
			}
			system("cls");
		}
	}

	void update_SEATS_PER_TABLE (){
		system ("cls");
		int pointer = 0;
		char ch = '0';
		while (1){
			cout<<"\n\n\t====================================";
			cout<<"\n\tPress Enter to choose\n";
			for (int i = 0; i < number_of_grades; i++){
				if (pointer == i){
					cout<<"             ->\t|Class: "<<Grade[i].grade<<"\n";
				}
				else{
					cout<<"\t\t|Class: "<<Grade[i].grade<<"\n";
				}
			}
			ch = _getch();

			/*
			ASCII of arrow keys
				up arrow: 72
				down arrow: 80
			*/
			if (ch == (char)72){
				if(pointer == 0)
					pointer = number_of_grades-1;
				else
					pointer--;
			}
			else if (ch == (char)80){
				if(pointer != number_of_grades-1)
					pointer++;
				else
					pointer = 0;
			}
			else if (ch == (char)13){
				system("cls");
				Grade[pointer].updateSEATSPERTABLE();
				break;
			}
			system("cls");
		}
	}

	void update_STUDENTS (){
		system ("cls");
		int pointer = 0;
		char ch = '0';
		while (1){
			cout<<"\n\n\t====================================";
			cout<<"\n\tPress Enter to choose\n";
			for (int i = 0; i < number_of_grades; i++){
				if (pointer == i){
					cout<<"             ->\t|Class: "<<Grade[i].grade<<"\n";
				}
				else{
					cout<<"\t\t|Class: "<<Grade[i].grade<<"\n";
				}
			}
			ch = _getch();

			/*
			ASCII of arrow keys
				up arrow: 72
				down arrow: 80
			*/
			if (ch == (char)72){
				if(pointer == 0)
					pointer = number_of_grades-1;
				else
					pointer--;
			}
			else if (ch == (char)80){
				if(pointer != number_of_grades-1)
					pointer++;
				else
					pointer = 0;
			}
			else if (ch == (char)13){
				system("cls");
				Grade[pointer].updateSTUDENTS();
				break;
			}
			system("cls");
		}
	}
};

void WRITE_DEFAULT_PROFILE (PROFILE &object);
void LOAD_DEFAULT_PROFILE (PROFILE &object);
void settings (PROFILE &object);
void create_arrangements (PROFILE &object);

# endif _SETTINGS_H_