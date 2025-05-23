# cmake/Mockery.cmake
# Author: Sam Caldwell
# Description: Defines the `mockery` target for spinning up mock device containers.

set(DOCKERFILE "${PROJECT_ROOT}/mocks/Dockerfile")

set(API_MOCK_LIGHTS "${HOST_IP}:8001")
set(API_MOCK_SECURITY "${HOST_IP}:8002")
set(API_MOCK_TELEVISION "${HOST_IP}:8003")
set(API_MOCK_THERMOSTAT "${HOST_IP}:8004")
set(API_MOCK_VACUUM "${HOST_IP}:8005")

add_custom_target(mockery
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
        COMMAND docker run -d --rm --name mocklights --publish "${API_MOCK_LIGHTS}:8000" mocklights:local
        COMMAND docker run -d --rm --name mocksecurity --publish "${API_MOCK_SECURITY}:8000" mocksecurity:local
        COMMAND docker run -d --rm --name mocktelevision --publish "${API_MOCK_TELEVISION}:8000" mocktelevision:local
        COMMAND docker run -d --rm --name mockthermostat --publish "${API_MOCK_THERMOSTAT}:8000" mockthermostat:local
        COMMAND docker run -d --rm --name mockvacuum --publish "${API_MOCK_VACUUM}:8000" mockvacuum:local

        COMMAND ${CMAKE_COMMAND} -E sleep 1
        COMMAND ${CMAKE_COMMAND} -E echo "Verifying containers..."
        COMMAND bash -c "for i in 1 2 3 4 5; do \
            echo 'Verifying http://${HOST_IP}:800'$i; \
            curl --fail http://${HOST_IP}:800$i/api/v1/health || (echo 'Failed at '$i; exit 1); \
            echo ''; \
        done"
        VERBATIM
)
