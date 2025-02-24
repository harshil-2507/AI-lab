import numpy as np
from sklearn.neural_network import MLPClassifier

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
    },
    "x XOR y": {
        "inputs": np.array([
            [0, 0], [0, 1], [1, 0], [1, 1]
        ]),
        "outputs": np.array([0, 1, 1, 0])
    }
}

def train_mlp(inputs, outputs):
    mlp = MLPClassifier(hidden_layer_sizes=(4,), activation='relu', max_iter=1000, solver='adam', random_state=42)
    mlp.fit(inputs, outputs)
    return mlp

print("MLP Model Results:")
for gate, data in logic_gates.items():
    mlp_model = train_mlp(data["inputs"], data["outputs"])
    predictions = mlp_model.predict(data["inputs"])
    print(f"{gate} => Predicted Outputs: {predictions}")
