#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class representing a single multimedia library item (movie)
class Library {
private:
    string title;
    string theme;
    string actors;
    double rating;
    double length;       // duration in minutes
    double speed;        // playback speed (1.0 = normal)
    string filename;
    string date;

public:
    Library() : rating(0), length(0), speed(1.0) {}

    Library(string t, string th, string a, double r, double l, double s, string f, string d)
        : title(t), theme(th), actors(a), rating(r), length(l), speed(s), filename(f), date(d) {
    }

    ~Library() {}

    void set(string t, string th, string a, double r, double l, double s, string f, string d) {
        title = t; theme = th; actors = a;
        rating = r; length = l; speed = s;
        filename = f; date = d;
    }

    string getTitle() const { return title; }
    string getTheme() const { return theme; }
    string getActors() const { return actors; }
    double getRating() const { return rating; }

    void show() const {
        cout << "Title: " << title << endl;
        cout << "Theme: " << theme << endl;
        cout << "Actors: " << actors << endl;
        cout << "Rating: " << rating << endl;
        cout << "Duration: " << length << " min" << endl;
        cout << "Playback speed: " << speed << "x" << endl;
        cout << "File: " << filename << endl;
        cout << "Date: " << date << endl;
        cout << "-----------------------------------" << endl;
    }
};

// Class representing the player, which contains a collection of movies
class Player {
private:
    vector<Library> films;

public:
    Player() {}

    void addFilm(const Library& film) {
        films.push_back(film);
    }

    void showAll() const {
        cout << "===== MOVIE LIST =====" << endl;
        for (const auto& f : films) {
            f.show();
        }
    }

    void searchByTitle(const string& t) const {
        cout << "=== Search by title: " << t << " ===" << endl;
        for (const auto& f : films) {
            if (f.getTitle() == t) {
                f.show();
            }
        }
    }

    void searchByActor(const string& a) const {
        cout << "=== Search by actor: " << a << " ===" << endl;
        for (const auto& f : films) {
            if (f.getActors().find(a) != string::npos) {
                f.show();
            }
        }
    }

    void searchByTheme(const string& th) const {
        cout << "=== Search by theme: " << th << " ===" << endl;
        for (const auto& f : films) {
            if (f.getTheme() == th) {
                f.show();
            }
        }
    }
};

int main() {
    Player player;

    // Create sample movies
    Library f1("Inception", "Sci-Fi", "Leonardo DiCaprio", 9.0, 148, 1.0, "inception.mp4", "2010-07-16");
    Library f2("Titanic", "Romance", "Leonardo DiCaprio, Kate Winslet", 8.5, 195, 1.0, "titanic.mp4", "1997-12-19");
    Library f3("Matrix", "Sci-Fi", "Keanu Reeves", 8.7, 136, 1.0, "matrix.mp4", "1999-03-31");

    // Add movies to the player
    player.addFilm(f1);
    player.addFilm(f2);
    player.addFilm(f3);

    // Display all movies
    player.showAll();

    // Search functionality
    player.searchByTitle("Titanic");
    player.searchByActor("Leonardo DiCaprio");
    player.searchByTheme("Sci-Fi");

    return 0;
}
