%% Main find_ExtremeNOCond
%% Person who does: Tran Trinh Manh Dung
% Update date: 03/05/2022
% Description: This is a main that runs the function 'find_ExtremeNOCond'. 
% Input: f ---> the function of type symbolic
%        x, y ---> the variables of type symbolic
% Output: MA = [M1, M2, M3], on which
%         M1 ---> column matrix in terms of x
%         M2 ---> column matrix in terms of y
%         M3 ---> column matrix in terms of index k
%         Case k = 1  ---> Local maximum
%         Case k = 2  ---> Local minimum
%         Case k = -1 ---> Saddle point
%         Case k = 0  ---> No conclusion
%%
clc
clear
close all
syms x y
% f = 2*x^3 + x*y^2 + 5*x^2 + y^2;
f = x^3 + y^3 + x + y;
[MA,k1] = find_ExtremeNOCond(f,x,y);
if isempty(MA) == 1
    disp('This problem has no local extrema.');
else
    fprintf('The problem has %d stationary solutions.\n',k1);
    for ii = 1:k1
        if MA(ii,3) == -1
            fprintf('Point (%f, %f) is SADDLE POINT.\n',MA(ii,[1 2]));
        elseif MA(ii,3) == 0
            fprintf('Point (%f, %f) which has no conclusion.\n',MA(ii,[1 2]));
        elseif MA(ii,3) == 1
            fprintf('Point (%f, %f) is the LOCAL MAXIMUM.\n',MA(ii,[1 2]));
        else
            fprintf('Point (%f, %f) is the LOCAL MINIMUM.\n',MA(ii,[1 2]));
        end
    end
end