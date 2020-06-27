rm(list=ls())

#=====================================================================
# 期末作業
#	主題:繪製出COVID-19相關資訊程式 
# 目標:擷取網路上COVID-19相關的開放資料集的資料
#      並在程式中完成繪出全世界感染人數地圖
#      結合R資料分析功能設計出其他相關功能方便使用者閱讀
#
# 內容:抓取線上資料庫繪製出COVID-19在全世界的感染人數圖
#      透過運算方式去計算出今日感染的人數
#      以每七天為一個單位去判斷COVID-19感染趨勢圖
#=====================================================================



if (!require(readr)) {
  install.packages("readr")
  library(readr)
}
if (!require(maps)) {
  install.packages("maps")
  library(maps)
} 
if (!require(ggplot2)) {
  install.packages("ggplot2")
  library(ggplot2)
} 
if (!require(lubridate)) {
  install.packages("lubridate")
  library(lubridate)
} 

library(lubridate) # 處理時間資料
library(readr)
library(ggplot2)
library(maps)

#抓取當前的時間 並設定COVID-19爆發至今的總天數
Today <- Sys.Date()
Yesterday <- (Today-1)
BeforeY <- (Yesterday-1)
OneWeekBefore <- (Today-7)
TotalDay <- Yesterday - as.Date("2020-01-22")  
TotalDay <- as.numeric(TotalDay)

#讀取世界地圖
wmap <- map_data("world")
#讀取全世界COVID-19的感染人數
#資料量有點大 需要等一陣子
data<- read_csv("https://data.humdata.org/hxlproxy/data/download/time_series_covid19_recovered_global_narrow.csv?dest=data_edit&filter01=merge&merge-url01=https%3A%2F%2Fdocs.google.com%2Fspreadsheets%2Fd%2Fe%2F2PACX-1vTglKQRXpkKSErDiWG6ycqEth32MY0reMuVGhaslImLjfuLU0EUgyyu2e-3vKDArjqGX7dXEBV8FJ4f%2Fpub%3Fgid%3D1326629740%26single%3Dtrue%26output%3Dcsv&merge-keys01=%23country%2Bname&merge-tags01=%23country%2Bcode%2C%23region%2Bmain%2Bcode%2C%23region%2Bsub%2Bcode%2C%23region%2Bintermediate%2Bcode&filter02=merge&merge-url02=https%3A%2F%2Fdocs.google.com%2Fspreadsheets%2Fd%2Fe%2F2PACX-1vTglKQRXpkKSErDiWG6ycqEth32MY0reMuVGhaslImLjfuLU0EUgyyu2e-3vKDArjqGX7dXEBV8FJ4f%2Fpub%3Fgid%3D398158223%26single%3Dtrue%26output%3Dcsv&merge-keys02=%23adm1%2Bname&merge-tags02=%23country%2Bcode%2C%23region%2Bmain%2Bcode%2C%23region%2Bsub%2Bcode%2C%23region%2Bintermediate%2Bcode&merge-replace02=on&merge-overwrite02=on&filter03=explode&explode-header-att03=date&explode-value-att03=value&filter04=rename&rename-oldtag04=%23affected%2Bdate&rename-newtag04=%23date&rename-header04=Date&filter05=rename&rename-oldtag05=%23affected%2Bvalue&rename-newtag05=%23affected%2Binfected%2Bvalue%2Bnum&rename-header05=Value&filter06=clean&clean-date-tags06=%23date&filter07=sort&sort-tags07=%23date&sort-reverse07=on&filter08=sort&sort-tags08=%23country%2Bname%2C%23adm1%2Bname&tagger-match-all=on&tagger-default-tag=%23affected%2Blabel&tagger-01-header=province%2Fstate&tagger-01-tag=%23adm1%2Bname&tagger-02-header=country%2Fregion&tagger-02-tag=%23country%2Bname&tagger-03-header=lat&tagger-03-tag=%23geo%2Blat&tagger-04-header=long&tagger-04-tag=%23geo%2Blon&header-row=1&url=https%3A%2F%2Fraw.githubusercontent.com%2FCSSEGISandData%2FCOVID-19%2Fmaster%2Fcsse_covid_19_data%2Fcsse_covid_19_time_series%2Ftime_series_covid19_recovered_global.csv")


#data$`Country/Region`
#將重複的資料刪除
#data_country <- base::unique(data$`Country/Region`)
#data_country <- data_country[-1] 

