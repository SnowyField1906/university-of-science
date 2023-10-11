#include <iostream>
#include <fstream>
#include <sstream>

#define FILE_IN "input.txt"
#define FILE_OUT "output.txt"

using namespace std;

// class Time inclues hour and minute
class Time
{
private:
     int hour;
     int minute;

public:
     Time();
     Time(const Time &);
     Time(int, int);
     bool between(Time, Time);
};

// class Message includes id, signer and time
class Message
{
private:
     string id;
     string signer;
     Time time;

public:
     Message();
     Message(const Message &);
     Message(string, string, Time);
     Time getTime();
     string getSinger();
};

// class MessageList includes start and end time, messages and length of messages
class MessageList
{
private:
     Time start, end;
     Message messages[100];
     int length;

public:
     MessageList();
     void importMessages();
     void mostVotedSinger();
};

// Time's constructors
Time::Time()
{
     this->hour = 0;
     this->minute = 0;
}
Time::Time(const Time &time)
{
     this->hour = time.hour;
     this->minute = time.minute;
}
Time::Time(int hour, int minute)
{
     this->hour = hour;
     this->minute = minute;
}
// Time's methods
bool Time::between(Time start, Time end)
{
     bool upperStart = (this->hour > start.hour) || (this->hour == start.hour && this->minute >= start.minute);
     bool lowerEnd = (this->hour < end.hour) || (this->hour == end.hour && this->minute <= end.minute);
     return upperStart && lowerEnd;
}

// Message's constructors
Message::Message()
{
     this->id = "";
     this->signer = "";
     this->time = Time();
}
Message::Message(const Message &message)
{
     this->id = message.id;
     this->signer = message.signer;
     this->time = message.time;
}
Message::Message(string id, string signer, Time time)
{
     this->id = id;
     this->signer = signer;
     this->time = time;
}
// Message's methods
Time Message::getTime()
{
     return this->time;
}
string Message::getSinger()
{
     return this->signer;
}

// MessageList's constructors
MessageList::MessageList()
{
     this->start = Time(0, 0);
     this->end = Time(0, 0);
     this->length = 0;
}
// MessageList's methods
void MessageList::importMessages()
{
     ifstream fin(FILE_IN);

     // get start and end time hour:minute
     string start, end;
     fin >> start >> end;
     this->start = Time(stoi(start.substr(0, 2)), stoi(start.substr(3, 2)));
     this->end = Time(stoi(end.substr(0, 2)), stoi(end.substr(3, 2)));

     // get messages without number of messages
     string message;
     fin.ignore();
     while (getline(fin, message, '\n'))
     {
          string chunk[10];
          int chunkLength = 0;
          stringstream ss(message);

          while (getline(ss, chunk[chunkLength], ' '))
          {
               chunkLength++;
          }
          string id = chunk[0];
          string time = chunk[chunkLength - 1];
          string signer;
          int i = 1;
          while (i < chunkLength - 1)
          {
               signer += chunk[i] + " ";
               i++;
          }

          this->messages[this->length] = Message(id, signer, Time(stoi(time.substr(0, 2)), stoi(time.substr(3, 2))));
          this->length++;
     }

     fin.close();
}
void MessageList::mostVotedSinger()
{
     ofstream fout(FILE_OUT);

     // get most voted singer
     string mostVotedSigner;
     int mostVotedSingerCount = 1;
     for (int i = 0; i < this->length; i++)
     {
          for (int j = i + 1; j < this->length; j++)
          {
               if (this->messages[i].getTime().between(this->start, this->end))
               {
                    if (this->messages[i].getSinger() == this->messages[j].getSinger() && this->messages[j].getTime().between(this->start, this->end))
                    {
                         mostVotedSigner = this->messages[i].getSinger();
                         mostVotedSingerCount++;
                    }
               }
          }
     }

     fout << mostVotedSigner << mostVotedSingerCount << endl;
     fout.close();
}

int main()
{
     MessageList messageList;
     messageList.importMessages();
     messageList.mostVotedSinger();
     return 0;
}
