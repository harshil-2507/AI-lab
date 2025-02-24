import numpy as np

logic_gates = {
    "x∧y∧z": {
        "inputs": np.array([
            [0, 0, 0], [0, 0, 1], [0, 1, 0], [0, 1, 1],
            [1, 0, 0], [1, 0, 1], [1, 1, 0], [1, 1, 1]
        ]),
        "outputs": np.array([0, 0, 0, 0, 0, 0, 0, 1])
    },
    "x∨y∨z": {
        "inputs": np.array([
            [0, 0, 0], [0, 0, 1], [0, 1, 0], [0, 1, 1],
            [1, 0, 0], [1, 0, 1], [1, 1, 0], [1, 1, 1]
        ]),
        "outputs": np.array([0, 1, 1, 1, 1, 1, 1, 1])
    }
}

def mp_model(inputs, weights, threshold):
    results = []
    for x in inputs:
        activation = np.dot(weights, x)
        results.append(1 if activation >= threshold else 0)
    return results

def perceptron_train(inputs, outputs, learning_rate=0.1, epochs=20, initial_weights=None):
    weights = initial_weights if initial_weights is not None else np.zeros(inputs.shape[1] + 1)
    for _ in range(epochs):
        for i in range(len(inputs)):
            x = np.insert(inputs[i], 0, 1)
            y = np.dot(weights, x) >= 0
            error = outputs[i] - y
            weights += learning_rate * error * x
    return weights

mp_weights = {
    "x∧y∧z": ([1, 1, 1], 3),
    "x∨y∨z": ([1, 1, 1], 1)
}

initial_weights_list = [
    np.array([0.5, 0.5, 0.5, 0.5]),
    np.array([-0.5, -0.5, -0.5, -0.5]),
    np.array([0, 0, 0, 0])
]

print("Fixed Weights (MP Model):")
for gate, (weights, threshold) in mp_weights.items():
    inputs = logic_gates[gate]["inputs"]
    outputs = mp_model(inputs, weights, threshold)
    print(f"{gate} => Weights: {weights}, Threshold: {threshold}, Output: {outputs}")

print("\nTrained Weights (Rosenblatt’s Model with different initial weights):")
for gate, data in logic_gates.items():
    for idx, init_weights in enumerate(initial_weights_list):
        trained_weights = perceptron_train(data["inputs"], data["outputs"], initial_weights=init_weights)
        print(f"Initial Weights {idx+1} for {gate}: {init_weights}, Trained Weights: {trained_weights}")
