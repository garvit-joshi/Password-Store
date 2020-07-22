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
    with open("Credentials.txt", "rb") as fIn2:
        with open("Credentials.txt.aes", "wb") as fOut2:
            pyAesCrypt.encryptStream(fIn2, fOut2, password, bufferSize)
    os.remove("Data.txt")
    os.remove("Credentials.txt")
    print("\tFiles have been Encrypted")
except:
    print("An Error Is Encountered")
    print("Error 404:May be Files are not present at the desired location")
    if(choice == "Y" or choice == "y"):
        os.remove("Password.txt")
        print("We Have Deleted Password.txt for your convenience as the File(s) could not be Encrypted.")
input("\nPress Enter to continue...")