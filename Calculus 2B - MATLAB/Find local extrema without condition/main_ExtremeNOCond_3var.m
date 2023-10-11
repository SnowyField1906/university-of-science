%% Main findExtremeNOCond_3var
%% Person who does: Tran Trinh Manh Dung
% Update date: 03/05/2022
% Description: This is a main that runs the function 'find_ExtremeNOCond_3var'. 
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
clc
clear
close all

syms x y z
f = x^4 + x^2*y + y^2 + z^2 + x*z + 1;
Var = [x y z];
[MA,k1] = find_ExtremeNOCond_3var(f,Var);
if isempty(MA) == 1
    disp('This problem has no local extrema.');
else
    fprintf('The problem has %d stationary solutions.\n',k1);
    for ii = 1:k1
        if MA(ii,end) == -1
            fprintf('Point (%f, %f) is SADDLE POINT.\n',MA(ii,[1 end-1]));
        elseif MA(ii,end) == 0
            fprintf('Point (%f, %f) which has no conclusion.\n',MA(ii,[1 end-1]));
        elseif MA(ii,end) == 1
            fprintf('Point (%f, %f) is the LOCAL MAXIMUM.\n',MA(ii,[1 end-1]));
        else
            fprintf('Point (%f, %f) is the LOCAL MINIMUM.\n',MA(ii,[1 end-1]));
        end
    end
end