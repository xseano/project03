group17: global.o jgrout.o ssoberoi.o afajhan.o group17.o
	g++ global.o jgrout.o ssoberoi.o afajhan.o group17.o -o p03
	make clean

clean:
	@rm -f $(PROGRAMS) *.o core