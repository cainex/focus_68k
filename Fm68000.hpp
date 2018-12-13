#pragma once

#include <cstdint>
#include <memory>

namespace Fm68000 {
    class RegisterFile {
        public:
        typedef std::shared_ptr<RegisterFile> Pointer;

        RegisterFile() {}
        ~RegisterFile() {}

        uint32_t A[8];
        uint32_t D[8];
        uint32_t PC;
        uint32_t SR;
        uint16_t instr;
    };

    class DataBus {
        public:
        typedef std::shared_ptr<DataBus> Pointer;

        DataBus() {}
        ~DataBus() {}

        virtual void Read(const uint32_t &address, uint8_t &value) = 0;
        virtual void Read(const uint32_t &address, uint16_t &value) = 0;
        virtual void Read(const uint32_t &address, uint32_t &value) = 0;

        virtual void Write(const uint32_t &address, const uint8_t &value) = 0;
        virtual void Write(const uint32_t &address, const uint16_t &value) = 0;
        virtual void Write(const uint32_t &address, const uint32_t &value) = 0;

    };

    class CPU {
        public:
        CPU() = delete;
        CPU(const DataBus::Pointer &dataBus, const RegisterFile::Pointer &registerFile) : 
            m_dataBus(dataBus), m_registerFile(registerFile) {}
        ~CPU() {}

        virtual uint32_t Run(const uint32_t &numInstructions) 
        {

        }

        virtual void Fetch();
        virtual void Decode();
        virtual void Execute();

        protected:
        DataBus::Pointer m_dataBus;
        RegisterFile::Pointer m_registerFile;
    };

};

