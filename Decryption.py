import pyAesCrypt
import os
#for installing pyAesCrypt please run this command:pip install pyAesCrypt
password=input("Please Enter Your Master Password:")
bufferSize = 64 * 1024
try:
    pyAesCrypt.decryptFile("Data.txt.aes", "Data.txt", password, bufferSize)
    pyAesCrypt.decryptFile("Credentials.txt.aes", "Credentials.txt", password, bufferSize)
    os.remove("Data.txt.aes")
    os.remove("Credentials.txt.aes")
except:
    print("An Error Is Encountered")
    print("Password May be wrong")