#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <iostream>

namespace Fm68000 {

class Uop {
public:
    typedef std::shared_ptr<Uop> Pointer;

    Uop() = delete;
    Uop(const std::string &name, const uint16_t &encoding, const uint16_t &mask) :
        m_name(name), m_encoding(encoding), m_mask(mask) {}
    ~Uop() {}

    void Display()
    {
    }

    uint16_t m_encoding;
    uint16_t m_mask;
    std::string m_name;

};

std::ostream& operator<<(std::ostream& os, const Uop& obj)
{
    // write obj to stream
    os << obj.m_name << " " << "[" << obj.m_encoding << ":" << obj.m_mask << "]" << std::endl;

    return os;
}

bool operator==(const Uop& lhs, const uint16_t& rhs)
{
    if ( (rhs & lhs.m_mask) == lhs.m_encoding ) 
        return true;
    else
        return false;
}

class ABCD : public Uop {
public:
    ABCD() : Uop("ABCD", 0b1100000100000000, 0b1111000111110000) {}
    ~ABCD() {}

};

class ADD : public Uop {
public:
    ADD() : Uop("ADD", 0b1100000100000000, 0b1111000111110000) {}
    ~ADD() {}

};

class ADDA : public Uop {
public:
    ADDA() : Uop("ADDA", 0b1100000100000000, 0b1111000111110000) {}
    ~ADDA() {}

};

class ADDI : public Uop {
public:
    ADDI() : Uop("ADDI", 0b1100000100000000, 0b1111000111110000) {}
    ~ADDI() {}

};

class ADDQ : public Uop {
public:
    ADDQ() : Uop("ADDQ", 0b1100000100000000, 0b1111000111110000) {}
    ~ADDQ() {}

};


};