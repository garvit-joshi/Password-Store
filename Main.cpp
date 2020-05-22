#include<iostream>
#include<fstream>
#include<vector>
#include <cstdlib>
using namespace std;
class Data{
	string Name;
	long long int Password;
	int n;
	public:
	int setValues(){
		cout<<"Please Enter Your Name:";
		getline(cin,Name);
		cout<<"Hello!! "<<Name<<" I will asist you in the process\n";
		cout<<"How Many Passwords Do you want to save:";
		cin>>n;
		cout<<"Please Enter A master password(Integers Only):";
		cin>>Password;
		return n;         
	}
	void getValues(){
		cout<<"Name:"<<Name;
		cout<<"\nNo. Of Passwords:"<<n;
		cout<<"\nMaster Passwords:"<<Password;
	}
};
class Credentials{
	char company[100],username[100],password[100];
	public:
	void setData(){
		cin.ignore();
		cout<<"Enter The Companies Name:";
		cin.get(company,100);
		cin.ignore();
		cout<<"Enter Your Username/Email:";
		cin.get(username,100);
		cout<<"Enter Your Password:";
		cin.ignore();
		cin.get(password,100);
	}
	void printData(){
		cout<<"\nThe Companies Name:"<<company;
		cout<<"\nYour Username/Email:"<<username;
		cout<<"\nYour Password:"<<password<<endl;
	}
};
int main()
{
	int choice,n;
	cout<<"\t\tWelcome To Password Store\n";
	cout<<"Enter Your Choice:\n";
	cout<<"1.New User\n2.Retrive Your Passwords\n3.Exit\n";
	cin>>choice;
	if(choice==1){
		Data D;
		cin.ignore();
		n=D.setValues();
		ofstream ofile1("Data.txt",ios::out|ios::binary|ios::trunc);
		ofile1.write((char*)&D,sizeof(D));
		ofile1.close();
		Credentials a;
		ofstream ofile2("Credentials.txt",ios::out|ios::binary|ios::trunc);
		for(int i=0;i<n;i++){
			a.setData();
			ofile2.write((char*)&a,sizeof(a));
		}
		ofile2.close();
	}
	else if(choice==2){
		Data D;
		ifstream ifile1("Data.txt",ios::in|ios::binary);
		ifile1.read((char*)&D,sizeof(D));
		D.getValues();
		ifile1.close();
		Credentials a;
		ifstream ifile2("Credentials.txt",ios::in|ios::binary);
		ifile2.seekg(0);
		while(ifile2.read((char*)&a,sizeof(a))){
			a.printData();
		}
		ifile2.close();
	}
	system("pause");
	return 0;
}