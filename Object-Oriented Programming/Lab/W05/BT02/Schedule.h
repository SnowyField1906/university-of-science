#ifndef SCHEDULE_H
#define SCHEDULE_H

class Schedule
{
private:
    bool **schedule;

public:
    Schedule();
    ~Schedule();

    bool **getSchedule();
    bool isAvailable(int day, int slot);
    void reserve(int day, int slot);
    void cancel(int day, int slot);
};

#endif
