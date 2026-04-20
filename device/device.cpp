#include <iostream>
#include "device.h"
using namespace std;

Device::Device(string id, string pass)
{
    deviceID = id;
    password = pass;
}

Packet Device::createAuthPacket()
{
    Packet p;
    string data = deviceID + ":" + password;

    p.create("Device", "Server", data, 0);

    return p;
}

int Device::generateResponse(int nonce, int key)
{
    Encryption enc;
    return enc.encrypt(nonce, key);
}