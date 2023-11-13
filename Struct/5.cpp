#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Course {
public:
    Course(string code, string name, int credits, string grade) {
        this->code = code;
        this->name = name;
        this->credits = credits;
        this->grade = grade;
    }
    string code;
    string name;
    int credits;
    string grade;
};

class Student {
public:
    Student(string nim, string name) {
        this->nim = nim;
        this->name = name;
    }
    void addCourse(Course course) {
        courses.push_back(course);
    }
    float calculateGPA() {
        float totalGradePoint = 0;
        int totalCredits = 0;
        for (int i = 0; i < courses.size(); i++) {
            string grade = courses[i].grade;
            int credits = courses[i].credits;
            totalCredits += credits;
            if (grade == "A") {
                totalGradePoint += 4.0 * credits;
            } else if (grade == "B") {
                totalGradePoint += 3.0 * credits;
            } else if (grade == "C") {
                totalGradePoint += 2.0 * credits;
            } else if (grade == "D") {
                totalGradePoint += 1.0 * credits;
            } else {
                totalGradePoint += 0.0 * credits;
            }
        }
        return totalGradePoint / totalCredits;
    }
    void printKHS() {
        cout << "KHS Mahasiswa" << endl;
        cout << "NIM: " << nim << endl;
        cout << "Nama: " << name << endl;
        cout << "Mata Kuliah yang diambil: " << endl;
        for (int i = 0; i < courses.size(); i++) {
            cout << courses[i].code << " - " << courses[i].name << " (" << courses[i].credits << " SKS)" << endl;
            cout << "Nilai: " << courses[i].grade << endl;
        }
        cout << "IPK: " << calculateGPA() << endl;
    }
private:
    string nim;
    string name;
    vector<Course> courses;
};

int main() {
    vector<Student> students;
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string nim;
        string name;
        cout << "Masukkan NIM Mahasiswa " << i + 1 << ": ";
        cin >> nim;
        cout << "Masukkan Nama Mahasiswa " << i + 1 << ": ";
        cin >> name;
        Student student(nim, name);
        for (int j = 0; j < 5; j++) {
            string code;
            string name;
            int credits;
            string grade;
            cout << "Masukkan Kode Mata Kuliah ke-" << j + 1 << ": ";
            cin >> code;
            cout << "Masukkan Nama Mata Kuliah ke-" << j + 1 << ": ";
            cin >> name;
            cout << "Masukkan Bobot SKS Mata Kuliah ke-" << j + 1 <<": ";
            cin >> credits;
            cout << "Masukkan Nilai Huruf Mata Kuliah ke-" << j + 1 << ": ";
            cin >> grade;
            Course course(code, name, credits, grade);
            student.addCourse(course);
        }
        students.push_back(student);
    }

    // Menampilkan KHS semua mahasiswa
    for (int i = 0; i < students.size(); i++) {
        students[i].printKHS();
        cout << endl;
    }

    return 0;
}