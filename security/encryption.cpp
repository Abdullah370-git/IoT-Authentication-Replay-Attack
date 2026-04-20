#include "encryption.h"

int Encryption::generateKey(string key)
{
    int sum = 0;
    for (int i = 0; i < key.length(); i++)
    {
        sum += key[i];
    }
    return sum;
}

int Encryption::encrypt(int data, int key)
{
    return data ^ key;
}

int Encryption::decrypt(int data, int key)
{
    return data ^ key;
}