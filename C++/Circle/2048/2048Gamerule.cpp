#include "2048GameRule.h"
void GameRule::Process(int direction, int game[][COL]){
    switch (direction){
        case UP:
            for (int row = 0; row < ROW; row++){//确保逐次最上面的能合并改变的先变//加入新一行的数据来处理
                for (int tmpr = row; tmpr >= 1; tmpr++){//逐行向上处理
                    for (int c = 0; c < COL; c++)
                    {
                        if (game[tmpr-1][c] == 0){
                            game[tmpr-1][c] = game[tmpr][c];
                            game[tmpr][c] = 0;
                        }//上一行为0，移动
                        else if(game[tmpr-1][c] == game[tmpr][c]){
                            game[tmpr-1][c] *= 2;
                            game[tmpr][c] = 0;
                        }//相等合并
                    }
                }
            }
            break;//!!
        case DOWN:
            for (int row = ROW-1; row >= 0; row--){//确保每轮处理的首先是从最下面开始
                for (int tmpr = row; tmpr <= ROW - 2; tmpr++){//本轮处理是依次逐行向下处理
                    for (int c = 0; c < COL; c++){
                        if (game[tmpr+1][c] == 0){
                            game[tmpr+1][c] = game[tmpr][c];
                            game[tmpr][c] = 0;
                        }
                        else if (game[tmpr+1][c] == game[tmpr][c]){
                            game[tmpr+1][c] *= 2;
                            game[tmpr][c] = 0;
                        }
                    }
                }
            }
            break;
        case LEFT:
            for (int col = 0; col < COL; col++){//第一轮处理从最左边的数据开始，逐轮加入一列未处理合并过的最左边的一行数据
                for (int tmpc = col; tmpc >= 1; tmpc--){//新加入的数据就近开始处理//就近处理完之后其边上一行也从旧数据变成新数据，也需要处理。由此类推。
                    for (int r = 0; r < ROW; r++){
                        if (game[r][tmpc-1] == 0){
                            game[r][tmpc-1] = game[r][tmpc];
                            game[r][tmpc] = 0;
                        }
                        else if (game[r][tmpc-1] == game[r][tmpc]){
                            game[r][tmpc-1] *= 2;
                            game[r][tmpc] = 0;
                        }
                    }
                }
            }
            break;
        case RIGHT:
            for (int col = COL - 1; col >= 0; col--){//定位新数据，该轮每次处理开始位置
                for (int tmpc = col; tmpc <= COL - 2; tmpc++){//就近开始处理，向右推进
                    for (int r = 0; r < ROW; r++){
                        if (game[r][tmpc+1] == 0){//向右推进处理
                            game[r][tmpc+1] == game[r][tmpc];
                            game[r][tmpc] == 0;
                        }
                        else if (game[r][tmpc+1] == game[r][tmpc]){
                            game[r][tmpc+1] *= 2;
                            game[r][tmpc] = 0;
                        }
                    }
                }
            }
            break;
    }
}

int GameRule::Judge(int game[][COL]){
    for (int r = 0; r < ROW; r++)
        for (int c = 0; c < COL; c++)
            if (game[r][c] == 2048)
                return GAME_WIN;
    for (int r = 0; r < ROW; r++)
        for (int c = 0; c < COL; c++){
            if (game[r][c] == 0)
                return GAME_CONTINUE;
            else if ((game[r][c] == game[r+1][c] && r+1 < ROW) || (game[r][c] == game[r][c+1] && c+1 < COL))//下有相等（纵向）       //右有相等（横向）
                return GAME_CONTINUE;
        }
    return GAME_OVER;
}