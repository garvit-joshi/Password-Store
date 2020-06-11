import pyAesCrypt
import os
password=input("Please Enter Your Master Password")
bufferSize = 64 * 1024
# decrypt
try:
    pyAesCrypt.decryptFile("Data.txt.aes", "Data.txt", password, bufferSize)
    pyAesCrypt.decryptFile("Credentials.txt.aes", "Credentials.txt", password, bufferSize)
except:
    print("An Error Is Encountered")
    print("Password May be wrong")