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
        if (tEnd < secondMilestone) {
            bill = (tEnd - tStart) * 4000;
        } else if(tEnd < thirdMilestone) {
            bill = (secondMilestone - tStart) * 4000 + (tEnd - secondMilestone) * 3500;
        } else {
            bill = (secondMilestone - tStart) * 4000 + (thirdMilestone - secondMilestone) * 3500 + (tEnd - thirdMilestone) * 3000;
        }
    } else if (tStart > secondMilestone) {
        if (tEnd < thirdMilestone) {
            bill = (tEnd - tStart) * 3500;
        } else {
            bill = (thirdMilestone - tStart) * 3500 + (tEnd - thirdMilestone) * 3000;
        }
    } else {
        bill = (tEnd - tStart) * 3000;
    }

    cout << "The bill is " << bill << " VND" << endl;

    return 0;

}