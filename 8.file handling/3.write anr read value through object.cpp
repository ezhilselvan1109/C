// To read and write values through Book object.
#include<iostream>
#include<fstream>
using namespace std;
class book{
	int book_id;
	string book_name,book_genre;
	public:
		void set_bookdata(){
			cout<<"Enter the book id no :";
			cin>>book_id;
			cin.ignore();
			cout<<"Enter the book name :";
			getline(cin,book_name);
			cout<<"Enter the book genre :";
			cin>>book_genre;
		}
		void display()
		{
			cout<<"Book id_no :"<<book_id<<endl;
			cout<<"Book Name :"<<book_name<<endl;
			cout<<"Book Genre :"<<book_genre<<endl;
			
		}
};
int main()
{
	book book_information;
	int record_number;
	cout<<"Enter the number of records that you want to store:";
  	cin>>record_number;
	ofstream file("3.book_info.txt",ios::out|ios::app);
	for(int i=0;i<record_number;i++){
       book_information.set_bookdata();
	   file.write((char *)&book_information,sizeof(book_information));
    }
	file.close();
	
	ifstream getfile("3.book_info.txt",ios::in);
	while(getfile.read((char *)&book_information,sizeof(book_information))){
	book_information.display();
   } 
   getfile.close();
	
	
	
}