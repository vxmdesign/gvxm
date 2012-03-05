SRCS := DbFile.cpp PartMap.cpp TextBlock.cpp

OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all: $(TARGET_OBJ) DbLoader

DbLoader: $(OBJS) DbLoader.o
	g++ $(CFLAGS) -o DbLoader $(OBJS) DbLoader.o

$(TARGET_OBJ): $(OBJS)
	ld -r -g -o $(TARGET_OBJ) $(OBJS)

%.o: %.cpp
	g++ $(CFLAGS) -c $^

clean:
	rm -f *.o
	rm -f DbLoader
	rm -f *~
