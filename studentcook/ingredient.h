#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int words_count(char s[]) {
    int count = 0;
    if (strstr(s,","))
    {
        for (int i = 0; s[i] != '\0';i++)
        {
            if (s[i] == ',')
                count++;
        }
    }
    else
    {
        for (int i = 0; s[i] != '\0';i++)
        {
            if (s[i] == ' ')
                count++;
        }
    }
    return count+1;
}

class Ingredients{

    private:
    std::vector<std::string> ingredients_list;
    public:
    Ingredients() = default;
    void add(const std::string& ingredient){
        if (std::find(this->ingredients_list.begin(), this->ingredients_list.end(), ingredient) == this->ingredients_list.end())
        this->ingredients_list.push_back(ingredient);
    }

    void remove(const std::string& ingredient){
        if (std::find(this->ingredients_list.begin(), this->ingredients_list.end(), ingredient) == this->ingredients_list.end())
            this->ingredients_list.erase(std::remove(this->ingredients_list.begin(), this->ingredients_list.end(), ingredient), this->ingredients_list.end());
    }

    std::string get(std::string delim) {
        std::string ingredients;
        for(auto &ingredient : this->ingredients_list)
            ingredients = ingredients + ingredient + delim;

        return ingredients.substr(0, ingredients.size()-1);
    }

   std::string ingredients_match(const std::string& recipe_ingredients, float &procent){

        char *recipe_ingredients_arr = (char*) recipe_ingredients.c_str();

        std::string it_uses;

        char* token		= NULL;
        char* context	= NULL;

        char* copy_recipe_ingredients = new char[strlen(recipe_ingredients_arr)+1];
        strcpy(copy_recipe_ingredients,recipe_ingredients_arr);

        bool virgulaDelim = 0;
        if (strstr(copy_recipe_ingredients,",")) virgulaDelim = 1;

        if (virgulaDelim)
            token = strtok_s(copy_recipe_ingredients, ",", &context);
        else
            token = strtok_s(copy_recipe_ingredients, " ", &context);

        procent = 0;
        while (token != NULL)
        {

            if (std::find(this->ingredients_list.begin(), this->ingredients_list.end(), token) != this->ingredients_list.end()) {
                procent++;
                if (it_uses.find(token) == std::string::npos)
                it_uses = it_uses + token + ",";
            }
            if (virgulaDelim)
                token = strtok_s(NULL, ",", &context);
            else
                token = strtok_s(NULL, " ", &context);
        }

        procent = procent /  words_count(recipe_ingredients_arr) *100;
        return it_uses;
    }
    void clear(){
        this->ingredients_list.clear();
    }
};

Ingredients list_of_ingredients;



#endif // INGREDIENT_H
