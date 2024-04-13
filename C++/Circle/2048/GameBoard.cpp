// #include "GameBoard.h"
// #include "Constants.h"
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int game[ROW][COL];//�����ﶨ����ȫ�ֱ���
// void GameBoard::PrintStartMenu() {
//     cout << "*********************************" << endl;
//     cout << "*            2048 Game           *" << endl;
//     cout << "*********************************" << endl;
//     cout << "1. Start Game" << endl;
//     cout << "2. Exit" << endl;
//     cout << "3. Help" << endl;
//     cout << "*********************************" << endl;
//     cout << "Enter your choice (1 or 2 or 3): ";
// }
// void GameBoard::Print() {
//     system("cls");
//     cout << "*****************  2048 �� �� ̨ ��  ******************" << endl;
//     for (int i = 0; i < ROW; ++i) {
//         cout << "---------------------------------" << endl;
//         for (int j = 0; j < COL; ++j) {
//             if (game[i][j] == 0) {
//                 cout << "|" << setw(4) <<"\t";
//             }
//             else {
//                 // ����ÿ������ռ�ݵĿ���
//                 cout << "| " << setw(4) << game[i][j] << "\t";
//             }
//         }
//         cout << "|" << endl;
//     }
//     cout << "---------------------------------" << endl;
// }

// bool GameBoard::CreateNumber() {
//     int emptyCells = 0;
//     for (int i = 0; i < ROW; ++i) {
//         for (int j = 0; j < COL; ++j) {
//             if (game[i][j] == 0) {
//                 ++emptyCells;
//             }
//         }
//     }

//     if (emptyCells == 0) {
//         return false; // �����������޷�����������
//     }

//     int targetCell = rand() % emptyCells; // ���ѡ��һ���ո�
//     int count = 0;
//     GameNum num = (rand() % 3 == 0) ? Game_4 : Game_2; // 25% �ĸ������� 4

//     // �����ҵ�ѡ�еĿո�
//     for (int i = 0; i < ROW; ++i) {
//         for (int j = 0; j < COL; ++j) {
//             if (game[i][j] == 0) {
//                 if (count == targetCell) {
//                     game[i][j] = num;
//                     return true;
//                 }
//                 ++count;
//             }
//         }
//     }

//     return false; // ��Ӧ�õ�������
// }

// void GameBoard::ResetGame() {
//     for (int i = 0; i < ROW; ++i) {
//         for (int j = 0; j < COL; ++j) {
//             game[i][j] = 0;
//         }
//     }
//     CreateNumber();
//     CreateNumber();
// }
// void GameBoard::help() {
//     system("cls");
//     cout << "�� => Up    �� => Left    �� => Down    �� => Right" << endl;
// }
