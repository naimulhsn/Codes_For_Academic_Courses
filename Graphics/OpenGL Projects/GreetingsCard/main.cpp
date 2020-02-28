#include<windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

/* GLUT callback Handlers */
float xx,x,y;
float yy;
GLfloat doot=0;
GLfloat sz=2000;
GLint height=500;
GLint width=800;
char message[] = "HAPPY NEW YEAR";
char message2[] = "2020";
static void resize(int width, int height)
{
    if(height==0)height = 1;
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    xx=sz;
    yy=sz;
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
void rndcol(int n){
    int ccc=((rand()%n)*100) + ((rand()%n)*10) +(rand()%n);
    color(ccc);
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
    if(c<0)clrRnd();
    else color(c);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        //if(c&&i%5==0)clrRnd();
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
void flower(float x, float y,float szz)
{
    drawFlowerTriangles(x,y,160*szz,240*szz,25);
    drawFlowerTriangles(x,y,100*szz,140*szz,30);
    drawFilledCircle(x,y,30*szz,-1);
}
void drawLines(int c)
{
    int x1=-10,x2=xx+10,y1=0,y2=-1000;
    if(c<0)clrRnd();
    else color(c);
    glLineWidth(2);
    glBegin(GL_LINES);
    for(int i=0; i<100; i++){
        glVertex2d(x1,y1+(i*50));
        glVertex2d(x2,y2+(i*50));
        glVertex2d(x1,y2+(i*50));
        glVertex2d(x2,y1+(i*50));
    }
    glEnd();
}
void text(){
    glLineWidth(10);

    glTranslatef(400,1500,0);
    for (int i = 0; i < strlen(message); i++) {
        clrRnd();
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, message[i]);
    }
}
void text2(){
    glLineWidth(20);

    glTranslatef(600,-1100,0);
    for (int i = 0; i < strlen(message2); i++) {
        clrRnd();
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, message2[i]);
    }
}
void rec(double x1,double y1, double x2, double y2){
    glBegin(GL_QUADS);
    glVertex2d(x1,y1);
    glVertex2d(x2,y1);
    glVertex2d(x2,y2);
    glVertex2d(x1,y2);
    glEnd();
}
void flowers(){
    flower(500,700,1);
    flower(1300,700,1);
    flower(900,900,1.2);
}
void mask();
void dot(int c){
    color(c);
    for(int i=0; i<=xx; i+=100){
        for(int j=0; j<=yy; j+=100){
            //glVertex2d(i,j);
            drawLineCircle(i+doot,j-doot,10,5);
            if(rand()%100==0)drawFlowerTriangles(i,j,100,160,15);
        }
    }
    doot+=3;
    if(doot>100)doot=0;

}
static void display(void)
{
    srand(time(NULL));
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
    glLoadIdentity();               // Reset the model-view matrix
    glPushMatrix();

    color(369);
    rec(200,200,3000,1800);
    //drawFilledCircle(0,2000,3000,0);

    clrRnd();
    //drawLines(666);
    //drawFilledCircle(-2000,200,3200,0);
    drawFilledCircle(100,2000,2000,999);
    drawFilledCircle(3500,-800,2000,746);

    dot(770);

    rndcol(2);
    rec(2400,350,4000,550);
    //flowers();


    mask();
    rndcol(3);
    rec(200,1450,1400,1650);
    rec(1350,1400,1900,1450);
    rec(1350,1650,1900,1700);
    rec(1900,1400,1950,1700);
    text();
    text2();
    glPopMatrix();

    glutSwapBuffers();   // Double buffered - swap the front and back buffers


}

void mask(){
    int val[]={

        0,0,    200,0,    200,yy,   0,yy,
        0,0,    xx,0,    xx,200,   0,200,
        3000,0,   xx,0,    xx,yy,  3000,yy,
        0,1800,   xx,1800,   xx,yy,  0,yy

    };
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        for(int i=0; i<32; i+=2){
            if(i%2==0)clrRnd();
            glVertex2d(val[i],val[i+1]);
        }
    glEnd();
}
void mask2(){
    int val[]={

        -10,-10,    200,-10,    200,5000,   -10,5000,
        -10,-10,    5000,-10,    5000,200,   -10,200,
        3000,-10,   5000,-10,    5000,5000,  3000,5000,
        -10,1800,   5000,1800,   5000,5000,  -10,5000

    };
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        for(int i=0; i<32; i+=2){
            glVertex2d(val[i],val[i+1]);
        }
    glEnd();
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
    glutInitWindowSize(width,height);
    glutInitWindowPosition(10,10);

    glutCreateWindow("Greeting Card");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0,0,0,1);
    //glClearColor(0.7,0.8,0.8,1);

    glutMainLoop();

    return EXIT_SUCCESS;
}
