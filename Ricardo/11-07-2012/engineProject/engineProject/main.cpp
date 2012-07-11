#define GLUT_DISABLE_ATEXIT_HACK
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/glut.h"
#include <math.h>
#include "sphere.h"
#define PI 3.14
//gluLookAt(eye x, eye y, eye z, center x, center y, center z, up x, up y, up z);

double i = 0;

void display()
{
     i+=0.1;
     
	 Sphere mySphere = Sphere(1);
     glEnable(GL_COLOR_MATERIAL);
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glEnable(GL_DEPTH_TEST);
     glEnable(GL_LIGHT0);
     glEnable(GL_LIGHTING);
     float lpos[] = {3,3,0,1};
     glLightfv(GL_LIGHT0,GL_POSITION,lpos);
     glMatrixMode(GL_MODELVIEW);
     glColor3d(1,1,0);
     
     glPushMatrix();
     glTranslated(0,0,-3);
     gluLookAt(0,0,0,0,0,-1,0,1,0);
     
     glPushMatrix();
     glRotated(i,0,1,0);
     
     /*glBegin(GL_QUADS);
     glColor3d(0,0,0);
     glNormal3d(0,0,1);
     glVertex3d(-0.75,-0.75,-0.5);
     glVertex3d(0.75,-0.75,-0.5);
     glVertex3d(0.75,0.75,-0.5);
     glVertex3d(-0.75,0.75,-0.5);
     glColor3d(0,1,0);
     glEnd();*/
     
     
	 mySphere.Draw();
     glPopMatrix();
     glPopMatrix();
     glFlush();
     glutPostRedisplay();
}


void reshape (int w, int h)
{
    //gluPerspective(angulo de abertura,formato da tela weigth/heigth,near 0.1,far 1000);
    glViewport(0, 0, w, h);
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,(float)w/(float)h,0.1,far 300);

}

int main (int argc, char* argv[])
{
    /* open GLUT */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    
    /* create window */
    glutCreateWindow("Aula 1");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    
    /* interact … */
    glutMainLoop();
    return 0;
}
