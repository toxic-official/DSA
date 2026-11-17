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

    for (int i = 1; i < n; i++) {
        Student key = s[i];
        int j = i - 1;

        while (j >= 0 && strcmp(s[j].name, key.name) > 0) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }

    cout << "\nSorted by Name:\n";
    for (int i = 0; i < n; i++)
        cout << s[i].id << " " << s[i].name << " " << s[i].cgpa << endl;

    for (int i = 1; i < n; i++) {
        Student key = s[i];
        int j = i - 1;

        while (j >= 0 && s[j].cgpa > key.cgpa) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }

    cout << "\nSorted by CGPA (Ascending):\n";
    for (int i = 0; i < n; i++)
        cout << s[i].id << " " << s[i].name << " " << s[i].cgpa << endl;

    free(s);
    return 0;
}