#只保留重要的資訊 其餘捨棄掉
Alldt <- data[,c("Province/State","Country/Region","Lat","Long","Date","Value")] 
#清除第一筆欄位資訊
Alldt <- Alldt[-1,]


#抓取最新的(昨天)全世界感染人數
data1 <- Alldt[ Alldt$Date == Yesterday, ]
#抓取再前一天的感染人數
data2 <- Alldt[ Alldt$Date == BeforeY, ]
#抓取一周前的感染人數
data3 <- Alldt[ Alldt$Date == OneWeekBefore, ]



#將感染人數 數字化
data1$Value <- as.numeric(data1$Value)
data2$Value <- as.numeric(data2$Value)
data3$Value <- as.numeric(data3$Value)


#繪製出全球感染人數圖
world_Cases <-
  ggplot()+
  labs(x = "Long", y = "Lat", title = "Covid-19 World Cases" ) +
  geom_polygon(data=wmap,aes(x=as.numeric(long),y=as.numeric(lat),group=group),fill="forestgreen",alpha=1) +
  geom_point(data=data1,aes(x=as.numeric(Long),y=as.numeric(Lat),size=as.numeric(Value)),color="red",alpha=0.7) +
  scale_size_continuous(name=Yesterday, trans = "sqrt", range=c(1,20), breaks=c(1, 500, 10000, 100000, 500000),labels=c("1-499", "500-9999", "10000-99999","100000-499999", "500000+"),limits=c(1, 500000)) +
  #scale_colour_viridis_c(option="inferno", direction=-1,name="Confirmed cases", breaks=c(1, 500, 10000, 100000, 500000),labels=c("1-499", "500-9999", "10000-99999","100000-499999", "500000+")) +
  #scale_colour_manual(values = c("red", "yello","black","blue","orange")) +
  #guides(size = guide_legend(override.aes = list(colour = list("orange","orange","orange","orange","blue")))) +
  theme_void() +
  theme(legend.position="bottom")  

world_Cases




# data1$Value - data2$Value
Newdt <- data1[,c("Province/State","Country/Region","Lat","Long","Date")] 
#將最新的感染人數 - 前一天感染人數 = 當日感染人數
NewCases <-  data1$Value - data2$Value
Newdt <- cbind(Newdt,NewCases)

#繪製出最新新增感染人數
world_NewCases <-
  ggplot()+
  labs(x = "Long", y = "Lat", title = "Covid-19 World New Cases" ) +
  geom_polygon(data=wmap,aes(x=as.numeric(long),y=as.numeric(lat),group=group),fill="forestgreen",alpha=1) +
  geom_point(data=Newdt,aes(x=as.numeric(Long),y=as.numeric(Lat),size=as.numeric(NewCases)), color = "blue", alpha=0.5) +
  scale_size_continuous(name="New Cases", trans = "sqrt", range=c(5,18), breaks=c(1, 100, 500, 1000, 5000, 10000),labels=c("1-99", "100-499", "500-999", "1000-4999","5000-9999", "10000+"),limits=c(1, 10000)) +
  #scale_fill_gradientn(colours = c("blue", "green", "yellow", "red"),breaks=c(1, 100, 500, 1000, 5000, 10000)) + 
  #scale_colour_manual(values = c("red", "yello","black","blue","orange")) +
  theme_void() +
  theme(legend.position="bottom")  


world_NewCases
#dim(Increasing_trend)[1]

#將資料按照日期排下來
Increasing_trend <- Alldt[order(Alldt["Date"]),]
#將感染人數 數字化
Increasing_trend$Value <- as.numeric(Increasing_trend$Value)


AllCase <- matrix(0,TotalDay,2)
colnames(AllCase) <- c("Date","Value")
x=1


#AllCase[,1][day] <- 5
#將每天感染人數隨著日期累加
for (day in c(1:TotalDay))
{
  AllCase[,1][day] <- Increasing_trend$Date[x]
  Worldvalue = 0
  dim(data1)[1]
  count = 1
  for (count in c(1:dim(data1)[1]))
  {
    Worldvalue = Worldvalue + Increasing_trend$Value[x] 
    x <- x + 1
  }
  AllCase[,2][day] <- Worldvalue
}
#typeof(AllCase$value)

# 10 %% 7

