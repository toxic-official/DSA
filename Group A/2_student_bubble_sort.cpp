#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Student {
    int id;
    char name[30];
    float cgpa;
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student *s = (Student*)malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++) {
        cout << "Enter ID, Name and CGPA: ";
        cin >> s[i].id >> s[i].name >> s[i].cgpa;
    }

    int newN;
    cout << "Enter number of new students: ";
    cin >> newN;
    s = (Student*)realloc(s, (n + newN) * sizeof(Student));

    for (int i = n; i < n + newN; i++) {
        cout << "Enter ID, Name and CGPA: ";
        cin >> s[i].id >> s[i].name >> s[i].cgpa;
    }
    n += newN;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(s[j].name, s[j + 1].name) > 0) {
                Student t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }

    cout << "\nSorted by Name:\n";
    for (int i = 0; i < n; i++)
        cout << s[i].id << " " << s[i].name << " " << s[i].cgpa << endl;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].cgpa > s[j + 1].cgpa) {
                Student t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }

    cout << "\nSorted by CGPA (Ascending):\n";
    for (int i = 0; i < n; i++)
        cout << s[i].id << " " << s[i].name << " " << s[i].cgpa << endl;

    free(s);
    return 0;
}
