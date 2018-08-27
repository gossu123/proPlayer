CC=gcc
CFLAGS=-I. -ftest-coverage -fprofile-arcs
all:sensor-demo

sensor-demo:  build/main.o build/function.o build/sensor.o build/accelerometer.o build/feat.o build/gyroscope.o build/magnetometer.o build/linear_acc.o
	g++ $^ -o $@ -ftest-coverage -fprofile-arcs
build/sensor.o: src/sensor.cpp include/sensor.h
	$(CC) -c src/sensor.cpp -o build/sensor.o $(CFLAGS)

build/function.o: src/function.cpp include/function.h
	$(CC) -c src/function.cpp -o build/function.o $(CFLAGS)

build/linear_acc.o: src/linear_acc.cpp include/linear_acc.h
	$(CC) -c src/linear_acc.cpp -o build/linear_acc.o $(CFLAGS)

build/accelerometer.o: src/accelerometer.cpp include/accelerometer.h
	$(CC) -c src/accelerometer.cpp -o build/accelerometer.o $(CFLAGS)

build/gyroscope.o: src/gyroscope.cpp include/gyroscope.h
	$(CC) -c src/gyroscope.cpp -o build/gyroscope.o $(CFLAGS)

build/magnetometer.o: src/magnetometer.cpp include/magnetometer.h
	$(CC) -c src/magnetometer.cpp -o build/magnetometer.o $(CFLAGS)

build/feat.o: src/feat.cpp include/feat.h
	$(CC) -c src/feat.cpp -o build/feat.o $(CFLAGS)

build/main.o: src/main.cpp 
	$(CC) -c src/main.cpp -o build/main.o $(CFLAGS)
clean:
	rm -rf build/*.o sensor-demo

