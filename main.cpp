#include <iostream>
#include "functions.h"
#include "classes.h"
using namespace std;
int main() {
    test();
    Recipe test1;
    Recipe test2(5);
    cout<<test1.get_x()<<endl;
    cout<<test2.get_x()<<endl;
    system("pause");
}
