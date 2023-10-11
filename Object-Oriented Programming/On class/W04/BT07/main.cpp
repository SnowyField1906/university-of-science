#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

#define FILE_IN "input.txt"
#define FILE_OUT "output.txt"

using namespace std;

// class Point includes x and y
class Point
{
private:
    float x, y;

public:
    Point();
    Point(float, float);
    Point(const Point &);
    float distance();
};

// class Meteorite includes id, point, radius and speed
class Meteorite
{
private:
    string id;
    Point point;
    float radius, speed;

public:
    Meteorite();
    Meteorite(string, Point, float, float);
    Meteorite(const Meteorite &);
    string getId();
    float getRadius();
    float getSpeed();
    Point getPoint();
};

// class MeteoriteList includes meteorites and length of meteorites
class MeteoriteList
{
private:
    Meteorite meteorites[100];
    int length;

public:
    MeteoriteList();
    void importMeteorites();
    void mostDangerousMeteorite();
};

// Point's constructors
Point::Point()
{
    this->x = 0;
    this->y = 0;
}
Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;
}
Point::Point(const Point &point)
{
    this->x = point.x;
    this->y = point.y;
}

// Point's methods
float Point::distance()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

// Meteorite's constructors
Meteorite::Meteorite()
{
    this->id = "";
    this->point = Point();
    this->radius = 0;
    this->speed = 0;
}
Meteorite::Meteorite(string id, Point point, float radius, float speed)
{
    this->id = id;
    this->point = point;
    this->radius = radius;
    this->speed = speed;
}
Meteorite::Meteorite(const Meteorite &meteorite)
{
    this->id = meteorite.id;
    this->point = meteorite.point;
    this->radius = meteorite.radius;
    this->speed = meteorite.speed;
}

// Meteorite's methods
string Meteorite::getId()
{
    return this->id;
}
float Meteorite::getRadius()
{
    return this->radius;
}
float Meteorite::getSpeed()
{
    return this->speed;
}
Point Meteorite::getPoint()
{
    return this->point;
}

// MeteoriteList's constructors
MeteoriteList::MeteoriteList()
{
    this->length = 0;
}

// MeteoriteList's methods
void MeteoriteList::importMeteorites()
{
    ifstream fin(FILE_IN);
    string meteorite;
    while (getline(fin, meteorite))
    {
        string id;
        string x, y, radius, speed;
        stringstream ss(meteorite);
        getline(ss, id, '(');
        getline(ss, x, ',');
        getline(ss, y, ')');
        ss >> radius >> speed;
        this->meteorites[this->length] = Meteorite(id, Point(atof(x.c_str()), atof(y.c_str())), atof(radius.c_str()), atof(speed.c_str()));
        this->length++;
    }
    fin.close();
}
void MeteoriteList::mostDangerousMeteorite()
{
    ofstream fout(FILE_OUT);

    string id;
    float time = 10000; // maximum time

    for (int i = 0; i < this->length; i++)
    {
        float radius = this->meteorites[i].getRadius();
        float distance = this->meteorites[i].getPoint().distance() - radius;
        float speed = this->meteorites[i].getSpeed();
        if (distance / speed <= time)
        {
            time = distance / speed;
            id = this->meteorites[i].getId();
        }
    }

    fout << id << time;
    fout.close();
}

int main()
{
    MeteoriteList meteoriteList;
    meteoriteList.importMeteorites();
    meteoriteList.mostDangerousMeteorite();
    return 0;
}
