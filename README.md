A simple tool for encrypting files **in place** by performing an XOR operation on the first 256 bytes of the file header, achieving the effect of preventing file recognition.

## Usage
```bash
## Encrypt
./cryptor <key> <file>

## Re-execute the encryption command to decrypt
./cryptor <key> <file>
```

## Build
```bash
clang++ -std=c++17 -O2 -g3 -static-libstdc++ -static-libgcc main.cpp -o cryptor
```