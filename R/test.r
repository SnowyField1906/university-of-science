x <- seq (10 , 22 , 2)
y <- x - 3
z <- x + 3
df = data . frame (x , y , z)
u = ( length (df)*max(df )) %% abs( ncol (df) - nrow (df ))