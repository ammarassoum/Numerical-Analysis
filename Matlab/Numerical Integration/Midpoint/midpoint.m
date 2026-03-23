function result = midpoint(f, a, b, n)
    % Implements the Midpoint Rule for numerical integration
    % Inputs:
    %   f - Function handle
    %   a, b - Integration bounds
    %   n - Number of subintervals
    % Output:
    %   result - Approximated integral value
    
    h = (b - a) / n; % Width of each subinterval
    midpoints = a + h/2:h:b - h/2; % Midpoints of subintervals
    y = f(midpoints); % Evaluate function at midpoints
    
    result = h * sum(y);
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% f = @(x) x.^2;
% a = 0; b = 1; n = 10;
% result = midpoint(f, a, b, n);
% disp(['Midpoint Rule Result: ', num2str(result)]);
