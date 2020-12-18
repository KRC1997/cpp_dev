# ifndef _CLASSROOMDETAILS_H_
# define _CLASSROOMDETAILS_H_

# include "universal.h"
using namespace std;

/*
    function prototype
	associated functions
	initial input
	update -> insert new
		   -> delete and insert
	file write
	file read
*/

# define NUMBER_OF_SECTIONS 4
# define SEATS_PER_TABLE 2
# define ROWS 5
# define COLUMNS 5
# define DEFAULT_NO_OF_CLASSROOMS 10
# define DEFAULT_NO_OF_STUDENTS 40

void flush_stream ();

class CLASSROOM{
public:
	int CLASS;
	int no_of_students;
	struct ROOM{
		char section;
		int seats_per_table;
		int rows;
		int columns;
	}object;

	inline void input_CLASS (int x){CLASS = x;}
	inline void input_STUDENTS (int x){no_of_students = x;}
	inline void input_ROOM_section (char x){object.section = x;}
	inline void input_ROOM_seats_per_table (int x){object.seats_per_table = x;}
	inline void input_ROOM_rows (int x){object.rows = x;}
	inline void input_ROOM_columns (int x){object.columns = x;}

	inline int output_CLASS (){return CLASS;}
	inline char output_ROOM_section (){return object.section;}
	inline int output_ROOM_seats_per_table (){return object.seats_per_table;}
	inline int output_ROOM_rows (){return object.rows;}
	inline int output_ROOM_columns (){return object.columns;}
	inline int output_students (){return no_of_students;}

