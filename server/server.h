#ifndef SERVER_H
#define SERVER_H

#include <string>
#include "../network/packet.h"
#include "../security/encryption.h"
#include "../security/nounce.h"

using namespace std;

class Server
{
public:
    string storedID;
    string storedPassword;
    int key;

    Server(string id, string pass, int k);

    bool verifyPacket(Packet p);
    int generateNonce();
    bool verifyResponse(int response, int nonce);
};

#endif