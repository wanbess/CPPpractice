#pragma once
#include<iostream>
#include<chrono>
#include<ratio>
#include<vector>
#include<memory>
#include<unordered_set>
#include"object.h"
class Painter {
    using second_type = std::chrono::duration<int>; 
public:
    explicit Painter() {}
    ~Painter() { }
    void flash();
    void init();
private:
    void checkone(std::shared_ptr<Object> obj);
    void attach(std::shared_ptr<Object> &obj);
    void checkcrash();
    void checkelime();
    second_type fre;
    int w;
    int h;
    std::vector<int> include_line;
    std::vector <std::vector<char>> heap;
    std::unordered_set<std::shared_ptr<Object>> alive_obj_list;
};