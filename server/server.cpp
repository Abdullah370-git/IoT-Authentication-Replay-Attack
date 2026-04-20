#include "server.h"
#include <iostream>
#include <sstream>

using namespace std;

Server::Server(string id, string pass, int k)
{
    storedID = id;
    storedPassword = pass;
    key = k;
}

bool Server::verifyPacket(Packet p)
{
    string expected = storedID + ":" + storedPassword;
    return p.data == expected;
}

int Server::generateNonce()
{
    Nonce n;
    return n.generate();
}

bool Server::verifyResponse(int response, int nonce)
{
    Encryption enc;
    int decrypted = enc.decrypt(response, key);
    return decrypted == nonce;
}