function x = backsub(U, b)
    % Function to solve Ux = b using Backward Substitution
    % Input:
    %   U - Upper triangular coefficient matrix (n x n)
    %   b - Right-hand side vector (n x 1)
    % Output:
    %   x - Solution vector (n x 1)

    n = length(b);
    x = zeros(n, 1); % Initialize solution vector

    % Iterate from the last row (n) down to the first row (1)
    for i = n:-1:1
        sum_val = 0;
        
        % Calculate summation of known values (U_ij * x_j)
        % Loop runs from j = i+1 to n
        for j = i+1:n
            sum_val = sum_val + U(i, j) * x(j);
        end
        
        % Check for division by zero
        if U(i, i) == 0
            error('Matrix is singular. Zero found on diagonal.');
        end

        % Compute x_i
        x(i) = (b(i) - sum_val) / U(i, i);
    end
end

% --- Example Execution (Run this in Command Window) ---
% U = [2, 1, 1;
%      0, 2, 1;
%      0, 0, 1];
% b = [4; 2; 2];
% x = backsub(U, b);
% disp('Solution vector x:');
% disp(x);