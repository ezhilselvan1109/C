// Read log file from our system and display it.

#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream file("log_file.txt",ios::in);
	char character;
	while(file.get(character)){
		cout<<character;
	}
	file.close();
}