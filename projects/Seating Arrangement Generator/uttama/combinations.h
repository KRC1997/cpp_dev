# ifndef _COMBINATIONS_H_
# define _COMBINATIONS_H_

# include "universal.h"

using namespace std;

struct STUDENT{
	int CLASS;
	char SEC;
	int ROLL_NO;
};

class CLASSroom{
public:
	int grade;
	char section;
	int rows;
	int columns;
	int seatspertable;
	int numberofstudents;
	STUDENT **arrangement;

	CLASSroom (){
		grade = 0;
		section = '#';
		rows = 5;
		columns = 5;
		seatspertable = 2;
		numberofstudents = 40;
		arrangement = NULL;
	}

	void prepare_seating (){
		arrangement = new STUDENT *[rows];
		for (int i = 0; i < rows; i++){
			arrangement[i] = new STUDENT [columns*seatspertable];
		}
	}

	CLASSroom (int g, char s, int r, int c, int spt, int nos) {
		grade = g;
		section = s;
		rows = r;
		columns = c;
		seatspertable = spt;
		numberofstudents = nos;
		prepare_seating ();
	}

	void copy_details (STUDENT object, int x_pos, int y_pos){
		arrangement[x_pos][y_pos].CLASS = object.CLASS;
		arrangement[x_pos][y_pos].ROLL_NO = object.ROLL_NO;
		arrangement[x_pos][y_pos].SEC = object.SEC;
	}

	void display_room (ofstream &file){
		for (int i = 0; i < 80; i ++){
			cout<<"=";
			file<<"=";
		}
		cout<<"\nCLASS: "<<grade<<"\tSECTION: "<<section<<"\n";
		file<<"\nCLASS: "<<grade<<"\tSECTION: "<<section<<"\n";
		for (int i = 0; i < 80; i ++){
			cout<<"=";
			file<<"=";
		}
		cout<<"\n";
		file<<"\n";
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < columns*seatspertable; j++){
				cout<<"| "<<arrangement[i][j].CLASS<<"\t";
				file<<"| "<<arrangement[i][j].CLASS<<"\t";
			}
			cout<<"|\n";
			file<<"|\n";
			for (int j = 0; j < columns*seatspertable; j++){
				cout<<"|"<<arrangement[i][j].SEC<<"  "<<arrangement[i][j].ROLL_NO<<"\t";
				file<<"|"<<arrangement[i][j].SEC<<"  "<<arrangement[i][j].ROLL_NO<<"\t";
			}
			cout<<"|\n";
			file<<"|\n";
		}
	}
};

void SWAP_STUDENT (STUDENT &ob1, STUDENT &ob2);

# endif