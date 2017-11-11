#include <stdio.h>   
#include <unistd.h>   
#include <sys/mman.h>   
#include <sys/types.h>   
#include <sys/stat.h>   
#include <fcntl.h>   
#include <iostream>

#define MEM_DEVICE "/dev/mem"

using namespace std;

int main( int argc,char** argv )  
{
	unsigned char * map_base;   
	int fd;  
  	
	// open /dev/fb0
	fd = open(MEM_DEVICE, O_RDWR|O_SYNC);  
	if (fd == -1)  
	{  
		return (-1);
		cout<<" Failed when open "<<MEM_DEVICE<<" with returnning fd ="<<fd<<endl; 
	}
	cout<<" Open "<<MEM_DEVICE<<" succed. "<<endl;
  	
	// mmap地址可修改
	map_base = (unsigned char *)mmap((void *)0x42000000, 0xff, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);  
	if (map_base == 0)  
	{  
		cout<<" Failed when mmap : NULL pointer!"<<endl; 
	}  
	else  
	{  
		cout<<" mmap succed ."<<endl;
	}  
	
	// read from mmap
	cout<<" The value of mem before : "<<endl;
	for ( int i=0;i<7;i++ )
	{
		cout<<"address:"<<(unsigned long)map_base<<"content:"<<(unsigned int)map_base[i*4]<<endl;
	}

	// change value from mmap
	for ( int i=0;i<7;i++ )
	{
		map_base[i*4] +=40;
	}

	// read from mmap
	cout<<" The value of mem after : "<<endl;
	for ( int i=0;i<7;i++ )
	{
		cout<<"address:"<<(unsigned long)map_base<<"content:"<<(unsigned int)map_base[i*4]<<endl;
	}
	close(fd);  
  
	munmap(map_base, 0xff);  
  
	return (1);  
}  
