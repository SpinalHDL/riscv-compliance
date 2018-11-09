OUTPUT_ARCH( "riscv" )
ENTRY(_start)

SECTIONS
{
  . = 0x00010;
  .text : { *(.text) }
  .data : { *(.data) }
  _end = .;
}
