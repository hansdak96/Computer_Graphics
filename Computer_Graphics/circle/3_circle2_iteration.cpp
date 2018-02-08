#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int pntX1=250, pntY1=250;//, r=5,r1,r2;
int r[3]={5,10,15},m=1000;

void plot(int x, int y)
{
        glBegin(GL_POINTS);
        glVertex2i(x+pntX1, y+pntY1);
        glEnd();
}


void myInit (void)
{
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glPointSize(4.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int minimum(int r[]){
        int i;
        if(r[0]<r[1]){
                m=r[0];
                i=0;
        }
        else{
                m=r[1];
                i=1;
        }
        if(r[2]<m){
                m=r[2];
                i=2;
        }
        return i;


}

void midPointCircleAlgo(int r)
{
        int x = 0;
        int y = r;
        int decision = 1 - r;
        plot(x, y);

        while (y > x)
        {
                if (decision < 0)
                {
                        x++; 
                        decision += 2*x+1;
                }
                else
                {
                        y--;
                        x++;
                        decision += 2*(x-y)+1;
                }
                plot(x, y);
                plot(x, -y);
                plot(-x, y);
                plot(-x, -y);
                plot(y, x);
                plot(-y, x);
                plot(y, -x);
                plot(-y, -x);
        }

}


void myDisplay(void)
{
        glClear (GL_COLOR_BUFFER_BIT);
        glColor3f (0.0, 0.0, 0.0);
        glPointSize(1.0);
        int c=1;
        while(c--){
        int count=3;
        
                Sleep(100);
                
                midPointCircleAlgo(r[0]);
                midPointCircleAlgo(r[1]);
                midPointCircleAlgo(r[2]);
                int i=minimum(r);
                if(i==0)
                        r[0]=5+rand()%100;
                if(i==1)
                        r[1]=5+rand()%100;
                if(i==2)
                        r[2]=5+rand()%100;
                glFlush ();

        //}
        Sleep(200);

        }
        

        
}

void main(int argc, char** argv)
{        
        


        glutInit(&argc, argv);
        glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize (640, 480);
        glutInitWindowPosition (100, 150);
        glutCreateWindow ("Line Drawing Alogrithms");
        //int i=10;
        //while(i--)
        glutDisplayFunc(myDisplay);
        myInit ();
        glutMainLoop();

}