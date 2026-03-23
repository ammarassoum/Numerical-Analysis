function result = gaussianQuadrature(f, a, b, n)
    % Implements Gaussian Quadrature for numerical integration
    % Inputs:
    %   f - Function handle
    %   a, b - Integration bounds
    %   n - Number of quadrature points
    % Output:
    %   result - Approximated integral value

    [nodes, weights] = lgwt(n, a, b); % Get nodes and weights for Gaussian quadrature
    result = sum(weights .* f(nodes));
end

function [x, w] = lgwt(n, a, b)
    % Generate nodes and weights for Gaussian quadrature
    % Adapted from Numerical Recipes
    
    x = cos(pi * (4*(1:n) - 1) ./ (4*n + 2))'; % Initial guess
    w = zeros(n, 1);
    max_iter = 100; tol = 1e-14;
    for k = 1:max_iter
        p0 = zeros(n, 1); p1 = ones(n, 1);
        for j = 1:n
            p2 = p0; p0 = p1;
            p1 = ((2*j - 1)*x.*p0 - (j - 1)*p2)/j;
        end
        dp = n*(p0 - x.*p1)./(1 - x.^2);
        x_new = x - p1 ./ dp;
        if max(abs(x_new - x)) < tol, break; end
        x = x_new;
    end
    w = 2 ./ ((1 - x.^2) .* dp.^2);
    x = (a + b)/2 + (b - a)/2 * x;
    w = (b - a)/2 * w;
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% f = @(x) x.^2;
% a = 0; b = 1; n = 3;
% result = gaussianQuadrature(f, a, b, n);
% disp(['Gaussian Quadrature Result: ', num2str(result)]);