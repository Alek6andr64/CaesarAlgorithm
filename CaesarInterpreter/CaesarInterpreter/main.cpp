#include <iostream>
#include <string>

using namespace std;

class CaesarInterpreter {
public:
    string encode(string data, unsigned short key, unsigned short choice) {
        string newData;
        char newChar;

        for (int i = 0; i < data.size(); i++) {
            newChar = data[i];

            if (choice == 1) {
                if (newChar >= 'А' && newChar <= 'Я') {
                    newChar = ((newChar - 'А' + key) % 32) + 'А';
                }
                else if (newChar >= 'а' && newChar <= 'я') {
                    newChar = ((newChar - 'а' + key) % 32) + 'а';
                }
            }
            else if (choice == 2) {
                if (newChar >= 'A' && newChar <= 'Z') {
                    newChar = ((newChar - 'A' + key) % 26) + 'A';
                }
                else if (newChar >= 'a' && newChar <= 'z') {
                    newChar = ((newChar - 'a' + key) % 26) + 'a';
                }
            }

            newData += newChar;
        }
        return newData;
    }
};

int main() {
    setlocale(LC_ALL, "Ru");

    CaesarInterpreter interpreter;
    unsigned short userChoice;
    string userString;
    unsigned short userKey;

    while (true) {
        cout << "Напишите алфавит ru - 1, eng - 2. Для завершения программы - 3: ";
        cin >> userChoice;

        if (userChoice == 3)
            break;

        if (userChoice == 1 || userChoice == 2) {
            cout << "Введите текст для шифрования: ";
            cin >> userString;

            cout << "Введите ключ для шифрования (целое число): ";
            cin >> userKey;

            cout << "Зашифрованный текст: " << interpreter.encode(userString, userKey, userChoice) << endl;
        }
        else {
            cout << "Неизвестная команда. Повторите попытку." << endl;
        }
    }

    return 0;
}