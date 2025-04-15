# mockVacuum.py
# Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
# Description: Mock Vacuum Robot API for simulation
# Dependencies: Flask (pip install -r mocks/requirements.txt)

from flask import Flask, request, jsonify

app = Flask(__name__)

# Initial vacuum robot state
vacuum_state = {
    "active": False,     # Is the robot currently running
    "scheduled": None    # Optional scheduled time (24hr format as int, e.g. 1800)
}

@app.route("/api/v1/health", methods=["GET"])
def health():
    return "OK", 200

@app.route("/api/v1/state", methods=["GET"])
def get_state():
    return jsonify(vacuum_state), 200

@app.route("/api/v1/state", methods=["POST"])
def update_state():
    data = request.get_json()
    if not data:
        return jsonify({"error": "Invalid or missing JSON body"}), 400

    if "active" in data:
        if isinstance(data["active"], bool):
            vacuum_state["active"] = data["active"]
        else:
            return jsonify({"error": "'active' must be a boolean"}), 400

    if "scheduled" in data:
        if data["scheduled"] is None:
            vacuum_state["scheduled"] = None
        elif isinstance(data["scheduled"], int) and 0 <= data["scheduled"] <= 2359:
            vacuum_state["scheduled"] = data["scheduled"]
        else:
            return jsonify({"error": "'scheduled' must be an integer time (e.g. 1830) or null"}), 400

    return jsonify(vacuum_state), 200

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000)
