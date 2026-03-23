function [L, U] = lu_crout(A)
    % Function to perform Crout's LU decomposition
    % Input: 
    %   A - square matrix (n x n)
    % Output: 
    %   L - Lower triangular matrix
    %   U - Upper triangular matrix

    % Get the size of the matrix
    [n, m] = size(A);
    
    % Ensure the matrix is square
    if n ~= m
        error('Matrix A must be square.');
    end

    % Initialize L and U matrices
    L = zeros(n);  % Lower triangular matrix
    U = eye(n);    % Upper triangular matrix (diagonal is 1)

    % Perform the decomposition
    for j = 1:n
        % Compute the L matrix (column-wise)
        for i = j:n
            sumL = 0;
            for k = 1:j-1
                sumL = sumL + L(i,k) * U(k,j);
            end
            L(i,j) = A(i,j) - sumL;
        end
        
        % Compute the U matrix (row-wise)
        for i = j+1:n
            sumU = 0;
            for k = 1:j-1
                sumU = sumU + L(j,k) * U(k,i);
            end
            U(j,i) = (A(j,i) - sumU) / L(j,j);
        end
    end
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% A = [4 6 10; 6 25 19; 10 19 62];
% [L, U] = lu_crout(A);
% disp(L)
% disp(U)