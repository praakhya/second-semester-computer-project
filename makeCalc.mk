calc: conversions.o scicalc.o matrix.o areaVolume.o trignometry.o mainProgram.o
	gcc conversions.o areaVolume.o mainProgram.o scicalc.o trignometry.o matrix.o -o calc -lm

conversions.c: functionHeaders.h
scicalc.c: functionHeaders.h
matrix.c: functionHeaders.h
areaVolume.c: functionHeaders.h
trignometry.c: functionHeaders.h
mainProgram.c: functionHeaders.h