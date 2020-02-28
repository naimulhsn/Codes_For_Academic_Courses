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
float x;
float y;
static void resize(int width, int height)
{
    if(height==0)height = 1;
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(width>height)gluOrtho2D(0, 100*ar, 0.0, 100.0);
    else gluOrtho2D(0.0, 100.0, 0.0, 100.0/ar);
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
void drawFilledCircle(GLfloat x, GLfloat y, GLdouble radius,int c)
{
    int i;
    int triangleAmount = 99; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * 3.14159265;
    //glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLE_FAN);
    clrRnd();
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        if(c&&i%5==0)clrRnd();
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}
void drawLineCircle(GLfloat x, GLfloat y, GLdouble radius,GLfloat width)
{
    glLineWidth(width);
    int triangleAmount = 199; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * 3.14159265;
    //glShadeModel(GL_SMOOTH);
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i <= triangleAmount; i++)
    {
        if(i%10==0)clrRnd();
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}
void drawFlowerTriangles(GLfloat x, GLfloat y, GLdouble r1, GLdouble r2,int n)
{
    int i;
    int triangleAmount = n; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * 3.14159265;
    //glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);

    for(i = 0; i <= triangleAmount; i++)
    {
        int j=(i+1)%(triangleAmount+1);
        //if(i%5==0)clrRnd();
        clrRnd();
        glVertex2f(x, y);
        glVertex2f(
            x + (r1 * cos(i *  twicePi / triangleAmount)),
            y + (r1 * sin(i * twicePi / triangleAmount))
        );
        glVertex2f(
            x + (r2 * cos(j *  twicePi / triangleAmount)),
            y + (r2 * sin(j * twicePi / triangleAmount))
        );
    }
    glEnd();
}
void flower(float x, float y)
{
    drawFlowerTriangles(x,y,8,12,25);
    drawFlowerTriangles(x,y,5,7,30);
    drawFilledCircle(x,y,2,0);
}
static void display(void)
{
    srand(time(NULL));
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
    glLoadIdentity();               // Reset the model-view matrix
    glPushMatrix();

    x+=.1*(rand()%5 -3);
    if(x>30 )x=30;
    if(x<-20)x=-20;
    y+=.1*(rand()%5 -2);
    if(y>10)y=10;
    if(y<-10)y=-10;
    glLineWidth(4);
    glBegin(GL_LINES);
    color(80);
    glVertex2d(30+x,50+y);
    glVertex2d(50,10);

    glVertex2d(50+x,60+y);
    glVertex2d(50,10);

    glVertex2d(70+x,50+y);
    glVertex2d(50,10);


    glEnd();
    flower(30+x,50+y);
    flower(50+x,60+y);
    flower(70+x,50+y);
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
    case 'c':
        glutPostRedisplay();
        break;

    }


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
    glutIdleFunc(idle);

    glClearColor(0,0,0,1);

    glutMainLoop();

    return EXIT_SUCCESS;
}
