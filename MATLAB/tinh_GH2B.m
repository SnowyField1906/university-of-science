function [test1a, cau1a] = tinh_GH2B(f, x, y)

syms k r p
C1 = [x, k*x];
C2 = [r*cos(p), r*sin(p)];

fLimC1 = limit(subs(f, [x, y], C1), x, 0);
fLimC2 = limit(subs(f, [x, y], C2), r, 0);

check = isempty(symvar(fLimC1)) && isempty(symvar(fLimC2));

if ~check
    test1a =  0;
    cau1a = [];
else
    if fLimC1 ~= fLimC2
        test1a =  0;
        cau1a = [];
    else
        test1a = 1;
        cau1a = fLimC1;
    end
end

end