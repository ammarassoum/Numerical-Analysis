function [root] = aitken(x0, error)
% Returns the root of the equation 1 + sin(x) = x using the Aitken method

x1 = f(x0);
x2 = f(x1);
while abs(x2 - x1) >= error
    xe = x0 - ((x1 - x0)*(x1 - x0))/(x2 - 2*x1 + x0);
    x0 = xe;
    x1 = f(x0);
    x2 = f(x1);
end

root = xe;

function [y] = f(x)
    y = 1 + sin(x);
end

end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% x0 = 0.5, error = 0.0001;
% root = aitken(x0, error);
% disp(['The root is: ' num2str(root,10)])