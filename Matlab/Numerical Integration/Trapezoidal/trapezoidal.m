function result = trapezoidal(f, a, b, n)
    % Implements the Trapezoidal Rule for numerical integration
    % Inputs:
    %   f - Function handle
    %   a, b - Integration bounds
    %   n - Number of subintervals
    % Output:
    %   result - Approximated integral value
    
    h = (b - a) / n; % Width of each subinterval
    x = a:h:b;       % Subinterval points
    y = f(x);        % Evaluate function at subinterval points
    
    result = h * (0.5 * y(1) + sum(y(2:end-1)) + 0.5 * y(end));
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
f = @(x) x.^2;
a = 0; b = 1; n = 10;
result = trapezoidalRule(f, a, b, n);
disp(['Trapezoidal Rule Result: ', num2str(result)]);
