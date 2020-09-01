# Password-Store:
Saves your password in two Encrypted files,<br>
with AES-256-CBC bit Encryption.<br>

## Prerequisite (for only building app from source):
1. [Python 3 (>=3.8.5)](https://www.python.org/)
2. [Visual Studio 2019](https://visualstudio.microsoft.com/vs/)

## Steps for building the app from source:

Although Everything is compiled and you can directly run [Main.exe](https://github.com/garvit-joshi/Password-Store/tree/master/bin64). Here are steps for building app from source.

1. Install Python3 with Environment Path. [click here](https://www.python.org/)
2. Install a C++ Compiler (Copiler Used In this project: [Microsoft C++ Compiler-MSVC](https://visualstudio.microsoft.com/downloads/))
3. Open cmd in folder and type <br>
3.1. ```cython Encryption.py --embed```  
3.2. ```cython Decryption.py --embed```
4. The above step will create ```Encryption.c``` and ```Decryption.c```.
5. Build ```Encryption.c``` , ```Decryption.c``` and ```Main.cpp```.
6. Run [Main.exe](https://github.com/garvit-joshi/Password-Store/tree/master/bin64)

### Support (for only building app from source):

1. For Downloading Python, [click here](https://www.python.org/) <br>
Note : Please click on 'Add Python 3.xx to PATH' while installing.
2. Install Required Modules:
    1. Open command prompt, in src folder.
    2. Run ```pip install -r requirements.txt```

### Notes:

1. Please Install **Microsoft Visual C++ Redistributable for Visual Studio 2019** before running binaries:
    1. For [x64](https://aka.ms/vs/16/release/VC_redist.x64.exe),
    2. For [x86](https://aka.ms/vs/16/release/VC_redist.x86.exe),
    3. For [ARM64](https://aka.ms/vs/16/release/VC_redist.arm64.exe).

2. The last thing is simply a matter of ***perception***. If you are running any sort of anti-virus, like ***ZoneAlarm, Norton, McAfee, etc***. then they will get a very unpleasant message about your program trying to do something considered ***dangerous***. It may be due to ***system(); function*** used in program. Read more about it [here](http://www.cplusplus.com/reference/cstdlib/system/) and [here](http://www.cplusplus.com/articles/j3wTURfi/)
