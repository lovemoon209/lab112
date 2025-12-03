/*
Варіант 14.

Дано текстовий файл t1.
Групи символів, відокремлені пробілами (одним або кількома), відмінні від знаків
пунктуації і які не містять пробілів, будемо називати словами. Переписати його
вміст у текстовий файл t2, при цьому: якщо слово записано після крапки – то
замінити першу букву в цьому слові відповідною великою буквою.
*/

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void CapitalizeAfterDot(string &s) {
  bool afterDot = true;

  for (size_t i = 0; i < s.length(); ++i) {

    if (afterDot && isalpha(s[i])) {
      s[i] = toupper(s[i]);
      afterDot = false;
    }

    if (s[i] == '.') {
      afterDot = true;
    } else if (s[i] != ' ' && s[i] != '.') {
      afterDot = false;
    }
  }
}
void ShowFile(const string &filename) {
  ifstream file(filename);

  if (!file.is_open()) {
    cout << "Don't open " << filename << endl;
    return;
  }
  cout << "componemt: " << filename << endl;
  string line;
  int linenom = 1;
  while (getline(file, line)) {
    cout << linenom << ": " << line << endl;
    linenom++;
  }
  file.close();
}

int main() {
  ifstream in("t1.txt");
  ofstream temp("t1.txt");
  if (!temp.is_open()) {
    cout << "Не вдалося створити t1.txt\n";
    return 1;
  }

  cout << "Введіть речення: ";
  string userText;
  getline(cin, userText);

  temp << userText;
  temp.close();

  cout << "Речення записано у t1.txt\n";
  ofstream out("t2.txt");

  if (!in.is_open()) {
    cout << "Not open t1 \n";
    return 1;
  }
  if (!out.is_open()) {
    cout << "Not open t2 \n";
    return 1;
  }
  string line;
  while (getline(in, line)) {
    CapitalizeAfterDot(line);
    out << line << endl;
  }
  cout << "t1-> t2 \n";
  ShowFile("t2.txt");
  in.close();
  out.close();

  return 0;
}
