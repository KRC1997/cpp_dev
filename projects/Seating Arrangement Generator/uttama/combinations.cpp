# include "universal.h"

using namespace std;

int global = 0;

void SWAP_STUDENT (STUDENT &ob1, STUDENT &ob2){
	STUDENT temp = ob1;
	ob1 = ob2;
	ob2 = temp;
}

int index_present (int *arr, int size, int index){
	for (int i = 0; i < size; i++){
		if (arr[i] == index)
			return 1;
	}
	return 0;
}

void delete_index (int *arr, int &size, int index){
	for (int i = 0; i < size; i++){
		if (arr[i] == index){
			for (int j = i; j < size-1; j++){
				arr[j] = arr[j+1];
			}
			break;
		}
	}
	size--;
}

void sort_array (int *arr, int size){
	//simple selection sort
	int min = 0;
	int min_index = 0;
	for (int i = 0; i < size-1; i++){
		min = arr[i];
		min_index = i;
		for (int j = i; j < size; j++){
			if (arr[j] < min){
				min = arr[j];
				min_index = j;
			}
		}
		int temp = arr[min_index];
		arr[min_index] = arr[i];
		arr[i] = temp;
	}
}

int MAX_NUMBER_STUDENTS (int *arr, int size, PROFILE &object){
	int result = 0;
	int temp = 0;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < object.number_of_grades; j++){
			if (arr[i] == object.Grade[j].grade){
				for (int k = 0; k < object.Grade[j].number_of_sections; k++){
					result += object.Grade[j].Classroom[k].output_students();
				}
				break;
			}
		}
		if (temp < result){
			temp = result;
			result = 0;
		}
	}
	return temp;
}

void fill_student_array (int *arr, STUDENT ** arry, int row_size, int column_size, PROFILE &object){
	int arry_index = 0;
	for (int i = 0; i < row_size; i++){
		for (int j = 0; j < object.number_of_grades; j++){
			if (arr[i] == object.Grade[j].grade){
				for (int k = 0; k < object.Grade[j].number_of_sections; k++){
					for (int l = 0; l < object.Grade[j].Classroom[k].no_of_students; l++){
						arry[i][arry_index].CLASS = object.Grade[j].grade;
						arry[i][arry_index].ROLL_NO = l+1;
						arry[i][arry_index].SEC = object.Grade[j].Classroom[k].output_ROOM_section();
						arry_index++;
					}
				}
			}
		}
		arry_index = 0;
	}
}

void display_student_array (STUDENT **ary, int row, int column){
	int k = 0;
	for (int i = 0; i < row; i++){
		while (k < column){
			for (int j = k; j < k+5 && j < column; j++){
				if (ary[i][j].ROLL_NO != 0){
					cout<<"Class: "<<ary[i][j].CLASS<<"\t";
				}
			}
			cout<<"\n";
			for (int j = k; j < k+5 && j < column; j++){
				if (ary[i][j].ROLL_NO != 0){
					cout<<"R: "<<ary[i][j].ROLL_NO;
					cout<<" S: "<<ary[i][j].SEC<<"\t";
				}
			}
			cout<<"\n\n";
			k+=5;
		}
		k = 0;
	}
}

int student_array_size (STUDENT *arr){
	/*
	int size = 0;
	for (int i = 0; i < global; i++){
		if (arr[i].ROLL_NO != 0)
			size++;
	}
	return size;
	*/
	return global;
}

void permutate_array (STUDENT *arr){
	srand (time(NULL));
	int size = student_array_size(arr);
	for (int i = 0; i < size; i++){
		int r = rand () % size;
		SWAP_STUDENT (arr[i], arr[r]);
	}
}

void permutate_array_index (STUDENT **arr, int size){
	srand (time(NULL));
	for (int i = 0; i < size; i++){
		int r = rand () % size;
		STUDENT *temp = arr[i];
		arr[i] = arr[r];
		arr[r] = temp;
	}
}

int get_no_of_rooms (int *arr, int size, PROFILE &object){
	int rooms = 0;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < object.number_of_grades; j++){
			if (arr[i] == object.Grade[j].grade){
				rooms += object.Grade[j].number_of_sections;
			}
		}
	}
	return rooms;
}

