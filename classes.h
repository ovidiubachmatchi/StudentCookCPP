#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
class Recipe{
    int x;
public:
    int get_x() {return this->x;}
    Recipe(int = 0);
};
Recipe::Recipe(int number){
    this->x = number;
}
#endif 