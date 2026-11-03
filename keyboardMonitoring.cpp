//#include <iostream>
//#include <string>
//#include <fstream>
//using namespace std;
//
//int main() {
//    ofstream file("log.txt", ios::app);
//    string k;
//    int cnt = 0;
//
//    while (getline(cin, k)) {
//        if (k == "0") break;
//
//        file << k << endl;
//        cnt++;
//    }
//
//    cout << "Total sentences: " << cnt << endl;
//
//    file.close();
//
//    cout << "History" << endl;
//
//    ifstream read("log.txt");
//    string line;
//    while (getline(read, line)) {
//        cout << line << endl;
//    }
//    return 0;
//}

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
