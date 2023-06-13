// To count words, lines and total size.

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ofstream file("5.sample.txt",ios::out);
	file<<"this is a file for reading the words"<<endl;
	file<<"this is file for reading the lines"<<endl;
	file<<"this is line for counting the total size"<<endl;
	file.close();
	ifstream getfile("5.sample.txt",ios::in);
	char character;
	int word_count=0,line_count=0;
	getfile.seekg(0,ios::end);
	int total_size = getfile.tellg(); 
	getfile.seekg(0,ios::beg);
	while(getfile.get(character)){
		if(character == ' '||character == '\n'){
			word_count++;
		}
	    if(character == '\n'){
			line_count++;
		}
	}
	cout<<"Total size :"<<total_size<<endl;
	cout<<"Word count :"<<word_count<<endl;
	cout<<"line count :"<<line_count<<endl;
}