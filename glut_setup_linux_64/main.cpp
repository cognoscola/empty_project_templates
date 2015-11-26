#include <iostream>
#include <GL/glut.h>

using namespace std;

void init();

void display(void)
{
    //Clear all pixels
    glClear(GL_COLOR_BUFFER_BIT);

    //draw white polygon (rectangle) with corners at
    // (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(0.25, 0.75, 0.0);
    glEnd();

    // Don't wait start processing buffered OpenGL routines
    glFlush();
}


int main(int argc, char** argv) {


    //Initialise GLUT with command-line parameters.
    glutInit(&argc, argv);

    //Set Display Mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    //Set the window size
    glutInitWindowSize(250,250);

    //Set the window position
    glutInitWindowPosition(100,100);

    //Create the window
    glutCreateWindow("A Simple OpenGL Windows Application with GLUT");

    //Call init (initialise GLUT
    init();

    //Call "display" function
    glutDisplayFunc(display);

    //Enter the GLUT event loop
    glutMainLoop();


    cout << "Hello, World!" << endl;
    return 0;
}

void init(void){

    //select clearing (background) color
    glClearColor(0.0, 0.0, 0.0, 0.0);

    //initialize viewing values
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

}