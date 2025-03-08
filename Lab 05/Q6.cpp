#include <iostream>
using namespace std;

class Level {
public:
    char* name;
    int difficulty;
    Level(char* levelName, int levelDifficulty) {
        int i = 0;
        while (levelName[i] != '\0') i++;
        name = new char[i + 1];
        for (int j = 0; j <= i; j++) name[j] = levelName[j];
        difficulty = levelDifficulty;
    }
    void display() {
        cout << "Level: " << name << " | Difficulty: " << difficulty << "\n";
    }
    ~Level() {
        delete[] name;
    }
};
class VideoGame {
public:
    char* title;
    char* genre;
    Level* levels[5]; 
    int levelCount;
    VideoGame(char* gameTitle, char* gameGenre) {
        int i = 0;
        while (gameTitle[i] != '\0') i++;
        title = new char[i + 1];
        for (int j = 0; j <= i; j++) title[j] = gameTitle[j];
        i = 0;
        while (gameGenre[i] != '\0') i++;
        genre = new char[i + 1];
        for (int j = 0; j <= i; j++) genre[j] = gameGenre[j];
        levelCount = 0;
    }
    void add_Level(char* name, int difficulty) {
        if (levelCount < 5) {
            levels[levelCount] = new Level(name, difficulty);
            levelCount++;
        }
    }
    void display() {
        cout << "Game: " << title << " | Genre: " << genre << "\nLevels:\n";
        for (int i = 0; i < levelCount; i++) {
            levels[i]->display();
        }
    }
    ~VideoGame() {
        for (int i = 0; i < levelCount; i++) {
            delete levels[i]; 
        }
        delete[] title;
        delete[] genre;
    }
};
int main() {
    VideoGame game("Space Adventure", "Sci-Fi");
    game.add_Level("Ateroid Field", 2);
    game.add_Level("Black Hole", 4);
    game.add_Level("Planet Alpha", 6);
    game.display();
    return 0;
}
