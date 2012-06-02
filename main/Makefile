SRCS := $(shell ls *.cpp)
BINS := $(patsubst %.cpp,%.bin,$(SRCS))

vxm_objs := $(addprefix ../, $(VXM_LD))

genbin: $(BINS)

%.bin: %.o
	g++ -m32 -g -Wall -o $@ $^ $(vxm_objs)
	mv $@ $(patsubst %.bin,%,$@)

%.o: %.cpp
	g++ $(CFLAGS) -c $^

clean:
	rm -rf *.o
	rm -rf $(patsubst %.bin,%,$(BINS))
