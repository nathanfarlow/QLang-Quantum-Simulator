#include "ofApp.h"

#include "quantum/qlang.h"

#include <bitset>

using namespace quantum;

ofTrueTypeFont font;

std::string load(std::string file) {
    std::ifstream in(file);

    if(!in)
        throw "Could not open qlang program file.";

    std::string program;

    std::string line;
    while(std::getline(in, line))
        program += line + "\n";

    return program;
}

//--------------------------------------------------------------
void ofApp::setup() {
    gui.setup();
    
    input.setup();
    try {
        input.text = load("qlang/Deutsch-Jozsa.qlang");
    } catch(...) {
        input.text = ";enter qlang program here\n\n";
    }
    input.bounds.x = 20;
    input.bounds.y = 20;
    input.bounds.width = 400;
    input.bounds.height = 800;
    input.multiline = true;
    font.loadFont(OF_TTF_MONO, 10);
    input.setFont(font);

    output.setup();
    output.bounds.x = input.bounds.x + input.bounds.width + 20;
    output.bounds.y = 20;
    output.bounds.width = input.bounds.width;
    output.bounds.height = input.bounds.height;
    output.multiline = true;
    output.setFont(font);

    compile.setup("Compile");
    compile.setPosition(335, 830);
    compile.addListener(this, &ofApp::compilePressed);
}

std::string to_binary(size_t i, size_t num_qubits) {
    std::string binary = std::bitset<64>(i).to_string();
    return binary.substr(binary.length() - num_qubits, binary.length());
}

void ofApp::compilePressed() {
    std::string source = input.text;

    QLangParser parser;
    QCircuit *c = nullptr;

    try {
        c = parser.Compile(input.text);
    } catch(std::string err) {
        output.text = err;
    }

    if(c != nullptr) {
        QState state = c->Compute();

        output.text = "";
        for(size_t i = 0; i < state.get_rows(); i++) {
            quantum::complex amp = state[i][0];
            output.text += to_binary(i, c->get_num_qubits()) + ": "
             + std::to_string(amp.real()) + "+"
             + std::to_string(amp.imag()) + "i" 
             + " (" + std::to_string(std::abs(amp) * std::abs(amp)) + ")"
             + "\n";
        }
    }

    delete c;
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

    compile.draw();
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
