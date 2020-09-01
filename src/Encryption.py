# cython: language_level=3, boundscheck=False
"""
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
"""
import pyAesCrypt
import os
#for installing pyAesCrypt please run this command(cmd):pip install pyAesCrypt
#or click "4" In Menu for Support.
password=input("Please Enter A master password:")
print("\nFor Your Ease, the program can store your password in a file(Password.txt)")
choice=input("\n Do you want to save the file in Password.txt(Y/N):")
if(choice=="Y" or choice == "y"):
    ofile=open("Password.txt","w")
    ofile.write("Password:"+password)
    print("\nPassword has been stored in Password.txt")
    ofile.write("\nPlease copy this password in a diary and delete this file Permanently.\n")
    ofile.close()
else:
    print("\nAs per your request, Password.txt will not be created. Please Memorize the password.\n")
bufferSize = 64 * 1024
try:
    with open("Data.txt", "rb") as fIn1:
        with open("Data.txt.aes", "wb") as fOut1:
            pyAesCrypt.encryptStream(fIn1, fOut1, password, bufferSize)
    fIn1.close()
    fOut1.close()
    with open("Credentials.txt", "rb") as fIn2:
        with open("Credentials.txt.aes", "wb") as fOut2:
            pyAesCrypt.encryptStream(fIn2, fOut2, password, bufferSize)
    print("\tFiles have been Encrypted")
    fIn2.close()
    fOut2.close()
except:
    print("An Error Is Encountered")
    print("Error 404:May be Files are not present at the desired location")
    if(choice == "Y" or choice == "y"):
        os.remove("Password.txt")
        print("We Have Deleted Password.txt for your convenience as the File(s) could not be Encrypted.")
input("\nPress Enter to continue...")