%% Person who does: Tran Trinh Manh Dung
% Update date: 03/05/2022
% Description: This is a two-variable function that finds the extrema of problems without conditions. 
% Note: The stationary solution must be finite.
%Input: f ---> the function of type symbolic
%       x, y ---> the variables of type symbolic
%Output: MA = [M1, M2, M3], on which
%        M1 ---> column matrix in terms of x
%        M2 ---> column matrix in terms of y
%        M3 ---> column matrix in terms of index k
%        Case k = 1  ---> Local maximum
%        Case k = 2  ---> Local minimum
%        Case k = -1 ---> Saddle point
%        Case k = 0  ---> No conclusion
%%
function [MA,k1] = find_ExtremeNOCond(f,x,y)

dfx = diff(f,x);
dfy = diff(f,y);
d2fxx = diff(dfx,x);
d2fyy = diff(dfy,y);
d2fxy = diff(dfx,y);
D = d2fxx*d2fyy - (d2fxy)^2;
SOL = solve(dfx == 0, dfy == 0, [x,y]);
% [SOL.x,SOL.y]
SOL = remove_ComplexSOL([SOL.x,SOL.y]);
nd = size(SOL);
MA = [];
% if nd(1) ~= 0 && nd(2) ~= 0
if isempty(SOL) == 0 
    for ii = 1:nd(1)
        if double(subs(D,[x,y],SOL(ii,:))) > 0
            if double(subs(d2fxx,[x,y],SOL(ii,:))) > 0
                MA = attach_Matrix(MA, attach_Matrix(SOL(ii,:), 2, 1), 2);  
            else
                MA = attach_Matrix(MA, attach_Matrix(SOL(ii,:), 1, 1), 2); 
            end
        elseif double(subs(D,[x,y],SOL(ii,:))) < 0
            MA = attach_Matrix(MA, attach_Matrix(SOL(ii,:), -1, 1), 2);
        else
            MA = attach_Matrix(MA, attach_Matrix(SOL(ii,:), 0, 1), 2);
        end
    end
end
k1 = nd(1);
end