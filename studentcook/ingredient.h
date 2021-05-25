#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <string>
#include <algorithm>
using namespace std;

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

class Ingredients{

    private:
    string ingredients_list;
    public:
    Ingredients() = default;
    void add(string ingredient){
        if (this->ingredients_list.find(ingredient) == string::npos)
        this->ingredients_list += ingredient + "\n";
    }

    void remove(string ingredient){
        if (this->ingredients_list.find(ingredient) != string::npos)
        replaceAll(this->ingredients_list, ingredient+"\n", "");
    }

    string get() { return this->ingredients_list;}

    void clear(){
        this->ingredients_list.clear();
    }
};

Ingredients list_of_ingredients;



#endif // INGREDIENT_H
