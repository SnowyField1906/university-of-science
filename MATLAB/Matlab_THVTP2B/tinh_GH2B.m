function [test1a, cau1a] = tinh_GH2B(f, x, y)
syms k r p
C1 = [x, k*x];
C2 = [r*cos(p), r*sin(p)]; 
R1 = limit(simplify(subs(f,[x,y],C1)), x , 0);
R2 = limit(simplify(subs(f,[x,y],C2)), r , 0);
check = [isempty(symvar(R1)), isempty(symvar(R2))];
if sum(check) <= 1
    cau1a = [];
    test1a = 0;
else
    if double(R1) ~= double(R2)
        cau1a = [];
        test1a = 0;
    else
        cau1a = double(R1);
        test1a = 1;
    end
end
end