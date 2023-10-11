function [cau1a, test1a] = tim_CtkhongDK(f, x, y)

fx = diff(f, x);
fy = diff(f, y);
fxx = diff(fx, x);
fyy = diff(fy, y);
fxy = diff(fy, x);

D = fxx*fyy - fxy^2;

res = solve([fx == 0, fyy == 0], [x, y], 'Real', true);
cau1a = [];

if isempty(res.x) == false && isempty(res.y) == false
    