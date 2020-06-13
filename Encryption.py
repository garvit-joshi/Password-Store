import pyAesCrypt
import os
#for installing pyAesCrypt please run this command(cmd):pip install pyAesCrypt
#or click "4" In Menu for Support.
password=input("Please Enter A master password:")
print("\nFor Your Ease, the proram can store your password in a file(Password.txt)")
choice=input("\n Do you want to save the file in Password.txt(Y/N):")
if(choice=="Y" or choice == "y"):
    ofile=open("Password.txt","w")
    ofile.write("Password:"+password)
    print("\n Password has been stored in Password.txt")
    ofile.write("\nPlease copy this password in a diary and delete this file Permanently.\n")
else:
    print("\nAs per your request, Password.txt will not be created. Please Memorize the password.\n")
bufferSize = 64 * 1024
try:
    pyAesCrypt.encryptFile("Data.txt", "Data.txt.aes", password, bufferSize)
    pyAesCrypt.encryptFile("Credentials.txt", "Credentials.txt.aes", password, bufferSize)
    os.remove("Data.txt")
    os.remove("Credentials.txt")
except:
    print("An Error Is Encountered")
    print("May be Files are not present at the desired location")
    if(choice == "Y" or choice == "y"):
        os.remove("Password.txt")
        print("We Have Deleted Password.txt for your convenience as the File(s) could not be Encrypted.")