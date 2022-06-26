SRCS = \
	mainProgram.c \
	matrixCalc.c \
	areaVolume.c \
	conversions.c \
	scicalc.c \
	trignometry.c

HEADERS = \
	functionHeaders.h 

%.c: $(HEADERS)

OBJS = $(subst .c,.o, $(SRCS))

ALL: calc 

calc:$(OBJS)
	$(CC) -o calc $(OBJS) -lm

clean:
	$(RM) $(OBJS) calc