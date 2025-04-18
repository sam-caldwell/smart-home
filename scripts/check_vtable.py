#!/usr/bin/env python3
import os
import re
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent
INCLUDE_DIR = PROJECT_ROOT / "include"
SRC_DIR = PROJECT_ROOT / "src"

virtual_pattern = re.compile(r'virtual\s+(?:[\w:<>]+[\s*&]+)?(\w+)\s*\([^)]*\)\s*(const)?\s*(= 0)?\s*;')
class_pattern = re.compile(r'class\s+(\w+)\s*[:{]')

def find_virtual_classes():
    classes = {}
    for header in INCLUDE_DIR.rglob("*.h"):
        current_class = None
        with open(header) as f:
            for line in f:
                class_match = class_pattern.search(line)
                if class_match:
                    current_class = class_match.group(1)
                    classes[current_class] = {"file": header, "virtuals": []}
                elif current_class:
                    virt = virtual_pattern.search(line)
                    if virt:
                        classes[current_class]["virtuals"].append(line.strip())
    return classes

def has_cpp_file(class_name):
    # Look for a .cpp file containing that class name in the src directory
    for cpp in SRC_DIR.rglob("*.cpp"):
        with open(cpp) as f:
            content = f.read()
            if f"class {class_name}" in content or f"{class_name}::" in content:
                return True
    return False

def main():
    print("Scanning for classes with virtuals missing vtable implementations...\n")
    classes = find_virtual_classes()
    missing = []

    for class_name, meta in classes.items():
        if meta["virtuals"]:
            if not has_cpp_file(class_name):
                missing.append((class_name, meta["file"], meta["virtuals"]))

    if missing:
        for class_name, header, virtuals in missing:
            print(f"{class_name} has virtual functions but no matching .cpp file found.")
            print(f"  → Header: {header}")
            for virt in virtuals:
                print(f"    - {virt}")
            print()
    else:
        print("All virtual classes appear to have .cpp files. VTables should be fine.")

if __name__ == "__main__":
    main()
