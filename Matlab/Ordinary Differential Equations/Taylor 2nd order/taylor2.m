function [t, y] = taylor2(f, df, t0, y0, h, t_end)
    % Implements the Second-Order Taylor's Method for solving ODEs
    % Inputs:
    %   f - Function handle representing dy/dt = f(t, y)
    %   df - Function handle for the derivative d^2y/dt^2
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
        % Taylor series expansion up to second-order term
        y(i + 1) = y(i) + h * f(t(i), y(i)) + (h^2 / 2) * df(t(i), y(i));
    end
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% f = @(t, y) -2 * y + t; % dy/dt = -2y + t
% df = @(t, y) -2; % d^2y/dt^2 = -2 (second derivative)
% [t, y] = taylor2(f, df, 0, 1, 0.1, 2);
% plot(t, y, '-o');
% title('Second-Order Taylor Method');
% xlabel('t'); ylabel('y');
