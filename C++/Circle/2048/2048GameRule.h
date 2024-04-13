#ifndef GAMERULE_H
#define GAMERULE_H
#include "2048Constants.h"
class GameRule{
public:
    static void Process(int direction, int gameboard[][COL]);
    static int Judge(int gameboard[][COL]);
};
#endif