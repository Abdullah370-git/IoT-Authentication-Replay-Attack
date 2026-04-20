#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
using namespace std;

class Encryption
{
public:
    int generateKey(string key);
    int encrypt(int data, int key);
    int decrypt(int data, int key);
};

#endif