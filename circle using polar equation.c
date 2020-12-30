#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
void init()
{
    gluOrtho2D(-20,20,-20,20);
}
void display(void)
{   
    float x,y,theta;
    int xc,yc,r,i;
    printf("Enter the center of circle:");
    scanf("%d %d",&xc,&yc);
    printf("Enter radius of circle:");
    scanf("%d",&r);
    glBegin(GL_POLYGON);
    glColor3f(0.054f, 0.803f, 0.270f);
    for(i=0;i<360;i++)
    {   
        theta=(3.14*i)/180;
        x=xc+(r*cos(theta));
        y=yc+(r*sin(theta));
        glVertex2d(x,y);
    }
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("CIRCLE");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
