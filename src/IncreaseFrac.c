#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "generate.h"

int IncreaseFracDec(int frac, FILE *fp){
  fprintf(fp,
	  "declare IncreaseFrac{\n"
	  "input cin;\n"
	  "input in<%d>;\n"
	  "output out<%d>;\n"
	  "output p;\n"
	  "instrin do;\n"
	  "instr_arg do(cin, in);\n"
	  "}\n\n",
	  frac, frac
	  );
  
  return 0;
}

int IncreaseFrac(int frac, FILE *fp){
  
  int bit_head = frac - 2;

  fprintf(fp,
	  "circuit IncreaseFrac{\n"
	  "input cin;\n"
	  "input in<%d>;\n"
	  "output out<%d>;\n"
	  "output p;\n"
	  "instrin do;\n\n"
	  "sel tmp<%d>;\n\n"
	  "instruct do par{\n"
	  "tmp = (0b0||in) + cin;\n"
	  "out = tmp<%d:0>;\n"
	  "p = tmp<%d>;\n"
	  "}\n}\n\n",
	  frac, frac, frac+1,
	  frac-1, frac
	  );
 

  return 0;
}

/*
int IncreaseFrac(int frac, FILE *fp){
  
  int bit_head = frac - 2;

  fprintf(fp,
	  "module IncreaseFrac{\n"
	  "input cin;\n"
	  "input in<%d>;\n"
	  "output out<%d>;\n"
	  "output p;\n"
	  "instrin do;\n\n"
	  "sel cry<%d>;\n\n"
	  "instruct do par{\n"
	  "p = /&(in) & cin;\n"
	  "cry = (/&(in<%d:0>) & cin)\n",
	  frac, frac, frac,
	  bit_head
	  );
  
  int i;
  for (i=bit_head-1; i >0; i--){
    fprintf(fp,
	    "|| (/&(in<%d:0>) & cin)\n",
	    i
	    );
  }

  fprintf(fp,
	  "|| (in<0> & cin)\n"
	  "|| cin;\n"
	  "out = in @ cry;\n"
	  "}\n"
	  "}\n\n"
	  );

  return 0;
}
*/
