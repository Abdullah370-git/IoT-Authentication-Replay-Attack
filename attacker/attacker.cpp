#include <iostream>
#include <fstream>
#include "attacker.h"
using namespace std;

void Attacker::capturePacket(Packet p)
{
    capturedPacket = p;

    cout << "[ATTACKER] Packet Captured!" << endl;

    ofstream file("data/packets.txt", ios::app);
    if (file.is_open())
    {
        file << p.sender << " " << p.receiver << " " << p.data << endl;
        file.close();
    }
}

Packet Attacker::replayPacket()
{
    cout << "[ATTACKER] Replaying Captured Packet..." << endl;
    return capturedPacket;
}

void Attacker::captureResponse(int response)
{
    capturedResponse = response;
    cout << "[ATTACKER] Response Captured!" << endl;
}

int Attacker::replayResponse()
{
    cout << "[ATTACKER] Replaying Old Response..." << endl;
    return capturedResponse;
}