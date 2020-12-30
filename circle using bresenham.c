#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
double radius,a,b;
void init()
{
    gluOrtho2D(-500,500,-500,500);
}
void display(void)
{
    double x,y,d;
    x=0;
    y=radius;
    d=1-radius;
    while(y>x)
  {
        if(d<0)
        {
            d+=(2*x)+3;
        }
Else
{
            d+=(2*x)-(2*y)+5;
            y-=1;
        }
        x+=1;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(a+x,b+y);
        glVertex2f(a-x,b+y);
        glVertex2f(a+x,b-y);
        glVertex2f(a-x,b-y);
        glVertex2f(a+y,b+x);
        glVertex2f(a-y,b+x);
        glVertex2f(a+y,b-x);
        glVertex2f(a-y,b-x);
    }
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    printf("Enter the radius of the circle:");
    scanf("%lf",&radius);
    printf("Enter the centre of the circle:");
    scanf("%lf %lf",&a,&b);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Bresenham Circle AMAN SARAOGI");
    gluOrtho2D(-500,500,-500,500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
