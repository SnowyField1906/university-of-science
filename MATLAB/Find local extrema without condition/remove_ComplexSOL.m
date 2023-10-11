% Function loc nghiem phuc
function [A] = remove_ComplexSOL(B)
% Remark: B = [B1, B2], 
% on which B1 is value column vector of x-axis, B2 is value column vector of y-axis
n = size(B);
A = [];
for ii =  1:n(1)
    if sum(imag(B(ii,:))) == 0
        A = attach_Matrix(A, B(ii,:), 2);
    end
end
end