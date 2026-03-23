function [root] = secant(x0, x1, error)
% Returns the root of the equation x^2 - 3x + 2 = 0 using the Secant method

while abs(x1 - x0) >= error
    x2 = x1 - (f(x1)*(x1 - x0))/(f(x1) - f(x0));
    x0 = x1;
    x1 = x2;
end

root = x2;

function [y] = f(x)
    y = x^2 - 3*x + 2;
end

end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% x0 = 0, x1 = 1.5, error = 0.0001;
% root = secant(x0, x1, error);
% disp(['The root is: ' num2str(root,10)])