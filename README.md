# Numerical Analysis Toolbox

A comprehensive collection of numerical methods implemented in **C**, **MATLAB**, and **Python**. This repository serves as a reference for students, engineers, and researchers to understand and apply fundamental numerical algorithms for solving mathematical problems.

## 🚀 Overview

Numerical analysis is the study of algorithms that use numerical approximation for the problems of mathematical analysis. This repository provides clean, documented, and ready-to-use implementations across three major programming environments, allowing for performance comparison and cross-platform utility.

## 📂 Repository Structure

The project is organized by mathematical category. Each category contains subdirectories for specific algorithms, available in **C**, **MATLAB**, and **Python**.

### 1. Nonlinear Equations (root finding)
Methods for finding roots of equations $f(x) = 0$.
*   **Aitken’s Delta-Squared Process**
*   **Bisection Method**
*   **Fixed-Point Iteration**
*   **Newton-Raphson Method**
*   **Regula-Falsi (False Position)**
*   **Secant Method**

### 2. Systems of Linear Equations
Algorithms for solving $Ax = b$ and matrix decompositions.
*   **Forward & Backward Substitution**
*   **Gaussian Elimination**
*   **Iterative Methods:** Jacobi and Gauss-Seidel
*   **LU Decomposition:**
    *   Cholesky Decomposition
    *   Crout Decomposition
    *   Doolittle Decomposition

### 3. Interpolation
Approximating functions through a discrete set of data points.
*   **Chebyshev Interpolation Nodes**
*   **Lagrange Interpolation**
*   **Newton’s Divided Differences**
*   **Spline Interpolation:**
    *   Linear Spline
    *   Cubic Spline
    *   Hermite Spline

### 4. Numerical Differentiation
Approximating derivatives using finite difference formulas.
*   **First-Order:** Forward and Backward Difference
*   **Second-Order:** Central Difference
*   **Fourth-Order:** Central Difference
*   **Richardson Extrapolation**

### 5. Numerical Integration
Methods for calculating the definite integral of a function.
*   **Newton-Cotes:** Trapezoidal Rule, Simpson 1/3’s Rule
*   **Quadrature:** Gaussian Quadrature, Adaptive Quadrature
*   **Advanced:** Romberg Integration, Midpoint Rule
*   **Stochastic:** Monte Carlo Integration

### 6. Ordinary Differential Equations (ODE)
Solving initial value problems $y' = f(t, y)$.
*   **Euler’s Method** (Standard and Improved)
*   **Runge-Kutta Methods:** 2nd Order and 4th Order
*   **Taylor Series Methods:** 2nd Order and 3rd Order

---

## 🛠️ Languages and Requirements

| Language | Requirements |
| :--- | :--- |
| **C** | `gcc` or any standard C compiler (e.g., MinGW, Clang) |
| **MATLAB** | R2020a or newer |
| **Python** | Python 3.x, `numpy`, `matplotlib`, `scipy` |

---

## 📖 How to Use

### C Implementation
Navigate to the desired directory and compile using `gcc`:
```bash
cd C/Nonlinear\ equations/Newton-Raphson
gcc main.c -o newton -lm
./newton
```

### MATLAB Implementation
Add the directory to your path and call the function from the Command Window:
```matlab
% Example:
[t, y] = taylor2(@f, @df, t0, y0, h, t_end);
```

### Python Implementation
Ensure you have the required dependencies installed:
```bash
pip install numpy matplotlib
python method_name.py
```

---

## 📝 Example: Taylor 2nd Order (Python)
```python
def taylor2(f, df, t0, y0, h, t_end):
    t = np.arange(t0, t_end + h, h)
    y = np.zeros(len(t))
    y[0] = y0
    for i in range(len(t) - 1):
        y[i+1] = y[i] + h*f(t[i], y[i]) + (h**2 / 2)*df(t[i], y[i])
    return t, y
```

## 🤝 Contributing
Contributions are welcome! If you find a bug or want to add a new method:
1. Fork the project.
2. Create your Feature Branch (`git checkout -b feature/NewMethod`).
3. Commit your changes (`git commit -m 'Add some NewMethod'`).
4. Push to the Branch (`git push origin feature/NewMethod`).
5. Open a Pull Request.

## 📄 License
Distributed under the MIT License. See `LICENSE` for more information.

---
**Author:** Ammar Assoum  
**GitHub:** https://github.com/ammarassoum/
