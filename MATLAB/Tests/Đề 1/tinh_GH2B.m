function [test1a, cau1a] = tinh_GH2B(f, x, y)

syms k r p

C1 = [x, k*x];
C2 = [r*cos(p), r*sin(p)];

lim1 = limit(simplify(subs(f, [x, y], C1)), x, 0);
lim2 = limit(simplify(subs(f, [x, y], C2)), r, 0);

check = isempty(symvar(lim1)) + isempty(symvar(lim2));

if check < 2
    test1a = 0;
    cau1a = [];
else
    if double(lim1) ~= double(lim2)
        test1a = 0;
        cau1a = [];
    else
        test1a = 1;
        cau1a = double(lim1);
    end
end

end