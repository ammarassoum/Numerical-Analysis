function result = simpson(f, a, b, n)
    % Implements Simpson's Rule for numerical integration
    % Inputs:
    %   f - Function handle
    %   a, b - Integration bounds
    %   n - Number of subintervals (must be even)
    % Output:
    %   result - Approximated integral value
    
    if mod(n, 2) ~= 0
        error('n must be an even number for Simpson’s rule.');
    end
    
    h = (b - a) / n; % Width of each subinterval
    x = a:h:b;       % Subinterval points
    y = f(x);        % Evaluate function at subinterval points
    
    result = h / 3 * (y(1) + 2 * sum(y(3:2:end-2)) + 4 * sum(y(2:2:end)) + y(end));
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% f = @(x) x.^2;
% a = 0; b = 1; n = 10;
% result = simpson(f, a, b, n);
% disp(['Simpson''s Rule Result: ', num2str(result)]);
