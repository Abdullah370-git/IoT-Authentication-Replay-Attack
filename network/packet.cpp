#include <iostream>
#include "packet.h"
using namespace std;

void Packet::create(string s, string r, string d, int enc)
{
    sender = s;
    receiver = r;
    data = d;
    encryptedData = enc;
}

void Packet::display()
{
    cout << "[PACKET] From: " << sender << " To: " << receiver << endl;
    cout << "[PACKET] Data: " << data << endl;
    cout << "[PACKET] Encrypted: " << encryptedData << endl;
}