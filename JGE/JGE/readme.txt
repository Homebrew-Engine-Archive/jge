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
|    |    |    |___libjge.a (JGE++ lib)
|    |    |    |___libhgetools.a (HGE helper classes)
|    |    |
|    |    |___win (lib files for Windows)
|    |         |
|    |         |___jge.lib (JGE++ lib Release version)
|    |         |___jge_debug.lib (JGE++ lib debug version)
|    |
|    |___src (JGE++ source files)
|
|___Tools
|    |___bin
|    |___Debug
|    |___JGEFramework
|    |___Release
|    |___src
|        |___GameApp.cpp
|        |___GameApp.h
|            
|___Tutorials
|
|___Projects



To build the JGE++ lib for Windows:
-----------------------------------
Open "JGE.sln" in Visual C++ 2005 Express.


To build a project for Windows:
-------------------------------


To build JGE for PSP:
---------------------
Change to the JGE directory (say, in a cygwin prompt). 

Do either:

(1) type in "make" or "make 1xx" to build for 1.xx firmware, 
	OR
(2) type in "make 3xx" to build for 3.xx firmware.


To build a project for PSP:
---------------------------
Change to your project directory (say, in a cygwin prompt). Do either:

(1) type in "make" or "make 1xx" to build for 1.xx firmware, 
	OR
(2) type in "make 3xx" to build for 3.xx firmware.


To Run (on Windows):
--------------------

Key mapping:

PSP                     WINDOWS
------------------      -------------
UP/DOWN/LEFT/RIGHT      W/S/A/D
ANALOG CONTROL          UP/DOWN/LEFT/RIGHT
TRIANGLE                I
SQUARE                  J
CIRCLE                  L
CROSS                   K
SELECT                  CTRL
START                   ENTER
HOME                    F1
HOLD                    F2
NOTE                    F3
L                       Q
R                       E


To Run (on PSP):
----------------
Then you need to copy the entire folder "bin\Res" into the appropriate folder.


License:
--------
JGE++ is Licensed under the BSD license, see LICENSE in root folder for details.


Credits:
--------
The JGE++ Team is: 
- James Hui (a.k.a. Dr.Watson)
- Sijiu Duan (a.k.a. Chi80)


Special thanks to:
------------------
- Cheese (WAV playback code)
- Cooleyes (MP3 hardware decoder)
- Fan990099
- Firenonsuch
- Subelf
- Youmentang
- Jasmine (James' lovely wife)


Contact:
--------
Bugs and comments can be forwarded to jhkhui@gmail.com.
 
Copyright (C) 2007 James Hui 
Copyright (C) 2007 Duan Sijiu


History:
--------

[2007.10.xx]
- v 1.0 released.

[2006.03.26]
- v0.2b released. 
- First version that enabled cross-platform development on Windows by using HGE
- Bundled with SkyAnimator and source code of StarBugz and Mario Demo.

[2006.03.12]
- first public release.
- PSP only.
