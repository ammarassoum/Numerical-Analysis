function y = lagrange(x, y_points, x_points)
    % Function for Lagrange Interpolation
    % Inputs:
    %   x_points - Known data points (1 x n)
    %   y_points - Function values at x_points (1 x n)
    %   x - Point(s) to interpolate
    % Output:
    %   y - Interpolated value(s) at x
    
    n = length(x_points);
    y = zeros(size(x));
    
    for i = 1:n
        L = ones(size(x));
        for j = 1:n
            if i ~= j
                L = L .* (x - x_points(j)) / (x_points(i) - x_points(j));
            end
        end
        y = y + L * y_points(i);
    end
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% x_points = [0, 1, 2];
% y_points = [1, 3, 2];
% x = 1.5;
% y = lagrange(x, y_points, x_points);
% disp(['Lagrange interpolation at x = ', num2str(x), ': ', num2str(y)]);