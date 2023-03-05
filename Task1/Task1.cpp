#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int function(string str, int forbidden_length) {
    int len = static_cast<int>(str.length());

    if (forbidden_length == len) throw runtime_error("Вы ввели слово запретной длины! До свидания\n");

    return len;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int len;
    string word;

    while (true)
    {
        cout << "Введите запретную длину: ";
        if (cin >> len) {
            if (len <= 0) cout << "Введите корректное число!\n";
            else break;
        }
        else cout << "Ошибка! Нужно ввести только цифры\n";

        cin.clear();
        cin.ignore(100500, '\n');
    }

    while (true)
    {
        cout << "Введите слов: ";
        cin >> word;

        try {
            int wordLen = function(word, len);

            cout << "Длина слова " << '\"' << word << '\"' << " равна " << wordLen << endl;
        }
        catch (runtime_error& ex) {
            cout << ex.what() << endl;
            return -1;
        }
    }
}