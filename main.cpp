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
template<typename It>
void PrintMap(It range_begin, It range_end) {
    for(auto it = range_begin; it != range_end; ++it) {
        cout << it->first << ": " << it->second << ", ";
    }
    cout << endl;
}


template<typename It>
int PrintMapRange(It range_begin, It range_end) {
    int counter = 0;
    for(auto it = range_begin; it != range_end; ++it) {
        cout << *it << ", ";
        counter++;
    }
    cout << endl;
    return counter;
}




void BuildChars(const Matrix& m, const string& alpha, vector<int>& shifts) {

    for (int j = 0; j < m.GetNumColumns(); j++) {
        map<char, int> count_letter;
        for (int i = 0; i < m.GetNumRows(); i++) {
            ++count_letter[m.At(i, j)];
        }

        auto x = max_element(begin(count_letter), end(count_letter),
                             [](const pair<char, int> &p1, const pair<char, int> &p2) {
                                 return p1.second < p2.second;
                             });
        //543 4
//ОПХБОЫХСЯСЫМГАТСОЫ_ТТЕЭЪС_ШЯ_О_ЮМЦШ_ЩНКЫЛВХЬЛЯП_ЭНЮФМТХЭЗНЮСЫРШЩМДВЮМЛАРЛЯПЩЩАЫСЪ_ЦЧЧЕЧЯЪМПЪЛБ__ЩЗЮФЪМПФСКРЖЛИАГЪРШИССЪЪА_ЯЧЬИЮЦМХПЯМЗТТЩНКЖЛТРЬЛПЮСЮЕЬСЩОТМШ_ЬТЮЕ_ЪМЛРЮЛИЧСЦОБ_ЬЫДСЮОУЦМ_ФЧЧАЫЪЛИЭВЮРВЮСНБМЛИП_ЬУЦЪС_БДЮ_ТВС_Я_ЩЯБЯЪ_Э_ЛВЮГЛЯПИФТРПЛП__ЬОЖЧЭТТТЛУЖЧЩЫДСЪ_Б_Ш_ЖГЪ_АЬЪРЮСПОАДРА_ВЮВРСНУФДЮ_С_ЬОБНЭЯПЩМ_Ъ_ЩТ__ЧЬПЯМДПЪЩФЮБШАЕЪСЙПТЛНХСЩАФСЫРШБЪДЭМШИПБССВБЭАЬЪЛЗТДВИБСОЕАНШАПЪЩТ_ЪПУНКС_Э_ЛЧБ_ЛПЮЦЬАЧДШЕТТСТАРЛПЮЦЛИЭЕЪРЬТБИХЫЛУБФСРЦЦСНШЧЛОПГЪМПИЮОПУЯДВКСЕПЩМ_ШЯ_О_ЮМЦШЧХ_ЭТЫОЬЯФЛЮСШНХСУНРЮСНШГЯЮПВБЕЭДЛИЧС_ИЫНШАПФЖПВВЦНШЬЛВКЙСДЗЧПОПЯМ_МЬЬАЭМЛВПГЖСОИМ_ФЧОЯБНЭОБСГЕАГЗДХВКТПВСДЛЮЪМПХЪДВСЩЕЪЪХ_СЪУНХВШЕЭСЮРЮХМЕБСУАПАЯГЮФФЦВСНЕЭЦТАЬЧЩАПФЖПВВЦНШЬМ_Ъ_ЧЛХЦТАПЧПОПЪПРРЭЛДРВЮИЭСАОГЮМНПЪЛП__ФЗЭ_ЭИБСОСХХЪ_ЮЦЩОПВЧОТ_ЛПЫТЭТЬТЭСКСЮАЪСЪНПЯМПВГЭТТДСТПЮЪЛЮЦЪГЮСВЕЫ_ОЕЪТЛВПЯМЧРЭС_ХХЪ_ЪТЬЬХБЖ_ШЯЮЕ_ЧЭНЮСССЫЪЛБКСИТВСЭЦХЯЯ_ЭТЫИАТЧИПЯССЪ_ЧЬЪ_ЛДХВКТШЭСТШЫЛСЯДЭТОСЩЕПВЦАЧТЧ_СМЛТЮГЛБШЩЩЕАЮСНПЪЩАЖЧЛИЭЕЪРЬТБИОСЫРХЦЭТРФЧЯНСЦАЪЪС_РУЭУ_ЦЩЫХСЬАЧХЪВЮБЖ_Ь_ПЛШСНЫПФССБЪЭЬПФЛДХЭЪВЮЮЛМШБС_АЬЪЛЛЬЪ_ВСОААСФНГ_ЬМРЗФИПЙОЕЩЗМРШРЛВХЭФКРРЛСББМНРСЯ_ЭЪА_АГЪЛЛЬЪ_ШЯ_О_ЮМЦШЪЛЯПВЧЫЗТЧ_ШЯРЕЪВЛСБ_ФМЮВЮИПЪЩФЮБШАЕЪФ_Я_ГЕЫСОВХБА_РУЭУ_ЦЩЫП_ЩИПАЪТЮЮЯ_ЖГЪ_ШЯ_О_ЮМЦШРЛХЮГК_ШСФГ_ТСТПФЭЕПУЪЛХЧЛЗЭТВИЬДЙ___ЧЬПФЛНРЙСЙПШФЗЭЪЛНХСКВЫРСТАРЛЧХЮЮОП_ЭЯЧТСМКЮЛИПЯС_Я_РДРЧЮСОСЮОЖЯЪМВСФЗЬЧЬЕЭЪЙ_ЪТЦ_ЬТЮЕ_ЪМЛКСЧИЕТЛП_ЧТНШЖЛЭЯ_А_ШЯ_О_ЮМЦШ_ЩНРРЛРХФЪЛНЗФЯПГЪЛЛЬЪ_ЭТВИЭТСТАРЛС_ЧРСБФМ_АФКЗШСЩЕШЩНЕЦЯЪ_Я_РЕЗЧОЕНГЛТРЬЛЖХСЬЕЧЬЪ_ЪТЦ_ТСЭВЮЧЛВ_ЧШЯПФЖЧШВЧИБЧЧЬЭТК_БЧАНШЬМ_Ъ_ПДРСФХПВЮОШЮЪСБНЛДЮВЮАБ_ВНЮСЭНШЩФТАРЛИПВЬЕЧ_ЩИ_ДСТПВЛД_ДПИЬЪЛДЮВЮИЦЧЩИОЮФ_БЧАНЮЭЪГШЪЛРХГФВКЧЛАФЮФНШВЮРРГЪРКСФ_ЭЧЬВЭМС_Я_ЧИБЪЦИПАСРХВЮАЭДЮ_ВАЪМШЯМТЛСОЫ_ТТЕЭЪС_ШЯ_О_ЮМЦШ_ЩНРРЛМРХФСББМЛЛСЫРЮВЮОПАЪТЮЮЯ_ЖГЪ_ЮЯЪ_Ь_РНЮСФ_ЯБССБЪТНЮСШАУЪЭТ_ТЧЬПВЮАЭЧЮ__ЧМЛЛЯЪСБНЙ_ШСЦАЪСИЛХЬЮРШИССБФЪ_ТМУОТЧЮ_ФТЧЕЪ_ЛИФДДИХСЫОАЭСДАГОИОСВТЮУЖ_Я_ЩЯБНЛПЮИСМВСФНГ_ЬМРЗФЯПВЮАЭ_ОИБВК_ШСБЕЭГЬ_ТВСГЮСФ_ТВК_ТТТНЮСЫОЭРЮЬПЬМКПГСХЭ_ЧОУЪК_ШЩШЕЭРСТПВЫОА_НЫПЧС_ЮУЬАС_ЮКШСЪБПОЮОЬСПЛРФЩЫЬСЪБ_ТУОЬСФ_Я_ХДХГЛРХИЗ_ТСРАЭЯЪЙПХЧАТЧЛСЫТНОПАЪДУ_ЮОТЭСНЭМС_ЖЪЮАБЧЧИПЯС_ЧЯМЮИЪС_ЯБФНЕЪЫОТСЬАС_ЮЫПФЖЧШВЧИБЧЧЬЭ_Х_БЧАНШЬФ_ШСФСБ_ЬИШССЕПБМЗТЪЮИОСЫОЫДВАБСЩЕЮУАОФЪШЫЩСШИЭЪШУЬСЭВХЦСНШЫЛЧБ_НЫПАЬОФ_ЧЖШГЗ_ЖГСНШЧЛКЭЪПИПТЛЕАЭФ_ТМЛЗЭТСТХСЦАЪСЬАС_ЮАНГЛЦШЕЬОТМС_Ъ_ШПЛПЮЕ_МЛМЮШСТХСЭПЮЬЪЙЭ_ЛП__ЧИАГМТЛСЩЕАЬЪЛЛЬЪ_АГЬАЭЪБ_ШСЫЕ_ЧХТШСЭРРЩЯ_ЪСЮРХГЗЕЩСПЛРФС
        //char res = x->first; //макс элемент (Й)
        auto it4 = find(begin(alpha), end(alpha), x->first);
        cout << "Max element: " << x->first << " " << x->second << endl;
        shifts.push_back(PrintMapRange(it4, end(alpha)));
       cout << endl;

    }
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
