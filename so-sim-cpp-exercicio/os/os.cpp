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

// ---------------------------------------
Arch::Cpu *cpuTeste;

void boot (Arch::Cpu *cpu)
{
	terminal_println(cpu, Arch::Terminal::Type::Command, "Type commands here");
	terminal_println(cpu, Arch::Terminal::Type::App, "Apps output here");
	terminal_println(cpu, Arch::Terminal::Type::Kernel, "Kernel output here");
	
	cpuTeste = cpu;
}

// ---------------------------------------

void interrupt (const Arch::InterruptCode interrupt)
{
	// // cpuTeste->read_io(2);
	// Arch::Computer::get().get_terminal().write(0, typedChar);
	
	uint16_t interruptCode = static_cast<uint16_t>(interrupt);
	// uint16_t read = cpuTeste->read_io(2);
	// terminal_println(cpuTeste, Arch::Terminal::Type::Kernel, read);
	
	// cpuTeste->interrupt(interrupt);
	// int typedChar = Arch::Computer::get().get_terminal().read(2);
	// // cpuTeste->run_cycle();
	
	// int typedChar;
	
	if (interruptCode == 0) {
		char typedChar;
		// std::cin >> typeChar;
		// terminal_println(cpuTeste, Terminal::write(1, 2));
		typedChar = cpuTeste->read_io(2);
		cpuTeste->write_io(1, typedChar);
		char asciiToChar = static_cast<char>(typedChar);
		// terminal_print(cpuTeste, Arch::Terminal::Type::Command, typedChar);

		switch (typedChar) {
			case 10:
				terminal_println(cpuTeste, Arch::Terminal::Type::Command, "randandandan");
			
			case 8:
				terminal_println(cpuTeste, Arch::Terminal::Type::Command, "backspace");
		}

		

		// if (typedChar == 10) {
		// } else if (typedChar == 8) {

		// }
		// if (typedChar == 8) {
		// 	cpuTeste->read_io(2);
		// }

	}
	

	// terminal_print(cpuTeste, Arch::Terminal::Type::Kernel, typedChar);
}	

// ---------------------------------------

void syscall ()
{
	
}

// ---------------------------------------

} // end namespace OS
