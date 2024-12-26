main: main.o std_manage.o
	gcc	main.o	std_manage.o	-o	main

main.o: main.c
	gcc	-c	main.c

std_manage.o: std_manage.c std_manage.h
	gcc	-c	std_manage.c	std_manage.h

clean:
	rm	.\std_manage.h.gch	.\std_manage.o	.\main.exe	.\main.o