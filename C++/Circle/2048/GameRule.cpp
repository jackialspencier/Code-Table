// #include "GameRule.h"
// void GameRule::Process(int direction, int game[ROW][COL]) {
//     switch (direction)
//     {
//     case UP: 
//         for (int r = 1; r < ROW; ++r)//每轮由上面开始
//             for (int tmpr = r; tmpr >= 1; --tmpr)//逐行向上处理
//                 for (int c = 0; c < COL; ++c)
//                     if (game[tmpr - 1][c] == 0)//移动
//                     {
//                         game[tmpr - 1][c] = game[tmpr][c];
//                         game[tmpr][c] = 0;
//                     }
//                     else if (game[tmpr - 1][c] == game[tmpr][c])//合并
//                     {
//                             game[tmpr - 1][c] += game[tmpr][c];
//                             game[tmpr][c] = 0;
//                     }
//         break;
//     case DOWN: 
//         for (int r = ROW - 2; r >= 0; --r)//每轮由下面开始
//             for (int tmpr = r; tmpr < ROW - 1; ++tmpr)//逐行向下处理
//                 for (int c = 0; c < COL; ++c)
//                     if (game[tmpr + 1][c] == 0)//移动
//                     {
//                         game[tmpr + 1][c] = game[tmpr][c];
//                         game[tmpr][c] = 0;
//                     }
//                     else if (game[tmpr + 1][c] == game[tmpr][c])//合并
//                     {
//                         game[tmpr + 1][c] += game[tmpr][c];
//                         game[tmpr][c] = 0;
//                     }
//         break;
//     case LEFT:
//         for (int c = 1; c < COL; ++c)//每轮由左边开始
//             for (int tmpc = c; tmpc >= 1; --tmpc)//逐行向左处理
//                 for (int r = 0; r < ROW; ++r)
//                     if (game[r][tmpc - 1] == 0)//移动
//                     {
//                         game[r][tmpc - 1] = game[r][tmpc];
//                         game[r][tmpc] = 0;
//                     }
//                     else if (game[r][tmpc - 1] == game[r][tmpc])//合并
//                     {
//                         game[r][tmpc - 1] *= 2;
//                         game[r][tmpc] = 0;
//                     }
//         break;
//     case RIGHT:
//         for (int c = COL - 2; c >= 0; --c)//每轮由右边开始
//             for (int tmpc = c; tmpc <= COL - 2; ++tmpc)//逐行向右处理
//                 for (int row = 0; row < ROW; ++row)
//                     if (game[row][tmpc + 1] == 0)//移动
//                     {
//                         game[row][tmpc + 1] = game[row][tmpc];
//                         game[row][tmpc] = 0;
//                     }
//                     else if (game[row][tmpc + 1] == game[row][tmpc])//合并
//                     {
//                         game[row][tmpc + 1] *= 2;
//                         game[row][tmpc] = 0;
//                     }
//         break;
//     }
// }

// int GameRule::Judge(int game[ROW][COL]) {
//     for (int i = 0; i < ROW; ++i)
//         for (int j = 0; j < COL; ++j)
//             if (game[i][j] == 2048)
//                 return GAME_WIN;
 
//     for (int i = 0; i < ROW; ++i)
//         for (int j = 0; j < COL - 1; ++j)
//             if (game[i][j] == 0 || (game[i][j] == game[i][j + 1]))
//                 return GAME_CONTINUE;
//     for (int j = 0; j < COL; ++j)
//         for (int i = 0; i < ROW - 1; ++i)
//             if (game[i][j] == 0 || (game[i][j] == game[i + 1][j]))
//                 return GAME_CONTINUE;

//     return GAME_OVER;
// }