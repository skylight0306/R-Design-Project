rm(list=ls())
#SQL EXISTS Operator

#create the data 
data <- data.frame(ProductID=c('1','2','3','4','5'),
                   ProductName=c('Chais','Chang','Aniseed Syrup','Chef Anton\'s Cajun Seasoning','Chef Anton\'s Gumbo Mix'),
                   SupplierID=c('1','1','1','2','2'),
                   CategoryID=c('1','1','2','2','2'),
                   Unit=c('10 boxes x 20 bags','24 - 12 oz bottles','12 - 550 ml bottles','48 - 6 oz jars','36 boxes'),
                   Price=c(18,19,10,22,21.35))


#example1
#lists the Product with a product price less than 20:

test1 <- data[ data$Price > 20, ]
test1



#example2
#lists the Product with a product price equal to 22:
test2 <- data[ data$Price == 22, ]
test2