void initialize_student_array (STUDENT **ary, int row, int column){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			ary[i][j].CLASS = 0;
			ary[i][j].ROLL_NO = 0;
			ary[i][j].SEC = '#';
		}
	}
}

void prepare_classes (PROFILE &object, int *arr, int size, CLASSroom *ROOMS, int NUMBER_OF_ROOMS){
	int index = 0;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < object.number_of_grades; j++){
			if (arr[i] == object.Grade[j].grade){
				for (int k = 0; k < object.Grade[j].number_of_sections; k++){
					ROOMS[index].grade = object.Grade[j].grade;
					ROOMS[index].columns = object.Grade[j].Classroom[k].output_ROOM_columns();
					ROOMS[index].rows = object.Grade[j].Classroom[k].output_ROOM_rows();
					ROOMS[index].numberofstudents = object.Grade[j].Classroom[k].output_students();
					ROOMS[index].seatspertable = object.Grade[j].Classroom[k].output_ROOM_seats_per_table();
					ROOMS[index].section = object.Grade[j].Classroom[k].output_ROOM_section();
					ROOMS[index].prepare_seating();
					initialize_student_array (ROOMS[index].arrangement, ROOMS[index].rows, ROOMS[index].columns*ROOMS[index].seatspertable);
					index++;
				}
			}
		}
	}
}

void fill_classrooms (CLASSroom *ROOM, int NUMBER_OF_ROOMS, STUDENT **arry, int row){
	if (row == 0){
		return;
	}

	int indicex = 0;
	int indicey = 0;
	int flag = 0;

	int arry_index1 = 0;
	int arry_index2 = 1;
	int a = 0;
	if (row == 1)
		arry_index2 = 0;

	int room_index = 0;
	while (room_index < NUMBER_OF_ROOMS){
		a = 0;
		for (int i = 0; i < ROOM[room_index].columns*ROOM[room_index].seatspertable; i++){
			for (int j = a; j < ROOM[room_index].rows; j+=2){
				ROOM[room_index].copy_details(arry[arry_index1][indicex++], j, i);
				if (indicex >= student_array_size(arry[arry_index1])){
					indicex = 0;
					arry_index1 += 2;
					if (arry_index1 >= row){
						flag = 55;
						break;
					}
				}
				if (flag == 55){
					break;
				}
			}
			if (flag == 55){
				break;
			}
			a = (a == 0)?1:0;
		}

		flag = 0;
		a = 1;
		if (row == 1)
			indicey = indicex;
		for (int i = 0; i < ROOM[room_index].columns*ROOM[room_index].seatspertable; i++){
			for (int j = a; j < ROOM[room_index].rows; j+=2){
				ROOM[room_index].copy_details(arry[arry_index2][indicey++], j, i);
				if (indicey >= student_array_size(arry[arry_index2])){
					indicey = 0;
					arry_index2 += 2;
					if (arry_index2 >= row){
						flag = 55;
						break;
					}
				}
				if (flag == 55){
					break;
				}
			}
			if (flag == 55){
				break;
			}
			a = (a == 0)?1:0;
		}
		room_index++;
		if (arry_index1 >= row || arry_index2 >= row){
			break;
		}
	}
}

void display_classrooms (CLASSroom *ROOM, int NUMBER_OF_ROOMS){
	system("cls");
	ofstream file;
	file.open ("temp.saf");

	int index = 0;
	while (index < NUMBER_OF_ROOMS){
		ROOM[index].display_room(file);
		cout<<"\n\n";
		index++;
	}
	file.close();
}

