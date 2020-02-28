#include<windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

/* GLUT callback Handlers */
float xx,x,y;
float yy;
GLfloat sz=100;
GLint height=500;
GLint width=500;
static void resize(int width, int height)
{
    if(height==0)height = 1;
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(width>height){gluOrtho2D(0, sz*ar, 0.0, sz); xx=sz*ar;}
    else {gluOrtho2D(0.0, sz, 0.0, sz/ar); yy=sz/ar;}
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
    color(c);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
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

static void display(void)
{
    srand(time(NULL));
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
    glLoadIdentity();               // Reset the model-view matrix
    glPushMatrix();
    glPointSize(5);
    clrRnd();
    int v[]={
                13,18,
                15,18,
                15,87,
                13,87,

                12,87,
                16,87,
                15,89,
                13,89,
//base
                10,15,
                18,15,
                18,18,
                10,18,

                6,12,
                22,12,
                20,15,
                8,15,

                16,61,
                56,61,
                56,85,
                16,85,

        };

    glBegin(GL_QUADS);
        for(int i=0; i<sizeof(v)/sizeof(v[0]); i+=2){
                if(i==32)color(42);
                else if(i==0)glColor3ub(69, 69, 69);
                else if(i==8)glColor3ub(110, 97, 89);
                else if(i==16)glColor3ub(138, 105, 85);
                else if(i==24)glColor3ub(112, 80, 61);
                glVertex2i(v[i],v[i+1]);
        }
    glEnd();
    drawFilledCircle(34,73,8,911);

    //glBegin(GL_LINES);

    //glEnd();


    glPopMatrix();

    glutSwapBuffers();


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
    //glutPostRedisplay();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(10,10);

    glutCreateWindow("Flag");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    //glClearColor(0.7,0.8,0.8,1);

    glutMainLoop();

    return EXIT_SUCCESS;
}
