k = 0:8;
p = function(k) choose(8,k) * 0.3^k * 0.7^(8-k);
print(p(k));
plot(k, p(k), type = "h", ylab = "P(X = x)");