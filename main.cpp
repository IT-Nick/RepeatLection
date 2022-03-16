#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>


using namespace std;

//lower_bound, prev, тернарный оператор
//Напиши функцию FindNearestElement, возвращающую итератор на элемент множества, ближайший к border.
//Если ближайших элементов несколько, верни итератор на наименьший иp них.
//set<int>::const_iterator - тип итераторов для константного множества целых чисел
//

/*int main() {
    set<int> numbers = {1, 4, 6};
    cout <<
         *FindNearestElement(numbers, 0) << " " << //1
         *FindNearestElement(numbers, 3) << " " << //4
         *FindNearestElement(numbers, 5) << " " << //4
         *FindNearestElement(numbers, 6) << " " << //6
         *FindNearestElement(numbers, 100) << endl;//6

    set<int> empty_set;
    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;//1
    return 0;
}
 */

set<int>::const_iterator FindNearestElement(const set<int>& elements, int border) {
    auto first = elements.lower_bound(border);
    if(first == elements.begin()) {
        return first;
    }
    auto last = prev(first);
    if(first == elements.end()) {
        return last;
    }

    if(border - *last <= *first - border) {
        return last;
    } else {
        return first;
    }
}

int main() {
    set<int> numbers = {1, 4, 6};
    cout <<
         *FindNearestElement(numbers, 0) << " " << //1
         *FindNearestElement(numbers, 3) << " " << //4
         *FindNearestElement(numbers, 5) << " " << //4
         *FindNearestElement(numbers, 6) << " " << //6
         *FindNearestElement(numbers, 100) << endl;//6

    set<int> empty_set;
    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;//1
    return 0;
}
