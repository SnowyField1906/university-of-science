%% Person who does: Tran Trinh Manh Dung
% Update date: 03/05/2022
% Description: This is a two-variable function that finds the extrema of problems without conditions. 
% Note: The stationary solution must be finite.
%Input: f ---> the function of type symbolic
%       x, y ---> the variables of type symbolic
%Output: cau1a = [M1, M2, M3], on which
%        M1 ---> column matrix in terms of x
%        M2 ---> column matrix in terms of y
%        M3 ---> column matrix in terms of index k
%        Case k = 1  ---> cuc dai dia phuong
%        Case k = 2  ---> cuc tieu dia phuong
%        Case k = -1 ---> diem yen ngua
%        Case k = 0  ---> khong có ket luan
%%
function [cau1a,test1a] = tim_CtkhongDK(f,x,y)

dfx = diff(f,x);
dfy = diff(f,y); 
d2fxx = diff(dfx,x);
d2fyy = diff(dfy,y);
d2fxy = diff(dfx,y);
D = d2fxx*d2fyy - (d2fxy)^2;
SOL = solve([dfx == 0, dfy == 0], [x,y], 'Real', true);
cau1a = [];
if isempty(SOL.x) == 0 && isempty(SOL.y) == 0
    nd = size(SOL);
    SOL = [SOL.x, SOL.y];
    for ii = 1:nd(1)
        if double(subs(D,[x,y],SOL(ii,:))) > 0
            if double(subs(d2fxx,[x,y],SOL(ii,:))) > 0
                cau1a = attach_Matrix(cau1a, attach_Matrix(SOL(ii,:), 2, 1), 2);
%                 cau1a = [cau1a; [SOL(ii,:),2]]; %Cach viet tuong duong
%                 voi cach viet tren
            else
                cau1a = attach_Matrix(cau1a, attach_Matrix(SOL(ii,:), 1, 1), 2); 
%                 cau1a = [cau1a; [SOL(ii,:),1]]; %Cach viet tuong duong
%                 voi cach viet tren
            end
        elseif double(subs(D,[x,y],SOL(ii,:))) < 0
            cau1a = attach_Matrix(cau1a, attach_Matrix(SOL(ii,:), -1, 1), 2);
%             cau1a = [cau1a; [SOL(ii,:),-1]]; %Cach viet tuong duong
%                 voi cach viet tren
        else
            cau1a = attach_Matrix(cau1a, attach_Matrix(SOL(ii,:), 0, 1), 2);
%             cau1a = [cau1a; [SOL(ii,:),0]]; %Cach viet tuong duong
%                 voi cach viet tren
        end
    end
end
nd = size(cau1a);
test1a = nd(1);
end

%% Description: The function that attachs the same-dimensional matrices
function [M] = attach_Matrix(A, B, t)
if t == 1
    M = [A, B];% t = 1 --> arranged by line
else
    M = [A; B];% t = 2 --> arranged by column
end
end