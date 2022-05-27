#ifndef BITMAPINFOHEADER_H_INCLUDED
#define BITMAPINFOHEADER_H_INCLUDED

#include <cstdint>

using namespace std;

#pragma pack(push, 2)

namespace cop
{
struct BitmapInfoHeader {
	int32_t headerSize{40}; // Total number of header bytes.
	                         //4byte x 9 (int32) + 2byte x 2 (int16) = 40 bytes
	int32_t width;
	int32_t height;
	int16_t planes{1};
	int16_t bitsPerPixel{24}; // RGB 3x(8bits) = 24 bits, 8bits = 1 byte
	int32_t compression{0};
	int32_t dataSize{0};
	int32_t horizontalResolution{2400};
	int32_t verticalResolution{2400};
	int32_t colors{0};
	int32_t importantColors{0};
};
}
#pragma pack(pop)

#endif // BITMAPINFOHEADER_H_INCLUDED
