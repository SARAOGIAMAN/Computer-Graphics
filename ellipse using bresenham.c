#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
double c1,c2,rx,rv;
void init()
{
    gluOrtho2D(-500,500,-500,500);
}
void display(void)
{
    double a,b,a2,b2,d1,d2,x,y;
    a=rx;
    b=rv;
    a2=a*a;
    b2=b*b;
    x=0;
    y=b;
    d1=b2+(a2*((1/4)-b));
    while((x*b2)<=(y*a2)){
        if(d1<0){
            d1+=b2*((2*x)+3);
        }
        else{
            d1+=b2*((2*x)+3)-a2*((2*y)-2);
            y-=1;
        }
        x+=1;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(c1+x,c2+y);
        glVertex2f(c1-x,c2+y);
        glVertex2f(c1+x,c2-y);
        glVertex2f(c1-x,c2-y);
    }
    glEnd();
    d2=(b2*(x+1/2)(x+1/2)) + (a2*(y-1)*(y-1)) - (a2*b2);
    while(y!=0){
        if(d2<0){
            d2+=2*b2*(x+1) - a2*(2*y-3);
            x+=1;
        }
        else{
             d2+=a2*(3-2*y);
        }
        y-=1;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(c1+x,c2+y);
        glVertex2f(c1-x,c2+y);
        glVertex2f(c1+x,c2-y);
        glVertex2f(c1-x,c2-y);
    }
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    printf("Enter the Major Axis of the ellipse:");
    scanf("%lf",&rx);
    printf("Enter the Minor Axis of the ellipse:");
    scanf("%lf",&rv);
    printf("Enter the centre of the ellipse:");
    scanf("%lf %lf",&c1,&c2);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Bresenham Ellipse AMAN SARAOGI");
    gluOrtho2D(-500,500,-500,500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
