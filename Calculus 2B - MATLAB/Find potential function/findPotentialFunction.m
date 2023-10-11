function [pot] = findPotentialFunction (P, Q)

syms x y;

F = @(P, Q) [];

if diff(P, y) ~= diff(Q, x)
    fprintf('F  is not conservative\n');
else
    pot = int(P, x);
    potY = diff(pot, y);
    gY = Q - potY;
    g = int(gY, y);
    pot = pot + g
end

end