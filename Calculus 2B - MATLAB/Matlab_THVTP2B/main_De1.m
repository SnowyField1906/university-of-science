%% Tran Trinh Manh Dung + MSSV
% DE 1
%% main DE 1.
clc
clear
close all
m = 7; % (Chu so cuoi cua MSSV) + 1
syms x y z
%% Cau 1b.
disp('||---------- Cau 1. ----------||');
f = m*x^2*y/(x^2+y^2);
g = (x^m - y^m)/(x^2+y^2);
[test_f, cau1a_f] = tinh_GH2B(f, x, y);
[test_g, cau1a_g] = tinh_GH2B(g, x, y);
if test_f == 0
    disp('ham f khong co GH');
else
    fprintf('ham f co gioi han theo 2 duong cong la: %f.\n',double(cau1a_f));
end
figure
[X,Y] = meshgrid(-m:0.1:m,-m:0.1:m);
f1 = matlabFunction(f);
mesh(X,Y,f1(X,Y));
title('cau 1: ham f')
if test_g == 0
    disp('ham g khong co GH');
else
    fprintf('ham g co gioi han theo 2 duong cong la: %f.\n',double(cau1a_g));
end
figure
[X,Y] = meshgrid(-m:0.1:m,-m:0.1:m);
g1 = matlabFunction(g);
mesh(X,Y,g1(X,Y));
title('cau 1: ham g')

%% Cau 2.
% Cau 2a.
disp('||---------- Cau 2. ----------||');
syms r p
f2 = m*x - m/2*y;
td = [r*cos(p), r*sin(p)];
I2a = double(int(int(subs(f2,[x,y],td)*r,r,0,m), p, 0, 2*pi));
fprintf('Ket qua cau 2a la: %f.\n', I2a);

%Cau 2b.
clear r
t = -m:0.1:m;
r = [t.^2; exp(m*t); sin(m*t)]; % o day la dau ";" de ta co the tien tach ra luc sau
figure
plot3(r(1,:), r(2,:), r(3,:),'r-');
title('cau 2b.');
grid on %tao luoi trong do thi
clear t r %Xoa di 2 mang t va r truoc khi bien doi t sang dang symbolic
syms t
r = [t^2, exp(m*t), sin(m*t)]; %o day la dau "," de tien su dung cho 'subs'
F = [x, m, 0];
I2b = double(int(dot(subs(F,[x,y,z],r),diff(r,t)),t,-m,m));
fprintf('Ket qua cau 2b la: %f.\n', I2b);

%% Cau 3.
disp('||---------- Cau 3. ----------||');
clear x y
syms y(x)
dy = diff(y,x);
d2y = diff(y,x,2);
S3 = dsolve(d2y + 2*dy + y == 0,[y(0) == m, dy(0) == -m+1]);%co 2 dieu kien thi phai de trong ngoac vuong
disp('Ket qua cau 3 la:');
disp(S3);