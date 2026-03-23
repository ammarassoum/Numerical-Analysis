function df = forwardDifference(f, x, h)
    % Implements First-Order Forward Difference
    % Inputs:
    %   f - Function handle
    %   x - Point at which to compute the derivative
    %   h - Step size
    % Output:
    %   df - Approximated derivative at x
    
    df = (f(x + h) - f(x)) / h;
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% f = @(x) x.^2; % Function
% x = 2; h = 0.01; % Point and step size
% df = forwardDifference(f, x, h);
% disp(['Forward Difference Result: ', num2str(df)]);
