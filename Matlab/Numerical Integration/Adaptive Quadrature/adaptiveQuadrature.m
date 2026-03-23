function result = adaptiveQuadrature(f, a, b, tol)
    % Implements Adaptive Quadrature for numerical integration
    % Inputs:
    %   f - Function handle
    %   a, b - Integration bounds
    %   tol - Error tolerance
    % Output:
    %   result - Approximated integral value
    
    c = (a + b) / 2;
    approx1 = (b - a) * (f(a) + 4*f(c) + f(b)) / 6; % Single Simpson's rule
    approx2 = ((c - a) * (f(a) + 4*f((a+c)/2) + f(c)) + ...
               (b - c) * (f(c) + 4*f((c+b)/2) + f(b))) / 6; % Split interval
    
    if abs(approx2 - approx1) < 15 * tol
        result = approx2;
    else
        result = adaptiveQuadrature(f, a, c, tol/2) + adaptiveQuadrature(f, c, b, tol/2);
    end
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% f = @(x) x.^2;
% a = 0; b = 1; tol = 1e-5;
% result = adaptiveQuadrature(f, a, b, tol);
% disp(['Adaptive Quadrature Result: ', num2str(result)]);
