//
// Cian McNamara, 2025
// template.c
//

// Includes required for a kernel module
#include <linux/module.h>
#include <linux/kernel.h>

// Function that runs when the module is inserted as a kernel module
int init(void) {
    printk("Module loaded\n");
    return 0;
}

// Function that runs when the module is removed as a kernel module
void exit(void) {
    printk("Module unloaded\n");
}

module_init(init);
module_exit(exit);

MODULE_LICENSE("GPL");