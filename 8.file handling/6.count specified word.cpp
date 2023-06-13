// To count the occurrence of specified word.

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ofstream file("6.sample_file.txt",ios::out);
	file<<"this is file named the file of file in file pointer"<<endl;
	file.close();
	string name,word;
	cout<<"Enter the word :";
	cin>>word;
	ifstream getfile("6.sample_file.txt",ios::in);
	int count=0;
	while(getfile>>name){
		if(name==word){
			count++;
		}
	}
	cout<<"count of specified word is :"<<count<<endl;
}