# mockLights.py
# Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
# Description: Mock Light System API to simulate smart lights by room
# Dependencies: Flask (install via `pip install -r mocks/requirements.txt`)

from flask import Flask, request, jsonify

app = Flask(__name__)

# Initial light states by room
lights_state = {
    "kitchen": "on",
    "office": "on",
    "bedroom": "on",
    "livingroom": "on",
    "bathroom": "on"
}

@app.route("/api/v1/health", methods=["GET"])
def health():
    return "OK", 200

@app.route("/api/v1/state", methods=["GET"])
def get_state():
    return jsonify(lights_state), 200

@app.route("/api/v1/state", methods=["POST"])
def update_state():
    data = request.get_json()
    if not data:
        return jsonify({"error": "Invalid or missing JSON body"}), 400

    for room, state in data.items():
        if room in lights_state and state in ["on", "off"]:
            lights_state[room] = state
        else:
            return jsonify({"error": f"Invalid room or state: {room} = {state}"}), 400

    return jsonify(lights_state), 200

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000)