#每7天為一周期 去取出感染人數累加資訊
WeekCase <- matrix(0,TotalDay/7,2)
colnames(WeekCase) <- c("Date","Value")
# AllCase$Date <- as.numeric(AllCase$Date)
x=1
for (y in c(1:TotalDay))
{
  if(y %% 7 == 0)
  {
    WeekCase[x,][1] <- AllCase[y,][1]
    WeekCase[x,][2] <- AllCase[y,][2]
    x <- x + 1
  }
  
  
}
# WeekCase[,2] <- as.numeric(WeekCase[,2])
# WeekCase[,2] <- as.integer(WeekCase[,2])
WeekCase <- as.data.frame(WeekCase)

WeekCase$Value <- as.integer(as.character(WeekCase$Value))


#is.integer(WeekCase$Value)
# WeekCase$Value <- as.integer(WeekCase$Value)
#AllCase<- head(AllCase)
#繪製每個星期增加的比例折線圖

 ggplot(data=WeekCase,aes(x = Date, y = Value,group = 1) )+
   geom_line(color = "blue") + geom_point(color = "blue")  


 
 
 
 
 
 
 #排序日期
CountryCase <- Alldt[order(Alldt["Date"]),]
#選擇國家
country <- "Taiwan*" 
data4 <- CountryCase[ CountryCase$`Country/Region` == country, ]
data4$Value <- as.integer(data4$Value)


#繪製該國家感染人數圖
ggplot(data=data4,aes(x = Date, y = Value,group = 1) )+

  geom_line(color = "steelblue") + geom_point(color = "steelblue") 
 
 

data5 <- data4[-1,]

data4 <- data4[-dim(data4)[1],]
data4$Value <- as.integer(data4$Value)

Value <- data5$Value - data4$Value


Growth1 <- data5[,c("Date")] 
Growth2 <- data4[,c("Value")]
Growth <- cbind(Growth1,Value)
type <- "Growth"
Growth <- cbind(Growth,type)

type <- "Case"
dt4 <- cbind(Growth1,Growth2)
dt4 <- cbind(dt4,type)

Rate <- rbind(dt4, Growth)
#Growth$GrowthR
# Growth <- cbind(Growth,Growth2)



ggplot(data=Rate,mapping = aes(x = Date, y = Value,colour = type, fill = type,group = type) )+
  
  geom_line() + geom_point() +

 scale_linetype_manual(values = c(1,2)) +    #自定義線條類型
 scale_color_manual(values = c('steelblue','darkred')) +   #自定義顏色
 scale_shape_manual(values = c(21,23)) +   #自定義點形狀
 scale_fill_manual(values = c('red','black'))    #自定義點的填充色





 

 
 
 
 
 
 
 
 
 
 
#============================================================================================================
 
