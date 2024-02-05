def can_rearrange_keys(T, test_cases):
    results = []

    for test_case in test_cases:
        N, M, C, S, F, corridors = test_case

        # Create a graph for the mootel
        graph = {i: [] for i in range(1, N + 1)}
        for u, v in corridors:
            graph[u].append(v)
            graph[v].append(u)

        # Function to check if there's a path from stall 1 to a given stall
        # under the constraint of having the correct key
        def is_path_exist(target_stall):
            visited = set()
            def dfs(node):
                if node == target_stall:
                    return True
                visited.add(node)
                for neighbor in graph[node]:
                    if neighbor not in visited and C[neighbor - 1] in keys_held and dfs(neighbor):
                        return True
                return False
            return dfs(1)

        # Determine which keys FJ can initially pick up in stall 1
        keys_held = {S[0]}
        for color in C[1:]:
            if color in keys_held:
                keys_held.add(color)

        # Check if FJ can deliver each key to its required stall
        possible = True
        for i in range(1, N):
            if S[i] != F[i] and not is_path_exist(i + 1):
                possible = False
                break

        results.append("YES" if possible else "NO")

    return results

# Test the function with the provided sample input
can_rearrange_keys(T, test_cases)
