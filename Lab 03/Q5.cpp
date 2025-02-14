#include <iostream>
using namespace std;

class MusicPlayer {
private:
    char playlist[10][50]; 
    int songCount;
    char currentlyPlayingSong[50];
public:
    MusicPlayer() {
        songCount = 0;
        currentlyPlayingSong[0] = '\0'; 
    }
    void addSong(char song[]) {
        if (songCount < 10) {
            int i = 0;
            while (song[i] != '\0') {
                playlist[songCount][i] = song[i];
                i++;
            }
            playlist[songCount][i] = '\0';  
            songCount++;
            cout << "Added song: " << song << endl;
        } else {
            cout << "Playlist is full!\n";
        }
    }
    void removeSong(char song[]) {
        for (int i = 0; i < songCount; i++) {
            int j = 0;
            while (playlist[i][j] == song[j] && song[j] != '\0') j++;
            if (song[j] == '\0' && playlist[i][j] == '\0') {  // Song match found
                for (int k = i; k < songCount - 1; k++) {
                    int l = 0;
                    while (playlist[k + 1][l] != '\0') {
                        playlist[k][l] = playlist[k + 1][l];
                        l++;
                    }
                    playlist[k][l] = '\0';
                }
                songCount--;
                cout << "Removed song: " << song << endl;
                return;
            }
        }
        cout << "Song not found in playlist!\n";
    }
    void playSong(char song[]) {
        int i = 0;
        while (song[i] != '\0') {
            currentlyPlayingSong[i] = song[i];
            i++;
        }
        currentlyPlayingSong[i] = '\0';
        cout << "Now Playing: " << currentlyPlayingSong << endl;
    }
    void displayPlaylist() {
        cout << "\nPlaylist:\n";
        for (int i = 0; i < songCount; i++) {
            cout << i + 1 << ". " << playlist[i] << endl;
        }
        if (currentlyPlayingSong[0] != '\0') {
            cout << "Currently Playing: " << currentlyPlayingSong << endl;
        }
    }
};
int main() {
    MusicPlayer imranPlayer;
    char song1[] = "Bohemian Rhapsody";
    char song2[] = "Imagine";
    imranPlayer.addSong(song1);
    imranPlayer.addSong(song2);
    imranPlayer.playSong(song2);
    imranPlayer.displayPlaylist();
    imranPlayer.removeSong(song2);
    imranPlayer.displayPlaylist();
    return 0;
}
