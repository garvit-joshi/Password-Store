# Password-Store
Saves your password in a binary file.<br>
Added Support to AES-256 bit Encryption.<br>
``` git clone https://github.com/garvit-joshi/Password-Store.git ```

## Prerequisite

1. Python3 Downloaded and Installed with Environment Variables. [click here](https://www.python.org/)<br>
2. pyAesCrypt Installed In python, if python is installed with Environment variables, then you can run Main.exe and click 4 and press Enter, it will install Required Module (Note: Internet Connection may be required). <br> <br>
[More About pyAesCrypt(Encrypt/decrypt a file using AES256-CBC.)](https://pypi.org/project/pyAesCrypt/)

## Building The app from source.

Although Everything is compiled and you can directly run Main.exe, first two steps are compulsory.

1. Install [git](https://git-scm.com/download/win) and Run git Bash, then Enter ```git clone https://github.com/garvit-joshi/Password-Store.git```
2. Install Python3 with Environment Path. [click here](https://www.python.org/)
3. Install a C++ Compiler(Copiler Used In this project:Microsoft C++ Compiler-MSVC)
4. Open cmd in folder and compile Encryption.py and Decryption.py (python -m compileall .)
5. Build Main.cpp from source.
6. Run Main.exe

### Support

1. For configuring Microsoft C/C++ for Visual Studio Code, [click here](https://docs.microsoft.com/en-us/cpp/build/building-on-the-command-line?view=vs-2019) <br>
2. For Downloading Python, [click here](https://www.python.org/) <br>
Note : Please click on 'Add Python 3.xx to PATH' while installing. <br>
3. Install Required Modules: <br>
3.1. open cmd <br>
3.2. run 'pip install pyAesCrypt'
