//
// Cian McNamara, 2025
// ddriver.c
//

// Includes required for a kernel module
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Cian McNamara");
MODULE_DESCRIPTION("Linux test driver");

// Runs when the device file is opened
static int driver_open(struct inode* device_file, struct file* instance) {
    printk("driver_open called\n");
    return 0;
}


// Runs when the device file is closed
static int driver_close(struct inode* device_file, struct file* instance) {
    printk("driver_close called\n");
    return 0;
}

// Struct which contains our file operations
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = driver_open,
    .release = driver_close
};

#define MAJOR_DEVICE_NUMBER 137
#define MINOR_DEVICE_NUMBER 0

// Function that runs when the module is inserted as a kernel module
static int __init init_mdl(void) {
    int retval;
    printk("Module loaded\n");

    // Register device number
    retval = register_chrdev(MAJOR_DEVICE_NUMBER, "dev_testdr", &fops);

    if (retval == 0) {
        printk("dev_testdr registered to major number %d and minor number %d\n", MAJOR_DEVICE_NUMBER, MINOR_DEVICE_NUMBER);
    } else {
        printk("Could not register dev_testdr\n");
        return -1;
    }

    return 0;
}

// Function that runs when the module is removed as a kernel module
static void __exit exit_mdl(void) {
    unregister_chrdev(MAJOR_DEVICE_NUMBER, "dev_testdr");
    printk("Module unloaded\n");
}

module_init(init_mdl);
module_exit(exit_mdl);
