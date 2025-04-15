# mockTelevision.py
# Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
# Description: Mock Television HTTP API for local simulation
# Dependencies: Flask (install via `pip install -r mocks/requirements.txt`)

from flask import Flask, request, jsonify

app = Flask(__name__)

# Initial state of the mocks television
tv_state = {
    "power": "off",   # "on" or "off"
    "channel": 1,     # int
    "volume": 10      # int, pretend range 0-100
}

@app.route("/api/v1/health", methods=["GET"])
def health():
    return "OK", 200

@app.route("/api/v1/state", methods=["GET"])
def get_state():
    return jsonify(tv_state), 200

@app.route("/api/v1/state", methods=["POST"])
def update_state():
    data = request.get_json()
    if not data:
        return jsonify({"error": "Invalid or missing JSON body"}), 400

    for key in ['power', 'channel', 'volume']:
        if key in data:
            tv_state[key] = data[key]

    return jsonify(tv_state), 200

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000)
