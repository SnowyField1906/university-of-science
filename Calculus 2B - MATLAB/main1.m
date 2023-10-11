%% Nguyễn Hữu Thuận - 21120566

m = 7;
syms x y

%% Bài 1:
% Câu b:

f = m*x^2*y/(x^2+y^2);
g = (x^m - y^m)/(x^2+y^2);

[fTest1a, fCau1a] = tinh_GH2B(f, x, y);
[gTest1a, gCau1a] = tinh_GH2B(g, x, y);

if fTest1a
   fprintf('Hàm f có giới hạn là: %f\n', fCau1a);
else
   disp('Hàm f không có giới hạn\n');
end

if gTest1a
   fprintf('Hàm g có giới hạn là: %f\n', gCau1a);
else
   disp('Hàm g không có giới hạn\n');
end

[X, Y] = meshgrid(-m:0.1:m, -m:0.1:m);

figure
fFunc = matlabFunction(f);
mesh(X, Y, fFunc(X, Y));
title('Hàm f');

figure
gFunc = matlabFunction(g);
mesh(X, Y, gFunc(X, Y));
title('Hàm g');

%% Bài 2:
% Câu a:

syms r p;

D = [r*cos(p), r*sin(p)];
f = m*x^2 - m*y/2;

fInt = int(int(subs(f, [x, y], D), r, 0, m), p, 0, 2*pi);

fprintf('Tích phân tính được là: %f\n', fInt);

% Câu b:

t = -m:0.1:m;
r = [t.^2; exp(m*t); sin(m*t)];

figure;
plot3(r(1, :), r(2, :), r(3, :));
title('Vector r');
grid on;

%% Bài 3:

syms y(x);

dy = diff(y, x);
dyy = diff(dy, x);

res = dsolve(dyy + 2*dy + y == 0, [y(0) == m, dy(0) == -m + 1]);
disp('Nghiệm của phương trình vi phân là: %f\n');
disp(res);