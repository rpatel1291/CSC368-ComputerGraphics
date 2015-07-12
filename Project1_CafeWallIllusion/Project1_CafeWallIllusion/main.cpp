//
//  main.cpp
//  Project1_CafeWallIllusion
//
//  Created by Ravi Patel on 7/10/15.
//  Copyright (c) 2015 Ravi Patel. All rights reserved.
//

#include <openGL/gl.h>
#include <openGL/glu.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdlib.h>

a
void display(void){
    /*
        Variables are floating points
            Width - The width of the output display set to 500
            Length - The length of the output displat set to 500
            BoxWidth - The width of the individual black boxes
            BoxHeight The length of the individual black boxes
            Offset - The offset value given to the the box to give the illusion
            Start - The beginning x value to start drawing the black boxes
        Variable that is interger value
            Skip - Value to keep track which row of boxes should get the offset
     */
    float width = 500.0, length = 500.0, boxWidth=30, boxHeight=30; 
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0 ,0.0 , 0.0); // background color set to black
    glBegin(GL_QUADS);
    float offset,start;
    int skip=0;
    /*
        For loop used to draw boxes vertically and to set an offset to the alternating row
     */
    for (float startHeight=.1; startHeight < length; startHeight+=.1) {
        if (skip++ %2 == 0) {
            offset=.1;
        }
        else offset = 10;
        /*
         For loop to draw alternating black and white boxes. It only draws black boxes and skips a set amount of spaces and draws another black box giving the appearance of alternating colors.
         */
        for(start=offset; start < width; start+=.1){
            
            glVertex2f(start, startHeight);
            glVertex2f(start+boxWidth, startHeight);
            glVertex2f(start+boxWidth, startHeight+boxHeight);
            glVertex2f(start, startHeight+boxHeight);
            start+= 2*boxWidth;
            
        }
        startHeight+=boxHeight;
    }
    
    glColor3f(.5, .5, .5);//change color from black to grey
    /*
        For loop to draw evenly spaced horizontal thin boxes that look like lines
     */
    for (float start = boxHeight; start<width; start+=.1) {
        glVertex2f(.1, start);
        glVertex2f(.1, start+1);
        glVertex2f(width-.1, start+1);
        glVertex2f(width-.1, start);
        start += boxHeight;
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Cafe Wall Illusion");
    glClearColor(1.0,1.0,1.0,1.0);
    gluOrtho2D(0,500.0,0,500.0);
    glutDisplayFunc(display);
    glutMainLoop();
}
