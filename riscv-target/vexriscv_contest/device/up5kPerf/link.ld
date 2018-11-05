OUTPUT_ARCH( "riscv" )
ENTRY(_start)

SECTIONS
{
  . = 0x80000;
  .text : { *(.text) }
  .data : { *(.data) }
  _end = .;
}
