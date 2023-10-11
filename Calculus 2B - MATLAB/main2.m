%% Nguyễn Hữu Thuận - 21120566

m = 7;
syms x y;

%% Bài 2:
% Câu a:

f = m*x^2 + m*y/2;

fInt = int(int(f, x, -m, m), y, -m, m);
fprintf('Tích phân tính được là: %f\n', fInt);

% Câu b:

t = (-m - 7):0.1:(m + 7);
r = [m*cos(t); m*sin(t); t.^2];

figure;
plot3(r(1, :), r(2, :), r(3, :));
title('Vector r');
grid on;

clear r;
syms t;

r = [m*cos(t), m*sin(t), t.^2];
f = [y*z; x*z; x*y];

fInt = int(dot(subs(f, [x, y, z], r), diff(r, t)), t, -m - 7, m + 7);
fprintf('Tích phân tính được là: %f\n', fInt);


%% Bài 3:

syms y(x);

dy = diff(y, x);

res = dsolve(dy + x*y == 0, y(0) == m);

disp('Nghiệm của phương trình vi phân là:');
disp(n);