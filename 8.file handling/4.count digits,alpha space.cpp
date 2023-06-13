// To count digits, alphabets & spaces and display all the count.

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ofstream file("4.sample_file.txt",ios::out);
	file<<"In this file there are many digits like 1,2,3 and spaces"<<endl;
	file.close();
	int digit_count =0,alphabet_count=0,space_count=0;
	ifstream getfile("4.sample_file.txt",ios::in);
	char character;
	while(getfile>>noskipws>>character){
		if(character==' '){
			space_count++;
		}
		else if(character>='0'&&character<='9'){
			digit_count++;
		}
		else if((character>='A' && character<='Z')||(character>='a' && character<='z')){
			alphabet_count++;
		}
	}
	cout<<"space count :"<<space_count<<endl;
	cout<<"digit count :"<<digit_count<<endl;
	cout<<"alphabet count :"<<alphabet_count<<endl;
	
}