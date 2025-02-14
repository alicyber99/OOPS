#include <iostream>
using namespace std;

class FitnessTrack {
private:
    char Name[50];
    int daily_StepGoal;
    int steps_taken;
    double calories_burned;
public:
    FitnessTrack(char name[], int stepGoal) {
        int i = 0;
        while (name[i] != '\0') {
            Name[i] = name[i];
            i++;
        }
        Name[i] = '\0';
        daily_StepGoal = stepGoal;
        steps_taken = 0;
        calories_burned = 0;
    }
    void logSteps(int steps) {
        steps_taken += steps;
        calories_burned += steps * 0.04;  
    }
    void displayProgress() {
        cout << Name << "'s Fitness Progress:\n";
        cout << "Steps Taken: " << steps_taken << "/" << daily_StepGoal << endl;
        cout << "Calories Burned: " << (int)calories_burned << " kcal\n";
        cout << (steps_taken >= daily_StepGoal ? "Goal Achieved!\n" : "Keep Going!\n");
    }
};
int main() {
    FitnessTrack laibaTrack("Laiba", 10000);
    laibaTrack.logSteps(5000);
    laibaTrack.displayProgress();
    return 0;
}
