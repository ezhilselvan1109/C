//  C++ program to manipulate file pointers.

#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream file("8.sample.txt",ios::out);
	file<<"this is file for question 8"<<endl;
	file.seekp(5,ios::beg);
	file<<"this is the overriding sentence from 10th position";
	int position = file.tellp();
	file.seekp(position+1,ios::beg);
	file<<"new things are added at end";
	file.close();
	ifstream getfile("8.sample.txt",ios::in);
	char character;
	while(getfile.get(character)){
		cout<<character;
	}
}