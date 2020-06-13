#include<iostream>

#include<fstream>

#include<cstdlib>

using namespace std;

class Data {
	char Name[100];
	int n = 0;
public:
	int setValues() {
		cout << "Please Enter Your Name:";
		cin.get(Name, 100);
		cout << "Hello!! " << Name << " I will asist you in the process\n";
		cout << "How Many Passwords Do you want to save:";
		cin >> n;
		return n;
	}
	int getValues() {
		cout << "Welcome" << Name;
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
		cout << "Enter The Companies Name:";
		cin.get(company, 100);
		cin.ignore();
		cout << "Enter Your Username/Email:";
		cin.get(username, 100);
		cout << "Enter Your Password:";
		cin.ignore();
		cin.get(password, 100);
	}
	void printData() {
		cout << "\nThe Companies Name:" << company;
		cout << "\nYour Username/Email:" << username;
		cout << "\nYour Password:" << password << endl;
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
		cout<<"\n===================================================\n\n";
		EntryNumber++;
	}
	cout<<"======================================================================\n\n";
	ifile.close();
}


void inputCredentialData(int n, bool type = false)
{
	Credentials a;
	if (type == false) {
		/**
		 * Type Will Tell If data is appended or new data is written
		 * type=false :New data is being written
		 * type=true  :Old data is being updated
		**/
		ofstream ofile("Credentials.txt", ios::out | ios::binary | ios::trunc);
		for (int i = 0; i < n; i++) {
			a.setData();
			ofile.write((char*)&a, sizeof(a));
		}
		ofile.close();
	}
	else
	{
		ofstream ofile("Credentials.txt", ios::out | ios::binary | ios::app);
		for (int i = 0; i < n; i++) {
			a.setData();
			ofile.write((char*)&a, sizeof(a));
		}
		ofile.close();
	}
}


void inputDatafile(bool type = false, int an = 0) {
	Data D;
	int n;
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



int main()
{
	char ch = 'Y';
	int choice1, choice2, n, an, flag;
	cout << "\t\t\t\tWelcome To Password Store\n";
	while (ch == 'Y' || ch == 'y')
	{
		cout << "1.New User\n2.Retrive Your Passwords\n3.About\n4.For installing supported modules(may require internet connection)\n";
		cout << "Enter Your Choice:";
		cin >> choice1;
		if (choice1 == 1) {
			cout << "Warning:Before Entering Information Please make sure you have saved \nyour previous Data.txt and Credentials.txt.\n";
			inputDatafile();
			system("python Encryption.py");
		}
		else if (choice1 == 2) {
			ifstream check1, check2;
			system("python Decryption.py");
			check1.open("Data.txt");
			if (!check1) {
				cout << "Data.txt Does Not Exist.";
				system("pause");
				return 0;
			}
			check2.open("Credentials.txt");
			if (!check2) {
				cout << "Credentials.txt Does Not Exist.";
				system("pause");
				return 0;
			}
			Data D;
			ifstream ifile("Data.txt", ios::in | ios::binary);
			ifile.read((char*)&D, sizeof(D));
			n=D.getValues();
			ifile.close();
			outputCredentialData(n);
			cout << "You can Perform These Functions:\n";
			cout << "1. Insert New Credentials:\n2. Delete a Credential:\n3. Edit A Credential\n";
			cout << "4. No Action";
			cout << "Enter Your Choice:";
			cin >> choice2;
			if (choice2 == 1) {
				cout << "\nHow Many New Credential do you want to save:";
				cin >> an;
				inputDatafile(true, an);
				inputCredentialData(an, true);
			}
			else if (choice2 == 2) {
				cout << "Which Creddential Entry do you want to delete:";
				cin >> an;
				flag = deleteCredential(an);
				if (flag == 0)
				{
					cout << "\n No data Was Deleted Please Enter A Correct Entry:";
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
					cout << "\n Data Has been Edited Successfully";
				}
			}
			system("python Encryption.py");
		}
		else if (choice1 == 3) {
			cout << "Dear Users,\nPassword-store is a Program that will store your password in";
			cout << "files that will be protected in a file with AES-256 bit Encryption. Feel";
			cout << "free to contact me on any reported bug and pull requests are very much welcomed.";
			cout << "\nCreator\nGarvit Joshi(garvitjoshi9@gmail.com)\n";
		}
		else if(choice1 == 4) {
			system("pip install pyAesCrypt");
			cout << "==================================================================\n";
			cout << "if an error occurs saying \"'pip' is not recognized as an internal \n";
			cout << "or external command,\"\nplease download and install python from \n";
			cout << "python.org and add it to Environment variable.\n";
		}
		cout << "Menu(Y/N):";
		cin >> ch;
		system("cls");
	}
	system("pause");
	return 0;
}