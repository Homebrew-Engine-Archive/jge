@echo off

IF %1 == "" GOTO ERROR

IF %2 == "" GOTO ERROR

mkdir ..\Projects\%1
xcopy template ..\Projects\%1 /e /y
replac32 template %1 ..\Projects\%1\template.sln
replac32 template %1 ..\Projects\%1\template.vcproj
replac32 template_desc %2 ..\Projects\%1\Makefile.1xx
replac32 template %1 ..\Projects\%1\Makefile.1xx
replac32 template_desc %2 ..\Projects\%1\Makefile.3xx
replac32 template %1 ..\Projects\%1\Makefile.3xx
replac32 template_desc %2 ..\Projects\%1\src\GameLauncher.cpp
rename ..\Projects\%1\template.sln %1.sln
rename ..\Projects\%1\template.vcproj %1.vcproj
rename ..\Projects\%1\template.vcproj.user %1.vcproj.user

GOTO DONE

:ERROR
echo usage: newproject project_name project_description

:DONE