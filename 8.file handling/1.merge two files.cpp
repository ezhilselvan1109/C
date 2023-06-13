// To merge two files to third File.

#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream getfile_1("1.file_1.txt",ios::in);
	ifstream getfile_2("1.file_2.txt",ios::in);
	ofstream file_3("1.file_3.txt",ios::out);
	string name;
	while(getline(getfile_1,name)){
		cout<<name<<endl;
		file_3<<name<<endl;
	}
	while(getline(getfile_2,name)){
		cout<<name<<endl;
		file_3<<name<<endl;
	}
	getfile_1.close();
	getfile_2.close();
	file_3.close();
}