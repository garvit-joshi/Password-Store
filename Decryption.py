import pyAesCrypt
import os
#for installing pyAesCrypt please run this command:pip install pyAesCrypt
#or click "4" In Menu for Support.
password=input("Please Enter Your Master Password:")
bufferSize = 64 * 1024
try:
    pyAesCrypt.decryptFile("Data.txt.aes", "Data.txt", password, bufferSize)
    pyAesCrypt.decryptFile("Credentials.txt.aes", "Credentials.txt", password, bufferSize)
    os.remove("Data.txt.aes")
    os.remove("Credentials.txt.aes")
except:
    print("An Error Is Encountered")
    print("Error 401: Password May be wrong")