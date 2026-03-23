function [root] = bisection(a, b, error)
% Returns the root of the equation x^3 - x^2 + 2 = 0 using the bisection method

if f(a) * f(b) >= 0
    error("Invalid input! f(a) and f(b) must have opposite signs.")
end

c = a;
while (b-a) >= error
    c = (a+b)/2;
    if f(c) == 0
        break;
    elseif f(c)*f(a) < 0
        b = c;
    else
        a = c;
    end
end

root = c;

function [y] = f(x)
    y = x^3 - x^2 + 2;
end

end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% a = -200, b = 300, error = 0.0001;
% root = bisection(a, b, error);
% disp(['The root is: ' num2str(root,10)])
