# Password-Store
Saves your password in two Encrypted files.<br>
Added Support to AES-256 bit Encryption.<br>
``` git clone https://github.com/garvit-joshi/Password-Store.git ```

## Prerequisite

1. Python3 Downloaded and Installed with Environment Variables. [click here](https://www.python.org/)<br>
2. ```pyAesCrypt``` Installed In python, if python is installed with Environment variables, then you can run  ```Main.exe``` and click ```4``` and press ```Enter```, it will install Required Modules, or just open cmd and type ```pip install pyAesCrypt```<br>***Note: Internet Connection may be required***. <br> <br>
[More About pyAesCrypt(Encrypt/decrypt a file using AES256-CBC.)](https://pypi.org/project/pyAesCrypt/)

## Building The app from source.

Although Everything is compiled and you can directly run ```Main.exe```, first step is compulsory.

1. Install Python3 with Environment Path. [click here](https://www.python.org/)
2. Download Project from [here](https://github.com/garvit-joshi/Password-Store), or just install [git](https://git-scm.com/) and run git Bash, then Enter ```git clone https://github.com/garvit-joshi/Password-Store.git``` <br>
3. Install a C++ Compiler(Copiler Used In this project: [Microsoft C++ Compiler-MSVC](https://visualstudio.microsoft.com/downloads/))
4. Open cmd in folder and compile ```Encryption.py and Decryption.py``` by typing ```python -m compileall .```
5. Build ```Main.cpp, ECaller.cpp, and DCaller.cpp``` from source.
6. Run Main.exe

### Support

1. For Downloading Python, [click here](https://www.python.org/) <br>
Note : Please click on 'Add Python 3.xx to PATH' while installing. <br>
2. Install Required Modules: <br>
2.1. Open cmd <br>
2.2. Run ```pip install pyAesCrypt```

### Caution:
The last thing is simply a matter of perception. If you are running any sort of anti-virus, like ZoneAlarm, Norton, McAfee, etc. then they will get a very unpleasant message about your program trying to do something considered dangerous. It may be due to system(); function used in program. Read more about it [here](http://www.cplusplus.com/reference/cstdlib/system/), and [here](http://www.cplusplus.com/articles/j3wTURfi/)
