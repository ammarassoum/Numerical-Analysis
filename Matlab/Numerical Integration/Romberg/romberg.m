function result = romberg(f, a, b, m)
    % Implements Romberg Integration for numerical integration
    % Inputs:
    %   f - Function handle
    %   a, b - Integration bounds
    %   m - Maximum number of levels
    % Output:
    %   result - Approximated integral value
    
    R = zeros(m, m);
    h = (b - a);
    R(1, 1) = h / 2 * (f(a) + f(b));
    
    for k = 2:m
        h = h / 2;
        summation = sum(f(a + h:2*h:b - h));
        R(k, 1) = 0.5 * R(k-1, 1) + h * summation;
        
        for j = 2:k
            R(k, j) = R(k, j-1) + (R(k, j-1) - R(k-1, j-1)) / (4^(j-1) - 1);
        end
    end
    
    result = R(m, m);
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% f = @(x) x.^2;
% a = 0; b = 1; m = 4;
% result = romberg(f, a, b, m);
% disp(['Romberg Integration Result: ', num2str(result)]);
