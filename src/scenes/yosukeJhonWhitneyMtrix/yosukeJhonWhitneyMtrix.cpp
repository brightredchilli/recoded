
#include "yosukeJhonWhitneyMtrix.h"

void yosukeJhonWhitneyMtrix::setup(){
  
// setup pramaters
    numOfGroup.set("number-of-group", 4, 1, MAXNUMOFGROPU);
    parameters.add(numOfGroup);
    numOfBall.set("number-of-ball", 6, 1, MAXNUMOFBALL);
    parameters.add(numOfBall);
    radius.set("rotation-radius", 150, 1, 1000 );
    parameters.add(radius);
    speed.set("speed", 1.0, 0.0, 10.0 );
    parameters.add(speed);
    ballRadius.set("ball-radius", 4, 0, 10);
    parameters.add(ballRadius);


    loadCode("scenes/yosukeJhonWhitneyMtrix/exampleCode.cpp");
    
    
    
    ofSetVerticalSync(true);
    ofBackground(0,0,0);
    ofSetCircleResolution(150);
    
    //transform the origin to the center of the screen.
    xorigin = dimensions.width/2.0;
    yorigin = dimensions.height/2.0;
    
    //the radius of the lissajus
    //radius = ;
    
    
    //set the initial positon of the ball
    for (int j=0; j<numOfGroup; j++) {
        for (int i = 0; i < numOfBall; i++) {
            t = ofGetElapsedTimef() / 10.0;
            angleofangle[j][i] = - (i-1)*PI/15;
            
            
            if(j==0 || j==1){
                angle[j][i] = 5.0*sin((t-0.1) * PI/2.0 - PI/2.0) + 3.0*angleofangle[j][i];
            } else {
                angle[j][i] = 5.0*sin((t-0.1) * PI/2.0 - PI/2.0) + 3.0*angleofangle[j][i];
            }
            
            x[j][i] = xorigin + radius * sin(angle[j][i] * 1.0);
            y[j][i] = yorigin + radius * -sin(angle[j][i] * 1.5);
            
        }
    }

    
}

void yosukeJhonWhitneyMtrix::update(){
    t = ofGetElapsedTimef()  / 10.0;
    for (int j=0; j<numOfGroup; j++) {
        for (int i = 0; i < numOfBall; i++) {
            angleofangle[j][i] = - (i-1)*PI/20; //the argument of sin
            if(j==0 || j==1){
                angle[j][i] = speed * (5.0*sin((t-0.1) * PI/2.0 - PI/2.0) + 3.0*angleofangle[j][i]);
            } else {
                angle[j][i] = speed * (5.0*sin((t-0.1) * PI/2.0 - PI/2.0) + 3.0*angleofangle[j][i]);
            }
        }
    }
   
}

void yosukeJhonWhitneyMtrix::draw(){
    for (int j=0; j<numOfGroup; j++) {
        for (int i = 0; i < numOfBall; i++) {
            if(j==0){
                x[j][i] = xorigin + radius * -sin(1.0 * (angle[j][i] - PI/2.0));
                y[j][i] = yorigin + radius * sin(1.5 * (angle[j][i] - PI/2.0));
                
            } else if(j==1){
                x[j][i] = xorigin + radius * sin(1.0 * (angle[j][i] - PI/2.0));
                y[j][i] = yorigin + radius * sin(1.5 * (angle[j][i] - PI/2.0));
            }  else if(j==2){
                x[j][i] = xorigin + radius * cos(1.0 * (angle[j][i] - PI/4.5));
                y[j][i] = yorigin + radius * cos(1.5 * (angle[j][i] - PI/4.5));
                
            } else {
                x[j][i] = xorigin + radius * -cos(1.0 * (angle[j][i] - PI/4.5));
                y[j][i] = yorigin + radius * cos(1.5 * (angle[j][i] - PI/4.5));
            }
        }
    }
    
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(255);
    ofFill();
    for (int j=0; j<numOfGroup; j++) {
        for (int i = 0; i < numOfBall; i++) {
            ofDrawCircle(x[j][i], y[j][i], ballRadius);
        }
    }

}
