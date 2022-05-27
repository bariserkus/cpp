#ifndef BITMAPFILEHEADER_H_INCLUDED
#define BITMAPFILEHEADER_H_INCLUDED

#include <cstdint>

using namespace std;

#pragma pack(push, 2)

namespace cop
{
struct BitmapFileHeader
{
    char header[2]{'B', 'M'};
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;

};
}
#pragma pack(pop)

#endif // BITMAPFILEHEADER_H_INCLUDED
