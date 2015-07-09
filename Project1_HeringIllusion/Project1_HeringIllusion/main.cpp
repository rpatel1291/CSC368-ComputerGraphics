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

/*
    Displaying function used to create the image
*/
void display(void){
    /*
        Variables are floating point
            width: the base of the screen the image is being displayed
            height: the length of the screen the image is being displayed
            length: the largest length of a line needed to from center to the edge of the display
                    (the R value from X^2+Y^2 = R^2)
            p: the conversion factor to get degree into radians
            t: randiant angle
    */
    float width = 799.9, height = 399.9;
    float length = sqrtf((width*width) + (height*height));
    float t, p=3.141593/180;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0 , 0.0 , 0.0); // using black color lines
    glBegin(GL_LINES);
    /*
        For loop used to create same spacing between the lines and lines are created by placing a point at on edge and using (x,y) -> (-x,-y) as the second point
            ( x value = R*cos(t)   y value = R*sin(t) )
    */
    for (int point = 0; point < 180; point = point + 10) {
        t=point*p;
        glVertex2f(length*cosf(t), length*sinf(t)); //point (x,y)
        glVertex2f(-1*length*cosf(t), -1*length*sinf(t));//point (-x,-y)
    }
    glColor3f(1.0, 0.0, 0.0);// change color from black to red
    // First horizontal line
    glVertex2f(-1*width, 50);
    glVertex2f(width, 50);
    // Second horizontal line
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
    glClearColor(1.0,1.0,1.0,1.0);// creating a white color display
    gluOrtho2D(-800.0,800.0,-400.0,400.0);// x axis (-800,800) and y axis (-400,400)
    glutDisplayFunc(display);
    glutMainLoop();
}
