%% Nguyễn Hữu Thuận - 21120566

m = 7;
syms x y;

%% Câu 2:
% 2a:

f = m*x^2 - m*y/2;

fInt = int(int(f, x, -m, m), y, -m, m);

fprintf('Tích phân bội tìm được là: %f\n', fInt);


% 2b:

t = (- m - 7):0.1:(m + 7);
r = [m*cos(t); m*sin(t); t.^2];
    
figure
plot3(r(1, :), r(2, :), r(3, :));
title('Câu 2b: Vectơ r');
grid on;

clear r t;
syms t;

f = [y*z, x*z, x*y];
r = [m*cos(t), m*sin(t), t.^2];

fInt = int(dot(subs(f, [x, y, z], r), diff(r, t)), t, -m - 7, m + 7);

fprintf('Tích phân tìm được là: %f\n', fInt);

%% Câu 3:

syms y(x);

dy = diff(y, x);

res = dsolve(dy + x*y == 0, y(0) == m);

fprintf('Kết quả tìm được là:\n');
disp(res);