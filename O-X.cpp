#include <iostream>
#include <string>
#include <windows.h>

 using namespace std;
 
 string delChar(string st, int n)
  {
       st.erase(n - 1, 1);
       return st;
  }

 void remove(char* arr, char ch)
 {
     char* old = arr;
     while (*old)
     {
         if (*old != ch) {
             *arr = *old;
             ++arr;
         }
         ++old;
     }
     *arr = '\0';
 }

 void add(string& s, char ch, size_t pos)
 {
     s += ch;
     for (size_t i = s.size() - 1; i >= pos; i--)
         s[i] = s[i - 1];
     s[pos - 1] = ch;
 }

 void zamena(char* s, char h,char u)
 {
     for (int i = 0; i < 5000; i++)
     {
         if (s[i] == h) {
             s[i] = u;
         }
     }
 }

 int chet(char* s,char u)
 {
     int sum = 0;
     for (int i = 0; i < 5000; i++)
     {
         if (s[i] == u) 
         {
             sum = sum + 1;
         }
     }
     return sum;
 }

 int rus(string& str)
 {
     int r;
     char vowels[20] = { 'а', 'у', 'о', 'ы', 'и', 'э', 'я', 'ю', 'ё', 'е', 'А', 'У', 'О', 'Ы', 'И', 'Э', 'Я', 'Ю', 'Ё', 'Е' };
     char consonants[42] = { 'б', 'в', 'г', 'д', 'ж', 'з', 'й', 'к', 'л', 'м', 'н', 'п', 'р', 'с', 'т', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'Б', 'В', 'Г', 'Д', 'Ж', 'З', 'Й', 'К', 'Л', 'М', 'Н', 'П', 'Р', 'С', 'Т', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ' };
     int vowels_quantity = 0, consonants_quantity = 0;
     for (int f = 0; f <= (int)str.size(); f++) {
         for (int v = 0; v <= 19; v++)
             if (str[f] == vowels[v]) vowels_quantity += 1;

         for (int c = 0; c <= 41; c++)
             if (str[f] == consonants[c]) consonants_quantity += 1;
     }
     r = consonants_quantity + vowels_quantity;
     cout << "Гласных русских букв: " << vowels_quantity;
     cout << "\nСогласных русских букв: " << consonants_quantity;
     return r;
 }

 int eng(string& str, int i = 0,int  d = 0,int l = 0)
 {
     while (str[i])
     {
         if (str[i] >= '0' && str[i] <= '9')
             d++;
         else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) l++;
         i++;
     }
     cout << "\nЧисел - " << d << endl;
     cout << "Английских букв - " << l << endl;
     i = i - d - l;
     return i;
 }

 int mi(int* dig, int n)
 {
     int g;
     int Max = dig[0], Min = dig[0];
     for (int i = 1; i < n; i++)
     {
         if (Min > dig[i])
             Min = dig[i];
     }
     
     return Min;
 }

 int mi1(int* dig1, int m)
 {
     int g;
     int Max = dig1[0], Min = dig1[0];
     for (int i = 1; i < m; i++)
     {
         if (Min > dig1[i])
             Min = dig1[i];
     }
     return Min;
 }

 int ma(int* dig,int n)
 {
     int g;
     int Max = dig[0], Min = dig[0];
     for (int i = 1; i < n; i++)
     {
         if (Max < dig[i])
             Max = dig[i];
     }
     return Max;
 }

 int ma1(int* dig1, int m)
 {
     int g;
     int Max = dig1[0], Min = dig1[0];
     for (int i = 1; i < m; i++)
     {
         if (Max < dig1[i])
             Max = dig1[i];
     }
     return Max;
 }

 void avr(int* dig, int* dig1, int n, int m)
 {
     double sum = 0, sum1 = 0;
     for (int i = 0; i < n; i++)
     {
         sum = sum + dig[i];
     }
     sum = sum / n;
     for (int d = 0; d < m; d++)
     {
         sum1 = sum1 + dig1[d];
     }
     sum1 = sum1 / m;
     cout << "Среднее арифметическое 1 массива равно " << sum<<endl;
     cout << "Среднее арифметическое 2 массива равно " << sum1<<endl;

 }

 void Action(int dig[], int dig1[], int n, int m)
 {
     int g,fd,fd1,fdd,fdd1;
     cout << "Какой ваш выбор 1 - min, 2 - max, 3 - avr; "; cin >> g;
     if (g < 0 || g > 4) while ((g < 0 || g > 4)) 
     {
         cout << "Вы ошиблись или промазали?"<<endl;
         cout << "Какой ваш выбор 1 - min, 2 - max, 3 - avr; "; cin >> g;
     }
     else
     {
         switch (g)
         {
         case 1:
             fd = mi(dig, n);
             fd1 = mi1(dig1, m);
             cout << "Наименьшее число в 1 массиве " << fd << endl;
             cout << "Наименьшее число в 2 массиве " << fd1 << endl;
             break;
         case 2:
             fdd = ma(dig, n);
             fdd1 = ma1(dig1, m);
             cout << "Наибольшее число в 1 массиве " << fdd << endl;
             cout << "Наибольшее число в 2 массиве " << fdd1 << endl;
             break;
         case 3:
             avr(dig, dig1, n, m);
             break;
         }
     }
 }

 void a1()
 {
     int n, m;
     cout << "Введите размер 1 массива: ";
     cin >> n;
     int* dig = new int[n];

     cout << "Массив #1 >>> { ";
     for (int i = 0; i < n; i++) {
         dig[i] = rand() % 101 - 50;
         cout << dig[i] << ", ";
     }
     cout << "}\n";
     
     cout << "Введите размер 2 массива: ";
     cin >> m;
     int* dig1 = new int[m];

     cout << "Массив #2 >>> { ";
     for (int i = 0; i < m; i++) {
         dig1[i] = rand() % 101 - 50;
         cout << dig1[i] << ", ";
     }
     cout << "}\n";

     Action(dig, dig1, n, m);
 }

 void a2()
  {
       
       string text;  int a;
       cout << "Введите строку: "; cin >> text;
       cout << "Введите номер символа, который нужно удалить: "; cin >> a;
       cout << "Переделанная строка >>> ";
       cout << delChar(text, a); cout << endl;
  }

 void a3()
 {
     char str[5000]; char s;
     cout << "Введите строку: "; cin >> str;
     cout << "Введите символ: "; cin >> s;
     remove(str, s);
     cout <<"Переделанная строка >>> "<< str << endl;
 }

 void a4()
 {
     char ch;
     size_t p, si;
     string s;
     cout << "Введите строку: ";   
     cin >> s;
     cout << "Введите символ: ";   
     cin >> ch;
     cout << "Введите позицию: ";
     cin >> p;
     add(s, ch, p);

     cout <<"Измененная строка >>> "<< s << "\n";
 }

 void a5()
 {
     char s[5000]; char h, u;
     cout << "Введите строку: ";   
     cin >> s;
     cout << "Введите символ, который нужно заменить: "; cin >> h;
     cout << "Введите символ, на который нужно изменить: "; cin >> u;
     zamena(s,h,u);
     cout << "Измененная строка >>> "<<s << "\n";
 }

 void a6()
 {
     char s[5000]; char h; int a;
     cout << "Введите строку: "; cin >> s;
     cout << "Введите символ, который нужно посчитать: "; cin >> h;
     a = chet(s, h);
     cout << "В строке \"" << s << "\" символ " << h << " встречался "<< a <<" раз(а).\n";
 }

 void a7()
 {
     SetConsoleCP(1251);
     SetConsoleOutputCP(1251);
     string str; int r, i, s;
     cout << "Введите строку: ";
     cin >> str;
     
     s = eng(str) - rus(str);
     cout << "\nДругого - "<< s<<endl;
 }

 void main()
 {
     setlocale(LC_ALL, "rus");
     srand(time(NULL));
     int f;
     do
     {


         cout << "1 - 4 >>> "; cin >> f;
         switch (f)
         {
         case 1:
             a1();
             break;
         case 2:
             a2();
             break;
         case 3:
             a3();
             break;
         case 4:
             a4();
             break;
         case 5:
             a5();
             break;
         case 6:
             a6();
             break;
         case 7:
             a7();
             break;
         }
     } while (f != 0);
 }