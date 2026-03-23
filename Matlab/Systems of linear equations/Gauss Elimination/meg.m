function x = meg(A, b)
    % Function to solve a system of linear equations Ax = b using Gauss Elimination
    % Input:
    %   A - Coefficient matrix (n x n)
    %   b - Right-hand side vector (n x 1)
    % Output:
    %   x - Solution vector (n x 1)

    % Augmented matrix
    Ab = [A, b];
    n = size(A, 1);

    % Forward Elimination
    for i = 1:n-1
        % Pivoting
        for j = i+1:n
            factor = Ab(j,i) / Ab(i,i);
            Ab(j, i:end) = Ab(j, i:end) - factor * Ab(i, i:end);
        end
    end

    % Back Substitution
    x = zeros(n, 1);
    x(n) = Ab(n, end) / Ab(n, n);
    for i = n-1:-1:1
        x(i) = (Ab(i, end) - Ab(i, i+1:n) * x(i+1:n)) / Ab(i, i);
    end
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% A = [2, -1, 1; 3, 3, 9; 3, 3, 5];
% b = [2; -1; 1];
% x = meg(A, b);
% disp('Solution using Gauss Elimination:');
% disp(x);