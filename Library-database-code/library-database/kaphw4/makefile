hello:main.o book.o EntityBook.o EntityLoan.o EntityPatron.o loan.o patron.o
	g++ -o hello *.o



main.o: main.cpp book.h patron.h loan.h
	g++ -c main.cpp
book.o:book.cpp book.h
	g++ -c book.cpp
EntityBook.o: EntityBook.cpp book.h
	g++ -c EntityBook.cpp
EntityLoan.o: EntityLoan.cpp EntityLoan.h
	g++ -c EntityLoan.cpp
EntityPatron.o: EntityPatron.cpp EntityPatron.h
	g++ -c EntityPatron.cpp
loan.o: loan.cpp loan.h patron.h book.h
	g++ -c loan.cpp
patron.o: patron.cpp patron.h
	g++ -c patron.cpp
