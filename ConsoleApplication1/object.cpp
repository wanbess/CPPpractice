#include"object.h"
#include<algorithm>
void Object::init(std::vector<std::string> s) {
	shape = std::move(s);
}
void Object::rotate(int time) {
	time %= 4;
	int wight = shape.size();
	assert(wight != 0);
	int heigh = shape[0].size();
	if()
	std::vector<std::string> temp(heigh,std::string('O', wight));
	for (int k = 0; k < time; ++k) {
		for (int i = 0; i < wight; i++) {
			for (int j = 0; j < heigh; j++) {
				temp[i][j] = shape[wight - 1-j][i];
			}
		 }
	}
	shape = temp;
}
void Object::elimite(int layer) {
	int heigh = shape.size();
	int leng = shape[0].size();
	assert(layer <= heigh);
	for (int j=0; j<layer; ++j) {
		shape.pop_back();
	}
	level -= layer;
}   
void  Object::move(int left) {
	x = std::max(0, x - left);
	y = std::min(y + (int)shape[0].size() - 1, world_x);
}
void Object::fall() {
	y--;
}