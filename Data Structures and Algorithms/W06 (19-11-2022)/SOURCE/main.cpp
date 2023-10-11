#include <iostream>
#include <algorithm>
#include <vector>
#include "DataGenerator.cpp"
using namespace std;

vector<string> Mode { "-a", "-c" };

vector<string> Name { "selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "shell-sort", "heap-sort", "merge-sort", "quick-sort", "counting-sort", "radix-sort", "flash-sort" };

vector<string> Input { "-rand", "-nsorted", "-sorted", "-rev" };

vector<string> Output { "-time", "-comp", "-both" };


vector<int> filter(vector<int> a, vector<int> b) {
    vector<int> result;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                result.push_back(a[i]);
            }
        }
    }
    return result;
}

vector<int> possibleCommand(char *argv[], int i, vector<int> cmds) {
    string a = argv[i];

    switch(i) {
        case 0:
            if (a == "-a")
                cmds = filter(cmds, {1, 2, 3});
            else if (a == "-c")
                cmds = filter(cmds, {4, 5});
            break;
        case 1:
            if (find(Name.begin(), Name.end(), a) != Name.end())
                cmds = filter(cmds, { 1, 2, 3, 4, 5 });
            break;
        case 2:
            if (a.find(".txt") != string::npos)
                cmds = filter(cmds, {1});
            else if (typeid(a).name() == "int")
                cmds = filter(cmds, {2, 3});
            else if (find(Name.begin(), Name.end(), a) != Name.end())
                cmds = filter(cmds, { 4, 5 });
            break;
        case 3:
            if (find(Output.begin(), Output.end(), a) != Output.end())
                cmds = filter(cmds, {1, 3});
            else if (find(Input.begin(), Input.end(), a) != Input.end())
                cmds = filter(cmds, {2});
            else if (a.find(".txt") != string::npos)
                cmds = filter(cmds, {4});
            else if (typeid(a).name() == "int")
                cmds = filter(cmds, {5});
            break;
        case 4:
            if (find(Output.begin(), Output.end(), a) != Output.end())
                cmds = filter(cmds, {2, 4});
            else if (find(Input.begin(), Input.end(), a) != Input.end())
                cmds = filter(cmds, {5});
            break;
        default:
            cout << "Error: unknown command!" << endl;
            exit(1);
    }

    return possibleCommand(argv, i + 1, cmds);
}

int detectCommand(int argc, char *argv[]) {
    vector<int> cmds = possibleCommand(argv, 0, vector<int> {1, 2, 3, 4, 5});
    if(cmds.size() == 1)
        return cmds[0];
    else {
        cout << "Error: unknown command!" << endl;
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    int command = detectCommand(argc, argv);

    cout << command << endl;

    return 0;
}