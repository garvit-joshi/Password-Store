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

#include <windows.h>

#include <stdio.h>

#include <tchar.h>

#include <atlstr.h>


using namespace std;


string stringFunctions(string str)
{
    for(int i=0;i<11;i++)
	{
		str.pop_back();
	}

    string s1="";


    for(int i=0;i<str.length();i++) 
    {
        if(str[i]!='\\')
        {
            s1=s1+str[i];
        }
        else
        { 
            s1=s1+str[i]+"\\";

        }
    }


    return s1;
}

void _tmain(int argc, char** argv)
{
    char n;
    TCHAR path[MAX_PATH];
	GetModuleFileName(NULL, path, MAX_PATH);
    string s;
	#ifndef UNICODE
    s = path;
	#else
    std::wstring wStr = path;
    s = std::string(wStr.begin(), wStr.end());
	#endif
	s=stringFunctions(s);
	s.append("Decryption.pyc");
	_tcscpy_s(path, CA2T(s.c_str()));
    ShellExecute(NULL, NULL,path, NULL, NULL, SW_SHOWNA);
    cout<<"\nPlease do not close this window!! This Window acts bridge between Python File and Main C++ File.\n";
    cout<<"After The Python Decryption file is closed, Please Type any Character and press Enter\n";
    cin>>n;
}