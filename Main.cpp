#include<iostream>
#include<fstream>
#include<vector>
#include <cstdlib>
using namespace std;
class Data{
	string Name;
	long long int Password;
	int key,n;
	public:
	int setvalues(){
		cout<<"Please Enter Your Name:";
		getline(cin,Name);
		cout<<"Hello!! "<<Name<<" I will asist you in the process\n";
		cout<<"How Many Passwords Do you want to save:";
		cin>>n;
		cout<<"Please Enter A master password(Integers Only):";
		cin>>Password;
		key=rand()%10;               //key 
		return n;         
	}
	void addno(int no){
		
	}
	void decreseno(int no){
	
	}
	
};
class Credentials{
	string company,username,password;
	public:
	void setData(){
		cout<<"Enter The Companies Name:";
		getline(cin,company);
		cout<<"Enter Your Username/Email:";
		getline(cin,username);
		cout<<"Enter Your Password:";
		getline(cin,password);
	}
	void printData(){
		cout<<"The Companies Name:"<<company;
		cout<<"\nYour Username/Email:"<<username;
		cout<<"Your Password:"<<password;
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
		n=D.setvalues();
		ofstream ofile("Data.txt",ios::out|ios::binary);
		ofile.write((char*)&D,sizeof(D));
		ofile.close();
		Credentials a;
		ofstream oofile("Credentials.txt",ios::out|ios::binary|ios::app);
		cin.ignore();
		for(int i=0;i<n;i++){
			a.setData();
			oofile.write((char*)&a,sizeof(a));
		}
		oofile.close();
	}
	else if(choice==2){
		Credentials a;
		ifstream ifile("Credentials.txt",ios::in|ios::binary);
		ifile.seekg(0);
		while(ifile.read((char*)&a,sizeof(a))){
			a.printData();
		}
		ifile.close();
	}
	system("pause");
	return 0;
}
