#pragma once
#include "ofMain.h"

class Actor {
public:
	Actor(vector<glm::vec3>& location_list, vector<vector<int>>& next_index_list, vector<int>& destination_list);
	void update(const int& frame_span, vector<glm::vec3>& location_list, vector<vector<int>>& next_index_list, vector<int>& destination_list);
	void draw();
	glm::vec3 getLocation();
	deque<glm::vec3> getLog();
	void setColor(ofColor color);
	ofColor getColor();

private:

	int select_index;
	int next_index;

	glm::vec3 location;
	deque<glm::vec3> log;
	ofColor color;

	ofMesh mesh;
};

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key) {};
	void keyReleased(int key) {};
	void mouseMoved(int x, int y) {};
	void mouseDragged(int x, int y, int button) {};
	void mousePressed(int x, int y, int button) {};
	void mouseReleased(int x, int y, int button) {};
	void mouseEntered(int x, int y) {};
	void mouseExited(int x, int y) {};
	void windowResized(int w, int h) {};
	void dragEvent(ofDragInfo dragInfo) {};
	void gotMessage(ofMessage msg) {};

	glm::vec3 make_point(float R, float r, float u, float v);

	vector<glm::vec3> location_list;
	vector<vector<int>> next_index_list;
	vector<int> destination_list;

	vector<unique_ptr<Actor>> actor_list;

	ofEasyCam cam;

	float rotate_deg;
};