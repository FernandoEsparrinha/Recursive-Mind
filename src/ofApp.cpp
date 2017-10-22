#include "ofApp.h"

ofRectangle originalRectangle;
int originalCenterX, originalCenterY, rectWidth, rectHeight;

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);
	//ofSetBackgroundAuto(false);

	//Setting the position and size of the original rectangle
	rectWidth = ofGetWidth() - 50;
	rectHeight = ofGetHeight() - 50;
	originalCenterX = (ofGetWidth() / 2) - (rectWidth / 2);
	originalCenterY = (ofGetHeight() / 2) - (rectHeight / 2);

	originalRectangle.x = originalCenterX;
	originalRectangle.y = originalCenterY;
	originalRectangle.width = rectWidth;
	originalRectangle.height = rectHeight;

	logRectangle(originalRectangle);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetWindowTitle("Recursive Mind");
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(255, 255, 255);
	recursiveRectangleDrawing(originalRectangle, true, 15);
}

//--------------------------------------------------------------
//Logs main information about the rectangle given 
void ofApp::logRectangle(ofRectangle rect) {
	ofLog(OF_LOG_NOTICE, "Rectangle : ");
	ofLog(OF_LOG_NOTICE, "X -> " + ofToString(rect.x));
	ofLog(OF_LOG_NOTICE, "Y -> " + ofToString(rect.y));
	ofLog(OF_LOG_NOTICE, "WIDTH -> " + ofToString(rect.width));
	ofLog(OF_LOG_NOTICE, "HEIGHT -> " + ofToString(rect.height));
}

//--------------------------------------------------------------
//Inverts color of the next rectangle. At the moment only works with black and white 
void ofApp::invertBackgroundColor(BOOLEAN isInverted) {
	if (isInverted) {
		ofSetColor(0, 0, 0);
		ofFill();
	}
	else {
		ofSetColor(255, 255, 255);
		ofFill();
	}
}

//--------------------------------------------------------------
//Draws rectangles recursively until a stopping criteria is meet
void ofApp::recursiveRectangleDrawing(ofRectangle rect, BOOLEAN isInverted, int numberOfIterations) {
	if (numberOfIterations > 0) {
		invertBackgroundColor(isInverted);
		ofDrawRectangle(rect);

		int centerX, centerY, rectWidth, rectHeight;
		rectWidth = rect.getWidth() - 50;
		rectHeight = rect.getHeight() - 50;
		centerX = (ofGetWidth() / 2) - (rectWidth / 2);
		centerY = (ofGetHeight() / 2) - (rectHeight / 2);

		ofRectangle newRectangle;
		newRectangle.x = centerX + (originalCenterX - rect.x);
		newRectangle.y = centerY + (originalCenterY - rect.y);
		newRectangle.width = rectWidth;
		newRectangle.height = rectHeight;

		numberOfIterations--;
		recursiveRectangleDrawing(newRectangle, !isInverted, numberOfIterations);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case OF_KEY_UP:		
		originalRectangle.y-=5;
		break;
	case OF_KEY_DOWN:
		originalRectangle.y+=5;
		break;
	case OF_KEY_LEFT:
		originalRectangle.x-=5;
		
		break;
	case OF_KEY_RIGHT:
		originalRectangle.x+=5;
		
		break;
	default:
		break;
	}
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
