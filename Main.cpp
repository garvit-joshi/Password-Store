/*******************************************************************************
 * Password-store:Stores your Credential in AES-256 bit Encryption


 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*******************************************************************************/
#include<iostream>

#include<fstream>


using namespace std;

class Data {
	char Name[100];
	int n = 0;
public:
	int setValues() {
		cout << "Please Enter Your Name:";
		cin.get(Name, 100);
		cout << "\n\n\tHello!! " << Name << " I will asist you in the process\n\n\n";
		cout << "\tHow Many Passwords Do you want to save:";
		cin >> n;
		system("cls");
		return n;
	}
	int getValues() {
		system("cls");
		cout << "Welcome!! " << Name;
		cout << "\nNo. Of Passwords you have saved:" << n;
		return n;
	}
	int incNumber(int an) {
		n += an;
		return n;
	}
	int decNumber() {
		n--;
		return n;
	}
};


class Credentials {
	char company[100], username[100], password[100];
public:
	void setData() {
		cin.ignore();
		cout << "\t\tEnter The Companies Name:";
		cin.get(company, 100);
		cin.ignore();
		cout << "\t\tEnter Your Username/Email:";
		cin.get(username, 100);
		cout << "\t\tEnter Your Password:";
		cin.ignore();
		cin.get(password, 100);
	}
	void printData() {
		cout << "\n\t\tThe Companies Name:" << company;
		cout << "\n\t\tYour Username/Email:" << username;
		cout << "\n\t\tYour Password:" << password << endl;
	}
	void setCompName() {
		cout << "Enter The Companies Name:";
		cin.ignore();
		cin.get(company, 100);
	}
	void setUserEmail() {
		cout << "Enter Your Username/Email:";
		cin.ignore();
		cin.get(username, 100);
	}
	void setPassword() {
		cout << "Enter Your Password:";
		cin.ignore();
		cin.get(password, 100);
	}
};




void outputCredentialData(int n)
{
	int EntryNumber = 1;
	Credentials a;
	ifstream ifile("Credentials.txt", ios::in | ios::binary);
	ifile.seekg(0);
	cout<<"\n\n======================================================================\n";
	while (ifile.read((char*)&a, sizeof(a))) {
		cout << "Entry " << EntryNumber << " of " << n;
		a.printData();
		cout<<"\n==================================================================\n\n";
		EntryNumber++;
	}
	cout<<"======================================================================\n\n";
	ifile.close();
}


void inputCredentialData(int n, bool type = false)
{
	Credentials a;
	if (type == false) {
		/**************************************************************
		 * Type Will Tell If data is appended or new data is written
		 * type=false :New data is being written
		 * type=true  :Old data is being updated
		***************************************************************/
		ofstream ofile("Credentials.txt", ios::out | ios::binary | ios::trunc);
		for (int i = 0; i < n; i++) {
			cout << "\nEntry "<<i+1 << " of "<<n <<" \n";
			a.setData();
			ofile.write((char*)&a, sizeof(a));
		}
		ofile.close();
	}
	else
	{
		ofstream ofile("Credentials.txt", ios::out | ios::binary | ios::app);
		for (int i = 0; i < n; i++) {
			cout << "\nEntry "<<i+1 << " of "<<n <<" \n";
			a.setData();
			ofile.write((char*)&a, sizeof(a));
		}
		ofile.close();
	}
}


int inputDatafile(bool type = false, int an = 0) {
	Data D;
	int n;
	/***********************************************************
	 * Type Will Tell If data is appended or new data is written
	 * type=false :New data is being written
	 * type=true  :Old data is being updated
	************************************************************/
	if (type == false) {
		cin.ignore();
		n = D.setValues();
		ofstream ofile("Data.txt", ios::out | ios::binary | ios::trunc);
		ofile.write((char*)&D, sizeof(D));
		ofile.close();
		inputCredentialData(n);   //new data will be written
	}
	else if (type == true) {
		ifstream DataFile1("Data.txt", ios::in | ios::binary);
		DataFile1.read((char*)&D, sizeof(D));
		n = D.incNumber(an);
		DataFile1.close();
		ofstream DataFile2("Data.txt", ios::in | ios::binary | ios::trunc);
		DataFile2.write((char*)&D, sizeof(D));
		DataFile2.close();
	}
	return n;
}


