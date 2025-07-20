#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstring>


using namespace std;

// ------------------------- Quote Provider -------------------------
class QuoteProvider {
    map<string, vector<string>> moodQuotes;

public:
    QuoteProvider() {
        moodQuotes["happy"] = {
            "Happiness is contagious.",
            "Joy is a form of gratitude.",
            "Keep smiling, it suits you."
        };
        moodQuotes["sad"] = {
            "It's okay to feel sad.",
            "This too shall pass.",
            "Crying is healing."
        };
        moodQuotes["anxious"] = {
            "Breathe. You’re doing great.",
            "Let go of what you can’t control.",
            "You are safe in this moment."
        };
        moodQuotes["calm"] = {
            "Peace begins with a deep breath.",
            "Enjoy this moment of stillness.",
            "Stay present, stay grounded."
        };
    }

    string getQuoteByMood(string mood) {
        if (moodQuotes.find(mood) != moodQuotes.end()) {
            vector<string> quotes = moodQuotes[mood];
            int index = rand() % quotes.size();
            return quotes[index];
        } else {
            return "Stay strong. Your feelings are valid.";
        }
    }
};

// ------------------------ Calming Exercises ------------------------
class CalmingExercise {
    vector<string> exercises;

public:
    CalmingExercise() {
        exercises.push_back("Try 4-7-8 breathing: inhale 4s, hold 7s, exhale 8s.");
        exercises.push_back("Close your eyes and take 3 deep breaths.");
        exercises.push_back("Imagine a peaceful place — the beach or forest.");
    }

    string getExercise() {
        return exercises[rand() % exercises.size()];
    }
};

// ------------------------ Information Storage ------------------------
class MoodStorage {
    string filename;
    map<string, int> moodCount;

public:
    MoodStorage(string file) : filename(file) {}

    void storeMood(const string& mood, const string& note) {
        ofstream out(filename.c_str(), ios::app);
        time_t now = time(0);
        char* dt = ctime(&now);
        dt[strlen(dt)-1] = '\0'; // remove newline

        out << dt << " | Mood: " << mood;
        if (!note.empty()) {
            out << " | Note: " << note;
        }
        out << endl;
        out.close();

        moodCount[mood]++;
    }

    void showHistory() {
        ifstream in(filename.c_str());
        string line;
        cout << "\n?? Mood History:\n";
        while (getline(in, line)) {
            cout << line << endl;
        }
        in.close();
    }

    void showMoodStats() {
        cout << "\n?? Mood Frequency:\n";
        for (map<string, int>::iterator it = moodCount.begin(); it != moodCount.end(); ++it) {
            cout << "- " << it->first << ": " << it->second << " times\n";
        }
    }
};

// ----------------------------- Main -----------------------------
int main() {
    srand(time(0));
    string name, mood, note, choice;

    cout << "?? Welcome to the Offline Mood Tracker (Dev-C++ Compatible)\n";
    cout << "Enter your name: ";
    getline(cin, name);

    MoodStorage storage("mood_log.txt");
    QuoteProvider quotes;
    CalmingExercise exercises;

    while (true) {
        cout << "\n?? Choose an option: start / history / stats / exit\n";
        cout << "?? Your choice: ";
        getline(cin, choice);

        if (choice == "start") {
            cout << "\nHello " << name << "! Let's log your mood.\n";
            cout << "?? How are you feeling? (happy/sad/anxious/calm etc): ";
            getline(cin, mood);

            cout << "?? Want to add a note? (optional, press enter to skip): ";
            getline(cin, note);

            storage.storeMood(mood, note);

            cout << "\n?? Quote for you:\n" << quotes.getQuoteByMood(mood) << endl;
            cout << "?? Calming Tip:\n" << exercises.getExercise() << endl;

        } else if (choice == "history") {
            storage.showHistory();
        } else if (choice == "stats") {
            storage.showMoodStats();
        } else if (choice == "exit") {
            cout << "?? Goodbye " << name << ". Take care!\n";
            break;
        } else {
            cout << "?? Invalid option. Please try again.\n";
        }
    }

    return 0;
}

