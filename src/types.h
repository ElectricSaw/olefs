//
// Created by sangwon on 2022-04-04.
//
#pragma once

#ifndef OLEFS_TYPES_H
#define OLEFS_TYPES_H

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

namespace OLEFS {
    typedef char        int8;
    typedef short       int16;
    typedef int         int32;
    typedef long long   int64;

    typedef unsigned char       uint8, byte;
    typedef unsigned short      uint16;
    typedef unsigned int        uint32;
    typedef unsigned long long  uint64;

    typedef std::vector<byte> ByteStream;
}

#endif //OLEFS_TYPES_H
