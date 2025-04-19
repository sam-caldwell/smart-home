.PHONY:build
.PHONY:clean

clean:
	./clean.sh

build:
	# Configure CMake project
	cmake -S . -B build

	# Build and run the custom build_and_test target
	cmake --build build --target build_and_test

run:
	./build/smart_home_exec

me-stop:
	kill $(shell ps aux | grep smart_home_exec | grep -v grep | awk '{print $$2}')

stop-log-tail:
	kill $(shell ps aux | grep tail | grep log | grep -v grep | awk '{print $$2}')
