syms x y z;
f1 = x^2 + y^2 + z^2 == 0;
 
f2 = 4*x^2 + y^2 + z^2 == 9;
 
xyz = solve([f1,f2]);

x = xyz.x;
 
y=xyz.y;
