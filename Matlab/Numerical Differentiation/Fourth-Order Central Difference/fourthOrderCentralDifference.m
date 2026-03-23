function df = fourthOrderCentralDifference(f, x, h)
    % Implements Fourth-Order Central Difference
    % Inputs:
    %   f - Function handle
    %   x - Point at which to compute the derivative
    %   h - Step size
    % Output:
    %   df - Approximated derivative at x
    
    df = (-f(x + 2*h) + 8*f(x + h) - 8*f(x - h) + f(x - 2*h)) / (12 * h);
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% f = @(x) x.^2; % Function
% x = 2; h = 0.01; % Point and step size
% df = fourthOrderCentralDifference(f, x, h);
% disp(['Fourth-Order Central Difference Result: ', num2str(df)]);
