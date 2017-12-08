# defining variables:
CC=g++
CFLAGS=-c
HEADERS=match.h player.h round.h stadium.h team.h tournament.h cup.h leg.h
OBJECTS=match.o player.o round.o stadium.o team.o tournament.o cup.o leg.cpp

#defining rules:
all: out

out: $(HEADERS) $(OBJECTS) main.o 
	$(CC) $(OBJECTS) main.o -o out

out_2: $(HEADERS) $(OBJECTS) main-with-extra-players.o 
	$(CC) $(OBJECTS) main-with-extra-players.o -o out

out_3: $(HEADERS) $(OBJECTS) main-with-penalty.o
	$(CC) $(OBJECTS) main-with-penalty.o -o out

out_4: $(HEADERS) $(OBJECTS) main-with-inaquate-teams.o
	$(CC) $(OBJECTS) main-with-inaquate-teams.o -o out

out_5: $(HEADERS) $(OBJECTS) main-bigger-testcase.o
	$(CC) $(OBJECTS) main-bigger-testcase.o -o out

main.o: main.cpp tournament.h
	$(CC) $(CFLAGS) main.cpp

tournament.o: tournament.cpp tournament.h cup.h
	$(CC) $(CFLAGS) tournament.cpp

cup.o: cup.cpp cup.h round.h team.h
	$(CC) $(CFLAGS) cup.cpp

team.o: team.cpp team.h stadium.h
	$(CC) $(CFLAGS) team.cpp

round.o: round.cpp round.h team.h match.h
	$(CC) $(CFLAGS) round.cpp

player.o: player.cpp player.h
	$(CC) $(CFLAGS) player.cpp

match.o: match.cpp match.h team.h leg.h
	$(CC) $(CFLAGS) match.cpp

leg.o: leg.cpp leg.h team.h
	$(CC) $(CFLAGS) leg.cpp

stadium.o: stadium.cpp stadium.h
	$(CC) $(CFLAGS) stadium.cpp

clean:
	rm -rf *o out	