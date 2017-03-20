#ifndef __intrinsics_h__
#define __intrinsics_h__
#include <stdlib.h>
/*
Intrinsics recognized by lcc-win32
*/
#pragma pack(push,1)
typedef unsigned char _bcdDigit[10];

double _fsincos(double,double *);
double	_fbld(_bcdDigit *d);
void _fbstp(_bcdDigit *d,double v);
void _itobcd(_bcdDigit *d,int i);
long _bswap(long);
long _fistp(double);
double _fabs(double);
double _fldpi(void);
double _fldl2e(void);
double _fldlg2(void);
double _fldln2(void);
div_t _div(int,int);
int _GetStatusWord(void);
int _examine(double);
int _signbit(double);
int _carry(void);
int _bsf(unsigned int);
int _bsr(unsigned int);
long long _rdtsc(void);
int _overflow(void);
void * _GetStackPointer(void);
typedef struct _cpuIdentification {
	char Vendor[16];
	unsigned Stepping:4;
	unsigned Model:4;
	unsigned Family:4;
/*
Encoding in the type field:
Original OEM Processor:     00B
Intel OverDrive  Processor: 01B
Dual processor:             10B
Intel reserved.             11B
*/
	unsigned Type:2;
	unsigned Reserved1:18;
/*
Bit 0:
Processor contains an FPU and executes the Intel 387
instruction set.
*/
	unsigned FpuPresent:1;
/*
Bit 1:
VME: Virtual-8086 Mode Enhancements
Processor supports the following virtual-8086 mode
enhancements:
 CR4.VME bit enables virtual-8086 mode extensions.
 CR4.PVI bit enables protected-mode virtual interrupts.
 Expansion of the TSS with the software indirection bitmap.
 EFLAGS.VIF bit (virtual interrupt flag).
 EFLAGS.VIP bit (virtual interrupt pending flag).
*/
	unsigned VME:1;
/*
Bit 2:
DE: Debugging Extensions
Processor supports I/O breakpoints, including the CR4.DE bit
for enabling debug extensions and optional trapping of access
to the DR4 and DR5 registers.
*/
	unsigned DebuggingExtensions:1;
/*
Bit 3:
PSE: Page Size Extensions
Processor supports 4-Mbyte pages, including the CR4.PSE bit
for enabling page size extensions, the modified bit in page
directory entries (PDEs), page directory entries, and page table
entries (PTEs).
*/
	unsigned PageSizeExtensions:1;
/*
Bit 4:
TSC: Time Stamp Counter
Processor supports the RDTSC (read time stamp counter)
instruction, including the CR4.TSD bit that, along with the CPL,
controls whether the time stamp counter can be read.
*/
	unsigned TimeStampCounter:1;
/*
Bit 5:
MSR: Model Specific Registers
Processor supports the RDMSR (read model-specific register)
and WRMSR (write model-specific register) instructions.
*/
	unsigned MSR:1;
/*
Bit 6:
PAE: Physical Address Extension
Processor supports physical addresses greater than 32 bits, the
extended page-table-entry format, an extra level in the page
translation tables, and 2-MByte pages. The CR4.PAE bit enables
this feature. The number of address bits is implementation specific.
The Pentium  Pro processor supports 36 bits of addressing when
the PAE bit is set.
*/
	unsigned PhysicalAddressExtensions:1;
/*
Bit 7:
MCE: Machine Check Exception
Processor supports the CR4.MCE bit, enabling machine check
exceptions. However, this feature does not define the model-specific
implementations of machine-check error logging, reporting,
or processor shutdowns. Machine-check exception handlers might
have to check the processor version to do model-specific
processing of the exception or check for the presence of the
standard machine-check feature.
*/
	unsigned MachineCheckException:1;
/*
Bit 8:
CX8: CMPXCHG8B Instruction
Processor supports the CMPXCHG8B (compare and exchange 8
bytes) instruction.
*/
	unsigned CMPXCHG8B:1;
/*
Bit 9:
APIC Processor contains an on-chip Advanced Programmable Interrupt
Controller (APIC) and it has been enabled and is available for use.
*/
	unsigned APICOnChip:1;

/*
Bit 10:
Reserved
*/
	unsigned reserved2:1;
/*
Bit 11:
SEPFast System Call Indicates whether the processor supports the
Fast System Call instructions, SYSENTER and SYSEXIT. */
	unsigned SEP:1;
/*
Bit 12:
MTRR: Memory Type Range Registers
Processor supports machine-specific memory-type range registers
(MTRRs). The MTRRs contains bit fields that indicate the
processors MTRR capabilities, including which memory types the
processor supports, the number of variable MTRRs the processor
supports, and whether the processor supports fixed MTRRs.
*/
	unsigned MTRR:1;
/*
Bit 13:
PGEPTE Global Flag Processor supports the CR4.PGE flag enabling the global bit in
both PTDEs and PTEs. These bits are used to indicate translation
lookaside buffer (TLB) entries that are common to different tasks
and need not be flushed when control register CR3 is written.
*/
	unsigned PGE:1;
/*
Bit 14:
MCAMachine Check
Architecture
Processor supports the MCG_CAP (machine check global
capability) MSR. The MCG_CAP register indicates how many
banks of error reporting MSRs the processor supports.
*/
	unsigned MCA:1;
/*
Bit 15:
CMOV: Conditional Move and Compare Instructions
Processor supports the CMOV cc instruction and, if the FPU feature
flag (bit 0) is also set, supports the FCMOV cc and FCOMI
instructions.
*/
	unsigned CMOV:1;
/*
Bit 16:
Processor supports CMOVcc, and if the FPU feature flag (bit 0) is also
set, supports the FMOVCC and FCOMI instructions.
*/
	unsigned FGPAT:1;
/*
Bit 17:
Processor supports 4MB pages with 36 bit physical addresses.
*/
	unsigned PSE36:1;
/*
Bit 18:
Processor number (processor ID number) supported and active
*/
	unsigned PN:1;
/*
Bit 19-22 Reserved
*/
	unsigned reserved3:4;
/*
Bit 23:
MMX Technology Processor supports the MMX instruction set. These instructions
operate in parallel on multiple data elements (8 bytes, 4 words, or 2
doublewords) packed into quadword registers or memory locations.
*/
	unsigned MMX:1;
/*
Bit 24:
FXSRFast FP/MMX Technology/Streaming SIMD Extensions save/restore
Indicates whether the processor supports the FXSAVE and FXRSTOR
instructions for fast save and restore of the floating point context.
Presence of this bit also indicates that CR4.OSFXSR is available for an
operating system to indicate that it uses the fast save/restore
instructions.
*/
	unsigned FXSR:1;
/*
Bit 25:
XMMStreaming SIMD Extensions Processor supports the Streaming SIMD Extensions
instruction set.
*/
	unsigned XMM:1;
/*
Bit 26: SSE2 Instruction set
*/
	unsigned SSE2:1;
/* Bit 27: Self Snoop (accepts different memory speeds) */
	unsigned SelfSnoop:1;
/* Bit 28: Reserved */
	unsigned reserved4:1;
/* Bit 29: Thermal monitor */
	unsigned ThermalMonitor:1;
/*
Bits 30-31:
Reserved
*/
	unsigned reserved5:2;

} _CPUID;
#pragma pack(pop)
/* _cpuid returns an 64 bit bit field containing processor features */
long long _cpuid(_CPUID *);
/* returns 1 if cpuid instruction supported, zero otherwise */
int _cpuidPresent(void);
#endif
