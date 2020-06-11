import sys
import pyAesCrypt
arguments=sys.argv
choice=arguments[1]
password=arguments[2]
bufferSize = 64 * 1024
if(choice=="1"):
    # encrypt
    try:
        pyAesCrypt.encryptFile("data.txt", "data.txt.aes", password, bufferSize)
    except:
        print("An Error Is Encountered")
        print("May be Files are not present at the desired location")
else:
    # decrypt
    try:
        pyAesCrypt.decryptFile("data.txt.aes", "dataout.txt", password, bufferSize)
    except:
        print("An Error Is Encountered")
        print("May be Files are not present at the desired location")