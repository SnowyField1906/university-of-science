#include "Schedule.h"

Schedule::Schedule()
{
    schedule = new bool *[5];
    for (int i = 0; i < 5; i++)
    {
        schedule[i] = new bool[8];
        for (int j = 0; j < 8; j++)
        {
            schedule[i][j] = false;
        }
    }
}

Schedule::~Schedule()
{
    for (int i = 0; i < 5; i++)
    {
        delete[] schedule[i];
    }
    delete[] schedule;
}

bool **Schedule::getSchedule()
{
    return schedule;
}

bool Schedule::isAvailable(int day, int slot)
{
    return !schedule[day][slot];
}

void Schedule::reserve(int day, int slot)
{
    schedule[day][slot] = true;
}

void Schedule::cancel(int day, int slot)
{
    schedule[day][slot] = false;
}
