
/*
#include <QApplication>


int main(int argc,char *argv[])
{
    QApplication app(argc,argv);



    return app.exec();
}
*/

#include <QCoreApplication>
#include <QApplication>
#include <iostream>
#include <QLibrary>
#include "../MagineGui/QtGui/MagineMainWindow.h"
//#include <GL/glut.h>
//#include "GlutWindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MagineMainWindow w;
    w.show();
    return a.exec();
}

/*
#include <QtCore/QCoreApplication>
//#include <QApplication>
//#include <QtDebug>
//#include <QDir>
#include <iostream>
#include <QLibrary>
#include "../MagineDependency/OpenGL/GL/glut.h"
//#include "../MagineBase/MagineMath/Vector.h"
//#include "../MagineBase/MagineMath/Matrix.h"
#include "../MagineBase/MagineMath/Range.h"
#include "../MagineGeometry/Cartesian_Grids/Grid.h"
#include "GlutWindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    //QCoreApplication app(argc, argv);
    //Glut
    //glutInit(&argc,argv);

    //GlutWindow* window = new GlutWindow("Test",500,500);

    //glutMainLoop();

    //end Glut
    //cout<<endl;
    //qDebug() << QDir::currentPath();
    return 0;
    //return app.exec();
}
*/



