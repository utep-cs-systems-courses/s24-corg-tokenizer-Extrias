all: uimain

tokenizer.o : tokenizer.c
	cc -c tokenizer.c

history.o: history.c
	cc -c history.c

uimain.o: uimain.c
	cc -c uimain.c

uimain: uimain.o tokenizer.o history.o
	cc -o uimain tokenizer.o uimain.o history.o

clean:
	rm -f *.o *.c~ uimain
