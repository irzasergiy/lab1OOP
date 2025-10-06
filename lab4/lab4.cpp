#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
protected:
    string surname;
    string name;
    int age;

public:
    Person(string s = "", string n = "", int a = 0)
        : surname(s), name(n), age(a) {
    }

    virtual void input(istream& in) {
        in >> surname >> name >> age;
    }

    virtual void output(ostream& out) const {
        out << "Прізвище: " << surname << ", Ім'я: " << name << ", Вік: " << age;
    }

    virtual void assign(const Person& other) {
        surname = other.surname;
        name = other.name;
        age = other.age;
    }

    virtual ~Person() {}

    friend istream& operator>>(istream& in, Person& p) {
        p.input(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, const Person& p) {
        p.output(out);
        return out;
    }
};

class Student : public Person {
protected:
    string university;
    int course;

public:
    Student(string s = "", string n = "", int a = 0, string u = "", int c = 1)
        : Person(s, n, a), university(u), course(c) {
    }

    void input(istream& in) override {
        Person::input(in);
        in >> university >> course;
    }

    void output(ostream& out) const override {
        Person::output(out);
        out << ", Університет: " << university << ", Курс: " << course;
    }

    void assign(const Person& other) override {
        const Student* s = dynamic_cast<const Student*>(&other);
        if (s) {
            Person::assign(other);
            university = s->university;
            course = s->course;
        }
    }
};

class GraduateStudent : public Student {
private:
    string thesisTitle;
    string advisor;

public:
    GraduateStudent(string s = "", string n = "", int a = 0, string u = "", int c = 1,
        string title = "", string adv = "")
        : Student(s, n, a, u, c), thesisTitle(title), advisor(adv) {
    }

    void input(istream& in) override {
        Student::input(in);
        in.ignore(); 
        cout << "Тема дипломної: ";
        getline(in, thesisTitle);
        cout << "Керівник: ";
        getline(in, advisor);
    }

    void output(ostream& out) const override {
        Student::output(out);
        out << ", Тема дипломної: " << thesisTitle << ", Керівник: " << advisor;
    }

    void assign(const Person& other) override {
        const GraduateStudent* g = dynamic_cast<const GraduateStudent*>(&other);
        if (g) {
            Student::assign(other);
            thesisTitle = g->thesisTitle;
            advisor = g->advisor;
        }
    }
};

// === Головна функція ===
int main() {
    try {
        // Створення об'єкта дипломника
        GraduateStudent gs1("Ковальчук", "Ірина", 23, "КНУ", 5,
            "AI в медицині", "д-р Петренко");

        // Вивід у файл
        ofstream fout("students.txt");
        if (!fout) {
            cerr << "Помилка відкриття файлу для запису!" << endl;
            return 1;
        }
        fout << gs1 << endl;
        fout.close();

        // Введення нового дипломника
        GraduateStudent gs2;
        cout << "🔹 Введіть дані нового дипломника:\n"
            << "(Прізвище Ім'я Вік Університет Курс)\n";
        cin >> gs2;

        // Присвоєння через віртуальний метод
        GraduateStudent gs3;
        gs3.assign(gs2);

        // Виведення всіх об'єктів
        cout << "\nСтворений об'єкт:\n" << gs1 << endl;
        cout << "\nВведений об'єкт:\n" << gs2 << endl;
        cout << "\nСкопійований через assign:\n" << gs3 << endl;
    }
    catch (const exception& ex) {
        cerr << "Помилка: " << ex.what() << endl;
    }

    return 0;
}
