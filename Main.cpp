#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
class Data{
	char Name[100];
	long long int Password;
	int n,an;
	public:
	int setValues(){
		cout<<"Please Enter Your Name:";
		cin.get(Name,100);
		cout<<"Hello!! "<<Name<<" I will asist you in the process\n";
		cout<<"How Many Passwords Do you want to save:";
		cin>>n;
		cout<<"Please Enter A master password(Integers Only):";
		cin>>Password;
		return n;         
	}
	void getValues(){
		cout<<"Welcome"<<Name;
		cout<<"\nNo. Of Passwords you have saved:"<<n;
		cout<<"\nMaster Passwords:"<<Password<<"\n\n";
	}
	int incNumber(){
		cout<<"How many No. Do you want to add:";
		cin>>an;
		n+=an;
		return n;
	}
	bool checkMasterPass(int passtemp){
		if(passtemp==Password)
		{
			return true;
		}
		return false;
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
	char ch='Y';
	int choice,n,masterPass;
	cout<<"\t\tWelcome To Password Store\n";
	while(ch=='Y'||ch=='y')
	{
		cout<<"Enter Your Choice:\n";
		cout<<"1.New User\n2.Retrive Your Passwords\n3.About\n";
		cin>>choice;
		if(choice==1){
			cout<<"Warning:Before Entering Information Please make sure you have saved \nyour previous Data.txt and Credentials.txt.\n";
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
			cout<<"Please Enter Master Password:\n";
			cin>>masterPass;
			Data D;
			ifstream ifile1("Data.txt",ios::in|ios::binary);
			ifile1.read((char*)&D,sizeof(D));
			bool check=D.checkMasterPass(masterPass);
			if(check==false)
			{
				system("pause");
				return 0;	
			}
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
		else if(choice==3){
			cout<<"Will Add Later\n";
		}
		cout<<"Menu(Y/N):";
		cin>>ch;
	}
	system("pause");
	return 0;
} 
