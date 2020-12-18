# include "universal.h"

using namespace std;

/*
	function to display a menu of given options in array and return selected option
*/
int Menu (char **arr, int rows){
	system ("cls");
	int pointer = 0;
	char ch = '0';
	while (1){
		cout<<"\n\tPress Enter to choose\n";
		for (int i = 0; i < rows; i++){
			if (pointer == i){
				cout<<"             ->\t|"<<arr[i]<<"\n";
			}
			else{
				cout<<"\t\t|"<<arr[i]<<"\n";
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
				pointer = rows-1;
			else
				pointer--;
		}
		else if (ch == (char)80){
			if(pointer != rows-1)
				pointer++;
			else
				pointer = 0;
		}
		else if (ch == (char)13){
			system("cls");
			return pointer;
			break;
		}
		system("cls");
	}
	return pointer;
}

int Menu (char **arr, int rows, char *header){
	system ("cls");
	int pointer = 0;
	char ch = '0';
	while (1){
		cout<<"\n\t"<<header<<"\n\t";
		for (int i = 0; i < strlen(header); i++)
			cout<<"--";
		cout<<"\n";
		for (int i = 0; i < rows; i++){
			if (pointer == i){
				cout<<"             ->\t|"<<arr[i]<<"\n";
			}
			else{
				cout<<"\t\t|"<<arr[i]<<"\n";
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
				pointer = rows-1;
			else
				pointer--;
		}
		else if (ch == (char)80){
			if(pointer != rows-1)
				pointer++;
			else
				pointer = 0;
		}
		else if (ch == (char)13){
			system("cls");
			return pointer;
			break;
		}
		system("cls");
	}
	return pointer;
}

int Menu (char **arr, int rows, char *header, char *footer){
	system ("cls");
	int pointer = 0;
	char ch = '0';
	while (1){
		cout<<"\n\t"<<header<<"\n\t";
		for (int i = 0; i < strlen(header); i++)
			cout<<"--";
		cout<<"\n";
		for (int i = 0; i < rows; i++){
			if (pointer == i){
				cout<<"             ->\t|"<<arr[i]<<"\n";
			}
			else{
				cout<<"\t\t|"<<arr[i]<<"\n";
			}
		}
		cout<<"\n\t"<<footer<<"\n";
		ch = _getch();

		/*
		ASCII of arrow keys
			up arrow: 72
			down arrow: 80
		*/
		if (ch == (char)72){
			if(pointer == 0)
				pointer = rows-1;
			else
				pointer--;
		}
		else if (ch == (char)80){
			if(pointer != rows-1)
				pointer++;
			else
				pointer = 0;
		}
		else if (ch == (char)13){
			system("cls");
			return pointer;
			break;
		}
		system("cls");
	}
	return pointer;
}