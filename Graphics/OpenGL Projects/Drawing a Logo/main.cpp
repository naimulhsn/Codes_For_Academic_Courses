/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<iostream>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

static int slices = 16;
static int stacks = 16;
GLfloat angle = 0.0f;
/* GLUT callback Handlers */

static void resize(int width, int height)
{
    if(height==0)height = 1;
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(width>height)gluOrtho2D(20, 80*ar, 20.0, 80.0);
    else gluOrtho2D(20.0, 80.0, 20.0, 80.0/ar);
}
void color(int n)
{
    float b=(float)(n%10)/10.0;
    n/=10;
    float g=(n%10)/10.0;
    n/=10;
    float r=(n%10)/10.0;
    glColor3f(r, g, b);
}
void clrRnd()
{
    float r = (float)(rand()%11)/10.0;
    float g = (float)(rand()%11)/10.0;
    float b = (float)(rand()%11)/10.0;
    glColor3f(r, g, b);
}
static void display(void)
{
    //srand(time(NULL));
    //const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    //const double a = t*90.0;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
    glLoadIdentity();               // Reset the model-view matrix
    glPushMatrix();
    //glTranslatef(-0.4f, -0.3f, 0.0f);   // Translate
    //glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees


    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    clrRnd();
    //color(800);
    glVertex2d(50,30);
    glVertex2d(55,30);
    //color(80);
    clrRnd();
    glVertex2d(55,55);
    glVertex2d(65,30);
    glVertex2d(70,30);
    glVertex2d(70,60);
    glVertex2d(65,60);
    glVertex2d(65,35);
    glVertex2d(55,60);
    glVertex2d(50,60);
    glEnd();
/*
    glBegin(GL_TRIANGLES);
    color(000);
    glVertex2d(55,30);
    glVertex2d(55,40);
    glVertex2d(60,30);
    glEnd();
*/
    glPopMatrix();

    glutSwapBuffers();   // Double buffered - swap the front and back buffers

    angle +=.1f;
    //glFlush();  // Render now

}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 :
    case 'q':
        exit(0);
        break;

    case '+':
        slices++;
        stacks++;
        break;

    case '-':
        if (slices>3 && stacks>3)
        {
            slices--;
            stacks--;
        }
        break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800,500);
    glutInitWindowPosition(10,10);

    glutCreateWindow("Basic Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    //glutIdleFunc(idle);

    glClearColor(0,0,0,1);

    glutMainLoop();

    return EXIT_SUCCESS;
}
