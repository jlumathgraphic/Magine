#等框架搭好后，按照starlab那样将工程文件重新写好
TEMPLATE = app     #模块配置
TARGET = MagineApp
#CONFIG += app_bundle
DESTDIR=$$_PRO_FILE_PWD_/../Bin
QT += core gui opengl


#INCLUDEPATH += ../MagineGui/QtGui
#INCLUDEPATH += ../MagineGeometry
INCLUDEPATH += ../MagineBase
INCLUDEPATH += ../Bin
#INCLUDEPATH += ../MagineDependency/OpenGL

LIBS += -L$$_PRO_FILE_PWD_/../Bin -lMagineBase
#LIBS += -L$$_PRO_FILE_PWD_/../Bin -lMagineGeometry
#LIBS += -L$$_PRO_FILE_PWD_/../Bin -lMagineAlgorithm
#LIBS += -L$$_PRO_FILE_PWD_/../Bin -lMagineQtGui
#LIBS += -L$$_PRO_FILE_PWD_/../Bin -lMagineGlut
//LIBS += -L/usr/X11/lib -lglut.3


SOURCES += main.cpp

