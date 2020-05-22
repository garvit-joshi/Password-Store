#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
class Data{
	char Name[100];
	long long int Password=0;
	int n=0,an=0;
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
		cout<<"How many Entries Do you want to add:";
		cin>>an;
		n+=an;
		return n;
	}
	int checkMasterPass(int passtemp){
		if(passtemp==Password)
		{
			return n;
		}
		return -1;
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
void outputCredentialData(int n)
{
	int EntryNumber=1;
	Credentials a;
	ifstream ifile("Credentials.txt",ios::in|ios::binary);
	ifile.seekg(0);
	while(ifile.read((char*)&a,sizeof(a))){
		cout<<"Entry "<<EntryNumber<<" of "<<n;
		a.printData();
		EntryNumber++;
	}
	ifile.close();
}
void inputCredentialData(int n,bool type=false) 
{
	Credentials a;
	if(type==false){
		/**
		 * Type Will Tell If data is appended or new data is written
		 * type=false :New data is being writter
		 * type=true  :Old data is being updated
		**/
		ofstream ofile("Credentials.txt",ios::out|ios::binary|ios::trunc);
		for(int i=0;i<n;i++){
			a.setData();
			ofile.write((char*)&a,sizeof(a));
		}
		ofile.close();
	}
	else
	{
		ofstream ofile("Credentials.txt",ios::out|ios::binary|ios::app);
		for(int i=0;i<n;i++){
			a.setData();
			ofile.write((char*)&a,sizeof(a));
		}
		ofile.close();
	}
}
void inputDatafile(){
	int n;
	Data D;
	cin.ignore();
	n=D.setValues();
	ofstream ofile("Data.txt",ios::out|ios::binary|ios::trunc);
	ofile.write((char*)&D,sizeof(D));
	ofile.close();
	inputCredentialData(n);
}
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
			inputDatafile();
		}
		else if(choice==2){
			cout<<"Please Enter Master Password:\n";
			cin>>masterPass;
			Data D;
			ifstream ifile1("Data.txt",ios::in|ios::binary);
			ifile1.read((char*)&D,sizeof(D));
			n=D.checkMasterPass(masterPass);
			if(n==-1)
			{
				cout<<"Password Was Wrong\n";
				system("pause");
				return 0;	
			}
			D.getValues();
			ifile1.close();
			outputCredentialData(n);
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
