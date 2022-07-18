#include "stdafx.h"
#include <stdio.h>
#include <GL/glut.h>
float width = 800.0;
float height = 600.0;
void changeSize(int w, int h)
{
    if (h == 0)
        h = 1;
    width = w;
    height = h;
    GLdouble ratio = 1.0f * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 10,
              0, 0, -1,
              0, 1, 0);
}
void renderScene()
{
    glClearColor(0, 0, 255, 1);
    glClearDepth(1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);;
    glRotatef(0.09, 0.0, 0.0, 0.09);
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(-3.0, 0.0, 0.0);
    glRotatef(0.09, 0.0, 0.0, -1.0);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-1, -1);
    glVertex2f(0, 1);
    glVertex2f(1, -1);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 200);
    glutInitWindowSize(width, height);
    glutCreateWindow("OpenGL");
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutMainLoop();
    return (0);
}
