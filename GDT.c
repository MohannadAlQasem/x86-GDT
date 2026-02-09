#include "GDT.h"
#include "types.h"
static struct gdt_entry_struct gdt_entries[5];
static struct gdt_ptr GDTPtr;

void setGDT(uint32_t index, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity) {
    gdt_entries[index].lower_base = (base & 0xFFFF);
    gdt_entries[index].middle_base = (base >> 16) & 0xFF;
    gdt_entries[index].high_base = (base >> 24) & 0xFF;
    gdt_entries[index].limit = (limit & 0xFFFF);
    gdt_entries[index].flags = (limit >> 16) & 0x0F;
    gdt_entries[index].flags |= (granularity & 0xF0);
    gdt_entries[index].access = access;
}


void initGDT() {

    setGDT(0,0,0,0,0); // NULL Segment

    setGDT(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Kernel Code Segment Descriptor

    setGDT(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Kernel Data Segment Descriptor

    setGDT(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User Code Segment Descriptor

    setGDT(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User Data Segment Descriptor

    GDTPtr.limit = sizeof(gdt_entries) - 1;
    GDTPtr.base = (uint32_t) &gdt_entries;

    loadgdt(&GDTPtr);
    load_registers();
};