void create_arrangements (PROFILE &object){ 
	int arr[DEFAULT_GRADE_MAX]; //defined in settings.h
	int arr_index = 0;

	system ("cls");
	int pointer = 0;
	char ch = '0';
	while (1){
		cout<<"\n\n\t==================================== (** -> item selected)";
		cout<<"\n\tPress Enter to choose classes\n";
		for (int i = 0; i < object.number_of_grades; i++){
			if (pointer == i){
				cout<<"             ->\t|Class: "<<object.Grade[i].grade;
				if (index_present (arr, arr_index, i)){
					cout<<"\t**\n";
				}
				else{
					cout<<"\n";
				}
			}
			else{
				cout<<"\t\t|Class: "<<object.Grade[i].grade;
				if (index_present (arr, arr_index, i)){
					cout<<"\t**\n";
				}
				else{
					cout<<"\n";
				}
			}
		}
		if (pointer == object.number_of_grades){
			cout<<"             ->\t|DONE\n";
		}
		else{
			cout<<"\t\t|DONE\n";
		}
		ch = _getch();

		/*
		ASCII of arrow keys
			up arrow: 72
			down arrow: 80
			enter : 13
		*/
		if (ch == (char)72){
			if(pointer == 0)
				pointer = object.number_of_grades;
			else
				pointer--;
		}
		else if (ch == (char)80){
			if(pointer != object.number_of_grades)
				pointer++;
			else
				pointer = 0;
		}
		else if (ch == (char)13){
			if (pointer == object.number_of_grades){
				break;
			}
			else {
				if (index_present (arr, arr_index, pointer)){
					delete_index (arr, arr_index, pointer);
				}
				else {
					arr[arr_index++] = pointer;
				}
			}
		}
		system("cls");
	}

	sort_array (arr, arr_index);
	for (int i = 0; i < arr_index; i++){
		++arr[i];
	}
	//preparing student array
	STUDENT **ary;
	ary = new STUDENT *[arr_index];
	int &NUMBER_OF_CLASSES = arr_index;
	int max_number_of_students = MAX_NUMBER_STUDENTS (arr, NUMBER_OF_CLASSES, object);
	for (int i = 0; i < NUMBER_OF_CLASSES; i++){
		ary[i] = new STUDENT [max_number_of_students];
	}
	global = max_number_of_students;

	initialize_student_array (ary, NUMBER_OF_CLASSES, max_number_of_students);
	fill_student_array (arr, ary, NUMBER_OF_CLASSES, max_number_of_students, object);
	//display_student_array (ary, arr_index, max_number_of_students);
	//_getch();

	//preparing classrooms
	int NUMBER_OF_ROOMS = get_no_of_rooms (arr, NUMBER_OF_CLASSES, object);
	CLASSroom *ROOMS = new CLASSroom [NUMBER_OF_ROOMS];
	prepare_classes (object, arr, NUMBER_OF_CLASSES, ROOMS, NUMBER_OF_ROOMS);

	//loop begins
	while (1){
		for (int i = 0; i < NUMBER_OF_CLASSES; i++){
			permutate_array (ary[i]);
		}
		permutate_array_index (ary, NUMBER_OF_CLASSES);
		//display_student_array (ary, arr_index, max_number_of_students);
		//_getch();
		//-----------------------------------------------------------all is well till here

		fill_classrooms (ROOMS, NUMBER_OF_ROOMS, ary, NUMBER_OF_CLASSES);
		display_classrooms (ROOMS, NUMBER_OF_ROOMS);

choice:
		cout<<"\nDo You Want ANOTHER Arrangement?(Y/N): ";
		char ch;
		cin>> ch;
		if (ch == 'y' || ch == 'Y'){
			continue;
		}
		else if (ch == 'n' || ch == 'N'){
			cout<<"Do You Want to SAVE to file?(Y/N): ";
			cin>> ch;
			if (ch == 'y' || ch == 'Y'){
				char name[50];
				cout<<"Enter name of file: ";
				flush_stream();
				gets_s(name);
				strcat(name, ".txt");
				ofstream output;
				ifstream input;
				output.open (name);
				input.open ("temp.saf");
				char ch;
				while (!input.eof()){
					ch = input.get();
					output<<ch;
				}
				input.close();
				output.close();
				cout<<"\nYOUR FILE HAS BEEN WRITTEN!!!\n\n\tPRESS ANY KEY TO CONTINUE\n\n";
				break;
			}
			else if (ch == 'n' || ch == 'N'){
				break;
			}
		}
		else{
			goto choice;
		}
	}
	delete [] ROOMS;
}

/*
	code for actual combinatorics
*/
//combination for one class(input taken on the spot)