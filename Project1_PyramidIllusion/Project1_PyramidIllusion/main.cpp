//
//  main.cpp
//  Project1_PyramidIllusion
//
//  Created by Ravi Patel on 7/10/15.
//  Copyright (c) 2015 Ravi Patel. All rights reserved.
//

#include <openGL/gl.h>
#include <openGL/glu.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdlib.h>


void display(void){
    float width = 500.0, length = 500.0; //start=.1;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0 ,0.0 , 0.0);
    glBegin(GL_QUADS);
    float change = .01;
    for( float start= 0; start <= width; start+= .1){
        glVertex2f(start,start);
        glVertex2f(width, start);
        glVertex2f(width, length);
        glVertex2f(start, length);
        length -= 10;
        width-= 10;
        start+=10;
        change+=.03;
        glColor3f(change, change, change);
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Pyramid Illusion");
    glClearColor(1.0,1.0,1.0,1.0);
    gluOrtho2D(0,500.0,0,500.0);
    glutDisplayFunc(display);
    glutMainLoop();
}
