function df = richardsonExtrapolation(f, x, h)
    % Implements Richardson Extrapolation for Derivative Approximation
    % Inputs:
    %   f - Function handle
    %   x - Point at which to compute the derivative
    %   h - Initial step size
    % Output:
    %   df - Refined approximated derivative at x
    
    D1 = (f(x + h) - f(x - h)) / (2 * h);       % Central difference with step h
    D2 = (f(x + h/2) - f(x - h/2)) / h;         % Central difference with step h/2
    df = (4 * D2 - D1) / 3;                     % Richardson extrapolation
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% f = @(x) x.^2; % Function
% x = 2; h = 0.01; % Point and step size
% df = richardsonExtrapolation(f, x, h);
% disp(['Richardson Extrapolation Result: ', num2str(df)]);
