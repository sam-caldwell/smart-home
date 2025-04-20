.PHONY:build
.PHONY:clean

clean:
	rm -rf ./build &> /dev/null || true
	rm CMakeCache.txt &> /dev/null || true

configure:
	# Configure CMake project
	cmake -S . -B build

build: configure
	cmake --build build --target build

get-ip:
	@cmake --build build --target PrintHostIP | grep -E 'HOST_IP=[0-9]+' | awk -F\= '{print $$2}'

me-stop:
	kill $(shell ps aux | grep smart_home_exec | grep -v grep | awk '{print $$2}')

mockery: configure
	cmake --build build --target mockery

package:
	docker build --tag smart-home:local \
				 --build-arg HOST_IP=$(shell make get-ip) .

run:
	./build/smart_home_exec

stop-log-tail:
	kill $(shell ps aux | grep tail | grep log | grep -v grep | awk '{print $$2}')
