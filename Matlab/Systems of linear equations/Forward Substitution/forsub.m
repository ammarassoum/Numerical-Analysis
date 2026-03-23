function x = forsub(L, b)
    % Function to solve Lx = b using Forward Substitution
    % Input:
    %   L - Lower triangular coefficient matrix (n x n)
    %   b - Right-hand side vector (n x 1)
    % Output:
    %   x - Solution vector (n x 1)

    n = length(b);
    x = zeros(n, 1); % Initialize solution vector

    % Iterate over rows from 1 to n
    for i = 1:n
        sum_val = 0;
        
        % Calculate summation of known values (L_ij * x_j)
        % Loop runs from j=1 to i-1
        for j = 1:i-1
            sum_val = sum_val + L(i, j) * x(j);
        end
        
        % Check for division by zero
        if L(i, i) == 0
            error('Matrix is singular. Zero found on diagonal.');
        end

        % Compute x_i
        x(i) = (b(i) - sum_val) / L(i, i);
    end
end

% --- Example Execution (Run this in Command Window) ---
% L = [3, 0, 0; 
%      2, 4, 0; 
%      1, 2, 5];
% b = [6; 8; 10];
% x = forsub(L, b);
% disp('Solution vector x:');
% disp(x);