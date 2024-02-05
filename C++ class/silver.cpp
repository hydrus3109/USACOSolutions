
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int simulateCommands(const string& commands, const unordered_set<int>& targets, int changeIdx = -1, char newCommand = ' ') {
    int position = 0, targetsHit = 0;
    for (int i = 0; i < commands.size(); ++i) {
        char command = (i == changeIdx) ? newCommand : commands[i];

        if (command == 'L') {
            position--;
        } else if (command == 'R') {
            position++;
        } else if (command == 'F' && targets.find(position) != targets.end()) {
            targetsHit++;
        }
    }
    return targetsHit;
}

int main() {
    int T, C;
    cin >> T >> C;

    unordered_set<int> targets;
    for (int i = 0; i < T; i++) {
        int target;
        cin >> target;
        targets.insert(target);
    }

    string commands;
    cin >> commands;

    int maxTargets = simulateCommands(commands, targets);

    for (int i = 0; i < C; ++i) {
        if (commands[i] == 'L' || commands[i] == 'R') {
            maxTargets = max(maxTargets, simulateCommands(commands, targets, i, 'F'));
        } else {
            maxTargets = max(maxTargets, simulateCommands(commands, targets, i, 'L'));
            maxTargets = max(maxTargets, simulateCommands(commands, targets, i, 'R'));
        }
    }

    cout << maxTargets << endl;
    return 0;
}
