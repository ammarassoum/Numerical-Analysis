function [t, y] = rk4(f, t0, y0, h, t_end)
    % Implements the Fourth-Order Runge-Kutta Method for solving ODEs
    % Inputs:
    %   f - Function handle representing dy/dt = f(t, y)
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
        k1 = h * f(t(i), y(i)); % Slope at the beginning
        k2 = h * f(t(i) + h/2, y(i) + k1/2); % Slope at midpoint using k1
        k3 = h * f(t(i) + h/2, y(i) + k2/2); % Slope at midpoint using k2
        k4 = h * f(t(i) + h, y(i) + k3); % Slope at the end
        
        y(i + 1) = y(i) + (k1 + 2*k2 + 2*k3 + k4) / 6; % Weighted average
    end
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% f = @(t, y) -2 * y + t; % dy/dt = -2y + t
% [t, y] = rk4(f, 0, 1, 0.1, 2);
% plot(t, y, '-o');
% title('Runge-Kutta 4th Order Method');
% xlabel('t'); ylabel('y');
