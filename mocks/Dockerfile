# Dockerfile
# Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
# Description: A Dockerfile to run our mocks mocks APIs
# Dependencies: Docker, limactl + containerd or kubernetes/minikube

##############################################
# Stage 1 - Devices image setup
##############################################
FROM ubuntu:latest as base

ENV DEBIAN_FRONTEND=noninteractive
# Install Python and pip
RUN apt-get update -y && apt-get upgrade -y && \
    apt-get install -y ca-certificates python3 python3-pip

# Create directories
RUN mkdir -p /opt/service
WORKDIR /opt/service

# Create non-root service user because I'm not a damned heathen!
RUN groupadd -r service && useradd -r -g service -d /opt/service service
RUN chown -R service:service /opt/service

# Set non-root user because least-privilege woohoo!
USER service

# Copy python requirements
COPY mocks/requirements.txt /opt/requirements.txt

# Install python packages
RUN pip3 install --no-cache-dir --break-system-packages -r /opt/requirements.txt

##############################################
# Stage: mocklights.py
##############################################
FROM base as mocklights

COPY --chown=service:service mocks/mockLights.py /opt/service/

ENV SERVICE_IP=127.0.0.1
ENV SERVICE_PORT=8000

CMD ["python3", "mockLights.py"]
ENTRYPOINT ["python3", "mockLights.py"]

##############################################
# Stage: mocksecurity.py
##############################################
FROM base as mocksecurity

COPY --chown=service:service mocks/mockSecurity.py /opt/service/

ENV SERVICE_IP=127.0.0.1
ENV SERVICE_PORT=8000

CMD ["python3", "mockSecurity.py"]
ENTRYPOINT ["python3", "mockSecurity.py"]

##############################################
# Stage: mocktelevision.py
##############################################
FROM base as mocktelevision

COPY --chown=service:service mocks/mockTelevision.py /opt/service/

ENV SERVICE_IP=127.0.0.1
ENV SERVICE_PORT=8000

CMD ["python3", "mockTelevision.py"]
ENTRYPOINT ["python3", "mockTelevision.py"]

##############################################
# Stage: mockthermostat.py
##############################################
FROM base as mockthermostat

COPY --chown=service:service mocks/mockThermostat.py /opt/service/

ENV SERVICE_IP=127.0.0.1
ENV SERVICE_PORT=8000

CMD ["python3", "mockThermostat.py"]
ENTRYPOINT ["python3", "mockThermostat.py"]

##############################################
# Stage: mockvacuum.py
##############################################
FROM base as mockvacuum

COPY --chown=service:service mocks/mockVacuum.py /opt/service/

ENV SERVICE_IP=127.0.0.1
ENV SERVICE_PORT=8000

CMD ["python3", "mockVacuum.py"]
ENTRYPOINT ["python3", "mockVacuum.py"]
