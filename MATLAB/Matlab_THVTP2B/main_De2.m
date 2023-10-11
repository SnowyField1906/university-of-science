%% Tran Trinh Manh Dung + MSSV
% DE 2
%% main DE 2.
clc
clear
close all
m = 7; % (Chu so cuoi cua MSSV) + 1
syms x y z


%% Cau 2.
disp('||---------- Cau 2. ----------||');
% Cau 2a
f2 = m*x^2 - m/2*y;
I2a = int(int(f2,x,-m,m),-m,m);
fprintf('Ket qua cau 2a la: %f.\n', I2a);

% Cau 2b
t = -m-7:0.1:m+7;
r = [m*cos(t); m*sin(t); t.^2]; % o day la dau ";" de ta co the tien tach ra luc sau
figure % De hinh minh hoa trong mot khung hinh rieng
plot3(r(1,:), r(2,:), r(3,:),'r-');
title('cau 2b.');
grid on %tao luoi trong do thi

% Cau 2c
clear t r %Xoa di 2 mang t va r truoc khi bien doi t sang dang symbolic
syms t
r = [m*cos(t), m*sin(t), t.^2]; %o day la dau "," de tien su dung cho 'subs'
F = [y*z, x*z, x*y];
I2b = double(int(dot(subs(F,[x,y,z],r),diff(r,t)),t,-m-7,m+7));
fprintf('Ket qua cau 2b la: %f.\n', I2b);

%% Cau 3.
disp('||---------- Cau 3. ----------||');
clear x y
syms y(x)
dy = diff(y,x);
S3 = dsolve(dy + x*y == 0, y(0) == m);
disp('Ket qua cau 3 la:');
disp(S3);