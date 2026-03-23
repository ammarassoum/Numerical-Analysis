function df = backwardDifference(f, x, h)
    % Implements First-Order Backward Difference
    % Inputs:
    %   f - Function handle
    %   x - Point at which to compute the derivative
    %   h - Step size
    % Output:
    %   df - Approximated derivative at x
    
    df = (f(x) - f(x - h)) / h;
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% f = @(x) x.^2; % Function
% x = 2; h = 0.01; % Point and step size
% df = backwardDifference(f, x, h);
% disp(['Backward Difference Result: ', num2str(df)]);