	void update_column (){
		while (1){
			system ("cls");
			cout<<"\n\n\t====================================";
			cout<<"\n\t|Number of Columns: "<<output_ROOM_columns ();
			cout<<"\n\t|Enter new value: ";
			int x;
			cin>>x;
			cout<<"\nSave and exit?(y/n): ";
			char ch = 'a';
			cin>>ch;
			if ((ch == 'y' || ch == 'Y') && x != 0){
				input_ROOM_columns (x);
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

	void update_row (){
		while (1){
			system ("cls");
			cout<<"\n\n\t====================================";
			cout<<"\n\t|Number of Rows: "<<output_ROOM_rows ();
			cout<<"\n\t|Enter new value: ";
			int x;
			cin>>x;
			cout<<"\nSave and exit?(y/n): ";
			char ch = 'a';
			cin>>ch;
			if ((ch == 'y' || ch == 'Y') && x != 0){
				input_ROOM_rows (x);
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

	void update_seats_per_table (){
		while (1){
			system ("cls");
			cout<<"\n\n\t====================================";
			cout<<"\n\t|Number of Rows: "<<output_ROOM_seats_per_table ();
			cout<<"\n\t|Enter new value: ";
			int x;
			cin>>x;
			cout<<"\nSave and exit?(y/n): ";
			char ch = 'a';
			cin>>ch;
			if ((ch == 'y' || ch == 'Y') && x != 0){
				input_ROOM_seats_per_table (x);
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

	void update_students (){
		while (1){
			system ("cls");
			cout<<"\n\n\t====================================";
			cout<<"\n\t|Number of Students: "<<output_students ();
			cout<<"\n\t|Enter new value: ";
			int x;
			cin>>x;
			cout<<"\nSave and exit?(y/n): ";
			char ch = 'a';
			cin>>ch;
			if ((ch == 'y' || ch == 'Y') && x != 0){
				input_STUDENTS (x);
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
};

class GRADE{
	void setup_classrooms (){
		char ch = 'A';
		for (int i = 0; i < number_of_sections; i++){
			Classroom[i].CLASS = grade;
			Classroom[i].object.section = ch;
			Classroom[i].object.rows = ROWS;
			Classroom[i].object.columns = COLUMNS;
			Classroom[i].object.seats_per_table = SEATS_PER_TABLE;
		}
	}

public:
	int grade;
	int number_of_sections;
	CLASSROOM Classroom [DEFAULT_NO_OF_CLASSROOMS];

	inline void input_GRADE (int x){grade = x;}
	inline void input_NUMBER_OF_SECTIONS (int x){number_of_sections = x;}

	inline int output_GRADE (){return grade;}
	inline int output_NUMBER_OF_SECTIONS (){return number_of_sections;}

	void updateSECTIONS (){
		while (1){
			system ("cls");
			cout<<"\n\n\t====================================(MAXIMUM VALUE: 10)";
			cout<<"\n\t|Number of Sections: "<<number_of_sections;
			cout<<"\n\t|Enter new value: ";
			int x;
			cin>>x;
			cout<<"\nSave and exit?(y/n): ";
			char ch = 'a';
			cin>>ch;
			if ((ch == 'y' || ch == 'Y') && x != 0){
				number_of_sections = x;
				setup_classrooms ();
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

	void updateCOLUMNS (){
		system ("cls");
		int pointer = 0;
		char ch = '0';
		while (1){
			cout<<"\n\n\t====================================";
			cout<<"\n\tPress Enter to choose\n";
			for (int i = 0; i < number_of_sections; i++){
				if (pointer == i){
					cout<<"             ->\t|Section: "<<Classroom[i].output_ROOM_section()<<"\n";
				}
				else{
					cout<<"\t\t|Section: "<<Classroom[i].output_ROOM_section()<<"\n";
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
					pointer = number_of_sections-1;
				else
					pointer--;
			}
			else if (ch == (char)80){
				if(pointer != number_of_sections-1)
					pointer++;
				else
					pointer = 0;
			}
			else if (ch == (char)13){
				system("cls");
				Classroom[pointer].update_column();
				break;
			}
			system("cls");
		}
	}

	void updateROWS (){
		system ("cls");
		int pointer = 0;
		char ch = '0';
		while (1){
			cout<<"\n\n\t====================================";
			cout<<"\n\tPress Enter to choose\n";
			for (int i = 0; i < number_of_sections; i++){
				if (pointer == i){
					cout<<"             ->\t|Section: "<<Classroom[i].output_ROOM_section()<<"\n";
				}
				else{
					cout<<"\t\t|Section: "<<Classroom[i].output_ROOM_section()<<"\n";
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
					pointer = number_of_sections-1;
				else
					pointer--;
			}
			else if (ch == (char)80){
				if(pointer != number_of_sections-1)
					pointer++;
				else
					pointer = 0;
			}
			else if (ch == (char)13){
				system("cls");
				Classroom[pointer].update_row();
				break;
			}
			system("cls");
		}
	}

	void updateSEATSPERTABLE (){
		system ("cls");
		int pointer = 0;
		char ch = '0';
		while (1){
			cout<<"\n\n\t====================================";
			cout<<"\n\tPress Enter to choose\n";
			for (int i = 0; i < number_of_sections; i++){
				if (pointer == i){
					cout<<"             ->\t|Section: "<<Classroom[i].output_ROOM_section()<<"\n";
				}
				else{
					cout<<"\t\t|Section: "<<Classroom[i].output_ROOM_section()<<"\n";
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
					pointer = number_of_sections-1;
				else
					pointer--;
			}
			else if (ch == (char)80){
				if(pointer != number_of_sections-1)
					pointer++;
				else
					pointer = 0;
			}
			else if (ch == (char)13){
				system("cls");
				Classroom[pointer].update_seats_per_table();
				break;
			}
			system("cls");
		}
	}

	void updateSTUDENTS (){
		system ("cls");
		int pointer = 0;
		char ch = '0';
		while (1){
			cout<<"\n\n\t====================================";
			cout<<"\n\tPress Enter to choose\n";
			for (int i = 0; i < number_of_sections; i++){
				if (pointer == i){
					cout<<"             ->\t|Section: "<<Classroom[i].output_ROOM_section()<<"\n";
				}
				else{
					cout<<"\t\t|Section: "<<Classroom[i].output_ROOM_section()<<"\n";
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
					pointer = number_of_sections-1;
				else
					pointer--;
			}
			else if (ch == (char)80){
				if(pointer != number_of_sections-1)
					pointer++;
				else
					pointer = 0;
			}
			else if (ch == (char)13){
				system("cls");
				Classroom[pointer].update_students();
				break;
			}
			system("cls");
		}
	}
};

# endif