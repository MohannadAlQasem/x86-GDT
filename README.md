
a minimal implementation of the Global Descriptor Table for x86 protected mode.

 Null descriptor (required).
 Kernel code segment (ring 0, executable, readable).
 Kernel data segment (ring 0, read/write).
 User code segment (ring 3, executable, readable).
 User data segment (ring 3, read/write).








MIT License — feel free to fork, study, or contribute.
