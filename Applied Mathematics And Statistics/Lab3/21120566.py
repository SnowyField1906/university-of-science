import numpy as np
import matplotlib.pyplot as plt

years = np.array([1971, 1972, 1974, 1978, 1982, 1985, 1989, 1993, 1997, 1999, 2000, 2002, 2003])
transistors = np.array([2250, 2500, 5000, 29000, 120000, 275000, 1180000, 3100000, 7500000, 24000000, 42000000, 220000000, 410000000])

X = np.column_stack((np.ones_like(years), years - 1970))

U, singular_values, VT = np.linalg.svd(X, full_matrices=False)
Sigma_plus = np.diag(1.0 / singular_values)
X_plus = VT.T @ Sigma_plus @ U.T

theta = X_plus @ np.log10(transistors)

predicted_transistors_2015 = 10 ** (theta[0] + theta[1] * (2015 - 1970))
transistors_z13 = 4e9

print("(theta_1, theta_2):", theta)
print("predicted transistors 2015:", predicted_transistors_2015)
print("number of IBM Z13 transistors:", transistors_z13)


# plot
plt.scatter(years, np.log10(transistors))
plt.legend()

plt.plot(years, theta[0] + theta[1] * (years - 1970), color='red')
plt.legend()

plt.scatter(2015, np.log10(predicted_transistors_2015), color='green')
plt.legend()
plt.show()