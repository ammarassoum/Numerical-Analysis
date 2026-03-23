function [root] = newton(x0, error)
% Returns the root of the equation x^3 - x^2 + 2 = 0 using the Newton-Raphson method

while true
    x1 = x0 - f(x0)/fprime(x0);
    if abs(x1 - x0) < error
        break
    end
    x0 = x1;
end

root = x1;

function [y] = f(x)
    y = x^3 - x^2 + 2;
end

function [y] = fprime(x)
    y = 3*x^2 - 2*x;
end

end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% x0 = -1.5, error = 0.0001;
% root = newton(x0, error);
% disp(['The root is: ' num2str(root,10)])