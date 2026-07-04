#include <fstream>
#include <string>
#include <iostream>
#include <stack>
#include <locale.h>    
#include <windows.h>
# include <clocale>
#include <vector>
#include <algorithm>
using namespace std;

class stroka
{ public:
    string name;
    short age;
    

};
istream& operator>>(istream& is, stroka& s) {
    return is >> s.name >> s.age;
}
ostream& operator<<(ostream& os, const stroka& s) {
    return os << s.name << " " << s.age;
}

void f1(stack<stroka>& stek);
void f2(stack<stroka>& stek);
void p_name(stack<stroka>& stek);
void p_age(stack<stroka>& stek);
void f3(stack<stroka>& stek);
void f4(stack<stroka>& stek);
stack<stroka> y_name(stack<stroka>& stek);
stack<stroka> y_age(stack<stroka>& stek);
void f5(stack<stroka>& stek);
void f6(stack<stroka>& stek);
bool comparePersonPtr_name(const stroka* a, const stroka* b);
bool comparePersonPtr_age(const stroka* a, const stroka* b);
int main()
{
    setlocale(LC_ALL, "rus");
    stack<stroka> stek;
    ifstream file("Список.txt");
    string name;
    if (!file.is_open()) {
        cout << "file error" << endl;

    }
    stroka punkt;
    while (file >> punkt)
    {

        stek.push(punkt);
    }
    int n;
    cout << "Вывод стека: 1" << endl
        << "Поиск: 2" << endl
        << "Добавление данных в стек: 3" << endl
        << "Удаление данных из стека: 4" << endl
        << "Сохранение стека в файл: 5" << endl
        << "Сортировка: 6" << endl
        << "Если вы хотите закончить : 7" << endl;
    cout << endl;
    do
    {

        cout << "Ведите номер действия:";
        cin >> n;
        
        switch (n)
        {
        case 1:
            f1(stek);
            break;
        case 2:
		    f2(stek);
		    break;
		case 3:
            f3(stek);
            break;
        case 4:
		    f4(stek);
			break;
		case 5:
		    f5(stek);
			break;
		case 6 :
		    f6(stek);
			break;   
        case 7:
            cout << "Пока пока";
            break;
        }
    } while (n != 7);


}
void f1(stack<stroka>& stek)
{
    stack<stroka> tmp = stek;
    while (!tmp.empty())
    {
        cout << tmp.top() << endl;
        tmp.pop();
    }
}
void f2(stack<stroka>& stek)
{
cout<<"Поиск по фамилии: 1"<<endl;
cout<<"Поиск по возрасту: 2"<<endl;
cout << "Ведите номер действия:";

short n;
cin >> n;
switch (n){
	case 1: p_name(stek);
            break;
    case 2: p_age(stek);
	        break;        
	
}
}

void p_name(stack<stroka>& stek)
{ 
      stack<stroka> tmp = stek;
      string name;
      cout<<"Ведите фамилию которую ищите: ";
      cin>>name;
      int a =0;
while (!tmp.empty())
       {stroka punkt=tmp.top();
       	if(name==punkt.name)
       	{cout<<tmp.top()<<endl;
		  a=a+1; }
		tmp.pop();
		   
	   }
if(a==0){cout<<"Нет такой фамилии"<<endl;}
}

void p_age(stack<stroka>& stek)
{stack<stroka> tmp = stek;
short age;
cout<<"Ведите возраст который ищите: ";
cin>>age;
int a =0;
while (!tmp.empty())
       {stroka punkt=tmp.top();
       	if(age==punkt.age)
       	{cout<<tmp.top()<<endl;
		  a=a+1; }
		tmp.pop();
		   
	   }
if(a==0){cout<<"Нет людей такого возраста"<<endl;}
}


void f3(stack<stroka>& stek)
{
    cout << "Введите имя и возраст через пробел: ";
    stroka s;
    cin >> s;         // используется твой operator>>
    stek.push(s);
}

void f4(stack<stroka>& stek)
{cout<<"Удалить по фамилии: 1"<<endl;
cout<<"Удалить возраст: 2"<<endl;
cout << "Ведите номер действия:";

short n;
cin >> n;
switch (n){
	case 1: y_name(stek);
            break;
    case 2:  y_age(stek);
            break;       
       
	
}
}

stack<stroka> y_name(stack<stroka>& stek)
{ 
      stack<stroka> tmp = stek;
      string name;
      cout<<"Ведите фамилию которую удаляем: ";
      cin>>name;
      int a =0;
      
      stack<stroka> t;
 while (!tmp.empty())
       {stroka punkt=tmp.top();
	    if(name!=punkt.name){
		t.push(punkt);
		tmp.pop();}
		else{
		tmp.pop();
		 a=a+1;}           
	   }
if(a==0){cout<<"Нет такой фамилии"<<endl;}
stek=t;
return stek;

}

stack<stroka> y_age(stack<stroka>& stek)
{ 
      stack<stroka> tmp = stek;
      short age;
      cout<<"Ведите возраст который удаляем: ";
      cin>>age;
      int a =0;
      
      stack<stroka> t;
 while (!tmp.empty())
       {stroka punkt=tmp.top();
	    if(age!=punkt.age){
		t.push(punkt);
		tmp.pop();}
		else{
		tmp.pop();
		 a=a+1;}           
	   }
if(a==0){cout<<"Нет людей такого возраста"<<endl;}
stek=t;
return stek;
}

void f5(stack<stroka>& stek)
{stack<stroka> tmp = stek;
ofstream file("Список.txt");
while (!tmp.empty())
       {
       file<<tmp.top()<<endl;
       tmp.pop();
	   }
}
void f6(stack<stroka>& stek) {
    vector<stroka> v;
    while (!stek.empty()) {
        v.push_back(stek.top());
        stek.pop();
    }

    int n = (int)v.size();
    vector<stroka*> ptrs(n);
    for (int i = 0; i < n; ++i)
        ptrs[i] = &v[i];

    cout << "Сортировка по алфавиту: 1\n";
    cout << "Сортировка по возрасту: 2\n";
    cout << "Введите номер действия: ";

    int variant;
    cin >> variant;

    switch (variant) {
        case 1:
            sort(ptrs.begin(), ptrs.end(), comparePersonPtr_name);
            break;
        case 2:
            sort(ptrs.begin(), ptrs.end(), comparePersonPtr_age);
            break;
        default:
            cout << "Неверный вариант\n";
            return;      // выходим, не меняя стек
    }

    stack<stroka> sorted;
    // кладём так, чтобы сверху был «первый» по сортировке (минимальный)
    for (int i = n - 1; i >= 0; --i)
        sorted.push(*ptrs[i]);

    stek = sorted;
}
bool comparePersonPtr_name(const stroka* a, const stroka* b) {
    if (a->name == b->name)
        return a->age < b->age;    // если фамилии равны – сортируем по возрасту
    return a->name < b->name;      // иначе по фамилии по алфавиту
}
bool comparePersonPtr_age(const stroka* a, const stroka* b) {
    if (a->age == b->age)
        return a->name < b->name;    // если фамилии равны – сортируем по возрасту
    return a->age < b->age;      // иначе по фамилии по алфавиту
}
