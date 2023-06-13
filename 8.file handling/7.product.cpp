// To read and write Product details using binary files.

#include<iostream>
#include<fstream>
using namespace std;
class product{
	int product_id;
	float product_price;
	string product_name,product_type,product_code;
	public:
		void set_productdata(){
			cout<<"Enter the product id :";
			cin>>product_id;
			cin.ignore();
			cout<<"Enter the product name :";
			getline(cin,product_name);
			cout<<"Enter the price per unit :";
			cin>>product_price;
			cin.ignore();
			cout<<"Enter the product type :";
			cin>>product_type;
			cout<<"Enter the product barcode :";
			cin>>product_code;
		}
		void display(){
			cout<<"Product  ID :"<<product_id<<endl;
			cout<<"Product Name :"<<product_name<<endl;
			cout<<"Product price per unit :"<<product_price<<endl;
			cout<<"Product type :"<<product_type<<endl;
			cout<<"Product barcode :"<<product_code<<endl;
		}
};
int main()
{
	product product_details;
	/*int records;
	cout<<"Enter the number that you want store :";
	cin>>records;
	ofstream file("7.product_details.bin",ios::binary|ios::out|ios::app);
	for(int i=0;i<records;i++){
		product_details.set_productdata();
		file.write((char *)&product_details,sizeof(product_details));
	}
	file.close(); */
	ifstream getline("7.product_details.bin",ios::in|ios::binary);
	while(getline.read((char *)&product_details,sizeof(product_details))){
		product_details.display();
	}
	}