TARGET := bd

$(TARGET): database.o table.o main.o
	g++ main.o database.o -o $(TARGET)

main.o: main.cpp database.h
	g++ -c main.cpp -o main.o

database.o: database.cpp table.h database.h
	g++ -c database.cpp -o database.o

table.o: table.cpp table.h
	g++ -c table.cpp -o table.o


.PHONY: clean
clean:
	rm -rf *.o
	rm -rf bd
