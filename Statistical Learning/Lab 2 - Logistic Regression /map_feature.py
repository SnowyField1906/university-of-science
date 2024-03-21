import numpy as np
import json
from sklearn.model_selection import train_test_split

def map_feature(x1, x2):
    degree = 6
    out = np.ones([len(x1), int((degree + 1) * (degree + 2) / 2)])
    idx = 1

    for i in range(1, degree + 1):
        for j in range(0, i + 1):
            a1 = x1 ** (i - j)
            a2 = x2 ** j
            out[:, idx] = a1 * a2
            idx += 1

    return out

def sigmoid(z):
    return 1 / (1 + np.exp(-z))

def compute_cost(X, y, theta, _lambda):
    m = len(y)
    h = sigmoid(np.dot(X, theta))
    J = (1 / m) * np.sum(-y * np.log(h) - (1 - y) * np.log(1 - h))
    J += (_lambda / (2 * m)) * np.sum(theta[1:] ** 2)
    return J

def compute_gradient(X, y, theta, _lambda):
    m = len(y)
    h = sigmoid(np.dot(X, theta))
    grad = (1 / m) * np.dot(X.T, (h - y))
    grad[1:] += (_lambda / m) * theta[1:]
    return grad

def gradient_descent(X, y, theta, alpha, _lambda, num_iters):
    for i in range(num_iters):
        grad = compute_gradient(X, y, theta, _lambda)
        theta -= alpha * grad

        """
        Considering turning off this,
        because 10.000 iterations is too many,
        it has converged before you can see any
        change from the loss function at the last
        iterations on the console.
        """

        loss = compute_cost(X, y, theta, _lambda)
        print(f'Iter {i + 1}, loss = {loss}')

    return theta

def predict(X, theta):
    h = sigmoid(np.dot(X, theta))
    return (h >= 0.5).astype(int)

def evaluate(y_true, y_pred):
    accuracy = np.mean(y_true == y_pred)

    tp = np.sum((y_true == 1) & (y_pred == 1))
    fp = np.sum((y_true == 0) & (y_pred == 1))
    fn = np.sum((y_true == 1) & (y_pred == 0))

    precision = tp / (tp + fp)
    recall = tp / (tp + fn)
    f1_score = 2 * precision * recall / (precision + recall)

    return accuracy, precision, recall, f1_score

if __name__ == "__main__":
    data = np.loadtxt('training_data.txt', delimiter=',')
    X = data[:, :2]
    y = data[:, 2]

    X_mapped = map_feature(X[:, 0], X[:, 1])

    X_train, X_test, y_train, y_test = train_test_split(X_mapped, y, test_size=0.2, random_state=42)
    
    theta = np.zeros(X_mapped.shape[1])

    with open('config.json',) as f:
        configs = json.load(f)

    theta = gradient_descent(
        X_train,
        y_train,
        theta,
        configs['Alpha'],
        configs['Lambda'],
        configs['NumIter']
    )

    with open('model.json', 'w') as f:
        f.write(json.dumps(theta.tolist()))

    y_pred = predict(X_test, theta)
    accuracy, precision, recall, f1_score = evaluate(y_test, y_pred)

    with open('classification_report.json', 'w') as f:
        f.write(json.dumps({
            "accuracy": accuracy,
            "precision": precision,
            "recall": recall,
            "f1_score": f1_score
        }))