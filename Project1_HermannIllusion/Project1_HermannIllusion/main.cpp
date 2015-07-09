//
//  main.cpp
//  Project1_HermannIllusion
//
//  Created by Ravi Patel on 7/9/15.
//  Copyright (c) 2015 Ravi Patel. All rights reserved.
//

#include <openGL/gl.h>
#include <openGL/glu.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdlib.h>


void display(void){
    float width = 500.0, length = 500.0, boxWidth = 90.0, boxHeight = boxWidth;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0 , 0.0 , 0.0);
    glBegin(GL_QUADS);
    for (float start=5.1; start<width; start+=.1) {
        glVertex2f(start, 5);
        glVertex2f(start, length-.1);
        glVertex2f(start+boxWidth, length-.1);
        glVertex2f(start+boxWidth, 5);
        start = start+boxWidth+10;
    }
    glColor3f(1.0, 1.0, 1.0);
    
    for (float start = boxHeight; start<500; start+=.1) {
        glVertex2f(.1, start);
        glVertex2f(.1, start+10);
        glVertex2f(width-.1, start+10);
        glVertex2f(width-.1, start);
        start += boxHeight+10;
    }
    
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Hermann Illusion");
    glClearColor(1.0,1.0,1.0,1.0);
    gluOrtho2D(0,500.0,0,500.0);
    glutDisplayFunc(display);
    glutMainLoop();
}
