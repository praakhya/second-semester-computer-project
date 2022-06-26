SRCS = \
	mainProgram.c \
	matrixCalc.c \
	areaVolume.c \
	conversions.c
OBJS = $(subst .c,.o, $(SRCS))
calc: $(OBJS)
	$(CC) -o calc $(OBJS)

	