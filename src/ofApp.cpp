#include "ofApp.h"
ofTrueTypeFont font;
//--------------------------------------------------------------
void ofApp::setup() {
    gui.setup();
    
    input.setup();
    input.text = "fuck\ning\nhell";
    input.bounds.x = 20;
    input.bounds.y = 20;
    input.bounds.width = 400;
    input.bounds.height = 500;
    input.multiline = true;
    font.loadFont(OF_TTF_SERIF, 10);
    input.setFont(font);

    output.setup();
    output.bounds.x = input.bounds.x + input.bounds.width + 20;
    output.bounds.y = 20;
    output.bounds.width = input.bounds.width;
    output.bounds.height = input.bounds.height;
    output.multiline = true;
    output.setFont(font);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(255*.15);
    
    ofSetColor(255);
    ofRect(input.bounds);
    ofRect(output.bounds);
    ofNoFill();
    input.draw();
    output.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) { 

}
