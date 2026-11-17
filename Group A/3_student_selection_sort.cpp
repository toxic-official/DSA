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
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(s[j].name, s[minIndex].name) < 0)
                minIndex = j;
        }
        Student t = s[i];
        s[i] = s[minIndex];
        s[minIndex] = t;
    }

    cout << "\nSorted by Name:\n";
    for (int i = 0; i < n; i++)
        cout << s[i].id << " " << s[i].name << " " << s[i].cgpa << endl;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (s[j].cgpa < s[minIndex].cgpa)
                minIndex = j;
        }
        Student t = s[i];
        s[i] = s[minIndex];
        s[minIndex] = t;
    }

    cout << "\nSorted by CGPA (Ascending):\n";
    for (int i = 0; i < n; i++)
        cout << s[i].id << " " << s[i].name << " " << s[i].cgpa << endl;

    free(s);
    return 0;
}
