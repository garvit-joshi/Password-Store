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
import sys
import pyAesCrypt

# for installing pyAesCrypt please run this command:pip install pyAesCrypt.
password = input("Please Enter Your Master Password:")
if (
    os.path.exists("Data.txt.aes") == False
    or os.path.exists("Credentials.txt.aes") == False
):
    print("Error 404: Encrypted File(s) Not Found")
    input("Press Enter to continue...")
    sys.exit()
BUFFERSIZE = 128 * 1024
try:
    pyAesCrypt.decryptFile("Data.txt.aes", "Data.txt", password, BUFFERSIZE)
    pyAesCrypt.decryptFile(
        "Credentials.txt.aes", "Credentials.txt", password, BUFFERSIZE
    )
except ValueError:
    print("An Error Is Encountered\n")
    print("\nError 401: Password May be wrong")
input("Press Enter to continue...")
