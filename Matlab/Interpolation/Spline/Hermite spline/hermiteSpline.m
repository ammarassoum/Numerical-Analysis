function pp = hermiteSpline(x_points, y_points, slopes)
    % Function for Hermite Spline Interpolation
    % Inputs:
    %   x_points - Known data points (1 x n)
    %   y_points - Function values at x_points (1 x n)
    %   slopes - Slopes (derivatives) at x_points (1 x n)
    % Output:
    %   pp - Piecewise polynomial structure

    pp = pchip(x_points, [y_points; slopes]);
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% x_points = [0, 1, 2];
% y_points = [1, 3, 2];
% slopes = [0, 1, -1];
% pp = hermiteSpline(x_points, y_points, slopes);
% x = linspace(0, 2, 100);
% y = ppval(pp, x);
% plot(x_points, y_points, 'o', x, y, '-');
% title('Hermite Spline Interpolation');
