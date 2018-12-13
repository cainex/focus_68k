#include "Fm68000.hpp"

namespace Fm68000 {

void CPU::Fetch()
{
    m_dataBus->Read(m_registerFile->PC, m_registerFile->instr);
    m_registerFile->PC += 2;
}

void CPU::Decode()
{

}

void CPU::Execute()
{

}

};
