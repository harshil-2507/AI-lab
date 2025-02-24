import numpy as np

logic_gates = {
    "x∧y": {
        "inputs": np.array([[0, 0], [0, 1], [1, 0], [1, 1]]),
        "outputs": np.array([0, 0, 0, 1])
    },
    "x∧~y": {
        "inputs": np.array([[0, 0], [0, 1], [1, 0], [1, 1]]),
        "outputs": np.array([0, 1, 0, 0])
    },
    "~x∧y": {
        "inputs": np.array([[0, 0], [0, 1], [1, 0], [1, 1]]),
        "outputs": np.array([0, 0, 1, 0])
    },
    "~x∧~y": {
        "inputs": np.array([[0, 0], [0, 1], [1, 0], [1, 1]]),
        "outputs": np.array([1, 0, 0, 0])
    },
    "x∨y": {
        "inputs": np.array([[0, 0], [0, 1], [1, 0], [1, 1]]),
        "outputs": np.array([0, 1, 1, 1])
    },
    "x∨~y": {
        "inputs": np.array([[0, 0], [0, 1], [1, 0], [1, 1]]),
        "outputs": np.array([1, 1, 1, 0])
    },
    "~x∨y": {
        "inputs": np.array([[0, 0], [0, 1], [1, 0], [1, 1]]),
        "outputs": np.array([1, 0, 1, 1])
    },
    "~x∨~y": {
        "inputs": np.array([[0, 0], [0, 1], [1, 0], [1, 1]]),
        "outputs": np.array([1, 1, 1, 0])
    }
}

def mp_model(inputs, weights, threshold):
    results = []
    for x in inputs:
        activation = np.dot(weights, x)
        results.append(1 if activation >= threshold else 0)
    return results


def perceptron_train(inputs, outputs, learning_rate=0.1, epochs=20):
    weights = np.zeros(inputs.shape[1] + 1)  
    for _ in range(epochs):
        for i in range(len(inputs)):
            x = np.insert(inputs[i], 0, 1)  
            y = np.dot(weights, x) >= 0  
            error = outputs[i] - y
            weights += learning_rate * error * x
    return weights


mp_weights = {
    "x∧y": ([1, 1], 2),
    "x∧~y": ([1, -1], 1),
    "~x∧y": ([-1, 1], 1),
    "~x∧~y": ([-1, -1], -1),
    "x∨y": ([1, 1], 1),
    "x∨~y": ([1, -1], 0),
    "~x∨y": ([-1, 1], 0),
    "~x∨~y": ([-1, -1], 0)
}

print("Fixed Weights (MP Model):")
for gate, (weights, threshold) in mp_weights.items():
    inputs = logic_gates[gate]["inputs"]
    outputs = mp_model(inputs, weights, threshold)
    print(f"{gate} => Weights: {weights}, Threshold: {threshold}, Output: {outputs}")

print("\nTrained Weights (Rosenblatt’s Model):")
for gate, data in logic_gates.items():
    trained_weights = perceptron_train(data["inputs"], data["outputs"])
    print(f"Weights for {gate}: {trained_weights}")


