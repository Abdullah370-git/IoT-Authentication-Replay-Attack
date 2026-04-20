Project: IoT Authentication System

This project demonstrates:
- Replay attack in IoT authentication
- Secure nonce-based defense

Modules:
- Device
- Server
- Attacker
- Encryption
- Logging

How to run:
g++ main.cpp device/device.cpp server/server.cpp attacker/attacker.cpp security/encryption.cpp security/nounce.cpp utils/logger.cpp network/packet.cpp -o iot_auth
.\iot_auth.exe
