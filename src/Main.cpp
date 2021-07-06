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
#include <iostream>

#include <fstream>

#include <Windows.h>

#include <atlstr.h>

using namespace std;

string UniPath; //Will Contain Folder Location

class Data
{
	char Name[100] = "None";
	int n = 0;

public:
	int setValues()
	{
		cout << "Please Enter Your Name:";
		cin.get(Name, 100);
		cout << "\n\n\tHello!! " << Name << " I will asist you in the process\n\n\n";
		cout << "\tHow Many Passwords Do you want to save:";
		cin >> n;
		system("cls");
		return n;
	}
	int getValues()
	{
		system("cls");
		cout << "Welcome!! " << Name;
		cout << "\nNo. Of Passwords you have saved:" << n;
		return n;
	}
	int incNumber(int an)
	{
		n += an;
		return n;
	}
	int decNumber()
	{
		n--;
		return n;
	}
};

class Credentials
{
	char company[100], username[100], password[100];

public:
	void setData()
	{
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
	void printData()
	{
		cout << "\n\t\tThe Companies Name:" << company;
		cout << "\n\t\tYour Username/Email:" << username;
		cout << "\n\t\tYour Password:" << password << endl;
	}
	void setCompName()
	{
		cout << "Enter The Companies Name:";
		cin.ignore();
		cin.get(company, 100);
	}
	void setUserEmail()
	{
		cout << "Enter Your Username/Email:";
		cin.ignore();
		cin.get(username, 100);
	}
	void setPassword()
	{
		cout << "Enter Your Password:";
		cin.ignore();
		cin.get(password, 100);
	}
};

void outputCredentialData(int n)
{
	/********************************************
	 * n = No of credential that are present in
	 * Credential.txt
	*********************************************/
	int EntryNumber = 1;
	Credentials a;
	ifstream ifile("Credentials.txt", ios::in | ios::binary);
	ifile.seekg(0);
	cout << "\n\n======================================================================\n";
	cout << "\n==================================================================\n\n";
	while (ifile.read((char *)&a, sizeof(a)))
	{
		cout << "Entry " << EntryNumber << " of " << n;
		a.printData();
		cout << "\n==================================================================\n\n";
		EntryNumber++;
	}
	cout << "======================================================================\n\n";
	ifile.close();
}

void inputCredentialData(int n, bool type = false)
{
	Credentials a;
	/**************************************************************
	 * Type Will Tell If data is appended or new data is written
	 * type=false :New data is being written
	 * type=true  :Old data is being updated
	***************************************************************/
	auto trunc_or_app = type ? ios::app : ios::trunc;

	ofstream ofile("Credentials.txt", ios::out | ios::binary | trunc_or_app);
	for (int i = 0; i < n; i++)
	{
		cout << "\nEntry " << i + 1 << " of " << n << " \n";
		a.setData();
		ofile.write((char *)&a, sizeof(a));
	}
	ofile.close();
}

int inputDatafile(bool type = false, int an = 0)
{
	Data D;
	int n = 0;
	/***********************************************************
	 * Type Will Tell If data is appended or new data is written
	 * type=false :New data is being written
	 * type=true  :Old data is being updated
	************************************************************/
	if (type == false)
	{
		n = D.setValues();
		ofstream ofile("Data.txt", ios::out | ios::binary | ios::trunc);
		ofile.write((char *)&D, sizeof(D));
		ofile.close();
		inputCredentialData(n); //new data will be written
	}
	else if (type == true)
	{
		ifstream DataFile1("Data.txt", ios::in | ios::binary);
		DataFile1.read((char *)&D, sizeof(D));
		n = D.incNumber(an);
		DataFile1.close();
		ofstream DataFile2("Data.txt", ios::in | ios::binary | ios::trunc);
		DataFile2.write((char *)&D, sizeof(D));
		DataFile2.close();
	}
	return n;
}

int deleteCredential(int an)
{
	/**************************************************
	Will Delete A credential from the decrypted file.
	The (an) argument in the function tells the number
	of the credential which has to be deleted.
	**************************************************/
	int count = 1, flag = 0;
	Credentials a;
	ifstream Credentialsfile("Credentials.txt", ios::in | ios::binary);
	ofstream tempfile("Temp.txt", ios::out | ios::binary | ios::trunc);
	while (Credentialsfile.read((char *)&a, sizeof(a)))
	{
		if (count == an)
		{
			flag = 1;
			cout << "Credential Found!!\n";
			a.printData();
		}
		else
		{
			tempfile.write((char *)&a, sizeof(a));
		}
		count++;
	}
	tempfile.close();
	Credentialsfile.close();
	/********************************************************************
	In the above code all the data except the record that has to be deleted
	is written into Temporary file
	*********************************************************************/
	if (flag == 1)
	{
		ifstream datafile("Data.txt", ios::binary | ios::in);
		Data D;
		datafile.read((char *)&D, sizeof(D));
		D.decNumber();
		datafile.close();
		ofstream newdatafile("Data.txt", ios::binary | ios::out | ios::trunc);
		newdatafile.write((char *)&D, sizeof(D));
		ifstream newtempfile("Temp.txt", ios::in | ios::binary);
		ofstream newCredentialsfile("Credentials.txt", ios::out | ios::binary | ios::trunc);
		while (newtempfile.read((char *)&a, sizeof(a)))
		{
			newCredentialsfile.write((char *)&a, sizeof(a));
		}
		newdatafile.close();
		newCredentialsfile.close();
		newtempfile.close();
	}
	remove("Temp.txt");
	/**********************************************************************************
	 * The data in temporary file is now written back into Credential.txt
	 * and Temp.txt(Temporary File) is deleted after this operation
	**********************************************************************************/
	return flag;
}

string stringFunctions(string str)
{
	/**********************************************************************************
	 * '\' is changed to '\\' as Create Process takes path in '\\'.
	 * "Main.exe" substring is ignored from str(path);
	**********************************************************************************/
	string s1 = "";

	for (unsigned int i = 0; i < str.find("Main.exe"); i++)
	{
		s1.push_back(str[i]);

		if (str[i] == '\\')
		{
			s1.push_back('\\');
		}
	}

	return s1;
}

void PathCalculator()
{
	TCHAR UPath[400];
	GetModuleFileName(NULL, UPath, MAX_PATH);
	/**********************************************************************************
	 * The above function calculates the path of Main.exe and stores it in UPath.
	**********************************************************************************/
	string temp;
#ifndef UNICODE
	temp = UPath;
#else
	std::wstring wStr = UPath;
	temp = std::string(wStr.begin(), wStr.end());
#endif
	temp = stringFunctions(temp);
	_tcscpy_s(UPath, CA2T(temp.c_str()));
	/**********************************************************************************
	 * Above Function converts TCHAR to String;
	**********************************************************************************/
	UniPath = temp;
}

int editCredential(int an)
{
	/*********************************************************************************
	 * the an arument tells the numbber of the credential that is to be edited
	*********************************************************************************/
	int count = 1, flag = 0, choice;
	Credentials a;
	ifstream Credentialsfile("Credentials.txt", ios::in | ios::binary);
	ofstream tempfile("Temp.txt", ios::out | ios::binary | ios::trunc);
	while (Credentialsfile.read((char *)&a, sizeof(a)))
	{
		if (count == an)
		{
			/***********************************************************
			 * if the data is found then prompt the user that credential
			 * is found and ask him what to edit in that credential,
			 * and flag is set to 1.
			***********************************************************/
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
			if (choice == 1)
			{
				a.setCompName();
			}
			else if (choice == 2)
			{
				a.setUserEmail();
			}
			else if (choice == 3)
			{
				a.setPassword();
			}
			else if (choice == 4)
			{
				a.setData();
			}
			tempfile.write((char *)&a, sizeof(a));
			/******************************************
			 * Write the new data in a temp file
			******************************************/
		}
		else
		{
			tempfile.write((char *)&a, sizeof(a));
			/*****************************************
			 * Everydata that has not to be edited is
			 * written as it is into temp.txt
			*****************************************/
		}
		count++;
	}
	tempfile.close();
	Credentialsfile.close();
	if (flag == 1)
	{
		/**************************************************************
		 * flag=1 tells that data has been edited sucsesfully and new
		 * data is present in temp.txt so the new data is now written
		 * into Credential.txt
		*************************************************************/
		ifstream newtempfile("Temp.txt", ios::in | ios::binary);
		ofstream newCredentialsfile("Credentials.txt", ios::out | ios::binary | ios::trunc);
		while (newtempfile.read((char *)&a, sizeof(a)))
		{
			newCredentialsfile.write((char *)&a, sizeof(a));
		}
		newCredentialsfile.close();
		newtempfile.close();
	}
	remove("Temp.txt");
	return flag;
}

void Encryption()
{
	string Encryption_File = UniPath;
	TCHAR PathF[400];
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	Encryption_File.append("Encryption.py");
	Encryption_File.push_back('\0'); //Zero Terminated
	_tcscpy_s(PathF, CA2T(Encryption_File.c_str()));
	if (CreateProcess(PathF, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
	{
		// Wait until child process exits.
		WaitForSingleObject(pi.hProcess, INFINITE);
		// Close process and thread handles.
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		/**************************************************************
		 * If the CreateProcess succeeds, the return value is nonzero.

		 * If the function fails, the return value is zero.
		***************************************************************/
		cout << "\n** Unable To Execute: " << Encryption_File << "**\n";
	}
}

void Decryption()
{
	string Decryption_File = UniPath;
	TCHAR PathF[400];
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	Decryption_File.append("Decryption.py");
	Decryption_File.push_back('\0'); //Zero Terminated
	_tcscpy_s(PathF, CA2T(Decryption_File.c_str()));
	if (CreateProcess(PathF, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
	{
		// Wait until child process exits.
		WaitForSingleObject(pi.hProcess, INFINITE);
		// Close process and thread handles.
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		/**************************************************************
		 * If the CreateProcess succeeds, the return value is nonzero.

		 * If the function fails, the return value is zero.
		***************************************************************/
		cout << "\n** Unable To Execute: " << Decryption_File << "**\n";
	}
}

void About()
{
	system("CLS");
	cout << "\n\n\n";
	cout << "\t ||                                                                                         ||\n";
	cout << "\t=================================================================================================\n";
	cout << "\t ||                                  Password-Store                                         ||\n";
	cout << "\t ||                                               --Garvit Joshi                            ||\n";
	cout << "\t ||Dear Users,                                                                              ||\n";
	cout << "\t ||          Password-store is a Program that will store your password in files that will   ||\n";
	cout << "\t ||be protected with AES-256 bit Encryption. Feel free to contact me on any reported bug.   ||\n";
	cout << "\t ||All the files are compiled and kept ready to use for the sake of your convenience.       ||\n";
	cout << "\t ||                                                                                         ||\n";
	cout << "\t=================================================================================================\n";
	cout << "\t ||  Git-Hub: https://github.com/garvit-joshi/Password-Store                                ||\n";
	cout << "\t ||  E-mail:  garvitjoshi9@gmail.com                                                        ||\n";
	cout << "\t ||                                                                                         ||\n";
	cout << "\t=================================================================================================\n";
	cout << "\t ||                                                                                         ||\n";
}

int main()
{
	char ch = 'Y', ch1 = 'Y';
	/******************************
	 *  This is menu driven program
	*******************************/
	int n, an, flag = 0, flag1 = 0;
	char choice1, choice2;
	cout << "\t\t\t\tWelcome To Password-Store \n\n\n";
	PathCalculator();
	while (ch == 'Y' || ch == 'y')
	{
		cout << "\t\t\t\t\tMain Menu\n";
		cout << "1. New User\n2. Retrive Your Passwords\n3. About\n";
		cout << "4. For Encrypting Files(Data.txt, Credentials.txt)\n5. Exit\n";
		cout << "Enter Your Choice:" << flush;
		choice1 = getchar();
		cin.ignore();
		system("cls");
		if (choice1 == '1')
		{
			cout << "\n\n\t";
			inputDatafile();
			Encryption();
		}
		else if (choice1 == '2')
		{
			ifstream check1, check2;
			Decryption();
			while (ch1 == 'Y' || ch1 == 'y')
			{
				check1.open("Data.txt");
				if (!check1)
				{
					cout << "\nError 404: Data.txt Does Not Exist.\n\n";
					cout << "Press Enter to Continue";
					cin.ignore();
					return 0;
				}
				check2.open("Credentials.txt");
				if (!check2)
				{
					cout << "\nError 404: Credentials.txt Does Not Exist.\n\n";
					cout << "Press Enter to Continue...";
					cin.ignore();
					return 0;
				}
				check1.close();
				check2.close();
				Data D;
				ifstream ifile("Data.txt", ios::in | ios::binary);
				ifile.read((char *)&D, sizeof(D));
				n = D.getValues();
				ifile.close();
				outputCredentialData(n);
				cout << "You can Perform These Functions:\n";
				cout << "1. Insert New Credentials:\n2. Delete a Credential:\n3. Edit A Credential\n";
				cout << "4. No Action\n";
				cout << "Enter Your Choice:";
				cin >> choice2;
				if (choice2 == '1')
				{
					cout << "\nHow Many New Credential do you want to add:";
					cin >> an;
					inputCredentialData(an, true);
					n = inputDatafile(true, an);
					Encryption();
				}
				else if (choice2 == '2')
				{
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
				else if (choice2 == '3')
				{
					cout << "Which Creddential Entry do you want to Edit:";
					cin >> an;
					flag = editCredential(an);
					if (flag == 0)
					{
						cout << "\n No Record Found for that Perticular Entry";
					}
					else
					{
						cout << "\n Data Has been Edited Successfully\n";
					}
				}
				cout << "Do You Want to see the Records Again(Y/N):";
				cin >> ch1;
				system("cls");
			}
			cout << "Program will be Encrypting your file again(You are free to choose a new password.)\n";
			Encryption();
		}
		else if (choice1 == '3')
		{
			About();
		}
		else if (choice1 == '4')
		{
			ifstream DataTXT, CredentialsTXT;
			DataTXT.open("Data.txt");
			if (!DataTXT)
			{
				cout << "\n** No Data.txt Found **\n";
				flag1 = 1;
			}
			DataTXT.close();
			CredentialsTXT.open("Credentials.txt");
			if (!CredentialsTXT)
			{
				cout << "\n** No Credentials.txt Found **\n";
				flag1 = 1;
			}
			CredentialsTXT.close();
			if (flag1 == 0)
			{
				Encryption();
			}
			flag1 = 0;
		}
		else if (choice1 == '5')
		{
			About();
			break;
		}
		getchar();
		cout << "Menu(Y/N):";
		ch = getchar();
		cin.ignore();
		system("cls");
	}
	ifstream DataAES, CredentialsAES, DataTXT, CredentialsTXT;
	DataAES.open("Data.txt.aes");
	DataTXT.open("Data.txt");
	if (DataAES && DataTXT)
	{
		DataTXT.close();
		remove("Data.txt");
	}
	DataAES.close();
	CredentialsAES.open("Credentials.txt.aes");
	CredentialsTXT.open("Credentials.txt");
	if (CredentialsAES && CredentialsTXT)
	{
		CredentialsTXT.close();
		remove("Credentials.txt");
	}
	CredentialsAES.close();
	cout << "\n\nPlease!! Remove Data.txt and Credential.txt manually if they are present.\n";
	cout << "Press Enter to Continue...";
	cin.ignore();
	return 0;
}