int deleteCredential(int an)
{
	/*
	Will Delete A credential from the decrypted file.
	The (an) argument in the function tells the number 
	of the credential which has to be deleted.
	*/
	int count = 1, flag = 0;
	Credentials a;
	ifstream Credentialsfile("Credentials.txt", ios::in | ios::binary);
	ofstream tempfile("Temp.txt", ios::out | ios::binary | ios::trunc);
	while (Credentialsfile.read((char*)&a, sizeof(a)))
	{
		if (count == an)
		{
			flag = 1;
			cout << "Credential Found!!\n";
			a.printData();
		}
		else
		{
			tempfile.write((char*)&a, sizeof(a));
		}
		count++;
	}
	tempfile.close();
	Credentialsfile.close();
	/* 
	In the above code all the data except the record that has to be deleted 
	is written into Temporary file
	*/
	if (flag == 1)
	{
		ifstream datafile("Data.txt", ios::binary | ios::in);
		Data D;
		datafile.read((char*)&D, sizeof(D));
		D.decNumber();
		datafile.close();
		ofstream newdatafile("Data.txt", ios::binary | ios::out | ios::trunc);
		newdatafile.write((char*)&D, sizeof(D));
		ifstream newtempfile("Temp.txt", ios::in | ios::binary);
		ofstream newCredentialsfile("Credentials.txt", ios::out | ios::binary | ios::trunc);
		while (newtempfile.read((char*)&a, sizeof(a)))
		{
			newCredentialsfile.write((char*)&a, sizeof(a));
		}
		newdatafile.close();
		newCredentialsfile.close();
		newtempfile.close();
	}
	remove("Temp.txt");
	return flag;
}



int editCredential(int an)
{
	int count = 1, flag = 0, choice;
	Credentials a;
	ifstream Credentialsfile("Credentials.txt", ios::in | ios::binary);
	ofstream tempfile("Temp.txt", ios::out | ios::binary | ios::trunc);
	while (Credentialsfile.read((char*)&a, sizeof(a)))
	{
		if (count == an)
		{
			flag = 1;
			cout << "Credential Found!!";
			a.printData();
			cout << "What Do you want to edit:";
			cout << "\n1. Comapny Name:";
			cout << "\n2. Username/email:";
			cout << "\n3. Password:";
			cout << "\n4. Edit Whole Credential";
			cout << "\n\t\tChoice:";
			cin >> choice;
			if (choice == 1) {
				a.setCompName();
			}
			else if (choice == 2) {
				a.setUserEmail();
			}
			else if (choice == 3) {
				a.setPassword();
			}
			else if (choice == 4) {
				a.setData();
			}
			tempfile.write((char*)&a, sizeof(a));
		}
		else
		{
			tempfile.write((char*)&a, sizeof(a));
		}
		count++;
	}
	tempfile.close();
	Credentialsfile.close();
	if (flag == 1)
	{
		ifstream newtempfile("Temp.txt", ios::in | ios::binary);
		ofstream newCredentialsfile("Credentials.txt", ios::out | ios::binary | ios::trunc);
		while (newtempfile.read((char*)&a, sizeof(a)))
		{
			newCredentialsfile.write((char*)&a, sizeof(a));
		}
		newCredentialsfile.close();
		newtempfile.close();
	}
	remove("Temp.txt");
	return flag;
}


void About() {
	system("CLS");
	cout<<"\n\n\n";
    cout<<"\t ||                                                                                         ||\n";
    cout<<"\t=================================================================================================\n";
    cout<<"\t ||                                  Password-Store                                         ||\n";
    cout<<"\t ||                                               --Garvit Joshi                            ||\n";
	cout<<"\t ||Dear Users,                                                                              ||\n";
    cout<<"\t ||          Password-store is a Program that will store your password in files that will   ||\n";
    cout<<"\t ||be protected in a file with AES-256 bit Encryption. Feel free to contact me on any       ||\n";
	cout<<"\t ||reported bug. All the files are compiled and kept ready to use for the sake of your      ||\n";
	cout<<"\t ||convenience.                                                                             ||\n";
	cout<<"\t ||                                                                                         ||\n";
    cout<<"\t=================================================================================================\n";
    cout<<"\t ||  Git-Hub: https://github.com/garvit-joshi/Password-Store                                ||\n";
	cout<<"\t ||  E-mail:  garvitjoshi9@gmail.com, garvitjoshi9@studentpartner.com                       ||\n";
	cout<<"\t ||                                                                                         ||\n";
    cout<<"\t=================================================================================================\n";
    cout<<"\t ||                                                                                         ||\n";
}


