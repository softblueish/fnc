fnc:
	g++ -o fnc ./fnc.cpp
install:
	cp fnc /bin/fnc
clean:
	rm fnc
uninstall:
	rm /bin/fnc

