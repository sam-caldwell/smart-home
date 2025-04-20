# ===============================
# Stage 1 - Base image
# ===============================
FROM ubuntu:latest AS base

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y \
        apt-transport-https \
        ca-certificates \
        curl \
        libcurl4-openssl-dev

# ===============================
# Stage 2 - Build environment
# ===============================
FROM base AS buildenv

RUN apt-get install -y \
        build-essential \
        cmake \
        git \
        g++ \
        make

# ===============================
# Stage 3 - Builder stage
# ===============================
FROM buildenv AS builder

# Copy everything into the container
COPY . /opt/
WORKDIR /opt/

# Create build directory and compile
#RUN make clean
#RUN make build

# ===============================
# Stage 4 - Runtime (distroless)
# ===============================
FROM base AS runtime
ENV HOST_IP="127.0.0.1"
ENV LIGHTS=8001
ENV SECURITY=8002
ENV TELEVISION=8003
ENV THERMOSTAT=8004
ENV VACCUM=8005

# Copy compiled binary from builder stage
COPY --from=builder /opt/build/smart_home_exec /opt/smart_home_exec

# Permissions (optional but recommended for clarity)
USER nonroot:nonroot

# Set entrypoint
ENTRYPOINT ["/opt/smart_home_exec"]
