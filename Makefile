OBJS    = main.o defns.o encoder.o decoder.o
OUT     = preprocess, encoder, decoder

OBJS0MAIN   = main.o
SOURCE0MAIN = main.cpp
HEADER0MAIN =
OUT0MAIN    = preprocess

OBJS1ENCODER   = encoder.o
SOURCE1ENCODER = encoder.cpp
HEADER1ENCODER =
OUT1ENCODER    = encoder

OBJS1DECODER   = decoder.o
SOURCE1DECODER = decoder.cpp
HEADER1DECODER =
OUT1DECODER    = decoder

CC       = g++
FLAGS    = -g -c -Wall

all: preprocess encoder decoder

preprocess: $(OBJS0MAIN) $(LFLAGS)
	$(CC) -g $(OBJS0MAIN) -o $(OUT0MAIN)

encoder: $(OBJS1ENCODER) $(LFLAGS)
	$(CC) -g $(OBJS1ENCODER) -o $(OUT1ENCODER)

decoder: $(OBJS1DECODER) $(LFLAGS)
	$(CC) -g $(OBJS1DECODER) -o $(OUT1DECODER)

#main.o: main.cpp
#	$(CC) $(FLAGS) main.cpp

#defns.o: defns.cpp
#	$(CC) $(FLAGS) defns.cpp

#encoder.o: encoder.cpp
#	$(CC) $(FLAGS) encoder.cpp

#decoder.o: decoder.cpp
#	$(CC) $(FLAGS) decoder.cpp


clean:
	rm -f $(OBJS) $(OUT)
	