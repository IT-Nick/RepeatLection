#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>


using namespace std;



/Степа Плеханов, [22.02.2022 02:40]
Напишите функцию, разбивающую строку на слова по пробелам.
vector<string> SplitIntoWords(const string& s);
(ищи пробел с помощью find, создавай слово с помощью констркуктора строки по двум итераторам)

Степа Плеханов, [22.02.2022 02:40]
Пример кода:
int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}
 */



int main() {
    g s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    c
    return 0;
}
