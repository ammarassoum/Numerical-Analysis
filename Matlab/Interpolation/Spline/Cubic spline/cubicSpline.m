function pp = cubicSpline(x_points, y_points)
    % Function for Cubic Spline Interpolation
    % Inputs:
    %   x_points - Known data points (1 x n)
    %   y_points - Function values at x_points (1 x n)
    % Output:
    %   pp - Piecewise polynomial structure

    pp = spline(x_points, y_points);
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% x_points = [0, 1, 2];
% y_points = [1, 3, 2];
% pp = cubicSpline(x_points, y_points);
% x = linspace(0, 2, 100);
% y = ppval(pp, x);
% plot(x_points, y_points, 'o', x, y, '-');
% title('Cubic Spline Interpolation');
