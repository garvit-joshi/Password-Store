import pyAesCrypt
import os
#for installing pyAesCrypt please run this command:pip install pyAesCrypt
#or click "4" In Menu for Support.
password=input("Please Enter Your Master Password:")
flag=0
bufferSize = 64 * 1024
try:
    encFileSize1 = os.stat("Data.txt.aes").st_size
    encFileSize2 = os.stat("Credentials.txt.aes").st_size
except:
    print("Error 404: Encrypted Files Not Found")
    flag=1
if(flag==0):
    with open("Data.txt.aes", "rb") as fIn1:
        try:
            with open("Data.txt", "wb") as fOut1:
                pyAesCrypt.decryptStream(fIn1, fOut1, password, bufferSize, encFileSize1)
            fOut1.close()
            fIn1.close()
        except ValueError:
            os.remove("Data.txt")
            print("An Error Is Encountered\n")
            print("\nError 401(@1): Password May be wrong")
            flag=1
if(flag==0):
    with open("Credentials.txt.aes", "rb") as fIn2:
        try:
            with open("Credentials.txt", "wb") as fOut2:
                pyAesCrypt.decryptStream(fIn2, fOut2, password, bufferSize, encFileSize2)
            print("All Data has been decrypted successfully")
            fIn2.close()
            fOut2.close()
        except ValueError:
            os.remove("Credentials.txt")
            print("An Error Is Encountered")
            print("Error 401(@2): Password May be wrong")
input("Press Enter to continue...")