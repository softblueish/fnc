fnc:
	g++ -fno-rtti -fno-exceptions -s -Os -o fnc ./fnc.cpp
c:
	gcc fnc.c -o fnc
linux64:
	nasm -felf64 -o fnc.o fnclinux64.asm
	ld -o fnc fnc.o
install:
	cp fnc /usr/local/bin/fnc
clean:
	rm fnc
uninstall:
	rm /usr/local/bin/fnc
