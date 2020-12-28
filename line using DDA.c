#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <math.h>
float x1,y3,x2,y2;
void display(void)
{
 float dy,dx,step,x,y,i,Xin,Yin;
 dx=x2-x1;
dy=y2-y3;
if(abs(dx)>abs(dy))
{
step=abs(dx);
}
else
{
step=abs(dy);
}
Xin=(dx/step)/100;
Yin=(dy/step)/100;
x=x1;y=y3;
//glClearColor(1,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
glBegin(GL_POINTS);
for(i=0.01;i<=step;i=i+0.01)
{
glVertex2f(x,y);
x=x+Xin;
y=y+Yin;
//glVertex2f(x,y);
}
glEnd();
glColor3f(1,1,1);
glRasterPos2f(-0.70,-0.70);
glFlush();
}
int main(int argc,char** argv)
{
printf("Enter the two end-points of the line:");
 printf("x1 =");
 scanf("%f",&x1);
 printf("y1 =");
 scanf("%f",&y3);
 printf("x2 =");
 scanf("%f",&x2);
 printf("y2 =");
 scanf("%f",&y2);
// glutDisplayFunc(display);
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(200,200);
 glutCreateWindow("dda algorithm");
 glutDisplayFunc(display);
//glutCreateWindow("Y=mx+c");
glutMainLoop();
 return 0;
}
