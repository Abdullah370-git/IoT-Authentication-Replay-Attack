#ifndef PACKET_H
#define PACKET_H

#include <string>
using namespace std;

class Packet
{
public:
    string sender;
    string receiver;
    string data;
    int encryptedData;

    void create(string s, string r, string d, int enc);
    void display();
};

#endif