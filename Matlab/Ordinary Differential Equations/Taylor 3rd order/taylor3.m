function [t, y] = taylor3(f, df, ddf, t0, y0, h, t_end)
    % Implements the Third-Order Taylor's Method for solving ODEs
    % Inputs:
    %   f - Function handle representing dy/dt = f(t, y)
    %   df - Function handle for the second derivative d^2y/dt^2
    %   ddf - Function handle for the third derivative d^3y/dt^3
    %   t0 - Initial time
    %   y0 - Initial value
    %   h - Step size
    %   t_end - Final time
    % Outputs:
    %   t - Time steps
    %   y - Solution at each time step
    
    t = t0:h:t_end; % Generate time steps
    y = zeros(size(t)); % Initialize solution array
    y(1) = y0; % Set initial condition
    
    for i = 1:length(t) - 1
        % Taylor series expansion up to third-order term
        y(i + 1) = y(i) + h * f(t(i), y(i)) + ...
                   (h^2 / 2) * df(t(i), y(i)) + ...
                   (h^3 / 6) * ddf(t(i), y(i));
    end
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% f = @(t, y) -2 * y + t; % dy/dt = -2y + t
% df = @(t, y) -2; % d^2y/dt^2 = -2
% ddf = @(t, y) 0; % d^3y/dt^3 = 0 (third derivative)
% [t, y] = taylor3(f, df, ddf, 0, 1, 0.1, 2);
% plot(t, y, '-o');
% title('Third-Order Taylor Method');
% xlabel('t'); ylabel('y');
