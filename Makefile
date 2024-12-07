all: main.cpp
	g++ main.cpp -o calc
clean:
	rm -f calc
