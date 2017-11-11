# Read-mem
从指定位置读取七个内存单元的内存值，进行加一操作后，再重新读一次。
# 注意
如果想读取其他位置的内存单元，可修改程序：

map_base = (unsigned char *)mmap((void *)0x42000000, 0xff, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

将0x42000000修改为自己想访问的地址即可
重新make clean;make 即可
