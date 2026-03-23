function result = monteCarlo(f, a, b, n)
    % Implements Monte Carlo Integration for numerical integration
    % Inputs:
    %   f - Function handle
    %   a, b - Integration bounds
    %   n - Number of random samples
    % Output:
    %   result - Approximated integral value
    
    x = a + (b - a) * rand(1, n);
    result = (b - a) * mean(f(x));
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% f = @(x) x.^2;
% a = 0; b = 1; n = 10000;
% result = monteCarlo(f, a, b, n);
% disp(['Monte Carlo Integration Result: ', num2str(result)]);
