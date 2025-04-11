#include <stdexcept>
#include <string>
#include <string_view>

#include <cstdint>
#include <cstdlib>

#include "../config.h"
#include "../lib.h"
#include "../arch/arch.h"
#include "os.h"
#include "os-lib.h"


namespace OS {
// --------------------------------------
//métodos para processo

// ---------------------------------------

Arch::Cpu *cpuTeste;

void boot (Arch::Cpu *cpu)
{
	terminal_println(cpu, Arch::Terminal::Type::Command, "Type commands here");
	terminal_println(cpu, Arch::Terminal::Type::App, "Apps output here");
	terminal_println(cpu, Arch::Terminal::Type::Kernel, "Kernel output here");
	cpuTeste=cpu;
}

// ---------------------------------------

void interrupt (const Arch::InterruptCode interrupt)
{	

	// terminal_println(cpuTeste, Arch::Terminal::Type::Kernel, var);
	Arch::Cpu ab = cpuTeste->read_io(interrupt)
	
	if (interrupt == InterruptCode::Keyboard)
	{
		uint16_t var = cpuTeste->read_io(IO_Port::TerminalReadTypedChar);
	}
	if(interrupt == Arch::InterruptCode::CpuException){
		const Arch::Cpu::CpuException& exception = cpuTeste->get_ref_cpu_exception();
		switch (exception.type)
		{
		case Arch::Cpu::CpuException::Type::VmemGPFnotReadable:
			terminal_println(cpuTeste, Arch::Terminal::Type::Kernel, "GPF: memória não legível.");
			break;

		case Arch::Cpu::CpuException::Type::VmemGPFnotWritable:
			terminal_println(cpuTeste, Arch::Terminal::Type::Kernel, "GPF: memória não gravável.");
			break;

		case Arch::Cpu::CpuException::Type::VmemGPFnotExecutable:
			terminal_println(cpuTeste, Arch::Terminal::Type::Kernel, "GPF: memória não executável.");
			break;

		case Arch::Cpu::CpuException::Type::GPFinvalidInstruction:
			terminal_println(cpuTeste, Arch::Terminal::Type::Kernel, "GPF: instrução inválida.");
			break;

		case Arch::Cpu::CpuException::Type::VmemPageFault:
			terminal_println(cpuTeste, Arch::Terminal::Type::Kernel, "Exceção: Page Fault.");
			break;

		default:
			terminal_println(cpuTeste, Arch::Terminal::Type::Kernel, "Exceção desconhecida.");
			break;
		}
	}
	
}

// ---------------------------------------

void syscall ()
{

}

// ---------------------------------------

} // end namespace OS
