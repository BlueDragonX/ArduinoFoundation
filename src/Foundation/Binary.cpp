#include "Binary.h"

#include <Arduino.h>

bool getBit(const byte* b, uint8_t offset, uint8_t bit) {
    return ((b[offset] >> bit) & 1) == 1;
}

bool setBit(byte* b, uint8_t offset, uint8_t bit, bool value) {
    if (getBit(b, offset, bit) == value) {
        return false;
    }
    if (value) {
        b[offset] |= (1 << bit);
    } else {
        b[offset] &= ~(1 << bit);
    }
    return true;
}

bool xorBits(const byte* b1, const byte* b2, uint8_t offset, uint8_t bit) {
    return (b1[offset] >> bit & 1) != (b2[offset] >> bit & 1);
}

bool flipBit(byte* b, uint8_t offset, uint8_t bit) {
    return b[offset] ^= (1 << bit);
}
