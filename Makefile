# defining variables:
CC=g++
CFLAGS=-c
HEADERS=match.h player.h round.h stadium.h team.h tournament.h
OBJECTS=main.o match.o player.o round.o stadium.o team.o tournament.o

#defining rules:
all: out

out: $(HEADERS) $(OBJECTS)
	$(CC) $(OBJECTS) -o out

main.o: tournament.h
	$(CC) $(CFLAGS) main.cpp

tournament.o: tournament.o tournament.h round.h team.h
	$(CC) $(CFLAGS) tournament.cpp

team.o: team.o team.h stadium.h
	$(CC) $(CFLAGS) team.cpp

round.o: round.o round.h team.h match.h
	$(CC) $(CFLAGS) round.cpp

player.o: player.o player.h
	$(CC) $(CFLAGS) player.cpp

match.o: match.o match.h team.h
	$(CC) $(CFLAGS) match.cpp

stadium.o: stadium.o stadium.h
	$(CC) $(CFLAGS) staduim.cpp

clean:
	rm -rf *o *_out	