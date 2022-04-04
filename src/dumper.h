//
// Created by sangwon on 2022-04-04.
//

#ifndef OLEFS_DUMPER_H
#define OLEFS_DUMPER_H

#include "types.h"

namespace OLEFS {
    class dumper {
    public:
        dumper();
        ~dumper();
        static std::string byteToString(byte b);
        static std::string integerBlockOfLength(const int32 i);
        static std::string shortToString(const int16 i);
        static std::string dump(const ByteStream* bytes);
        static std::string dump(const ByteStream& bytes);
        static std::string dump(const byte* bytes, uint32 size);
        static std::string bytesBlockOfLength(const byte* bytes, uint32 len);
        static std::string bytesBlockOfLength(const ByteStream* bytes, uint32 len);
        static std::string bytesBlockOfLength(const ByteStream& bytes, uint32 len);
        static std::string bytesBlock(const byte* bytes, const uint32 size);
        static std::string bytesBlock(const ByteStream* bytes);
        static std::string bytesBlock(const ByteStream& bytes);
    };
}

#endif //OLEFS_DUMPER_H