void systemHelp() {
	/**********************************
	 * For Adding Desired Modules To python
	 * ->pyAesCrypt
	************************************/
	system("cls");
	system("pip install pyAesCrypt");
	cout<<"\n\n\n";
	cout<<"\t ||                                                                                            ||\n";
	cout<<"\t===================================================================================================\n";
    cout<<"\t ||                                  Password-Store                                            ||\n";
    cout<<"\t ||                                                                                            ||\n";
	cout<<"\t ||Note: Some Supported Modules Need to be installed when using this application.              ||\n";
	cout<<"\t ||                                                                                            ||\n";
	cout<<"\t ||                                                                                            ||\n";
	cout<<"\t ||Dear Users,                                                                                 ||\n";
    cout<<"\t ||  If an error occurs saying \"'pip' is not recognized as an internal or external command,\"   ||\n";
    cout<<"\t ||  please download and install python from python.org and add it to Environment variable.    ||\n";
	cout<<"\t ||                                                                                            ||\n";
    cout<<"\t====================================================================================================\n";
	cout<<"\t ||  Git-Hub: https://github.com/garvit-joshi/Password-Store                                   ||\n";
	cout<<"\t ||  E-mail:  garvitjoshi9@gmail.com, garvitjoshi9@studentpartner.com                          ||\n";
	cout<<"\t ||                                                                                            ||\n";
    cout<<"\t=================================================================================================\n";
    cout<<"\t ||                                                                                            ||\n";
}



int main()
{
	char ch = 'Y',ch1='Y';
	/******************************
	 *  This is menu driven program
	*******************************/
	int choice1, choice2, n, an, flag;
	cout << "\t\t\t\tWelcome To Password-Store \n\n\n";
	while (ch == 'Y' || ch == 'y')
	{
		cout<<"\t\t\t\t\tMain Menu\n";
		cout << "1.New User\n2.Retrive Your Passwords\n3.About\n4.For installing supported modules(may require internet connection)\n";
		cout << "Enter Your Choice:";
		cin >> choice1;
		system("cls");
		if (choice1 == 1) {
			cout << "\n\n\t";
			inputDatafile();
			system("Encryption.pyc");
		}
		else if (choice1 == 2) {
			ifstream check1, check2;
			system("Decryption.pyc");
			while(ch1== 'Y' || ch1== 'y'){
				check1.open("Data.txt");
				if (!check1) {
					cout << "Error 404: Data.txt Does Not Exist.\n\n";
					system("pause");
					return 0;
				}
				check2.open("Credentials.txt");
				if (!check2) {
					cout << "Error 404: Credentials.txt Does Not Exist.\n\n";
					system("pause");
					return 0;
				}
				check1.close();
				check2.close();
				Data D;
				ifstream ifile("Data.txt", ios::in | ios::binary);
				ifile.read((char*)&D, sizeof(D));
				n=D.getValues();
				ifile.close();
				outputCredentialData(n);
				cout << "You can Perform These Functions:\n";
				cout << "1. Insert New Credentials:\n2. Delete a Credential:\n3. Edit A Credential\n";
				cout << "4. No Action\n";
				cout << "Enter Your Choice:";
				cin >> choice2;
				if (choice2 == 1) {
					cout << "\nHow Many New Credential do you want to add:";
					cin >> an;
					inputCredentialData(an, true);
					n = inputDatafile(true, an);
					system("Encryption.pyc");
				}
				else if (choice2 == 2) {
					cout << "Which Creddential Entry do you want to delete:";
					cin >> an;
					flag = deleteCredential(an);
					if (flag == 0)
					{
						cout << "\n No data was deleted, Please enter a correct entry:";
					}
					else
					{
						cout << "Data Deleted Successfully";
					}
				}
				else if (choice2 == 3) {
					cout << "Which Creddential Entry do you want to Edit:";
					cin >> an;
					flag = editCredential(an);
					if (flag == 0) {
						cout << "\n No Record Found for that Perticular Entry";
					}
					else {
						cout << "\n Data Has been Edited Successfully\n";
					}
				}
				cout << "Do You Want to see the Records Again(Y/N):";
				cin >> ch1;
				system("cls");
			}
			cout << "Program will be Encrypting your file again(You are free to choose a new password.)\n";
			system("Encryption.pyc");
		}
		else if (choice1 == 3) {
			About();
		}
		else if(choice1 == 4) {
			systemHelp();
		}
		cout << "Menu(Y/N):";
		cin >> ch;
		system("cls");
	}
	cout << "Please!! Remove Data.txt and Credential.txt manually if they are present.\n";
	system("pause");
	return 0;
}