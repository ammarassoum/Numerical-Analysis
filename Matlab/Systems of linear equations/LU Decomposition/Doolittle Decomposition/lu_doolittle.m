function [L, U] = lu_doolittle(A)
    % Function to perform Doolittle's LU decomposition
    % Input:
    %   A - square matrix (n x n)
    % Output:
    %   L - Lower triangular matrix with unit diagonal
    %   U - Upper triangular matrix

    % Get the size of the matrix
    [n, m] = size(A);

    % Ensure the matrix is square
    if n ~= m
        error('Matrix A must be square.');
    end

    % Initialize L and U matrices
    L = eye(n); % Lower triangular matrix with 1's on the diagonal
    U = zeros(n); % Upper triangular matrix

    % Perform decomposition
    for j = 1:n
        % Compute U (row by row)
        for i = 1:j
            sumU = 0;
            for k = 1:i-1
                sumU = sumU + L(i,k) * U(k,j);
            end
            U(i,j) = A(i,j) - sumU;
        end

        % Compute L (column by column)
        for i = j+1:n
            sumL = 0;
            for k = 1:j-1
                sumL = sumL + L(i,k) * U(k,j);
            end
            L(i,j) = (A(i,j) - sumL) / U(j,j);
        end
    end
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% A = [4 6 10; 6 25 19; 10 19 62];
% [L, U] = lu_doolittle(A);
% disp(L)
% disp(U)