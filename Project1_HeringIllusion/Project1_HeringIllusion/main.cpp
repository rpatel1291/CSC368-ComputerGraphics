//
//  main.cpp
//  Project1_HeringIllusion
//
//  Created by Ravi Patel on 7/8/15.
//  Copyright (c) 2015 Ravi Patel. All rights reserved.
//


#include <openGL/gl.h>
#include <openGL/glu.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdlib.h>


void display(void){
    float width = 799.9, height = 399.9;
    float length = sqrtf((width*width) + (height*height));
    float t, p=3.141593/180;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0 , 0.0 , 0.0);
    glBegin(GL_LINES);
    for (int point = 0; point < 180; point = point + 10) {
        t=point*p;
        glVertex2f(length*cosf(t), length*sinf(t));
        glVertex2f(-1*length*cosf(t), -1*length*sinf(t));
    }
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-1*width, 50);
    glVertex2f(width, 50);
    glVertex2f(-1*width, -50);
    glVertex2f(width, -50);
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,400);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Hering Illusion");
    glClearColor(1.0,1.0,1.0,1.0);
    gluOrtho2D(-800.0,800.0,-400.0,400.0);
    glutDisplayFunc(display);
    glutMainLoop();
}
