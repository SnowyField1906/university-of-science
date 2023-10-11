%main grad
syms x y
f = x^2 + y^2;
A = [1,2];
[F,S] = grad(f, A, x, y);