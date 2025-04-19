# mockThermostat.py
# Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
# Description: Mock Thermostat HTTP API for local simulation
# Dependencies: Flask (install via `pip install -r mocks/requirements.txt`)

from flask import Flask, request, jsonify

app = Flask(__name__)

# Initial state of the mocks thermostat
thermostat_state = {
    "mode": "heat",  # or "heat"
    "fan": "on",  # or "on"
    "temp": 72  # integer temp
}


@app.route("/api/v1/health", methods=["GET"])
def health():
    return "OK", 200


@app.route("/api/v1/state", methods=["GET"])
def get_state():
    return jsonify(thermostat_state), 200


@app.route("/api/v1/state", methods=["POST"])
def update_state():
    data = request.get_json()
    if not data:
        return jsonify({"error": "Invalid or missing JSON body"}), 400

    # Update any provided fields
    for key in ['mode', 'fan', 'temp']:
        if key in data:
            thermostat_state[key] = data[key]

    return jsonify(thermostat_state), 200


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000)
