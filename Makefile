EXENAME = main
OBJS = main.o

CFLAGS = -DNDEBUG -g3 -O2 -Wall -Wextra
LIBS = -L/usr/lib/ -lcryptopp -lpthread

main.o: main.cpp
	$(CXX) $(CFLAGS)  *.cpp -o $(OBJS) $(LIBS)

clean:
	-rm -f *.o $(EXENAME)