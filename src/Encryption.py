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
import os
import pyAesCrypt
# for installing pyAesCrypt please run this command(cmd):pip install pyAesCrypt
password = input("Please Enter A master password:")
print("\nFor Your Ease, the program can store your password in a file(Password.txt)")
choice = input("\nDo you want to save the file in Password.txt(Y/N):")
if choice in ('Y', 'y'):
    ofile = open("Password.txt", "w")
    ofile.write("Password:"+password)
    print("\nPassword has been stored in Password.txt")
    ofile.write(
        "\nPlease copy this password in a diary and delete this file Permanently.\n")
    ofile.close()
else:
    print("\nAs per your request, Password.txt will not be created.\n")
    print("Please Memorize the password.\n")
try:
    pyAesCrypt.encryptFile("Data.txt", "Data.txt.aes", password)
    pyAesCrypt.encryptFile("Credentials.txt", "Credentials.txt.aes", password)
    print("\tFiles have been Encrypted")
except:
    print("An Error Is Encountered")
    print("Error 404: May be File(s) are not present at the desired location")
    if choice in ('Y', 'y'):
        os.remove("Password.txt")
        print("We Have Deleted Password.txt for your convenience as the File(s) could not be Encrypted.")
input("\nPress Enter to continue...")
