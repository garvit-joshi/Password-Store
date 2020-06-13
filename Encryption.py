import pyAesCrypt
import os
password=input("Please Enter A master password(Integers Only):")
bufferSize = 64 * 1024
try:
    pyAesCrypt.encryptFile("Data.txt", "Data.txt.aes", password, bufferSize)
    pyAesCrypt.encryptFile("Credentials.txt", "Credentials.txt.aes", password, bufferSize)
    os.remove("Data.txt")
    os.remove("Credentials.txt")
except:
    print("An Error Is Encountered")
    print("May be Files are not present at the desired location")