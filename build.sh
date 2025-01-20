echo "Building driver"
sudo rmmod ddriver.ko
make
sudo insmod ddriver.ko
sudo mknod /dev/dev_testdr c 137 0
sudo chmod 666 /dev/dev_testdr 
echo "Driver built"
