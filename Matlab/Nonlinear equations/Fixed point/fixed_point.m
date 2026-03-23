function [root] = fixed_point(x0, error)
% Returns the root of the equation x = 1 + sin(x) using the Fixed Point method

x1 = g(x0);
while abs(x1 - x0) >= error
    x0 = x1;
    x1 = g(x0);
end

root = x1;

function [y] = g(x)
    y = 1 + sin(x);
end

end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% x0 = 0.5, error = 0.0001;
% root = fixed_point(x0, error);
% disp(['The root is: ' num2str(root,10)])