
#include "ofApp.h"


string DeleteSpace(string buf) {
  size_t pos;
  while((pos = buf.find_first_of(" ")) != string::npos){
    buf.erase(pos, 1);
  }
  return buf;
}

//--------------------------------------------------------------
void ofApp::setup() {
  joy_.setup(GLFW_JOYSTICK_1);
  string joy_name = DeleteSpace(joy_.getName());
  ofLog() << "device name : " + joy_name;
  
  string xml_path = "settings.xml";
  if (xml_.load(xml_path.c_str())) {
    ofLog() << "\"" << xml_path.c_str() << "\" : loaded" << endl;
  } else {
    ofLog() << "unable load data : \"" << xml_path.c_str() << "\"" << endl;
  }
  
  xml_.pushTag("Joystick");
  xml_.pushTag(joy_name.c_str());
  
  joySettings_ = unordered_map<string, int> {
    {"Left", xml_.getValue("Left", -1)},
    {"Right", xml_.getValue("Right", -1)},
    {"Up", xml_.getValue("Up", -1)},
    {"Down", xml_.getValue("Down", -1)},
    
    {"Button1", xml_.getValue("Button1", -1)},
    {"Button2", xml_.getValue("Button2", -1)},
    {"Button3", xml_.getValue("Button3", -1)},
    {"Button4", xml_.getValue("Button4", -1)},
  };
}

//--------------------------------------------------------------
void ofApp::update() {
  joy_.update();

  if (joy_.isPush(joySettings_["Left"]))  { ofLog() << "push Left";  }
  if (joy_.isPush(joySettings_["Right"])) { ofLog() << "push Right"; }
  if (joy_.isPush(joySettings_["Up"]))    { ofLog() << "push Up";    }
  if (joy_.isPush(joySettings_["Down"]))  { ofLog() << "push Down";  }
  
  if (joy_.isPush(joySettings_["Button1"])) {
    ofLog() << "push Button1";
  }
  if (joy_.isPush(joySettings_["Button2"])) {
    ofLog() << "push Button2";
  }
  if (joy_.isPush(joySettings_["Button3"])) {
    ofLog() << "push Button3";
  }
  if (joy_.isPush(joySettings_["Button4"])) {
    ofLog() << "push Button4";
  }
}

//--------------------------------------------------------------
void ofApp::draw() {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
