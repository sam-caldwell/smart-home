#!/usr/bin/env python3
import os
import subprocess
import sys
import re
from collections import defaultdict

def run_preprocessor(file):
    """Run g++ -E -H and capture include tree from stderr."""
    cmd = ['g++', '-E', '-H', file, '-o', os.devnull]
    proc = subprocess.run(cmd, stderr=subprocess.PIPE, stdout=subprocess.DEVNULL, text=True)
    return proc.stderr.splitlines()

def parse_includes(stderr_lines):
    """Build an include graph from g++ -H output."""
    graph = defaultdict(set)
    stack = []

    for line in stderr_lines:
        match = re.match(r'^(\.+) (.+)$', line)
        if not match:
            continue

        depth = len(match.group(1))
        header = os.path.normpath(match.group(2))

        while len(stack) >= depth:
            stack.pop()

        if stack:
            graph[stack[-1]].add(header)

        stack.append(header)

    return graph

def find_cycles(graph):
    """Detect cycles in a directed graph using DFS."""
    visited, stack, cycles = set(), [], []

    def dfs(node, path):
        if node in path:
            idx = path.index(node)
            cycles.append(path[idx:] + [node])
            return
        if node in visited:
            return
        visited.add(node)
        path.append(node)
        for neighbor in graph.get(node, []):
            dfs(neighbor, path)
        path.pop()

    for node in graph:
        dfs(node, [])

    return cycles

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 gen_include_graph.py <file1.cpp> [file2.cpp ...]")
        sys.exit(1)

    full_graph = defaultdict(set)
    for f in sys.argv[1:]:
        print(f"Analyzing {f}...")
        lines = run_preprocessor(f)
        graph = parse_includes(lines)
        for k, v in graph.items():
            full_graph[k].update(v)

    cycles = find_cycles(full_graph)

    print("\nInclude cycles found:")
    if not cycles:
        print("  None.")
    else:
        for cycle in cycles:
            print("  " + " -> ".join(cycle))

if __name__ == '__main__':
    main()
