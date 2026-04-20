#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include "../network/packet.h"
#include "../security/encryption.h"

using namespace std;

class Device
{
public:
    string deviceID;
    string password;

    Device(string id, string pass);

    Packet createAuthPacket();
    int generateResponse(int nonce, int key);
};

#endif