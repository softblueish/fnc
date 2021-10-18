fnc:
	g++ -fno-rtti -fno-exceptions -s -Os -o fnc ./fnc.cpp
install:
	cp fnc /usr/local/bin/fnc
clean:
	rm fnc
uninstall:
	rm /usr/local/bin/fnc

