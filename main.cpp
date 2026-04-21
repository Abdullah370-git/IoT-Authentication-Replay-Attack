#include <iostream>
#include <ctime>

#include "device/device.h"
#include "server/server.h"
#include "attacker/attacker.h"
#include "security/encryption.h"
#include "utils/logger.h"
# include "security/nounce.h"
using namespace std;

int main()
{
    srand(time(0));

    Logger log;

    log.log("===== IoT Authentication Security System =====");

    // ==============================
    // Setup Secret Key
    // ==============================
    Encryption enc;
    string secret = "12345";
    int key = enc.generateKey(secret);

    // ==============================
    // Initialize Components
    // ==============================
    Device device("device01", "pass123");
    Server server("device01", "pass123", key);
    Attacker attacker;

    // ==============================
    // PHASE 1: Vulnerable System   
    // ==============================
    log.log("\n===== PHASE 1: Vulnerable Authentication =====");

    Packet authPacket = device.createAuthPacket();
    authPacket.display();

    // Attacker captures packet
    attacker.capturePacket(authPacket);

    // Server verifies
    if (server.verifyPacket(authPacket))
    {
        log.log("[SERVER] Access Granted (Normal Login)");
    }
    else
    {
        log.log("[SERVER] Access Denied");
    }

    // ==============================
    // PHASE 2: Replay Attack
    // ==============================
    log.log("\n===== PHASE 2: Replay Attack =====");

    Packet replayedPacket = attacker.replayPacket();

    if (server.verifyPacket(replayedPacket))
    {
        log.log("[SERVER] Access Granted  (Replay Attack Successful)");
    }
    else
    {
        log.log("[SERVER] Access Denied");
    }

    // ==============================
    // PHASE 3: Secure Authentication
    // ==============================
    log.log("\n===== PHASE 3: Secure Authentication (Nonce-Based) =====");

    int nonce = server.generateNonce();
    cout << "[SERVER] Generated Nonce: " << nonce << endl;

    int response = device.generateResponse(nonce, key);
    cout << "[DEVICE] Encrypted Response: " << response << endl;

    attacker.captureResponse(response);

    if (server.verifyResponse(response, nonce))
    {
        log.log("[SERVER] Access Granted (Secure Authentication)");
    }
    else
    {
        log.log("[SERVER] Access Denied");
    }

    // ==============================
    // PHASE 4: Replay Attack on Secure System
    // ==============================
    log.log("\n===== PHASE 4: Replay Attack on Secure System =====");

    int newNonce = server.generateNonce();
    cout << "[SERVER] New Nonce: " << newNonce << endl;

    int replayedResponse = attacker.replayResponse();

    if (server.verifyResponse(replayedResponse, newNonce))
    {
        log.log("[SERVER] Access Granted  (Security Failed)");
    }
    else
    {
        log.log("[SERVER] Access Denied (Replay Attack Prevented)");
    }

    log.log("\n===== SYSTEM FINISHED SUCCESSFULLY =====");

    return 0;
}