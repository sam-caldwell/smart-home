# mockSecurity.py
# Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
# Description: Mock Security System API for simulation
# Dependencies: Flask (install via `pip install -r mocks/requirements.txt`)

from flask import Flask, request, jsonify

app = Flask(__name__)

# Initial state of the security system
security_state = {
    "armed": False,
    "sensitivity": 3  # range from 1 (low) to 5 (high)
}

@app.route("/api/v1/health", methods=["GET"])
def health():
    return "OK", 200

@app.route("/api/v1/state", methods=["GET"])
def get_state():
    return jsonify(security_state), 200

@app.route("/api/v1/state", methods=["POST"])
def update_state():
    data = request.get_json()
    if not data:
        return jsonify({"error": "Invalid or missing JSON body"}), 400

    if "armed" in data:
        if isinstance(data["armed"], bool):
            security_state["armed"] = data["armed"]
        else:
            return jsonify({"error": "'armed' must be a boolean"}), 400

    if "sensitivity" in data:
        if isinstance(data["sensitivity"], int) and 1 <= data["sensitivity"] <= 5:
            security_state["sensitivity"] = data["sensitivity"]
        else:
            return jsonify({"error": "Sensitivity must be an integer between 1 and 5"}), 400

    return jsonify(security_state), 200

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000)
