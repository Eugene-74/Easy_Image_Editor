unset GTK_PATH
sh compileLib.sh

g++ -g main.cpp ressources/qrc_ressources.cpp \
    -fPIC \
    -L./lib -lfolders -o main.exe  `pkg-config --cflags --libs Qt5Widgets Qt5Gui Qt5Core opencv4` -lexiv2
