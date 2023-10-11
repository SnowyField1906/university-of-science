%% Nguyễn Hữu Thuận - 21120566

m = 7;
syms x y;

%% Câu 1:
% 1b

f = (m*x^2*y)/(x^2+y^2);
g = (x^m - y^m)/(x^2 + y^2);

[fTest1a, fCau1a] = tinh_GH2B(f, x, y);
[gTest1a, gCau1a] = tinh_GH2B(g, x, y);

if fTest1a == 1
    fprintf('Hàm f có giới hạn theo 2 đường cong bằng: %f\n', fCau1a);
else
    fprintf('Hàm f không có giới hạn theo 2 đường cong\n');
end

if gTest1a == 1
    fprintf('Hàm g có giới hạn theo 2 đường cong bằng: %f\n', gCau1a);
else
    fprintf('Hàm g không có giới hạn theo 2 đường cong\n');
end

[X, Y] = meshgrid(-m:0.1:m, -m:0.1:m);

figure
fFunc = matlabFunction(f);
mesh(X, Y, fFunc(X, Y));
title('Câu 1b: Hàm f');

figure
gFunc = matlabFunction(g);
mesh(X, Y, gFunc(X, Y));
title('Câu 1b: Hàm g');


%% Câu 2:
% 2a:

syms r p;

D = [r*cos(p), r*sin(p)];
f = m*x^2 - m*y/2;
fFunc = matlabFunction(f);

fInt = int(int(subs(f, [x, y], D), r, 0, m), p, 0, 2*pi);

fprintf('Tích phân bội tính được là: %f\n', fInt);


% 2b:

t = -m:0.1:m;
r = [t.^2; exp(m*t); sin(m*t)];

figure
plot3(r(1, :), r(2, :), r(3, :));
title('Câu 2b: Vectơ r');
grid on

clear r t;
syms t;

f = [x, m, 0];
r = [t.^2, exp(m*t), sin(m*t)];

fInt = int(dot(subs(f, [x, y, z], r), diff(r, t)), t, -m, m);

fprintf('Tích phân tìm được là: %f\n', fInt);

%% Câu 3:

syms y(x)

dy = diff(y, x);
dyy = diff(dy, x);

n = dsolve(dyy + 2*dy + y == 0, [y(0) == m, dy(0) == -m + 1]);

fprintf('Nghiệm của phương trình vi phân là: %f\n');
disp(n);