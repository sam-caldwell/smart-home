.PHONY:build
.PHONY:clean

clean:
	./clean.sh

build:
	# Configure CMake project
	cmake -S . -B build

	# Build and run the custom build_and_test target
	cmake --build build --target build_and_test

