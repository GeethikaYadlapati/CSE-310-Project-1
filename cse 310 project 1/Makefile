OBJS	= main.o defns.o encoder.o
OUT	= preprocess, encoder

OBJS0	= main.o
SOURCE0	= main.cpp
HEADER0	= 
OUT0	= preprocess

OBJS1	= defns.o
SOURCE1	= defns.cpp
HEADER1	= 
OUT1	= encoder

CC	 = g++
FLAGS	 = -g -c -Wall

all: preprocess encoder

preprocess: $(OBJS0) $(LFLAGS)
	$(CC) -g $(OBJS0) -o $(OUT0)

encoder: $(OBJS1) $(LFLAGS)
	$(CC) -g $(OBJS1) -o $(OUT1)

main.o: main.cpp,
	$(CC) $(FLAGS) main.cpp, 

defns.o: defns.cpp,
	$(CC) $(FLAGS) defns.cpp, 

encoder.o: encoder.cpp
	$(CC) $(FLAGS) encoder.cpp 


clean:
	rm -f $(OBJS) $(OUT)