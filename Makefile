vxm_dirs := core dsl app db landpat
vxm_base := $(addprefix vxm., $(vxm_dirs))
vxm_cln := $(addprefix cln., $(vxm_dirs))
vxm_objs := $(addsuffix /vxm-obj.o, $(vxm_dirs))

PWD := $(shell pwd)

export CFLAGS = -Werror -Wall -g -m32 -I$(PWD)/include

all: $(vxm_base)
	make -C main VXM_LD="$(vxm_objs)" genbin

#	g++ -m32 -g -Wall -o VxmTest $(vxm_objs) 

clean: $(vxm_cln)
	make -C main clean
	rm -f ./VxmTest

vxm.%:
	make -C $(patsubst vxm.%, %, $@) TARGET_OBJ=vxm-obj.o

cln.%:
	make -C $(patsubst cln.%, %, $@) clean

