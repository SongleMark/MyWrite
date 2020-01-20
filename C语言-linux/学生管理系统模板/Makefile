ALL:=test
QBJEST:=main.o menu.o
CC:=gcc
OPTION:=-g -Wall -lm
$(ALL):$(OBJEST)
	$(CC) $^ -o $@ $(OPTION)
%.o:%.c
	$(CC) -c $< -o $@
clean:
	rm -rf $(ALL) $(OBJEST)
