function [x_cheb, y_cheb] = chebyshev(func, n, a, b)
    % Function for Chebyshev Interpolation
    % Inputs:
    %   func - Function handle to interpolate
    %   n - Number of Chebyshev points
    %   a, b - Interval [a, b]
    % Outputs:
    %   x_cheb - Chebyshev nodes
    %   y_cheb - Function values at Chebyshev nodes

    x_cheb = 0.5 * ((b - a) * cos((2*(1:n) - 1) * pi / (2*n)) + (b + a));
    y_cheb = func(x_cheb);
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% func = @(x) 1./(1 + x.^2); % Runge's function
% a = -5;
% b = 5;
% n = 10;
% [x_cheb, y_cheb] = chebyshev(func, n, a, b);
% disp('Chebyshev nodes and function values:');
% disp([x_cheb', y_cheb']);
