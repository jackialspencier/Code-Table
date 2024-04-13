// #include "GameRule.h"
// void GameRule::Process(int direction, int game[][COL]){
//     switch (direction){
//         case UP:
//             for (int row = 0; row < ROW; row++){//每轮由上面开始
//                 for (int tmpr = row; tmpr >= 1; tmpr--){//逐行向上处理
//                     for (int c = 0; c < COL; c++)
//                     {
//                         if (game[tmpr-1][c] == 0){
//                             game[tmpr-1][c] = game[tmpr][c];
//                             game[tmpr][c] = 0;
//                         }//上一行为0，移动
//                         else if(game[tmpr-1][c] == game[tmpr][c]){
//                             game[tmpr-1][c] *= 2;
//                             game[tmpr][c] = 0;
//                         }//相等合并
//                     }
//                 }
//             }
//             break;//!!
//         case DOWN:
//             for (int row = ROW-1; row >= 0; row--){//每轮由下面开始
//                 for (int tmpr = row; tmpr <= ROW - 2; tmpr++){//逐行向下处理
//                     for (int c = 0; c < COL; c++){
//                         if (game[tmpr+1][c] == 0){
//                             game[tmpr+1][c] = game[tmpr][c];
//                             game[tmpr][c] = 0;
//                         }
//                         else if (game[tmpr+1][c] == game[tmpr][c]){
//                             game[tmpr+1][c] *= 2;
//                             game[tmpr][c] = 0;
//                         }
//                     }
//                 }
//             }
//             break;
//         case LEFT:
//             for (int col = 0; col < COL; col++){//每轮由左边开始
//                 for (int tmpc = col; tmpc >= 1; tmpc--){//逐列向左处理
//                     for (int r = 0; r < ROW; r++){
//                         if (game[r][tmpc-1] == 0){
//                             game[r][tmpc-1] = game[r][tmpc];
//                             game[r][tmpc] = 0;
//                         }
//                         else if (game[r][tmpc-1] == game[r][tmpc]){
//                             game[r][tmpc-1] *= 2;
//                             game[r][tmpc] = 0;
//                         }
//                     }
//                 }
//             }
//             break;
//         case RIGHT:
//             for (int col = COL - 1; col >= 0; col--){//每轮由右边开始
//                 for (int tmpc = col; tmpc <= COL - 2; tmpc++){//逐列向右处理
//                     for (int r = 0; r < ROW; r++){
//                         if (game[r][tmpc+1] == 0){
//                             game[r][tmpc+1] == game[r][tmpc];
//                             game[r][tmpc] == 0;
//                         }
//                         else if (game[r][tmpc+1] == game[r][tmpc]){
//                             game[r][tmpc+1] *= 2;
//                             game[r][tmpc] = 0;
//                         }
//                     }
//                 }
//             }
//             break;
//     }
// }

// int GameRule::Judge(int game[ROW][COL]) {
    
//     for (int i = 0; i < ROW; ++i)
//     {
//         for (int j = 0; j < COL; ++j)
//         {
//             if (game[i][j] == 2048)
//             {
//                 return GAME_WIN;
//                 break;
//             }
//         }
//     }

//     for (int i = 0; i < ROW; ++i)
//     {
//         for (int j = 0; j < COL - 1; ++j)
//         {
//             if (!game[i][j] || (game[i][j] == game[i][j + 1]))
//             {
//                 return GAME_CONTINUE;
//                 break;
//             }
//         }
//     }

//     for (int j = 0; j < COL; ++j)
//     {
//         for (int i = 0; i < ROW - 1; ++i)
//         {
//             if (!game[i][j] || (game[i][j] == game[i + 1][j]))
//             {
//                 return GAME_CONTINUE;
//                 break;
//             }
//         }
//     }

//     return GAME_OVER;
// }