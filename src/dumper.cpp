//
// Created by sangwon on 2022-04-04.
//

#include "dumper.h"
#include <sstream>
#include <iomanip>

namespace OLEFS {

    dumper::dumper() = default;

    dumper::~dumper() = default;

    std::string dumper::byteToString(byte b) {
        std::stringstream ss;
        ss << std::hex << std::uppercase << std::setfill('0');

        ss << std::setw(2) << (int)b;

        return ss.str();
    }

    std::string dumper::integerBlockOfLength(const int32 i) {
        std::stringstream ss;
        ss << std::hex << std::uppercase << std::setfill('0');

        ss << std::setw(8) << i;

        return ss.str();
    }

    std::string dumper::shortToString(const int16 i) {
        std::stringstream ss;
        ss << std::hex << std::uppercase << std::setfill('0');

        ss << std::setw(4) << (short)i;

        return ss.str();
    }

    std::string dumper::dump(const ByteStream* bytes) {
        return dump(bytes->data(), bytes->size());
    }

    std::string dumper::dump(const ByteStream& bytes) {
        return dump(bytes.data(), bytes.size());
    }

    std::string dumper::dump(const byte* bytes, const uint32 size) {
        std::stringstream ss;
        ss << std::hex << std::uppercase << std::setfill('0');

        //ss << "             Offset: 00 01 02 03  04 05 06 07  08 09 0A 0B  0C 0D 0E 0F" << endl;
        //ss << "-----------------------------------------------------------------------" << endl;
        ss << "     Offset: 00 01 02 03  04 05 06 07  08 09 0A 0B  0C 0D 0E 0F" << std::endl;
        ss << "---------------------------------------------------------------" << std::endl;

        for (size_t i = 0; i < size; i++) {
            if (i % 4 == 0) ss << " ";
            if (i % 16 == 0)
                ss << "0x" << std::setw(8) << (int)i << ": ";
            // ss << "0x" << addressof(bytes) + i << ": ";
            ss << std::setw(2) << (int)bytes[i] << " ";
            if (i % 16 == 15) ss << std::endl;
        }

        return ss.str();
    }

    std::string dumper::bytesBlockOfLength(const byte* bytes, uint32 len) {
        std::stringstream ss;
        ss << std::hex << std::uppercase << std::setfill('0');
        size_t i;

        for (i = 0; i < len; i++) {
            ss << std::setw(2) << (int)bytes[i];
            if (i % 4 == 3 && i < len - 1) ss << " ";
        }

        return ss.str();
    }

    std::string dumper::bytesBlockOfLength(const ByteStream* bytes, uint32 len) {
        return bytesBlockOfLength(bytes->data(), len);
    }

    std::string dumper::bytesBlockOfLength(const ByteStream& bytes, uint32 len) {
        return bytesBlockOfLength(bytes.data(), len);
    }

    std::string dumper::bytesBlock(const byte* bytes, const uint32 i) {
        return bytesBlockOfLength(bytes, i);
    }

    std::string dumper::bytesBlock(const ByteStream* bytes) {
        return bytesBlockOfLength(bytes->data(), bytes->size());
    }

    std::string dumper::bytesBlock(const ByteStream& bytes) {
        return bytesBlockOfLength(bytes.data(), bytes.size());
    }
}