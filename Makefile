all:read_mem

read_mem:read_mem.o
	g++ -o read_mem read_mem.o
read_mem.o:read_mem.cpp
	g++ -c read_mem.cpp
clean:
	rm -f *.o read_mem
