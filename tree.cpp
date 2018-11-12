#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-320,320,-240,240);
}

void drawTree(int currentDepth, int maxDepth)
{
    if (currentDepth > maxDepth)
        return;
   if (currentDepth <= maxDepth - 2)
    {
        glColor3d(0.45, 0.2, 0.05);                   //set branch color
        glLineWidth(10 * static_cast<GLfloat>(pow(0.7, currentDepth)));      //set branch line  width  
    }
    else
    {
        glColor3d(0, 0.5, 0);            //set leaf color 
        glLineWidth(30 * static_cast<GLfloat>(pow(0.7, currentDepth)));        // set leaf line width 
    }

    double lineLen = 100 * pow(0.7,currentDepth);
    glBegin(GL_LINES);
    glVertex2d(0, 0);
    glVertex2d(0, lineLen);
    glEnd();

    int angle1 = 10+ rand()%40;          // taking angle of rotation to be random to remove symmetry from tree
    int angle2 = 10+ rand()%40;

    glTranslated(0, lineLen, 0);
    glRotated(-angle1, 0, 0, 1);
    drawTree(currentDepth + 1, maxDepth);
    glRotated(angle1 + angle2, 0, 0, 1);
    drawTree(currentDepth + 1, maxDepth);
    glRotated(-angle2, 0, 0, 1);
    glTranslated(0, -lineLen, 0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    drawTree(1,10);
    glEnd();
    glFlush();
}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(640,0);
    glutCreateWindow("Arpan");
    glutDisplayFunc(display);
   
    init();
   
    glutMainLoop();
    return 0;
}
