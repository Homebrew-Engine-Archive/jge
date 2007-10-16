Introduction
------------

JGE++ (Jas Game Engine++) is a hardware accelerated 2D game SDK for PSP. It supports cross-platform development under MS Windows. The entire game development process, including coding, debugging and testing, can be done in Windows. (However, it's still recommended to test your game on PSP from time to time to make sure everything is fine.)

You can use JGE++ to make Windows games but the primary platform is PSP.


Directory Structure:
--------------------
____JGE
|    |___HGE (Windows backend)
|    |___include (JGE++ header files)
|    |___lib
|    |    |___psp (lib files for PSP)
|    |    |    |
|    |    |    |___libjgesky.a (SkyAnimator lib)
|    |    |    |___libjge.a (JGE++ lib)
|    |    |
|    |    |___win (lib files for Windows)
|    |         |
|    |         |___JgeSky60.lib (SkyAnimator lib for VC6.0)
|    |         |___JgeSky71.lib (SkyAnimator lib for VC2003)
|    |         |___jge.lib (JGE++ lib Release version)
|    |         |___jge_debug.lib (JGE++ lib debug version)
|    |
|    |___src (JGE++ source files)
|
|___Demo
|    |___bin
|    |___Debug
|    |___JGEFramework
|    |___Release
|    |___src
|        |___GameApp.cpp
|        |___GameApp.h
|            
|___Mario (same structure as Demo)
|
|___SkyDemo (same structure as Demo)
|
|___StarBugz (same structure as Demo)


To build the JGE++ lib for Windows:
-----------------------------------
Open "JGE.dsw" in JGE directory with Visual Studio 6.0. With the BATCH BUILD
option, select "REBUILD ALL".


To build the JGE++ lib for PSP:
-------------------------------
Change to JGE directory, then

make clean
make install

or just run the batch file "mk.bat"


To build a project for Windows:
-------------------------------
Open "xxx.dsw" in the project directory with Visual Studio 6.0 and build 
for either "Release" or "Debug". 


To build a project for PSP:
---------------------------
Change to the project directory, then

make clean
make

or just run the batch file "mk.bat"


To Run (on Windows):
--------------------
You need DirectX 8.0+ installed.

Key mapping:

PSP                     WINDOWS
------------------      -------------
UP/DOWN/LEFT/RIGHT      W/S/A/D
ANALOG CONTROL          UP/DOWN/LEFT/RIGHT
TRIANGLE                8 on NumPad (with NUMLOCK)
SQUARE                  4 on NumPad (with NUMLOCK)
CIRCLE                  6 on NumPad (with NUMLOCK)
CROSS                   2 on NumPad (with NUMLOCK)
SELECT                  CTRL
START                   ENTER
HOME                    F1
HOLD                    F2
NOTE                    F3
L                       Q
R                       E


To Run (on PSP):
----------------
With firmware 1.50 PSP, use KXploit Tool to transfer the proper EBOOT.PBP 
onto your memory stick. Then you need to copy the entire folder "Res" into 
the appropriate folder.


License:
--------

JGE++ is Licensed under the BSD license, see LICENSE in root folder for details.


Special thanks to:
------------------

- PSPSDK team
- devkitPro team
- friends at pspchina.net
- Jasmine (James' lovely wife)


Credits:
--------
JGE++: 
Programmer - James Hui (a.k.a. Dr.Watson)

SkyAnimator and SkyAnimator Demo:
Programmer - HuangYZ

JGE++ Demo:
Programmer - James Hui
Artist - Zhen (TMD Games)

StarBugz:
Programmer - James Hui
Artist - Fung Lap Tong

Mario Demo:
Programmer - James Hui
Artist - Zhen (TMD Games)


Contact:
--------
Bugs and comments can be forwarded to jhkhui@yahoo.com.
 
Copyright (C) 2006 James Hui 
Copyright (C) 2006 HuangYZ


History:
--------

[2006.03.26]

- v0.2b released. 
- First version that enabled cross-platform development on Windows by using HGE
- Bundled with SkyAnimator and source code of StarBugz and Mario Demo.

[2006.03.12]

- first public release.
- PSP only.