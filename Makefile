HEAD=src/generate.h
#GCC=gcc
#GCC=~/opt/gcc/bin/gcc #ver6.3.0
GCC=~/opt/gnat-gpl-2017-x86_64-linux-bin/bin/gcc #ver6.3.1
OPTION=-Wall -lm -O2

all:	comp

comp:	src/BarrelShift.o src/LeadingZeroShift.o src/MantissaAdder.o src/IncreaseFrac.o src/add_float.o src/arg_check.o src/generator.o src/main.o
	$(GCC) $^ -o bin/gen $(OPTION)

src/BarrelShift.o:	src/BarrelShift.c $(HEAD)
src/BarrelShift.c:
	$(GCC) -c src/BarrelShift.c $(OPTION)

src/LeadingZeroShift.o:	src/LeadingZeroShift.c $(HEAD)
src/LeadingZeroShift.c:
	$(GCC) -c src/LeadingZeroShift.c $(OPTION)

src/MantissaAdder.o:	src/MantissaAdder.c $(HEAD)
src/MantissaAdder.c:
	$(GCC) -c src/MantissaAdder.c $(OPTION)

src/IncreaseFrac.o:	src/IncreaseFrac.c $(HEAD)
src/IncreaseFrac.c:
	$(GCC) -c src/IncreaseFrac.c $(OPTION)

src/add_float.o:	src/add_float.c $(HEAD)
src/add_float.c:
	$(GCC) -c src/add_float.c $(OPTION)

src/arg_check.o:	src/arg_check.c $(HEAD)
src/arg_check.c:
	$(GCC) -c src/arg_check.c $(OPTION)

src/generator.o:	src/generator.c $(HEAD)
src/generator.c:
	$(GCC) -c src/generator.c $(OPTION)

src/main.o:	src/main.c $(HEAD)
src/main.c:
	$(GCC) -c src/main.c $(OPTION)

clean:
	rm -rf *~ *.out src/*.o src/*~ *.sfl bin/*
