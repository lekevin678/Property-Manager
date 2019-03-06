CC = g++ -g
exe_file = a.out
$(exe_file): driver.o house.o no_class.o property.o business.o apartment.o
	$(CC) driver.o house.o no_class.o property.o business.o apartment.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
house.o: house.cpp
	$(CC) -c house.cpp
no_class.o: no_class.cpp
	$(CC) -c no_class.cpp
property.o: property.cpp
	$(CC) -c property.cpp
business.o: business.cpp
	$(CC) -c business.cpp
apartment.o:
	$(CC) -c apartment.cpp
clean:
	rm -f *.out *.o $(exe_file)

