function L = cholesky(A)
    % Function to perform Cholesky LU decomposition
    % Input:
    %   A - symmetric positive-definite matrix (n x n)
    % Output:
    %   L - Lower triangular matrix such that A = L * L'

    % Get the size of the matrix
    [n, m] = size(A);

    % Ensure the matrix is square
    if n ~= m
        error('Matrix A must be square.');
    end

    % Ensure the matrix is symmetric positive definite
    if ~isequal(A, A') || any(eig(A) <= 0)
        error('Matrix A must be symmetric and positive definite.');
    end

    % Initialize L matrix
    L = zeros(n);

    % Perform decomposition
    for i = 1:n
        for j = 1:i
            if i == j
                % Diagonal elements of L
                sumDiag = 0;
                for k = 1:j-1
                    sumDiag = sumDiag + L(j,k)^2;
                end
                L(i,j) = sqrt(A(i,i) - sumDiag);
            else
                % Off-diagonal elements of L
                sumOffDiag = 0;
                for k = 1:j-1
                    sumOffDiag = sumOffDiag + L(i,k) * L(j,k);
                end
                L(i,j) = (A(i,j) - sumOffDiag) / L(j,j);
            end
        end
    end
end


% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% A = [4 6 10; 6 25 19; 10 19 62];
% L = cholesky(A);
% disp(L)
