#include"painter.h"
void Painter::init() {

 }

void Painter::checkcrash() {
	for (auto& obj : alive_obj_list) {
		checkone(obj);
	}
}
void Painter::checkone(std::shared_ptr<Object> obj) {
	int heigh = obj->shape.size(),weight=obj->shape[0].size();
	for (int i = obj->x; i < obj->x + weight; ++i) {
		if (obj->shape[heigh - 1][i] == 'X' && obj->y == include_line[i]+1) {
			
		}
	}
}
void Painter::attach(std::shared_ptr<Object> &obj) {
	int x_min = obj->x, x_max = x_min + obj->shape[0].size() - 1;
	int y_max = obj->y, y_min = y_max - obj->shape.size() + 1;
	for (int i = x_min; i <= x_max; ++i) {
		for (int j = y_min; j <= y_max; ++j) {
			heap[j][i] = obj->shape[obj->shape.size() - (j - y_min) - 1][i - x_min];
		}
    }
	for (int i = x_min; i <= x_max; i++) {
		for (int j = y_max; j >= y_min; j--) {
			if (heap[j][i] == 'X') {
				include_line[i] = j; break;
			}
		}
	}
	alive_obj_list.erase(obj);
}
void Painter::checkelime() {
	std::vector < std::vector<char> >temp;
	int elia = 0;
	for (int i = 0; i < h; ++i) {
		bool is_full = 1;
		for (int j = 0; j < w; ++j) {
			if (heap[i][j] != 'O') { is_full = 0; break; }
		}
		if (!is_full) { temp.push_back(heap[i]); }
		else elia++;
	}
	for (int i = 0; i < w; ++i) include_line[i] -= elia;
}