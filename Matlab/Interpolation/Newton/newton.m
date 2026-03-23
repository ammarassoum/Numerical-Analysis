function y = newton(x, y_points, x_points)
    % Function for Newton Interpolation
    % Inputs:
    %   x_points - Known data points (1 x n)
    %   y_points - Function values at x_points (1 x n)
    %   x - Point(s) to interpolate
    % Output:
    %   y - Interpolated value(s) at x

    n = length(x_points);
    diff_table = zeros(n, n);
    diff_table(:, 1) = y_points(:);
    
    % Construct divided difference table
    for j = 2:n
        for i = 1:n-j+1
            diff_table(i, j) = (diff_table(i+1, j-1) - diff_table(i, j-1)) / ...
                               (x_points(i+j-1) - x_points(i));
        end
    end

    % Perform interpolation
    y = diff_table(1, 1);
    product_term = 1;
    for i = 2:n
        product_term = product_term .* (x - x_points(i-1));
        y = y + product_term * diff_table(1, i);
    end
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% x_points = [0, 1, 2];
% y_points = [1, 3, 2];
% x = 1.5;
% y = newton(x, y_points, x_points);
% disp(['Newton interpolation at x = ', num2str(x), ': ', num2str(y)]);
