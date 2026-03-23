function [t, y] = heuns(f, t0, y0, h, t_end)
    % Implements Improved Euler's Method (Heun's Method) for solving ODEs
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
        % Predictor step (Euler's method)
        y_predict = y(i) + h * f(t(i), y(i));
        
        % Corrector step (average slope)
        y(i + 1) = y(i) + h/2 * (f(t(i), y(i)) + f(t(i + 1), y_predict));
    end
end

% To test the written function, run the following code in the MATLAB
% command window (be sure that the M-File is in the current folder)
% f = @(t, y) -2 * y + t; % dy/dt = -2y + t
% [t, y] = heuns(f, 0, 1, 0.1, 2);
% plot(t, y, '-o');
% title('Heun''s Method');
% xlabel('t'); ylabel('y');
