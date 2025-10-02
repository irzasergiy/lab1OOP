#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
using namespace std;

// Class representing a single record
class Record {
private:
    string name;
    string phone;
    string birthday; // format: YYYY-MM-DD

public:
    Record() : name(""), phone(""), birthday("") {}

    Record(string n, string p, string b) {
        setName(n);
        setPhone(p);
        setBirthday(b);
    }

    void setName(string n) {
        if (n.empty()) throw invalid_argument("Name cannot be empty");
        name = n;
    }

    void setPhone(string p) {
        for (char c : p) {
            if (!isdigit(c) && c != '+')
                throw invalid_argument("Phone must contain only digits or '+'");
        }
        phone = p;
    }

    void setBirthday(string b) {
        if (b.size() != 10 || b[4] != '-' || b[7] != '-')
            throw invalid_argument("Birthday must be in format YYYY-MM-DD");
        birthday = b;
    }

    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getBirthday() const { return birthday; }

    void show() const {
        cout << "Name: " << name << ", Phone: " << phone
            << ", Birthday: " << birthday << endl;
    }

    // Overload comparison by birthday (for sorting)
    bool operator<(const Record& other) const {
        return birthday < other.birthday;
    }

    // Overload equality for search
    bool operator==(const string& key) const {
        return (name == key || birthday == key);
    }
};

// Class representing a notebook of records
class Notebook {
private:
    vector<Record> records;

public:
    Notebook() {}

    // Add record (operator+)
    Notebook& operator+(const Record& r) {
        records.push_back(r);
        return *this;
    }

    // Remove record by name (operator-)
    Notebook& operator-(const string& name) {
        auto it = remove_if(records.begin(), records.end(),
            [&](const Record& r) { return r.getName() == name; });
        if (it == records.end())
            throw runtime_error("Record not found for deletion");
        records.erase(it, records.end());
        return *this;
    }

    // Search for a record (overloaded method)
    void search(const string& key) const {
        bool found = false;
        for (const auto& r : records) {
            if (r == key) {
                r.show();
                found = true;
            }
        }
        if (!found) cout << "No record found for: " << key << endl;
    }

    // Sort records by birthday
    void sortByBirthday() {
        sort(records.begin(), records.end());
    }

    // Display all records
    void showAll() const {
        cout << "===== NOTEBOOK =====" << endl;
        for (const auto& r : records) r.show();
    }

    // Overload assignment operator
    Notebook& operator=(const Notebook& other) {
        if (this != &other) {
            this->records = other.records;
        }
        return *this;
    }
};

// Demonstration
int main() {
    try {
        Notebook nb;

        Record r1("John Smith", "+380123456789", "1999-05-10");
        Record r2("Alice Brown", "+380987654321", "2000-12-01");
        Record r3("Bob Johnson", "+380555555555", "1995-07-22");

        // Add records
        nb = nb + r1;
        nb = nb + r2;
        nb = nb + r3;

        nb.showAll();

        // Search by name
        cout << "\nSearch by name 'Alice Brown':" << endl;
        nb.search("Alice Brown");

        // Search by birthday
        cout << "\nSearch by birthday '1995-07-22':" << endl;
        nb.search("1995-07-22");

        // Sort by birthday
        cout << "\nAfter sorting by birthday:" << endl;
        nb.sortByBirthday();
        nb.showAll();

        // Remove record
        cout << "\nRemoving 'John Smith':" << endl;
        nb = nb - string("John Smith");
        nb.showAll();

    }
    catch (exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
