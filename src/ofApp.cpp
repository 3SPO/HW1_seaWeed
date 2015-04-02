#include "ofApp.h"
/*  Alex Esposito
    Seaweed quiz for Advanced Coding
    4/1/2015
 */

//--------------------------------------------------------------
void ofApp::setup(){
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //This is the equations used to move the top two points of the polyline in order to give it natural movement. This is done through sin and cos
    pos = sin(ofGetElapsedTimef()/2.1)*50 + ofGetWindowWidth()/2.0f ;
    pos1 = cos(ofGetElapsedTimef()/2.3)*25 + ofGetWindowWidth()/2.0f ;
}

//--------------------------------------------------------------
void ofApp::draw(){
    //set up the color of the main polyline
    paint.setHue( 60 ) ;
    paint.setSaturation( 255 ) ;
    paint.setBrightness( 250 ) ;
    ofSetColor(paint) ; //initilize the color
    //This is the main piece of the drawing done in the code. This create the polyline with two anchors. The top anchor and the point directly underneath it uses pos and pos1 in order to give it movement
    seaWeed.curveTo(pos, 30);
    seaWeed.curveTo(pos, 30);
    seaWeed.curveTo(pos1, 200);
    seaWeed.curveTo(250, 420);
    seaWeed.curveTo(250, 550);
    seaWeed.curveTo(250, 550);
    seaWeed.draw() ; // draws the line that was created
    
    
    //two variables created. The first is numPoints used in the creation of tangent lines on the original polyline and the second is a counter to adjust the brightness to scale from dark to light as the tangent lines go up the polyline
    float numPoints = 3 ;
    int lineBrightness = 240 ;
    //This is the most math intensive portion of the code. This code creates tangent lines across the whole polyline in order to create the "leaves" of the seaweed
    for (int a=0; a<100; a+=1) {
        //makes the sizes go from large to small from the bottom of the original polyline straight to the top
        normalLength = (a * -1) / 2 ;
        //this creates a brightness of green from dark to light going up the original polyline in correlation withe the growth of size in the tangent lines
        lineBrightness-- ;
        paint.setBrightness(lineBrightness) ;
        ofSetColor(paint) ; //initialize the color
        // using getPointatPercent to space the tangent lines evenly up the entire original polyline and interpolate them to give them the wavy appearance
        ofVec3f point = seaWeed.getPointAtPercent(a/100.0);
        float floatIndex = a/100.0 * (numPoints-1);
        ofVec3f normal = seaWeed.getNormalAtIndexInterpolated(floatIndex) * normalLength;
        ofLine(point-normal/2, point+normal/2);
    }
    seaWeed.clear() ;
    
    //congratualtions you now have achieved a university students level of coding prowess. pat yourself on the back and keep it up.
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
