menu: menu.o directory.o entry.o
	g++ menu.o directory.o entry.o -o menu

menu.o: menu.cpp directory.h entry.h
	g++ -c menu.cpp

directory.o: directory.cpp directory.h entry.h
	g++ -c directory.cpp

entry.o: entry.cpp entry.h
	g++ -c entry.cpp

clean:
	rm -f menu *.o