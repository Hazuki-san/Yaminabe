#include <iostream>
#include <unordered_map>
#include <Windows.h>

// Function keys
const int F20 = 0x83; // VK_F20
const int F21 = 0x84; // VK_F21
const int F22 = 0x85; // VK_F22
const int F23 = 0x86; // VK_F23

// A, S, K, L keys
const int A = 0x41; // VK_A
const int S = 0x53; // VK_S
const int K = 0x4B; // VK_K
const int L = 0x4C; // VK_L

bool isKeyPressed(int key) {
    return (GetAsyncKeyState(key) & 0x8000) != 0;
}

int main() {
    std::cout << "Press A, S, K, and L to activate F20, F21, F22, and F23 function keys." << std::endl;

    std::unordered_map<int, int> keysToFunctionKeys;
    std::unordered_map<int, bool> keyPressed;
    std::unordered_map<int, DWORD> keyPressTime;

    const DWORD threshold = 115; // Adjust this threshold (in milliseconds) as needed

    while (true) {
        // For A key
        if (isKeyPressed(A)) {
            if (!keyPressed[A]) {
                keyPressed[A] = true;
                keyPressTime[A] = GetTickCount();
                std::cout << "A key pressed. F20 will be activated when A is released." << std::endl;
            }
        }
        else {
            if (keyPressed[A]) {
                int functionKey = keysToFunctionKeys[A];
                if (GetTickCount() - keyPressTime[A] > threshold) {
                    keysToFunctionKeys[A] = F20;

                    INPUT input;
                    input.type = INPUT_KEYBOARD;
                    input.ki.wScan = 0;
                    input.ki.time = 0;
                    input.ki.dwExtraInfo = 0;
                    input.ki.wVk = functionKey;
                    input.ki.dwFlags = 0; // 0 for key press
                    SendInput(1, &input, sizeof(INPUT));

                    input.ki.dwFlags = KEYEVENTF_KEYUP; // key release
                    SendInput(1, &input, sizeof(INPUT));

                    std::cout << "A key released. F20 activated." << std::endl;
                }

                keyPressed[A] = false;
            }
        }

        // Similar checks for S, K, and L keys...
        // (Note: You can use a function to handle the common logic for these checks.)

        // For S key
        if (isKeyPressed(S)) {
            if (!keyPressed[S]) {
                keyPressed[S] = true;
                keyPressTime[S] = GetTickCount();
                std::cout << "S key pressed. F21 will be activated when S is released." << std::endl;
            }
        }
        else {
            if (keyPressed[S]) {
                int functionKey = keysToFunctionKeys[S];
                if (GetTickCount() - keyPressTime[S] > threshold) {
                    keysToFunctionKeys[S] = F21;

                    INPUT input;
                    input.type = INPUT_KEYBOARD;
                    input.ki.wScan = 0;
                    input.ki.time = 0;
                    input.ki.dwExtraInfo = 0;
                    input.ki.wVk = functionKey;
                    input.ki.dwFlags = 0; // 0 for key press
                    SendInput(1, &input, sizeof(INPUT));

                    input.ki.dwFlags = KEYEVENTF_KEYUP; // key release
                    SendInput(1, &input, sizeof(INPUT));

                    std::cout << "S key released. F21 activated." << std::endl;
                }

                keyPressed[S] = false;
            }
        }

        // For K key
        if (isKeyPressed(K)) {
            if (!keyPressed[K]) {
                keyPressed[K] = true;
                keyPressTime[K] = GetTickCount();
                std::cout << "K key pressed. F22 will be activated when K is released." << std::endl;
            }
        }
        else {
            if (keyPressed[K]) {
                int functionKey = keysToFunctionKeys[K];
                if (GetTickCount() - keyPressTime[K] > threshold) {
                    keysToFunctionKeys[K] = F22;

                    INPUT input;
                    input.type = INPUT_KEYBOARD;
                    input.ki.wScan = 0;
                    input.ki.time = 0;
                    input.ki.dwExtraInfo = 0;
                    input.ki.wVk = functionKey;
                    input.ki.dwFlags = 0; // 0 for key press
                    SendInput(1, &input, sizeof(INPUT));

                    input.ki.dwFlags = KEYEVENTF_KEYUP; // key release
                    SendInput(1, &input, sizeof(INPUT));

                    std::cout << "K key released. F22 activated." << std::endl;
                }

                keyPressed[K] = false;
            }
        }

        // For L key
        if (isKeyPressed(L)) {
            if (!keyPressed[L]) {
                keyPressed[L] = true;
                keyPressTime[L] = GetTickCount();
                std::cout << "L key pressed. F23 will be activated when L is released." << std::endl;
            }
        }
        else {
            if (keyPressed[L]) {
                int functionKey = keysToFunctionKeys[L];
                if (GetTickCount() - keyPressTime[L] > threshold) {
                    keysToFunctionKeys[L] = F23;

                    INPUT input;
                    input.type = INPUT_KEYBOARD;
                    input.ki.wScan = 0;
                    input.ki.time = 0;
                    input.ki.dwExtraInfo = 0;
                    input.ki.wVk = functionKey;
                    input.ki.dwFlags = 0; // 0 for key press
                    SendInput(1, &input, sizeof(INPUT));

                    input.ki.dwFlags = KEYEVENTF_KEYUP; // key release
                    SendInput(1, &input, sizeof(INPUT));

                    std::cout << "L key released. F23 activated." << std::endl;
                }

                keyPressed[L] = false;
            }
        }
    }

    return 0;
}
