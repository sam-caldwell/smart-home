#!/usr/bin/env python3
# File: test/integration_test.py
# Description: Integration test harness for smart_home_exec shell program

import subprocess
import time

TEST_CASES = [
    {
        "name": "Help Command",
        "input": "help\n",
        "expect": "lights <name> <on|off>",
    },
    {
        "name": "Exit Command",
        "input": "exit\n",
        "expect": "Exiting...",
    },
    # Add more test cases here...
]

def run_test_cases(executable_path="./build/smart_home_exec"):
    passed = 0

    for test in TEST_CASES:
        print(f"[TEST] {test['name']}")

        # Start the process
        process = subprocess.Popen(
            [executable_path],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )

        try:
            # Send the input command
            stdout, stderr = process.communicate(
                input=test['input'], timeout=2
            )
        except subprocess.TimeoutExpired:
            process.kill()
            stdout, stderr = process.communicate()

        if test["expect"] in stdout:
            print(f"   ✔ PASSED")
            passed += 1
        else:
            print(f"   ❌ FAILED")
            print(f"   Expected: {test['expect']}")
            print(f"   Got:\n{stdout}")

    print(f"\n=== Summary ===")
    print(f"Passed {passed} / {len(TEST_CASES)} tests.")

if __name__ == "__main__":
    run_test_cases()
