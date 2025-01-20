# Template Linux Device Driver

## Setup
1. Enter into build.sh
2. Change ``ddriver.ko`` in lines 2 and 4 to your own ``.ko`` file.
3. Change ``dev_testdr`` in lines 5 and 6 to your device driver name.
4. On line 6 change the ``137`` to your own major device id.
5. On line 6 change the ``0`` to your own minor device id.

## Build Command

```
./build.sh
```
