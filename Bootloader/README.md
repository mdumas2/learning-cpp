# Bootloader

https://interrupt.memfault.com/tag/zero-to-main/

https://interrupt.memfault.com/blog/fix-bugs-and-secure-firmware-with-the-mpu

https://interrupt.memfault.com/blog/cortex-m-rtos-context-switching

https://embeddedartistry.com/blog/2019/04/08/a-general-overview-of-what-happens-before-main/

https://interrupt.memfault.com/blog/zero-to-main-1

https://www.youtube.com/watch?v=MhOba73z-dQ

https://github.com/artfulbytes/how_a_microcontroller_starts_video/tree/main

https://github.com/ataradov/mcu-starter-projects/tree/master

The Bootloader (startup) is the code that executes before the main function

And before the Bootloader some configuration already had happen like:
    - Power voltage is estabalized
    - Clock Signals are already sincronized
    - Peripherals and Registers had already bean reset to their reset default state

1° Most CPUs satart executing at a fixed address
    PC register <- Address of first instruction
    On ARM: PC register <- Second value of IVT (Interrupt Vector table)
    ldr   sp, =_estack 

2° SP register <- First value of IVT

Obs: The IVT is place on the begining of the flash memory and can be check on the Linker script



Setup Boot Configuration

Initialize C runtime enviroment C Runtime init (CRT0)
    Copy the data segment initializers from flash to SRAM
    Initialize Variables stored in ram 
    .bss variaveis globais e staticas inicializadas com 0 ou não inicializadas
    .data data section global and static variables

call systeminit
    hardware initialization, clock peripherals 
    before main program 

call __libc_init_array
    call constructors
    in c -> __attribute((constructor))

call main

set the interrupt vector table

basically
0 power reset
1 hardware init(load pc and sp)
(system init)
c runtime init(crt0)
    init data variables
    clear bss variables
__lib_init_array
main

for default the gcc linker link the standard systemcall libs
so we have to provide our own implementation of those libs

standard library and runtime library code (crt*.o)

0x8000 << stm32 FLASH

arm gcc default link behaviour
newlib (standard c library)
    system calls (e.g, _exit, _write, _fork, ...)
startfiles/c runtime library (crt.o)
default linker script

-nolibc option on gcc
-nostartfiles option on gcc
-T pass linker script

SP register <- First value of IVT
PC register <- Second value of IVT

example

extern int main(void);
extern void __libc_init_array(void);

extern unsigned int _stack;
extern unsigned int _idata;
extern unsigned int _data;
extern unsigned int _edata;
extern unsigned int _bss;
extern unsigned int _ebss;

static void copy_data(void)
{
    unsigned int *src_data_ptr = &_idata;
    unsigned int *dst_data_ptr = &_data;
    while (dst_data_ptr < &_edata) {
        *dst_data_ptr++ = *src_data_ptr++;
    }
}

static void clear_bss(void)
{
    unsigned int *bss_ptr = &_bss;
    while (bss_ptr < &_ebss) {
        *bss_ptr++ = 0;
    }
}

void _init(void) {}

void isr_reset(void) {
    // You may implement system_init to perform additional early hardware
    // initialization depending on system requirements. This may include
    // configuring clocks, setting up memory or other peripherals, working
    // around hardware errata, and so on.
    // system_init();

    copy_data();
    clear_bss();
    __libc_init_array();
    main();

    // For a more feature-rich C runtime, you may link with the C runtime files
    // files (crt0.o, crti.o...) from Newlib. To do so, remove "-nostartfiles"
    // and replace __libc_init_array() and main() with a call to _start().
    // The runtime files from Newlib includes semi-hosting, profiling,
    // transactional memory, function hooks, and so on. Note, this will likely
    // require som additions in the linker script as well.
    // _start();
    //newlib/crt0.s

    while(1)
}

void isr_hardfault(void) {
    while(1)
}

 
#define IVT_ARRAY_SIZE (48U) // define on datasheet
typedef void (*isr_t)(void);
__attribute((used, section(".ivt")))
static const isr_t ivt[IVT_ARRAY_SIZE] = 
{
    (isr_t)&_stack,
    isr_reset,
    0, //isr_nmi
    isr_hardfault,

    incomplete table (only for demo) the rest of the SRs defaults to value 0. Common practice otherwise is to give these default handler and attribute them weak
}

linker script

MEMORY
{
  flash (rx) : ORIGIN = 0x8000000, LENGTH = 32K
  ram (rwx) : ORIGIN = 0x20000000, LENGTH = 6K
}

_eram = ORIGIN(ram) + LENGTH(ram);
_stack = _eram; /* Stack starts at end of RAM and grows downwards */

SECTIONS
{
  .text : ALIGN(4)
  {
    KEEP(*(.ivt)) /* Interrupt vector table */
    *(.text*)
    . = ALIGN(4);
    _etext = .;
  } > flash

  .init_array : ALIGN(4)
  {
    __init_array_start = .;
    KEEP(*(.init_array*))
    __init_array_end = .;
    . = ALIGN(4);
  } > flash

    /* Initial (constant) values for data is placed in flash after the program code */
  _idata = LOADADDR(.data);

  .data : ALIGN(4)
  {
    _data = .;
    *(.data*)
    . = ALIGN(4);
    _edata = .;
  } > ram AT > flash

  .bss : ALIGN(4)
  {
    _bss = .;
    *(.bss*)
    . = ALIGN(4);
    _ebss = .;
    PROVIDE(_end = .);
  } > ram
}

main.c

__attribute((constructor))
static void function_called_before_main(void) {
    return
}

int main(void)
{
    return 0;
}

startup file
    - ivt[IVT_ARRAY_SIZE]
    - isr_reset()
        - copy_data()
        - clear_bss()
        - main()
        - while(1)

    linker script
        - MEMORY - flash, ram
        - SECTIONS - .text, .data, .bss

    Link with libc
        --specs=nosys.specs (stubs)
        --specs=nano.specs (small Newlib)
        -mcpu=cortex-m0
        -mthumb

