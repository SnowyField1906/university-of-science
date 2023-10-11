%% Person who does: Tran Trinh Manh Dung
% Update date: 03/05/2022
% Description: This is a THREE-variable function that finds the extrema of problems without conditions. 
% Note: The stationary solution must be finite.
% Input: f ---> the function of type symbolic
%        x, y, z ---> the variables of type symbolic
% Output: MA = [M1, M2, M3, M4], on which
%         M1 ---> column matrix in terms of x
%         M2 ---> column matrix in terms of y
%         M3 ---> column matrix in terms of z
%         M4 ---> column matrix in terms of index k
%         Case k = 1  ---> Local maximum
%         Case k = 2  ---> Local minimum
%         Case k = -1 ---> Saddle point
%         Case k = 0  ---> No conclusion
%%
function [MA,k1] = find_ExtremeNOCond_3var(f,Var)
nv = length(Var);
A = gradient(f,Var);
B = [];
for iv = 1:nv
    B = attach_Matrix(B, gradient(A(iv),Var)',2);
end
SOL_temp = solve(A == 0, Var);
SOL1 = struct2cell(SOL_temp);
outS = cat(3,SOL1{:});
SOL = remove_ComplexSOL(outS);
nd = size(SOL);
MA = [];
% if nd(1) ~= 0 && nd(2) ~= 0
% SOL
% subs(B,Var,SOL(1,:))
if isempty(SOL) == 0 
    for ii = 1:nd(1)
        if double(det(subs(B,Var,SOL(ii,:)))) ~= 0
            if double(det(subs(B,Var,SOL(ii,:)))) < 0 && ...
                    double(det(subs(B(1:2,1:2),Var,SOL(ii,:)))) > 0 && ...
                    double(det(subs(B(1,1),Var,SOL(ii,:)))) < 0
                MA = attach_Matrix(MA, attach_Matrix(SOL(ii,:), 2, 1), 2);  
            elseif double(det(subs(B,Var,SOL(ii,:)))) > 0 && ...
                    double(det(subs(B(1:2,1:2),Var,SOL(ii,:)))) > 0 && ...
                    double(det(subs(B(1,1),Var,SOL(ii,:)))) > 0
                MA = attach_Matrix(MA, attach_Matrix(SOL(ii,:), 1, 1), 2); 
            else
                MA = attach_Matrix(MA, attach_Matrix(SOL(ii,:), -1, 1), 2);
            end
        else
            MA = attach_Matrix(MA, attach_Matrix(SOL(ii,:), 0, 1), 2);
        end
    end
end
k1 = nd(1);
end