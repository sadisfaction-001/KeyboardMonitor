#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    HANDLE h = GetStdHandle(STD_INPUT_HANDLE);

    INPUT_RECORD event;
    DWORD count;
    string sent = "";
    ofstream file("NewLog.txt", ios::app);
    while (true) {
        ReadConsoleInput(h, &event, 1, &count);

        if (event.EventType == KEY_EVENT &&
            event.Event.KeyEvent.bKeyDown) {

            int key = event.Event.KeyEvent.wVirtualKeyCode;

            if (key >= 'A' && key <= 'Z') {
                sent += (char)key;
            }
            else if (key >= '0' && key <= '9') {
                sent += (char)key;
            }
            else if (key == VK_SPACE) {
                sent += " ";
            }
            else if (key == VK_BACK) {
                if (!sent.empty()) sent.pop_back();
            }
            else if (key == VK_RETURN) {
                cout << sent << endl;
                file << sent << endl;
                sent = "";
            }
            if (key == VK_ESCAPE)
                break;
        }
    }
    
    file.close();
    return 0;
}