Get_Covid19_Map <- function(Method = 1, Date = Yesterday, Country = "Taiwan*" ) { 
 
  #讀取世界地圖
  wmap <- map_data("world")  
  #data<- read_csv("https://data.humdata.org/hxlproxy/data/download/time_series_covid19_recovered_global_narrow.csv?dest=data_edit&filter01=merge&merge-url01=https%3A%2F%2Fdocs.google.com%2Fspreadsheets%2Fd%2Fe%2F2PACX-1vTglKQRXpkKSErDiWG6ycqEth32MY0reMuVGhaslImLjfuLU0EUgyyu2e-3vKDArjqGX7dXEBV8FJ4f%2Fpub%3Fgid%3D1326629740%26single%3Dtrue%26output%3Dcsv&merge-keys01=%23country%2Bname&merge-tags01=%23country%2Bcode%2C%23region%2Bmain%2Bcode%2C%23region%2Bsub%2Bcode%2C%23region%2Bintermediate%2Bcode&filter02=merge&merge-url02=https%3A%2F%2Fdocs.google.com%2Fspreadsheets%2Fd%2Fe%2F2PACX-1vTglKQRXpkKSErDiWG6ycqEth32MY0reMuVGhaslImLjfuLU0EUgyyu2e-3vKDArjqGX7dXEBV8FJ4f%2Fpub%3Fgid%3D398158223%26single%3Dtrue%26output%3Dcsv&merge-keys02=%23adm1%2Bname&merge-tags02=%23country%2Bcode%2C%23region%2Bmain%2Bcode%2C%23region%2Bsub%2Bcode%2C%23region%2Bintermediate%2Bcode&merge-replace02=on&merge-overwrite02=on&filter03=explode&explode-header-att03=date&explode-value-att03=value&filter04=rename&rename-oldtag04=%23affected%2Bdate&rename-newtag04=%23date&rename-header04=Date&filter05=rename&rename-oldtag05=%23affected%2Bvalue&rename-newtag05=%23affected%2Binfected%2Bvalue%2Bnum&rename-header05=Value&filter06=clean&clean-date-tags06=%23date&filter07=sort&sort-tags07=%23date&sort-reverse07=on&filter08=sort&sort-tags08=%23country%2Bname%2C%23adm1%2Bname&tagger-match-all=on&tagger-default-tag=%23affected%2Blabel&tagger-01-header=province%2Fstate&tagger-01-tag=%23adm1%2Bname&tagger-02-header=country%2Fregion&tagger-02-tag=%23country%2Bname&tagger-03-header=lat&tagger-03-tag=%23geo%2Blat&tagger-04-header=long&tagger-04-tag=%23geo%2Blon&header-row=1&url=https%3A%2F%2Fraw.githubusercontent.com%2FCSSEGISandData%2FCOVID-19%2Fmaster%2Fcsse_covid_19_data%2Fcsse_covid_19_time_series%2Ftime_series_covid19_recovered_global.csv")
  #只保留重要的資訊 其餘捨棄掉
  Alldt <- data[,c("Province/State","Country/Region","Lat","Long","Date","Value")] 
  #清除第一筆欄位資訊
  Alldt <- Alldt[-1,]
  #抓取最新的(昨天)全世界感染人數

  
  
  #繪製出全球感染地圖
  if (Method == 1)
  {
    data1 <- Alldt[ Alldt$Date == Date, ]  
    data1$Value <- as.numeric(data1$Value)
    world_Cases <-
      ggplot()+
      labs(x = "Long", y = "Lat", title = "Covid-19 World Cases" ) +
      geom_polygon(data=wmap,aes(x=as.numeric(long),y=as.numeric(lat),group=group),fill="forestgreen",alpha=1) +
      geom_point(data=data1,aes(x=as.numeric(Long),y=as.numeric(Lat),size=as.numeric(Value)),color="red",alpha=0.7) +
      scale_size_continuous(name=Date, trans = "sqrt", range=c(1,20), breaks=c(1, 500, 10000, 100000, 500000),labels=c("1-499", "500-9999", "10000-99999","100000-499999", "500000+"),limits=c(1, 500000)) +
     
      theme_void() +
      theme(legend.position="bottom")  
    
    world_Cases
    
  }
  else if (Method == 2 )
  {
    data1 <- Alldt[ Alldt$Date == Date, ]  
    data1$Value <- as.numeric(data1$Value)
    BeforeDate <- as.Date(Date) - 1
    data2 <- Alldt[ Alldt$Date == BeforeDate, ]  
    data2$Value <- as.numeric(data2$Value)
    Newdt <- data1[,c("Province/State","Country/Region","Lat","Long","Date")] 
    #將最新的感染人數 - 前一天感染人數 = 當日感染人數
    NewCases <-  data1$Value - data2$Value
    Newdt <- cbind(Newdt,NewCases)
    world_NewCases <-
      ggplot()+
      labs(x = "Long", y = "Lat", title = "Covid-19 World New Cases" ) +
      geom_polygon(data=wmap,aes(x=as.numeric(long),y=as.numeric(lat),group=group),fill="forestgreen",alpha=1) +
      geom_point(data=Newdt,aes(x=as.numeric(Long),y=as.numeric(Lat),size=as.numeric(NewCases)), color = "blue", alpha=0.5) +
      scale_size_continuous(name="New Cases", trans = "sqrt", range=c(5,18), breaks=c(1, 100, 500, 1000, 5000, 10000),labels=c("1-99", "100-499", "500-999", "1000-4999","5000-9999", "10000+"),limits=c(1, 10000)) +
      #scale_fill_gradientn(colours = c("blue", "green", "yellow", "red"),breaks=c(1, 100, 500, 1000, 5000, 10000)) + 
      #scale_colour_manual(values = c("red", "yello","black","blue","orange")) +
      theme_void() +
      theme(legend.position="bottom")  
    
    
    world_NewCases    
    
  }
  

  else if (Method == 3 )
  {
    CountryCase <- Alldt[order(Alldt["Date"]),]
    data4 <- CountryCase[ CountryCase$`Country/Region` == Country, ]

    data5 <- data4[-1,]
    data4 <- data4[-dim(data4)[1],]
    data4$Value <- as.integer(data4$Value)
    data5$Value <- as.integer(data5$Value)
    Value <- data5$Value - data4$Value
    
    Growth1 <- data5[,c("Date")] 
    Growth2 <- data4[,c("Value")]
    Growth <- cbind(Growth1,Value)
    type <- "Growth"
    Growth <- cbind(Growth,type)
    
    type <- "Case"
    dt4 <- cbind(Growth1,Growth2)
    dt4 <- cbind(dt4,type)
    Rate <- rbind(dt4, Growth)
    
    
    ggplot(data=Rate,mapping = aes(x = Date, y = Value,colour = type, fill = type,group = type) ) +
      geom_line() + geom_point() +
      scale_linetype_manual(values = c(1,2)) +    #自定義線條類型
      scale_color_manual(values = c('steelblue','darkred')) +   #自定義顏色
      scale_shape_manual(values = c(21,23)) +   #自定義點形狀
      scale_fill_manual(values = c('red','black'))    #自定義點的填充色
  }

  
  
  
  
  
  
  
  
}
 #Date = "2020-06-22"


 Get_Covid19_Map(1,)
 #Method = 1,繪製出全球感染地圖 可選擇日期 (若未選擇則自動選擇最新日期)
 Get_Covid19_Map(1,"2020-02-22")
 #Method = 2,繪製出全球當日感染人數地圖 可選擇日期 (若未選擇則自動選擇最新日期)
 Get_Covid19_Map(2,"2020-02-22")
 Get_Covid19_Map(3,,)
 Get_Covid19_Map(3,,"Japan")

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


 
# 
# data1$Value <- as.numeric(data1$Value)
# max(data1$Value)
# size0 <- data1[ data1$Value > 0 & data1$Value <= 100, ]
# size1 <- data1[ data1$Value > 100 & data1$Value <= 500 ,]
# size2 <- data1[ data1$Value > 500 & data1$Value <= 10000, ]
# size3 <- data1[ data1$Value > 10000 & data1$Value <= 100000, ]
# size4 <- data1[ data1$Value > 100000 & data1$Value <= 500000, ]
# size5 <- data1[ data1$Value > 500000 , ]
# 
# 
# 
# ggplot()+
#   geom_polygon(data=wmap,aes(x=long,y=lat,group=group),fill="grey",alpha=0.3) +
#   geom_point(data=size0,aes(x=as.numeric(Long),y=as.numeric(Lat),size=1,color="red"),alpha=0.5) +
#   geom_point(data=size1,aes(x=as.numeric(Long),y=as.numeric(Lat),size=5,color="red"),alpha=0.5) +
#   geom_point(data=size2,aes(x=as.numeric(Long),y=as.numeric(Lat),size=10,color="red"),alpha=0.5) +
#   geom_point(data=size3,aes(x=as.numeric(Long),y=as.numeric(Lat),size=100,color="red"),alpha=0.5) +
#   geom_point(data=size4,aes(x=as.numeric(Long),y=as.numeric(Lat),size=500,color="red"),alpha=0.5) +
#   geom_point(data=size5,aes(x=as.numeric(Long),y=as.numeric(Lat),size=1000,color="red"),alpha=0.5) +
#   scale_size_continuous(name="COVID-19 cases", range=c(1,20), breaks=c(1, 500, 10000, 100000, 500000),labels=c("1-499", "500-9999", "10000-99999","100000-499999", "500000"),limits=c(1, 500000)) +
#   theme_void() +
#   theme(legend.position="bottom") 
# 
# 
# 
# 
# 
# 
# 







#scale_colour_viridis_c(option="D", direction= 1,values = NULL, name="COVID-19 cases", breaks=c(1, 20, 100, 1000, 30000),labels=c("1-19", "20-99", "100-999","1,000-29,999", "30,000"))

# 
# 
# map <- map_data("world", region = unique(wmap$region))
# wmap1 <- ggplot(map, aes(x = long, y = lat, group = group)) + geom_polygon(colour = "white")
# wmap1
# 
# 
# 
# 
# map <- map_data("world", region = c("Japan","Laos","Cambodia", "Vietnam", "Malaysia", "Thailand", "Taiwan", "China","South Korea","North Korea","Singapore","Indonesia", "Mongolia"))
# wmap1 <- ggplot(map, aes(x = long, y = lat, group = group)) + geom_polygon(colour = "white")
# wmap1 
# 
# 
# map <- map_data("world", region = data_country )
# wmap1 <- ggplot(map, aes(x = long, y = lat, group = group)) + geom_polygon(colour = "white")
# wmap1
# 
# 
# 
# 

