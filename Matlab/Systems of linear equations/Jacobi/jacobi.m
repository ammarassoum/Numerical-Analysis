function x = jacobi(A, b, tol, maxIter)
    % Function to solve Ax = b using Jacobi iteration
    % Input:
    %   A - Coefficient matrix (n x n)
    %   b - Right-hand side vector (n x 1)
    %   tol - Convergence tolerance
    %   maxIter - Maximum number of iterations
    % Output:
    %   x - Solution vector (n x 1)

    n = length(b);
    x = zeros(n, 1); % Initial guess (zeros)
    x_old = x;

    for iter = 1:maxIter
        for i = 1:n
            sum = 0;
            for j = 1:n
                if j ~= i
                    sum = sum + A(i, j) * x_old(j);
                end
            end
            x(i) = (b(i) - sum) / A(i, i);
        end
        
        % Check for convergence
        if norm(x - x_old, inf) < tol
            fprintf('Jacobi converged in %d iterations.\n', iter);
            return;
        end

        % Update for next iteration
        x_old = x;
    end

    warning('Jacobi method did not converge within the maximum iterations.');
end


% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% A = [4, -1, 0; -1, 4, -1; 0, -1, 4];
% b = [15; 10; 10];
% tol = 1e-5;
% maxIter = 100;
% x = jacobi(A, b, tol, maxIter);
% disp('Solution using Jacobi Method:');
% disp(x);