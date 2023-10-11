zp <- function(y , n , p0, alpha = 0.05 ,HA = c('neq', 'greater' , 'smaller')){
	
	#Compute sample proportion
	p.hat <- y / n ;  
	#Compute Standard Eror (SE) 
	se <- sqrt(p0 * (1 - p0) / n) 
	#Compute test statistic
	Z0 <- (p.hat - p0) / se 
	#Compute critical value
	critical.z <- qnorm(1 - alpha/2)
	HO <- ifelse(abs(Z0) > critical.z , 'Reject' ,'Do not reject')
	HA <-match.arg(HA)
  	if (HA == 'smaller') {
		critical.z <- qnorm(alpha)
		HO <- ifelse(Z0 < critical.z , 'Reject' ,'Do not reject')
	}
	if (HA == 'greater') {
		critical.z <- qnorm(1 - alpha)
		HO <- ifelse(Z0 > critical.z , 'Reject' ,'Do not reject')
	}
	results <- list(Z0 , critical.z , alpha , HO)
	names(results) <- c('Z' , 'critical.z' , 'alpha' , 'HO')
	class(results) <- 'table'
	print(results)
}