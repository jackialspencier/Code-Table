// #include "GameBoard.h"
// #include "GameRule.h"
// #include "UserInput.h"
// #include "Constants.h" 

// #include <iostream>
// #include <unistd.h> 
// #include <ctime>
// using namespace std;
// int main() {
//     srand((unsigned int)time(0));
//     GameBoard gameBoard;  // GameBoard 类的实例
//     GameRule gameRules;   // GameRule 类的实例
//     UserInput userInput;  // UserInput 类的实例

//     int direction = 0;
//     int gameState = -1;

//     int choice;
//     do {
//         gameBoard.PrintStartMenu();
//         cin >> choice;

//         switch (choice) {
//         case 1:
//             gameBoard.ResetGame();
//             gameBoard.Print();

//             while (true) {
//                 direction = userInput.GetDirection();
//                 gameState = gameRules.Judge(game);

//                 if (direction && gameState == GAME_CONTINUE) {
//                     gameRules.Process(direction, game);
//                     gameBoard.CreateNumber();
//                     gameBoard.Print();
//                     usleep(100);
//                 }
//                 else if (gameState == GAME_WIN) {
//                     gameBoard.Print();
//                     cout << "You Win!" << endl;
//                     break;
//                 }
//                 else if (gameState == GAME_OVER) {
//                     gameBoard.Print();
//                     cout << "You lose!" << endl;
//                     break;
//                 }
//             }
//             break;
//         case 2:
//             cout << "Goodbye!" << endl;
//             break;
//         case 3:
//             gameBoard.help();
//             break;
//         default:
//             cout << "Invalid choice. Please enter 1 or 2 or 3." << endl;
//         }

//     } while (choice != 2);

//     return 0;
// }
