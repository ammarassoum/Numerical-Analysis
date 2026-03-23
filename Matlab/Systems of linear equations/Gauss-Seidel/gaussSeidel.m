function x = gaussSeidel(A, b, tol, maxIter)
    % Function to solve Ax = b using Gauss-Seidel iteration
    % Input:
    %   A - Coefficient matrix (n x n)
    %   b - Right-hand side vector (n x 1)
    %   tol - Convergence tolerance
    %   maxIter - Maximum number of iterations
    % Output:
    %   x - Solution vector (n x 1)

    n = length(b);
    x = zeros(n, 1); % Initial guess (zeros)

    for iter = 1:maxIter
        x_old = x; % Store the previous iteration

        for i = 1:n
            sum = 0;
            for j = 1:n
                if j ~= i
                    sum = sum + A(i, j) * x(j);
                end
            end
            x(i) = (b(i) - sum) / A(i, i);
        end

        % Check for convergence
        if norm(x - x_old, inf) < tol
            fprintf('Gauss-Seidel converged in %d iterations.\n', iter);
            return;
        end
    end

    warning('Gauss-Seidel method did not converge within the maximum iterations.');
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% A = [4, -1, 0; -1, 4, -1; 0, -1, 4];
% b = [15; 10; 10];
% tol = 1e-5;
% maxIter = 100;
% x = gaussSeidel(A, b, tol, maxIter);
% disp('Solution using Gauss-Seidel Method:');
% disp(x);