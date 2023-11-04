#include <iostream>

using namespace std;

int main() {
    float mStart, hStart, mEnd, hEnd;
    float bill;

    cout << "Enter the start time (hour and minute): "; cin >> hStart >> mStart;
    cout << "Enter the end time (hour and minute): "; cin >> hEnd >> mEnd;

    float tStart = hStart * 60 + mStart;
    float tEnd = hEnd * 60 + mEnd;

    float firstMilestone = 7 * 60;
    float secondMilestone = 17 * 60;
    float thirdMilestone = 24 * 60;

    if (tStart > firstMilestone) {
        float first = (secondMilestone - tStart) * 100;
        float second = (tEnd - secondMilestone) * 75;
        float third = (tEnd - firstMilestone) * 50;

        if (secondMilestone - tStart > 6) second *= 0.9;
        if (tEnd - secondMilestone > 4) second *= 0.88;
        if (tEnd - firstMilestone > 2) third *= 0.85;

        if (tEnd < secondMilestone) {
            bill = (tEnd - tStart) * 100;
            if (tEnd - tStart > 6) bill *= 0.9;
        } else if (tEnd < thirdMilestone) {
            bill = first + second;
        } else {
            bill = first + (thirdMilestone - secondMilestone) * 75 * 0.88 + third;
        }
        
    } else if (tStart > secondMilestone) {
        float second = (thirdMilestone - tStart) * 75;
        float third = (tEnd - thirdMilestone) * 50;

        if (tEnd - secondMilestone > 4) second *= 0.88;
        if (tEnd - firstMilestone > 2) third *= 0.85;
        
        if (tEnd < thirdMilestone) {
            bill = (tEnd - tStart) * 75;
            if (tEnd - tStart > 4) bill *= 0.88;
        } else {
            bill = second + third;
        }
    } else {
        bill = (tEnd - tStart) * 50;
        if (tEnd - tStart > 2) bill *= 0.85;
    }

    cout << "The bill is " << bill << " VND" << endl;

    return 0;
}