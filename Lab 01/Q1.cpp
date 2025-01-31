#include <iostream>
#include <cstring> 
using namespace std;

int main() {
    const int max_Participants = 5;
    const int name_Length = 50;    
    char event1[max_Participants][name_Length] = {};
    char event2[max_Participants][name_Length] = {};
    int countEvent1 = 0, countEvent2 = 0;
    cout << "Enter names for Event 1 participants (maximum 5):\n";
    for (int i = 0; i < max_Participants; i++) {
        cout << "Participant " << i + 1 << ": ";
        cin.getline(event1[i], name_Length);
        if (strlen(event1[i]) > 0) {
            countEvent1++;
        }
    }
    cout << "\nEnter names for Event 2 participants (maximum 5):\n";
    for (int i = 0; i < max_Participants; i++) {
        cout << "Participant " << i + 1 << ": ";
        cin.getline(event2[i], name_Length);
        if (strlen(event2[i]) > 0) {
            countEvent2++;
        }
    }
    char nameToCheck[name_Length];
    cout << "\nEnter a name to check attendance: ";
    cin.getline(nameToCheck, name_Length);
    bool found = false;
    for (int i = 0; i < countEvent1; i++) {
        if (strcmp(event1[i], nameToCheck) == 0) {
            found = true;
            break;
        }
    }
    for (int i = 0; i < countEvent2 && !found; i++) {
        if (strcmp(event2[i], nameToCheck) == 0) {
            found = true;
            break;
        }
    }
    if (found) {
        cout << nameToCheck << " is registered in one of the events.\n";
    } else {
        cout << nameToCheck << " is NOT registered in any event.\n";
    }
    const int donation_participant = 10;
    int totalDonations = (countEvent1 + countEvent2) * donation_participant;
    cout << "\nTotal Donations Collected: $" << totalDonations << "\n";
    cout << "\nParticipants of Event 1 in Reverse Order:\n";
    for (int i = countEvent1; i >= 0; i--) {
        cout << event1[i] << "\n";
    }
    cout << "\nParticipants of Event 2 in Reverse Order:\n";
    for (int i = countEvent2; i >= 0; i--) {
        cout << event2[i] << "\n";
    }
    cout << "\nEvent Popularity Bar Chart:\n";
    cout << "Event 1: ";
    for (int i = 0; i < countEvent1; i++) cout << "*";
    cout << " (" << countEvent1 << " participants)\n";
    cout << "Event 2: ";
    for (int i = 0; i < countEvent2; i++) cout << "*";
    cout << " (" << countEvent2 << " participants)\n";
    return 0;
}
