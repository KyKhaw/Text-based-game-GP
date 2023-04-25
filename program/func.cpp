#include <iostream>
#include <cstdlib>
#include <ctime>
#include "func.h"
using namespace std;

int dice() {
    srand((unsigned int) time(NULL));
    int roll = 0;
    roll = rand() % 6 + 1;
    return roll;
}
