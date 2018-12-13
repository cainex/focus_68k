#include "Decoder.hpp"

#include <iostream>

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
            if (uop & 0b0000000100000000)
            {
                if (uop & 0b0000000000001000) 
                {
                    std::cout << "MOVEP" << std::endl;
                }
                else 
                {
                    switch ((uop & 0b0000000011000000) >> 6) {
                        case 0b00 :
                            std::cout << "BTST" << std::endl;
                        break;
                        case 0b01 :
                            std::cout << "BCHG" << std::endl;
                        break;
                        case 0b10 : 
                            std::cout << "BSET" << std::endl;
                        break;
                        case 0b11 : 
                            std::cout << "BCLR" << std::endl;
                        break;
                    };
                }
            }
            else
            {

            }
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
