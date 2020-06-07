incl = -I /usr/local/include/boost/
libs = -L /usr/local/lib/ -lboost_system -lboost_fiber -lboost_context -lboost_thread

time = /usr/bin/time -p

all: clean run.cpp run.go run.cpp_threads

clean:
	rm -f routines_*

cpp:
	g++ $(incl) -o routines_cpp main.cpp $(libs)

run.cpp: cpp
	$(time) ./routines_cpp

cpp_threads:
	g++ $(incl) -o routines_cpp_threads main_threads.cpp $(libs)

run.cpp_threads: cpp_threads
	$(time) ./routines_cpp_threads

go:
	go build -o routines_go main.go

run.go: go
	$(time) ./routines_go


