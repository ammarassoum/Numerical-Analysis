function [c,err,k]=bisection(f,a,b,epsilon)

%% Resolving a non linear equation f(x)=0 using bisection method

%Input  - f is the function corresponding to the equation to be solved
%       - a and b are the left and right end points
%       - epsilon is the desired tolerance/error/precision
%Output - c is the approximate zero/solution of the equation
%       - err is the error estimate for c
%       - k is the number of iterations needed for convergence

ya = feval(f,a);
yb = feval(f,b);
k = 0;

if ya*yb>0
    disp('Bisection method not applicable for the given end points...')
    disp('f(a)*f(b) > 0!!!!!')
    return
end

err = abs(b-a);

while err>epsilon
    k = k+1;
    c = (a+b)/2;
    yc = feval(f,c);
    if yc == 0
        a = c;
        b = c;
    elseif yb*yc > 0
        b = c;
        yb = yc;
    else
        a = c;
        ya = yc;
    end
    err=abs(b-a);
end

end