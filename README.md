# Numerical Analysis Toolbox

A comprehensive collection of numerical methods implemented in **C**, **MATLAB**, and **Python**. This repository serves as a reference for students, engineers, and researchers to understand and apply fundamental numerical algorithms for solving mathematical problems.

## 🚀 Overview

Numerical analysis is the study of algorithms that use numerical approximation for the problems of mathematical analysis. This repository provides clean, documented, and ready-to-use implementations across three major programming environments, allowing for performance comparison and cross-platform utility.

## 📂 Repository Structure

The project is organized by mathematical category. Each category contains subdirectories for specific algorithms, available in [**C**](C), [**MATLAB**](Matlab), and [**Python**](Python).

### 1. Nonlinear Equations (root finding)
Methods for finding roots of equations $f(x) = 0$.
*   **Aitken’s Delta-Squared Process:** A technique used to accelerate the rate of convergence of a sequence that is already converging linearly.
*   **Bisection Method:** A robust bracketing method that repeatedly halves an interval containing a root until the desired precision is reached.
*   **Fixed-Point Iteration:** Finds a root by transforming $f(x)=0$ into the form $x = g(x)$ and iteratively applying the function to its own output.
*   **Newton-Raphson Method:** An efficient algorithm that uses the function's derivative to find roots via tangent line approximations.
*   **Regula-Falsi (False Position):** A bracketing method similar to bisection that uses linear interpolation between endpoints to converge on a root more quickly.
*   **Secant Method:** A root-finding algorithm that uses a secant line through two points to approximate the derivative, requiring only the function values.

### 2. Systems of Linear Equations
Algorithms for solving $Ax = b$ and matrix decompositions.
*   **Forward & Backward Substitution:** Efficient techniques used to solve linear systems with lower or upper triangular matrices by solving for variables one by one.
*   **Gaussian Elimination:** A systematic algorithm for solving linear equations by applying row operations to transform a matrix into row-echelon form.
*   **Iterative Methods (Jacobi and Gauss-Seidel):** Algorithms that solve linear systems by starting with an initial guess and repeatedly refining the values until they converge to a solution.
*   **LU Decomposition:** Factors a square matrix into the product of a Lower ($L$) and an Upper ($U$) triangular matrix to simplify repeated calculations.
    *   Cholesky Decomposition: A specialized, efficient LU decomposition for symmetric, positive-definite matrices where the matrix is factored into $L \cdot L^T$.
    *   Crout Decomposition: A variation of LU decomposition where the upper triangular matrix ($U$) is designed to have ones on its main diagonal.
    *   Doolittle Decomposition: A variation of LU decomposition where the lower triangular matrix ($L$) is designed to have ones on its main diagonal.

### 3. Interpolation
Approximating functions through a discrete set of data points.
*   **Chebyshev Interpolation Nodes:** Specific points chosen within an interval to minimize the maximum interpolation error and prevent the Runge phenomenon (oscillations at the edges).
*   **Lagrange Interpolation:** A direct method for constructing a unique polynomial that passes through a given set of data points using a linear combination of basis polynomials.
*   **Newton’s Divided Differences:** An efficient, recursive algorithm for building interpolating polynomials that allows for the easy addition of new data points without recomputing the entire system.
*   **Spline Interpolation:** A method that fits low-degree piecewise polynomials between adjacent data points to create a smooth curve while avoiding the instability of high-degree polynomials.
    *   Linear Spline: The simplest form of spline interpolation, which connects data points with straight-line segments.
    *   Cubic Spline: A sophisticated piecewise method that uses third-degree polynomials to ensure a smooth curve with continuous first and second derivatives at every node.
    *   Hermite Spline: An interpolation technique that ensures a high degree of smoothness by matching both the function values and their derivatives at each data point.

### 4. Numerical Differentiation
Approximating derivatives using finite difference formulas.
*   **First-Order Forward and Backward Difference:** Basic approximations that estimate the derivative using the function value at a point and one adjacent point (either ahead or behind).
*   **Second-Order Central Difference:** A symmetric method that uses points on both sides of a value to cancel out the first-order error, providing $O(h^2)$ accuracy.
*   **Fourth-Order Central Difference:** A high-precision formula utilizing four neighboring points to achieve a very low error rate of $O(h^4)$.
*   **Richardson Extrapolation:** A sequence acceleration technique that combines two lower-order approximations (at different step sizes) to eliminate the leading error terms and produce a much more accurate derivative.

### 5. Numerical Integration
Methods for calculating the definite integral of a function.

*   **Trapezoidal Rule:** A simple method that approximates the area under a curve by dividing it into trapezoids, connecting data points with straight-line segments.
*   **Simpson’s 1/3 Rule:** A more accurate approach that fits second-order parabolas through groups of three equally spaced points to estimate the integral.
*   **Gaussian Quadrature:** A high-precision technique that optimally selects non-equally spaced points and weights to exactly integrate polynomials of a specific degree.
*   **Adaptive Quadrature:** An intelligent algorithm that automatically sub-divides the integration interval, using more points in regions where the function changes rapidly to ensure a target accuracy.
*   **Romberg Integration:** A method that applies Richardson extrapolation to the Trapezoidal rule to systematically eliminate error terms and achieve high-order precision.
*   **Midpoint Rule:** An integration formula that estimates the area of each sub-interval using the function value at its center, often serving as a foundation for more complex methods.
*   **Monte Carlo Integration:** A stochastic method that uses random sampling and statistical averages to estimate integrals, especially effective for complex domains or high-dimensional problems.

### 6. Ordinary Differential Equations (ODE)
Solving initial value problems $y' = f(t, y)$.

*   **Standard Euler’s Method:** The simplest first-order numerical procedure for solving ODEs by taking small steps in the direction of the local tangent.
*   **Improved Euler (Heun’s Method):** A predictor-corrector approach that uses the average of the slopes at the start and end of a step to achieve second-order accuracy.
*   **Runge-Kutta 2nd Order (RK2):** A family of methods that use an intermediate midpoint slope to provide better accuracy than standard Euler with the same step size.
*   **Runge-Kutta 4th Order (RK4):** The industry-standard solver that calculates a weighted average of four different slopes to achieve high precision and numerical stability.
*   **Taylor 2nd and 3rd Order Methods:** High-accuracy techniques that utilize the second and third derivatives of the function to follow the mathematical curve of the solution more closely than linear approximations.

---

## 🛠️ Languages and Requirements

| Language | Requirements |
| :--- | :--- |
| **C** | `gcc` or any C compiler or IDE (e.g., MinGW, Clang, CodeBlocks, OnlineGDB) |
| **MATLAB** | R2020a or newer (or **GNU Octave**) | 
| **Python** | Python 3.x, `numpy`, `matplotlib`, `scipy` |

---

## 📖 How to Use

### C Implementation
Navigate to the desired directory and compile using `gcc`:
```bash
cd "C/Nonlinear equations/Newton-Raphson"
gcc newton.c -o newton -lm
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
