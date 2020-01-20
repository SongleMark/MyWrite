install:main.o 2_fwrite.o  3_fread.o
	gcc  main.o  2_fwrite.o  3_fread.o  -o  install
main.o:main.c
	gcc  -I ../inc main.c  -o  main.o  -c  -g
2_fwrite.o:2_fwrite.c
	gcc  -I  ../inc 2_fwrite.c  -o  2_fwrite.o  -c  -g
3_fread.o:3_fread.c
	gcc  -I  ../inc  3_fread.c  -o  3_fread.o  -c  -g

clear:
	rm  -rf   *.o   install
