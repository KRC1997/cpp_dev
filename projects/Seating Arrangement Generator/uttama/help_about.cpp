# include "universal.h"

using namespace std;

void help (){
/*
	system("cls");
	cout<<"\n\n\t\tUNDER DEVELOPMENT";
*/
	fstream file;
	file.open("help.txt", ios::in);
	if(!file){
		cout<<"help file not found";
		return;
	}
	char ch;
	while (!file.eof()){
		file.get(ch);
		cout<<ch;
	}
	cout<<"Press ANY key to return: ";
	file.close();
}

void about (){
/*
	system("cls");
	cout<<"\n\n\t\tUNDER DEVELOPMENT";
*/
	fstream file;
	file.open("about.txt", ios::in);
	if(!file){
		cout<<"about file not found";
		return;
	}
	char ch;
	while (!file.eof()){
		file.get(ch);
		cout<<ch;
	}
	cout<<"Press ANY key to return: ";
	file.close();
}