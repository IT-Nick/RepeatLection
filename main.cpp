#include <iostream>
#include <vector>
#include "operators.h"
#include "matrix.h"
#include <map>
#include <algorithm>

using namespace std;

//
//Напиши функцию, принимающую множество elements и объект border,
//которая возвращает вектор из всех элементов множества, больших border, в возрастающем порядке
//template <typename T>
//vector<T> FindGreaterElements(const set<T>& elements, const T& border);

//Пример кода:
//int main() {
//  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
//    cout << x << " ";
//  }
//  cout << endl;
//
//  string to_find = "Python";
//  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
//  return 0;
//}
//http://ru.cppreference.com/w/cpp/container/set/lower_bound
template<typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    auto it = find_if(begin(elements), elements.end(), [border](const T& element) {
        return border < element;
    });

    return vector<T>(it, end(elements));
}

int main() {
//https://www.cryptool.org/en/cto/vigenere
    Matrix m;
    string alpha;
    cin >> alpha; //АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ_
    cin >> m;
    cout << m;
    vector<int> shifts;
    BuildChars(m, alpha, shifts);
    int zeroShift = shifts[0];
    int oneShift = shifts[1];
    int twoShift = shifts[2];
    int threeShift = shifts[3];
    oneShift += 33 - zeroShift;
    twoShift += 33 - zeroShift;
    threeShift += 33 - zeroShift;

    for(int j = 128; j <= 159; j++) {
        int fk = j - oneShift;
        int tk = j - twoShift;
        int fok = j - threeShift;
        if(fk < 128) {
            fk += 33;
            if (fk == 159) {
                fk = 128;
            }
        }
        if(tk < 128) {
            tk += 33;
            if (tk == 159) {
                tk = 128;
            }
        }
        if(fok < 128) {
            fok += 33;
            if (fok == 159) {
                fok = 128;
            }
        }
        cout << (char) j << (char) fk << (char) tk << (char) fok << endl;
    }

    //PrintMap(BuildChars(m));
    //A E A O
   //A:2 E:1 O:1
    /*
    A B C D
    E F G H
    A B K H
    O B N P
m.At(i, 1)
    A: 2 B: 3 C: 0 H: 2
    */
    return 0;
}
