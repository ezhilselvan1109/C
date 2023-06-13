//To encrypt and decrypt Files.

#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream getfile_1("2.file_1.txt",ios::in);
	ofstream file_1("2.encrpt_file.txt",ios::out);
	ofstream file_2("3.decrpt_file.txt",ios::out);
	char character;
	while(getfile_1>>noskipws>>character){
		file_1<<(char)(character+2);
	}
	getfile_1.close();
	file_1.close();
	ifstream getfile_2("2.encrpt_file.txt",ios::in);
	while(getfile_2>>noskipws>>character){
		file_2<<(char)(character-2);
	}
	file_2.close();
}