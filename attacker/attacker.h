#ifndef ATTACKER_H
#define ATTACKER_H

#include "../network/packet.h"

class Attacker
{
public:
    Packet capturedPacket;
    int capturedResponse;

    void capturePacket(Packet p);
    Packet replayPacket();

    void captureResponse(int response);
    int replayResponse();
};

#endif