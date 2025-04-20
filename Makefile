.PHONY:build
.PHONY:clean

clean:
	@rm -rf ./build &> /dev/null || true
	@rm -f CMakeCache.txt &> /dev/null || true

configure:
	# Configure CMake project
	cmake -S . -B build

configure-no-tests:
	cmake -S . -B build -DFF_TEST_ENABLE=OFF

build:
	cmake --build build --target build

get-ip:
	@cmake --build build --target PrintHostIP | grep -E 'HOST_IP=[0-9]+' | awk -F\= '{print $$2}'

local: mockery build
	@echo "local dev environment running"

me-stop:
	kill $(shell ps aux | grep smart_home_exec | grep -v grep | awk '{print $$2}')

mockery:
	cmake --build build --target mockery

DOCKER_IMAGE:=smart-home:local
package:
	docker build --tag ${DOCKER_IMAGE} .

run:
	@( \
		export HOST_IP=$(shell make get-ip); \
		export PORT_LIGHTS=8001; \
        export PORT_SECURITY=8002; \
        export PORT_TELEVISION=8003; \
        export PORT_THERMOSTAT=8004; \
        export PORT_VACCUM=8005; \
        clear; \
		./build/smart_home_exec \
	)

CONTAINER_NAME:=smart-home
kill-docker:
	docker kill ${CONTAINER_NAME} &>/dev/null || true
	docker rm ${CONTAINER_NAME} &>/dev/null || true

run-docker: kill-docker mockery
	docker run -it \
			   --name ${CONTAINER_NAME} \
			   --env HOST_IP=$(shell make get-ip) ${DOCKER_IMAGE}

stop-log-tail:
	kill $(shell ps aux | grep tail | grep log | grep -v grep | awk '{print $$2}')

tree:
	cmake --build build --target generate_file_tree

zip: clean configure tree
	cmake --build build --target zip_submission
