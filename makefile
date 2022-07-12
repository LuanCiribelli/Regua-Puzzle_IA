
TARGET=main

CC=g++

OBJS=*.o

ifdef OS
   RM = del /Q
   FixPath = $(subst /,\,$1)
else
   ifeq ($(shell uname), Linux)
      RM = rm -f
      FixPath = $1
   endif
endif

all: clean exec main 
		

main:
		$(CC) $(OBJS) -o $(TARGET)
exec: 
		$(CC) -c src/*.cpp
			
clean:
			 $(RM) $(call FixPath,*.o) 
			 $(RM) $(call FixPath,main) 