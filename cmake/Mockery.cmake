# cmake/Mockery.cmake
# Author: Sam Caldwell
# Description: Defines the `mockery` target for spinning up mock device containers.

set(DOCKERFILE "${PROJECT_ROOT}/mocks/Dockerfile")

set(MOCK_LIGHTS,"127.0.0.1:8001")
set(MOCK_SECURITY,"127.0.0.1:8002")
set(MOCK_TELEVISION,"127.0.0.1:8003")
set(MOCK_THERMOSTAT,"127.0.0.1:8004")
set(MOCK_VACUUM,"127.0.0.1:8005")

add_custom_target(mockery ALL
        COMMENT "Starting mock Thermostat on port 8000..."
        COMMAND ${CMAKE_COMMAND} -E echo "Building Docker images..."
        COMMAND docker build --tag mockery:local --target base --file "${DOCKERFILE}"  "${PROJECT_ROOT}"
        COMMAND docker build --tag mocklights:local --target mocklights --file "${DOCKERFILE}"  "${PROJECT_ROOT}"
        COMMAND docker build --tag mocksecurity:local --target mocksecurity --file "${DOCKERFILE}"  "${PROJECT_ROOT}"
        COMMAND docker build --tag mocktelevision:local --target mocktelevision --file "${DOCKERFILE}"  "${PROJECT_ROOT}"
        COMMAND docker build --tag mockthermostat:local --target mockthermostat --file "${DOCKERFILE}"  "${PROJECT_ROOT}"
        COMMAND docker build --tag mockvacuum:local --target mockvacuum --file "${DOCKERFILE}"  "${PROJECT_ROOT}"

        COMMAND ${CMAKE_COMMAND} -E echo "Stopping any running mock containers..."
        COMMAND docker kill mocklights || true
        COMMAND docker kill mocksecurity || true
        COMMAND docker kill mocktelevision || true
        COMMAND docker kill mockthermostat || true
        COMMAND docker kill mockvacuum || true

        COMMAND ${CMAKE_COMMAND} -E echo "Starting mock containers..."
        COMMAND docker run -d --rm --name mocklights --publish ${MOCK_LIGHTS}:8000 mocklights:local
        COMMAND docker run -d --rm --name mocksecurity --publish ${MOCK_SECURITY}:8000 mocksecurity:local
        COMMAND docker run -d --rm --name mocktelevision --publish ${MOCK_TELEVISION}:8000 mocktelevision:local
        COMMAND docker run -d --rm --name mockthermostat --publish ${MOCK_THERMOSTAT}:8000 mockthermostat:local
        COMMAND docker run -d --rm --name mockvacuum --publish ${MOCK_VACUUM}:8000 mockvacuum:local

        COMMAND ${CMAKE_COMMAND} -E sleep 1
        COMMAND ${CMAKE_COMMAND} -E echo "Verifying containers..."
        COMMAND bash -c "for i in 1 2 3 4 5; do \
            echo 'Verifying http://127.0.0.1:800'$i; \
            curl --fail http://127.0.0.1:800$i/api/v1/health || (echo 'Failed at '$i; exit 1); \
            echo ''; \
        done"
        VERBATIM
)
