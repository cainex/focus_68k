#include "Decoder.hpp"

namespace Fm68000 {

Decoder::Decoder()
{

}

Decoder::~Decoder()
{

}

Uop::Pointer Decoder::Decode(const uint16_t &uop)
{
    switch ( (uop & 0b1111000000000000) >> 12 )
    {
        case 0b0000:
            break;
        case 0b0001: 
        case 0b0010:
        case 0b0011:
            break;
        case 0b0100:
            break;
        case 0b0101:
            break;
        case 0b0110:
            break;
    }
}

};
