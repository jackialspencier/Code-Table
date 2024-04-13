#ifndef CONSTANTS_H
#define CONSTANTS_H
const int ROW = 4;
const int COL = 4;
 
// 用户输入
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;

// 游戏战局judge
const int GAME_OVER = 1;
const int GAME_WIN = 2;
const int GAME_CONTINUE = 3;

enum GameNum
{
    Game_2 = 2,
    Game_4 = 4,
    Game_8 = 8,
    Game_16 = 16,
    Game_32 = 32,
    Game_64 = 64,
    Game_128 = 128,
    Game_256 = 256,
    Game_512 = 512,
    Game_1024 = 1024,
    Game_2048 = 2048,
};
#endif

// #include "2048GameRule.h"
// void GameRule::Process(int direction, int gameboard[][COL]){
//     // 移动
//     switch (direction){
//         case UP:for (int i = 0; i < COL; i++){
//                 // 计算空格数量
//                 int space = 0;
//                 for (int j = 0; j < ROW; j++){
//                     if (gameboard[j][i] == 0) 
//                         space++;
//                     else 
//                         break;
//                 }
//                 //移动非空格的数字space个位置
//                 for (int j = space; j < ROW; j++){
//                     gameboard[j - space][i] = gameboard[j][i];
//                     gameboard[j][i] = 0;
//                 }
//                 }
//                 break;
//         case DOWN:for (int i = 0; i < COL; i++){
//                     //计算空格
//                 int space = 0;
//                 for (int j = ROW-1; j >= 0; j--){
//                     if (gameboard[j][i] == 0)
//                         space++;
//                     else 
//                         break;
//                 }
//                 //移动
//                 for (int j = ROW - 1 - space; j >= 0; j--){
//                     gameboard[j+space][i] = gameboard[j][i];
//                     gameboard[j][i] = 0;
//                 }
//                 }
//                 break;
//         case LEFT:for (int i = 0; i < ROW; i++){
//                 //space
//                 int space;
//                 for (int j = 0; j < COL; j++){
//                     if (gameboard[i][j])
//                         space++;
//                     else
//                         break;
//                 }
//                 //move
//                 for (int j = space; j < ROW; j++){
//                     gameboard[i][j-space] = gameboard[i][j];
//                     gameboard[i][j] = 0;
//                 }
//                 }
//                 break;
//         case RIGHT:for (int i = 0; i < ROW; i++){
//                 int space = 0;
//                 for (int j = COL-1; j >= 0; j--){
//                     if (gameboard[i][j] == 0)
//                         space++;
//                     else
//                         break;
//                 }
//                 for (int j = COL - 1 - space; j >= 0; j++){
//                     gameboard[i][j+space] = gameboard[i][j];
//                     gameboard[i][j] = 0;
//                 }
//                 }
//                 break;
//     }

// }
