#pragma once
#include<assert.h>
#include<string>
#include<vector>
enum shapetype {
	line,
	square,
	L_shape,
};
class Object {
public:
	Object(int world_x,int world_y,int x,int y):x(x),y(y){}
	virtual ~Object(){}
	virtual void move(int left);
	virtual void rotate(int time);
	virtual void elimite(int layer);
	virtual void fall();
	virtual void init(std::vector<std::string> );
	int level;
	std::vector < std::string > shape;
	int x;
	int y;
	int world_x;
	int world_y;
	int rotat_time;//À≥ ±’Î
};
