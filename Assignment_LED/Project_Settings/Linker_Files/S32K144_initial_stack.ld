SECTIONS
{
	/* Initializes stack on the end of block */
  __StackTop   = ORIGIN(m_data_2) + LENGTH(m_data_2);
  __StackLimit = __StackTop - STACK_SIZE;
  PROVIDE(__stack = __StackTop);
  __RAM_END = __StackTop;

  .stack __StackLimit :
  {
    . = ALIGN(8);
    __stack_start__ = .;
    . += STACK_SIZE;
    __stack_end__ = .;
  } > m_data_2

  /* Labels required by EWL */
  __START_BSS = __BSS_START;
  __END_BSS = __BSS_END;
  __SP_INIT = __StackTop;  
  
  .ARM.attributes 0 : { *(.ARM.attributes) }

  ASSERT(__StackLimit >= __HeapLimit, "region m_data_2 overflowed with stack and heap")
}