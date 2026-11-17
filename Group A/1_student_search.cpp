#include <iostream>
#include <cstdlib>
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
    n = n + newN;

    int key, found = 0;
    cout << "Enter ID for Linear Search: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (s[i].id == key) {
            cout << "Found: " << s[i].id << " " << s[i].name << " " << s[i].cgpa << endl;
            found = 1;
            break;
        }
    }
    if (!found) cout << "Student not found\n";

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].id > s[j + 1].id) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    cout << "Enter ID for Binary Search: ";
    cin >> key;
    int low = 0, high = n - 1;
    found = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (s[mid].id == key) {
            cout << "Found: " << s[mid].id << " " << s[mid].name << " " << s[mid].cgpa << endl;
            found = 1;
            break;
        } else if (key < s[mid].id) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (!found) cout << "Student not found\n";

    free(s);
    return 0;
}
