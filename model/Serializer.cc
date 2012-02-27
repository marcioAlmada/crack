// copyright 2012 Google Inc.

#include "Serializer.h"

#include <stdint.h>
#include <ostream>

using namespace std;
using namespace model;

void Serializer::write(unsigned int val) {
    // special case 0
    if (!val) {
        dst << static_cast<char>(val);
        return;
    }

    while (val) {
        uint8_t b = val & 0x7f;
        val >>= 7;
        if (val)
            b |= 0x80;
        dst << b;
    }
}

void Serializer::write(size_t length, const void *data) {
    write(length);
    dst.write(reinterpret_cast<const char *>(data), length);
}

bool Serializer::writeObject(void *object) {
    ObjMap::iterator iter = objMap.find(object);
    if (iter == objMap.end()) {

        // new object
        int id = lastId++;
        objMap[object] = id;
        write(id << 1 | 1);
        return true;
    } else {
        write(iter->second << 1);
        return false;
    }
}