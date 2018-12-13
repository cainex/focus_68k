#pragma once

#include "Uops.hpp";

namespace Fm68000 {

class Decoder {
public:
Decoder();
~Decoder();

Uop::Pointer Decode(const uint16_t &uop);

};

};
