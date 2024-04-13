// // UserInput.cpp
// #include <unistd.h>
// #include "Constants.h"
// #include "UserInput.h"
// #include <ctime>

// #ifndef __wtypes_h__
// #include <wtypes.h>
// #endif

// #ifndef __WINDEF_
// #include <windef.h>
// #endif

// int UserInput::GetDirection() {
//     int upArrow = 0;
//     int downArrow = 0;
//     int leftArrow = 0;
//     int rightArrow = 0;
//     int direction = 0;
//     while (true) {
//         upArrow = GetAsyncKeyState(VK_UP);
//         downArrow = GetAsyncKeyState(VK_DOWN);
//         leftArrow = GetAsyncKeyState(VK_LEFT);
//         rightArrow = GetAsyncKeyState(VK_RIGHT);

//         if (upArrow) {
//             direction = UP;
//             break;
//         }
//         else if (downArrow) {
//             direction = DOWN;
//             break;
//         }
//         else if (leftArrow) {
//             direction = LEFT;
//             break;
//         }
//         else if (rightArrow) {
//             direction = RIGHT;
//             break;
//         }

//         usleep(100);
//     }

//     return direction;
// }


