#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int id;
    char name[50];
    int age;
    char course[30];
};

void addStudent() {
    Student s;
    ofstream file("students.dat", ios::binary | ios::app);

    cout << "Enter Student ID: ";
    cin >> s.id;
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter Age: ";
    cin >> s.age;
    cout << "Enter Course: ";
    cin >> s.course;

    file.write((char*)&s, sizeof(s));
    file.close();

    cout << "Student added successfully!\n";
}

void displayStudents() {
    Student s;
    ifstream file("students.dat", ios::binary);

    cout << "\n--- Student Records ---\n";
    while (file.read((char*)&s, sizeof(s))) {
        cout << "ID: " << s.id << endl;
        cout << "Name: " << s.name << endl;
        cout << "Age: " << s.age << endl;
        cout << "Course: " << s.course << endl;
        cout << "------------------------\n";
    }
    file.close();
}

void searchStudent() {
    Student s;
    int id, found = 0;
    ifstream file("students.dat", ios::binary);

    cout << "Enter Student ID to search: ";
    cin >> id;

    while (file.read((char*)&s, sizeof(s))) {
        if (s.id == id) {
            cout << "Record Found!\n";
            cout << "Name: " << s.name << endl;
            cout << "Age: " << s.age << endl;
            cout << "Course: " << s.course << endl;
            found = 1;
            break;
        }
    }
    file.close();

    if (!found)
        cout << "Student not found!\n";
}

void deleteStudent() {
    Student s;
    int id;
    ifstream file("students.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    cout << "Enter Student ID to delete: ";
    cin >> id;

    while (file.read((char*)&s, sizeof(s))) {
        if (s.id != id)
            temp.write((char*)&s, sizeof(s));
    }

    file.close();
    temp.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    cout << "Student record deleted (if existed).\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
Added main program structure

