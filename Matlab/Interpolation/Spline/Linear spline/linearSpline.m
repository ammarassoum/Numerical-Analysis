function y = linearSpline(x, x_points, y_points)
    % Function for Linear Spline Interpolation
    % Inputs:
    %   x_points - Known data points (1 x n)
    %   y_points - Function values at x_points (1 x n)
    %   x - Point(s) to interpolate
    % Output:
    %   y - Interpolated value(s) at x

    n = length(x_points) - 1;
    y = zeros(size(x));
    for i = 1:n
        idx = x >= x_points(i) & x <= x_points(i+1);
        y(idx) = y_points(i) + (y_points(i+1) - y_points(i)) / ...
                 (x_points(i+1) - x_points(i)) * (x(idx) - x_points(i));
    end
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% x_points = [0, 1, 2];
% y_points = [1, 3, 2];
% x = 1.5;
% y = linearSpline(x, x_points, y_points);
% disp(['Linear spline interpolation at x = ', num2str(x), ': ', num2str(y)]);
